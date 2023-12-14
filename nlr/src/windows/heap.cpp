#include <nlr_heap.hpp>
#include "../logging.h"


nlr_api_impl void nlr_heap_init()
{
	nlr_log_info("Heap was init");
}

nlr_api_impl void nlr_heap_terminate()
{
	nlr_log_info("Heap was terminate");
}