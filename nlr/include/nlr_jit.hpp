#pragma once
#include <nlr_std.hpp>
#include <nlr_error.hpp>
#include <nlr_id.hpp>

begin_no_mangling

nlr_api nlr_error_code nlr_stdcall nlr_jit_execute(method_rid method, void *arguments, void *dst);

end_no_mangling
