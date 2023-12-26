#pragma once
#include <nlr_type.hpp>

typedef struct _NlrTypeEx
{
	NlrType *base_type;
	enum Kind
	{
		None,
		Local,
		Ref,
		Object,
	}kind;
} NlrTypeEx;