#pragma once
#include <nlr_std.hpp>

struct NlrHeapInitOptions
{
	usize begin_oheap_size;
	usize limit_oheap_size;
};

nlr_api int nlr_heap_init(const NlrHeapInitOptions &options);
nlr_api int nlr_heap_terminate();