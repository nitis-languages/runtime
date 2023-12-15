#if _WIN32
#include <nlr_std.hpp>
#include "../logging.h"
#include <Windows.h>
#include <string>
#ifdef NLR_ENABLE_LOGGING

void __write_log(const char *const buffer, int len) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	WriteConsoleA(h, buffer, len, 0, 0);
}

#define __ERR_MSG "Error message: "
#define __ERR_MSG_LEN sizeof(__ERR_MSG) / sizeof(char)
#define __WRN_MSG "Warning message: "
#define __WRN_MSG_LEN sizeof(__WRN_MSG) / sizeof(char)
#define __INF_MSG "Info message: "
#define __INF_MSG_LEN sizeof(__INF_MSG) / sizeof(char)

nlr_api_impl void nlr_log_err(const char *const msg) {
	__write_log(__ERR_MSG, __ERR_MSG_LEN);
	__write_log(msg, strlen(msg));
	__write_log("\n", 1);
}
nlr_api_impl void nlr_log_warn(const char *const msg) {
	__write_log(__WRN_MSG, __WRN_MSG_LEN);
	__write_log(msg, strlen(msg));
	__write_log("\n", 1);
}
nlr_api_impl void nlr_log_info(const char *const msg) {
	__write_log(__INF_MSG, __INF_MSG_LEN);
	__write_log(msg, strlen(msg));
	__write_log("\n", 1);
}

#endif
#endif