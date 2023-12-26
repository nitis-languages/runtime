#pragma once
#include <nlr_std.hpp>
#include <nlr_id.hpp>

// WARNING: All values in nlib stored in little-endian, include signatures and constants in bytecode

#define NLR_HEADER_SIGNATURE ((u32)1651076206)
#define NLR_END_OF_HEADER_SIGNATURE ((u8)0x0F)
constexpr usize NlrLibHeaderSize = 64;
#define NLR_STDLIB_NAME "stdlib.nlib"

struct NlrLibHeader {

	/*0x00 - 0x0F */
	u32 header_signature;
	u16 nlr_required_version_major;
	u16 nlr_required_version_minor;
	u16 nlr_required_version_patch;
	u8  reserved_01[3];

	/* 0x10 - 0x1F */
	u64 nlr_required_features;
	u8 reserved_02[8];

	/* 0x20 - 0x2F */
	u8 resered_03[12];
	u32 entry_point_lid; // If 0, has no entry point

	/* 0x30 - 0x3F */
	u8 reserved_04[15];
	u8 end_of_header_signature;
};

constexpr usize NlrLibSegmentSize = 16;

enum NlrLibSegmentType : u8 {
	ST_INALID_NONE = 0,

	ST_STRING_UTF8  = 0x01,

	ST_METHOD_TABLE = 0x10,
	ST_TYPE_TABLE = 0x11,
	
	ST_METHOD_REF_TABLE = 0x20,
	ST_TYPE_REF_TABLE = 0x21,
	ST_LIBRARY_REF_TABLE = 0x22,
};

struct NlrLibSegment {
	NlrLibSegmentType type;
	u8 reserved_01[3];
	u32 size;
	u32 offset_to_next_segment;
	u32 reserved_02;
};

struct NlrLibSegment_LibraryRefTableEntity
{
	library_lid id;
	string_lid name_id;
};

static_assert(sizeof(NlrLibSegment) == NlrLibSegmentSize, "The NlrLibSegment struct is not 16 bytes long!");
static_assert(sizeof(NlrLibHeader) == NlrLibHeaderSize, "The NlrLibHeader struct is not 64 bytes long!");
