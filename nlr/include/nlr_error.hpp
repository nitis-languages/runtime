#pragma once
#include <nlr_std.hpp>

enum nlr_error_code {
	NLR_SUCCESS = 0,
	NLR_GENERIC_ERROR = 1,
	NLR_FILE_NOT_EXISTS = 2,
	NLR_INVALID_FORMAT = 3,
	NLR_UNSUITABLE_VERSION = 4,
	ERR_HEAP_OUT_OF_MEMORY = 5,
};