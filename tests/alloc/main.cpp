#include <nlr_std.hpp>
#include <nlr_version_info.hpp>
#include <iostream>
#include <nlr_heap.hpp>
#include <nlr_lib.hpp>

u32 main()
{
	NlrHeapInitOptions options{};
	options.begin_oheap_size = 32768;
	nlr_heap_init(options);
	std::cout << "Version: " << nlr_get_version_string() << "\n";
	
	library_rid lib_rid{};
	nlr_error_code err_code = nlr_lib_load("C:/Users/SatiNickola/Desktop/ex.nlib", lib_rid);

	if (err_code != 0)
	{
		std::cout << "Error code: " << err_code << std::endl;
	}

	std::cout << "Library rid: " << lib_rid;

	while (1)
	{

	}
	
	nlr_heap_terminate();
}