#pragma once
#include <nlr_std.hpp>

nlr_api void nlr_heap_init();
nlr_api void nlr_heap_terminate();

nlr_api u8 *nlr_stdcall nlr_heap_alloc(usize size);
nlr_api void nlr_stdcall nlr_heap_free(u8 *ref);