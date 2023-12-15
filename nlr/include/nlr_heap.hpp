#pragma once
#include <nlr_std.hpp>

#define ERR_HEAP_OUT_OF_MEMORY 1

nlr_api int nlr_heap_init();
nlr_api int nlr_heap_terminate();

/// @brief Allocate not-executable memory
nlr_api u8 *nlr_stdcall nlr_heap_alloc(usize size);
/// @brief Allocate executable memory
nlr_api u8 *nlr_stdcall nlr_heap_alloc_exc(usize size);
nlr_api void nlr_stdcall nlr_heap_free(u8 *ref);