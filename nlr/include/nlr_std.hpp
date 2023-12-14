#pragma once
#include <stdint.h>

typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;

typedef uint8_t		i8;
typedef uint16_t	i16;
typedef uint32_t	i32;
typedef uint64_t	i64;

typedef float		f32;
typedef double		f64;

typedef size_t		usize;
typedef intptr_t	isize;

#ifdef __cplusplus
#define begin_no_mangling extern "C" {
#define end_no_mangling }
#else
#define begin_no_mangling
#define end_no_mangling
#endif

#if defined(__clang__) || defined(__GNUC__)
	#define nlr_stdcall __attribute__((stdcall))
	#define nlr_cdecl __attribute__((cdecl))
#elif defined(_MSC_VER)
	#define nlr_stdcall __stdcall
	#define nlr_cdecl __cdecl
#endif

#if defined(_WIN32)
	#define nlr_api __declspec(dllimport)
	#define nlr_api_impl __declspec(dllexport)
#elif defined(__GNUC__)
	#define nlr_api __attribute__((visibility("default")))
	#define nlr_api_impl __attribute__((visibility("default")))
#endif