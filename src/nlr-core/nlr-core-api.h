#ifndef _NLR_CORE_API
#define _NLR_CORE_API

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <array>
#if !defined(__cplusplus)
#include <stdbool.h>
#endif

// Prettier numeric types
typedef uint8_t		Uint8;
typedef uint16_t	Uint16;
typedef uint32_t	Uint32;
typedef uint64_t	Uint64;
typedef uintptr_t	UintPtr;
typedef int8_t		Sint8;
typedef int16_t		Sint16;
typedef int32_t		Sint32;
typedef int64_t		Sint64;
typedef intptr_t	SintPtr;
typedef float		Float32;
typedef double		Float64;

// Exports
#if !defined(NLR_STATIC)
	#if defined(_WIN32) && (defined(_MSC_VER) || defined(__MINGW32__))
		#ifdef NLR_EXPORTS
			#define NLR_API __declspec(dllexport)
		#else
			#define NLR_API __declspec(dllimport)
		#endif
	#elif defined(_WIN32) && defined(__GNUC__)
		#ifdef NLR_EXPORTS
			#define NLR_API __attribute__((__dllexport__))
		#else
			#define NLR_API __attribute__((__dllimport__))
		#endif
	#elif defined(__GNUC__)
		#define NLR_API __attribute__((__visibility__("default")))
	#endif
#endif

// Force inline
#if !defined(DEBUG) && defined(__GNUC__)
  #define NLR_INLINE inline __attribute__((__always_inline__))
#elif !defined(DEBUG) && defined(_MSC_VER)
  #define NLR_INLINE __forceinline
#else
  #define NLR_INLINE inline
#endif

// Namespaces
#define NLR_BEGIN_NAMESPACE									\
	namespace nlr {
#define NLR_END_NAMESPACE									\
	}
#define NLR_BEGIN_SUBNAMESPACE(subnamespace)				\
	NLR_BEGIN_NAMESPACE namespace subnamespace {
#define NLR_END_SUBNAMESPACE								\
	} NLR_END_NAMESPACE

// Type restrictions
#define NLR_TYPE_REMOVE_CONSTRUCTORS(type)					\
	type() = delete;										\
	type(const type& other) = delete;						\
	type& operator=(const type& other) = delete;

#define NLR_TYPE_REMOVE_COPY(type)							\
	type(const type& other) = delete;						\
	type& operator=(const type& other) = delete;

#endif