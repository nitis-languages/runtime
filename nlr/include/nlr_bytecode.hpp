#pragma once
#include <nlr_std.hpp>

#define _NiTiSByteCodeDefine(name, value, argSizeBytes) NLR_BC_##name = value,

enum NiTiSIntermediateBytecode : u8
{
	// Opcode pack №0
	_NiTiSByteCodeDefine(NOPE, 0x00, 0)			// nope			:nil:
	_NiTiSByteCodeDefine(LOAD_THIS, 0x01, 0)	// load.this	:nil:
	_NiTiSByteCodeDefine(LOAD_ARG, 0x02, 1)		// load.arg		:id8:
	_NiTiSByteCodeDefine(LOAD_LOCAL, 0x03, 2)	// load.loc		:id16:
	_NiTiSByteCodeDefine(LOAD_FIELD, 0x04, 4)	// load.fld		:id32:
	_NiTiSByteCodeDefine(RETURN, 0x05, 0)		// return		:nil:
	_NiTiSByteCodeDefine(CALL, 0x06, 4)			// call			:lid32:
	_NiTiSByteCodeDefine(CALL_VIRT, 0x07, 4)	// call.virt 	:lid32:
	_NiTiSByteCodeDefine(PUSH_32, 0x08, 4)		// push.int32	:int32:
	_NiTiSByteCodeDefine(PUSH_64, 0x09, 8)		// push.int64	:int64:
	_NiTiSByteCodeDefine(CONV_8, 0x0A, 0)		// conv.8		:nil:
	_NiTiSByteCodeDefine(CONV_16, 0x0B, 0)		// conv.16		:nil:
	_NiTiSByteCodeDefine(CONV_32, 0x0C, 0)		// conv.32		:nil:
	_NiTiSByteCodeDefine(CONV_64, 0x0D, 0)		// conv.64		:nil:
	_NiTiSByteCodeDefine(CONV_S, 0x0E, 0)		// conv.sign	:nil:
	_NiTiSByteCodeDefine(CONV_U, 0x0F, 0)		// conv.unsign	:nil:
	//_NiTiSByteCodeDefine(PUSH_THIS, 0x10, 0)	// push.this	:nil:
	_NiTiSByteCodeDefine(PUSH_ARG, 0x11, 0)		// push.arg		:nil:
	_NiTiSByteCodeDefine(PUSH_LOCAL, 0x12, 0)	// push.loc		:nil:
	_NiTiSByteCodeDefine(PUSH_FIELD, 0x13, 0)	// push.fld		:nil:
	_NiTiSByteCodeDefine(NOT, 0x13, 0)			// not			:nil:
	_NiTiSByteCodeDefine(NEG, 0x14, 0)			// neg			:nil:
	_NiTiSByteCodeDefine(ADD, 0x15, 0)			// add			:nil:
	_NiTiSByteCodeDefine(SUB, 0x16, 0)			// sub			:nil:
	_NiTiSByteCodeDefine(MUL, 0x17, 0)			// mul			:nil:
	_NiTiSByteCodeDefine(DIV, 0x18, 0)			// div			:nil:
	_NiTiSByteCodeDefine(REM, 0x19, 0)			// rem			:nil:
	_NiTiSByteCodeDefine(IS_INST, 0x1A, 4)		// is_type		:lid32:
	_NiTiSByteCodeDefine(POP, 0x1B, 0)			// pop			:nil:
	_NiTiSByteCodeDefine(DUP, 0x1C, 0)			// dup			:nil:
};
#undef _NiTiSByteCodeDefine

#define nlr_bc(_literal) ((u8)NLR_BC_##_literal)
#define nlr_bc_u32(_literal) ((u32)NLR_BC_##_literal)


static_assert(sizeof(NiTiSIntermediateBytecode) == 1, "NiTiS Languages bytecode should be 1-byte size!");