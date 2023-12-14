#pragma once
#include <nlr_std.hpp>

begin_no_mangling

nlr_api void nlr_stdcall nlr_get_version(u32 *const major, u32 *const minor, u32 *const patch);
nlr_api char *nlr_stdcall nlr_get_version_string();

end_no_mangling
