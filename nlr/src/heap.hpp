#pragma once
#include <nlr_std.hpp>

typedef struct _NlrAlloca{
	void *mem;
	usize size;
} NlrAlloca;

static NlrAlloca s_oHeap; // object heap for 0 and 1gen objects
static NlrAlloca s_eHeap; // heap for executable memory (jit generated code)
static NlrAlloca s_bHeap; // heap for big objects and long long time objects (2 gen)

void *nlr_alloc(usize size); // allocate unmovable memory
void *nlr_alloc_exec(usize size); // allocate executable memory on heap
void *nlr_alloc_obj(usize size); // allocate managed memory on heap
void  nlr_alloc_pin(void *mem); // pin managed memory on heap
void  nlr_alloc_unpin(void *mem); // unpin managed memory on heap

void *nlr_int_alloc(usize size); // initialize memory allocation system
void  nlr_int_destroy(void *mem); // terminate memory allocation system

#ifndef NLR_DISABLE_NEW_OVERRIDE

#endif
