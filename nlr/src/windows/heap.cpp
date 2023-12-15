#if _WIN32
#include <nlr_heap.hpp>
#include <Windows.h>
#include <string>
#include <iostream>
#include "../logging.h"
#include "../heap.hpp"


nlr_api_impl int nlr_heap_init(const NlrHeapInitOptions &options)
{
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	// Alloc object heap
	u8 *heap;
	usize heap_size = static_cast<usize>(info.dwPageSize);
	heap_size = max(heap_size, options.begin_eheap_size);

	heap = (u8 *)VirtualAlloc(0, heap_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (nullptr == heap)
	{
		nlr_log_err((std::string("WinErr: ") + std::to_string(GetLastError())).c_str());
		return ERR_HEAP_OUT_OF_MEMORY;
	}

	// Alloc executable heap
	u8 *exec_heap;
	usize exec_heap_size = info.dwPageSize;
	exec_heap = (u8 *)VirtualAlloc(0, exec_heap_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE);
	if (nullptr == exec_heap)
	{
		nlr_log_err((std::string("WinErr: ") + std::to_string(GetLastError())).c_str());
		return ERR_HEAP_OUT_OF_MEMORY;
	}

	s_oHeap.mem = heap;
	s_oHeap.size = heap_size;
	s_eHeap.mem = exec_heap;
	s_eHeap.size = exec_heap_size;

#ifdef NLR_ENABLE_LOGGING
	std::cout << "Heap pos: " << s_oHeap.mem << " Size: " << s_oHeap.size << "\n\r";
	std::cout << "Heap pos: " << s_eHeap.mem << " Size: " << s_eHeap.size << "\n\r";
#endif

	nlr_log_info("Heap was init");
}

nlr_api_impl int nlr_heap_terminate()
{
	nlr_log_info("Heap was terminate");

	return 0;
}

#endif