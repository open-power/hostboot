///
/// @file fapi2.H
/// @brief top level header for fapi2
///

#ifndef __FAPI2_TOP_LEVEL__
#define __FAPI2_TOP_LEVEL__

#include <target.H>
#include <return_code.H>
#include <buffer.H>
#include <hw_access.H>
#include <utils.H>
#include <plat_trace.H>

// In turn includes the needed generated headers (hwp_ffd_classes, etc.)
#include <error_scope.H>
#include <set_sbe_error.H>      // Generated file

#include <hwp_executor.H>

// Block of headers not currently in fapi2
#ifdef FAPI2_MISSING_HEADERS
  #include <mvpdAccess.H>
  #include <mbvpdAccess.H>
#endif

#endif // __FAPI2_TOP_LEVEL__
