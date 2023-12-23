#pragma once
#include <nlr_std.hpp>
#include <nlr_id.hpp>

typedef struct _NlrType {
	rid32 id;
	_NlrType *parent;
} NlrType;