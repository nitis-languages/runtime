#ifdef _WIN32
#include <nlr_lib.hpp>
#include <nlr_nlib_header.hpp>
#include <nlr_version_info.hpp>
#include <nlr_id.hpp>
#include <nlr_error.hpp>
#include <Windows.h>
#include "../logging.h"
#include <iostream>

nlr_api_impl nlr_error_code nlr_stdcall nlr_lib_load(const char *const path, library_rid &retusa)
{
	usize file_size;
	HANDLE file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	GetFileSizeEx(file, (PLARGE_INTEGER)&file_size);

	if (file == 0)
		return NLR_FILE_NOT_EXISTS;

#ifdef NLR_ENABLE_LOGGING
	std::cout << "File: " << file << std::endl;
	std::cout << "Size: " << file_size << std::endl;
#endif

	if (file_size < NlrLibHeaderSize)
	{
		CloseHandle(file);
		return NLR_INVALID_FORMAT;
	}

	NlrLibHeader header;

	if (!ReadFile(file, &header, NlrLibHeaderSize, 0, 0))
	{
		nlr_log_err("Failure on file reading");
		CloseHandle(file);
		return NLR_GENERIC_ERROR;
	}

	if (NLR_HEADER_SIGNATURE != header.header_signature)
	{
		CloseHandle(file);
		return NLR_INVALID_FORMAT;
	}

	u32 curr_major, curr_minor, curr_patch;
	nlr_get_version(&curr_major, &curr_minor, &curr_patch);

	if (curr_major < header.nlr_required_version_major
		|| curr_minor < header.nlr_required_version_minor
		|| curr_patch < header.nlr_required_version_patch)
	{
		CloseHandle(file);
		return NLR_UNSUITABLE_VERSION;
	}

	CloseHandle(file);
	return NLR_SUCCESS;
}

#endif