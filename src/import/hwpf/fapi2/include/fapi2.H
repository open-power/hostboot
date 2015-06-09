/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/fapi2.H $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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

#include <mvpd_access.H>

// Block of headers not currently in fapi2
#ifdef FAPI2_MISSING_HEADERS
    #include <mbvpdAccess.H>
#endif

#endif // __FAPI2_TOP_LEVEL__
