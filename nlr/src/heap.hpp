#pragma once
#include <nlr_std.hpp>

typedef struct _NlrAlloca{
	void *mem;
	usize size;
} NlrAlloca;

static NlrAlloca s_oHeap;
static NlrAlloca s_eHeap;

void *nlr_alloc_exec(usize size);
void *nlr_alloc_obj(usize size);
void  nlr_alloc_pin(void *mem);
void  nlr_alloc_unpin(void *mem);

void *nlr_int_alloc(usize size);
void  nlr_int_destroy(void *mem);

#ifndef NLR_DISABLE_NEW_OVERRIDE

#endif