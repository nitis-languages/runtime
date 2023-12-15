#pragma once
#include <nlr_id.hpp>
#include <nlr_error.hpp>
begin_no_mangling

nlr_api nlr_error_code nlr_stdcall nlr_lib_get_entry_point_rid(library_rid lib, method_rid &retusa);
nlr_api nlr_error_code nlr_stdcall nlr_lib_load(const char *const path, library_rid &retusa);

end_no_mangling