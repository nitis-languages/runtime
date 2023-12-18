#pragma once
#include <nlr_std.hpp>

enum NlrFeatures : u64 {
	NLR_FEATURE_NONE = 0,
	NLR_FEATURE_GENERICS = 1 << 0,
	NLR_FEATURE_STATIC_CONSTRUCTORS = 1 << 1,
	NLR_FEATURE_THREAD_LOCALS = 1 << 2,
};

nlr_api NlrFeatures nlr_stdcall nlr_get_features(void);
