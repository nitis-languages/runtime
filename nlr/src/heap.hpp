#pragma once
#include <nlr_std.hpp>

typedef struct _NlrAlloca {
	void *mem;
	usize size;
	_NlrAlloca *next_segment;
} NlrAlloca;

static NlrAlloca s_obj_heap; // object heap for 0 and 1gen objects
static NlrAlloca s_exe_heap; // heap for executable memory (jit generated code)
static NlrAlloca s_big_obj_heap; // heap for big objects and long long time objects (2 gen) 

struct nlr_type;

template<typename _Type>
struct nlr_object
{
	u32 obj_data;
	nlr_type *type_ref;
	_Type val;

	void pin();
	void unpin();
};

void *nlr_heap_alloc_obj(usize size);
void *nlr_heap_alloc_obj_big(usize size);
void  nlr_heap_free_obj(void *memory);

void *nlr_heap_alloc_exec(usize size);


#ifndef NLR_DISABLE_NEW_OVERRIDE

#endif
