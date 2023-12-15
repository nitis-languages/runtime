#pragma once

typedef struct _NlrAlloca{
	void *mem;
	usize size;
} NlrAlloca;

static NlrAlloca s_oHeap;
static NlrAlloca s_eHeap;

enum HeapAllocationGen {
	NLR_HEAP_GEN_00	= 0,
	NLR_HEAP_GEN_01	= 1,
	NLR_HEAP_GEN_02	= 2,
};

void *nlr_alloc_exec(usize size);
void *nlr_alloc_obj(usize size);
void  nlr_alloc_pin(void *mem);
void  nlr_alloc_unpin(void *mem);