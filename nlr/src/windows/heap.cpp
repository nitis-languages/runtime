#if _WIN32
#include <nlr_heap.hpp>
#include <nlr_error.hpp>
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
	heap_size = max(heap_size, options.begin_oheap_size);

	heap = (u8 *)VirtualAlloc(0, heap_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (nullptr == heap)
	{
		nlr_log_err((std::string("WinErr: ") + std::to_string(GetLastError())).c_str());
		return NLR_HEAP_OUT_OF_MEMORY;
	}

	// Alloc executable heap
	u8 *exec_heap;
	usize exec_heap_size = info.dwPageSize;
	exec_heap = (u8 *)VirtualAlloc(0, exec_heap_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE);
	if (nullptr == exec_heap)
	{
		nlr_log_err((std::string("WinErr: ") + std::to_string(GetLastError())).c_str());
		return NLR_HEAP_OUT_OF_MEMORY;
	}

	// Alloc big object heap
	u8 *big_obj_heap;
	usize big_obj_heap_size = info.dwPageSize * 8;
	big_obj_heap = (u8 *)VirtualAlloc(0, exec_heap_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (nullptr == big_obj_heap)
	{
		nlr_log_err((std::string("WinErr: ") + std::to_string(GetLastError())).c_str());
		return NLR_HEAP_OUT_OF_MEMORY;
	}

	s_obj_heap.mem = heap;
	s_obj_heap.size = heap_size;
	s_exe_heap.mem = exec_heap;
	s_exe_heap.size = exec_heap_size;
	s_big_obj_heap.mem = big_obj_heap;
	s_big_obj_heap.size = big_obj_heap_size;

#ifdef NLR_ENABLE_LOGGING
	std::cout << "LOH pos: " << s_obj_heap.mem << " Size: " << s_obj_heap.size << "\n\r";
	std::cout << "BOH pos: " << s_big_obj_heap.mem << " Size: " << s_big_obj_heap.size << "\n\r";
	std::cout << "EH pos:  " << s_exe_heap.mem << " Size: " << s_exe_heap.size << "\n\r";
#endif

	nlr_log_info("Heap was init");
}

void _clear_alloca(_NlrAlloca *alloca)
{
BEGIN:
	VirtualFree(alloca->mem, 0, MEM_RELEASE);

#ifdef NLR_ENABLE_LOGGING
	std::cout << "Release segment: " << alloca->mem << "\n\r";
#endif

	if (alloca->next_segment == nullptr)
		return;
	else {
		alloca = alloca->next_segment;
		goto BEGIN;
	}
}

nlr_api_impl int nlr_heap_terminate()
{
	_clear_alloca(&s_obj_heap);
	_clear_alloca(&s_exe_heap);
	_clear_alloca(&s_big_obj_heap);

	return 0;
}

#endif
