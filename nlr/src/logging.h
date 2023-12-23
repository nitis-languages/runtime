#pragma once
#include <nlr_std.hpp>

#ifdef DEBUG
#define NLR_ENABLE_LOGGING 1
#endif

#ifdef NLR_ENABLE_LOGGING
nlr_api void nlr_log_err(const char *const msg);
nlr_api void nlr_log_warn(const char *const msg);
nlr_api void nlr_log_info(const char *const msg);
#else
#define nlr_log_err(x)
#define nlr_log_warn(x)
#define nlr_log_info(x)
#endif
