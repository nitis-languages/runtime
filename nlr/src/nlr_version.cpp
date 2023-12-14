#include <nlr_std.hpp>
#include <nlr_version_info.hpp>

begin_no_mangling

#define NLR_API_VERSION_MAJOR 0
#define NLR_API_VERSION_MINOR 0
#define NLR_API_VERSION_PATCH 1

#define NLR_API_VERSION "NiTiS Languages Runtime v0"

nlr_api_impl void nlr_stdcall nlr_get_version(u32 *const major, u32 *const minor, u32 *const patch)
{
	if (major)
		*major = NLR_API_VERSION_MAJOR;
	
	if (minor)
		*minor = NLR_API_VERSION_MINOR;

	if (patch)
		*patch = NLR_API_VERSION_PATCH;
}

nlr_api_impl char *nlr_stdcall nlr_get_version_string()
{
	return NLR_API_VERSION;
}

end_no_mangling