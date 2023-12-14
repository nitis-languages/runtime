#include <nlr_std.hpp>
#include <nlr_version_info.hpp>
#include <iostream>
#include <nlr_heap.hpp>

u32 main()
{
	nlr_heap_init();
	std::cout << "Version: " << nlr_get_version_string() << "\n";
	nlr_heap_terminate();
}