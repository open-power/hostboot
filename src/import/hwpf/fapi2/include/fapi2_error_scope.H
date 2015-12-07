/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/fapi2_error_scope.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2012,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file fapi2_error_scope.H
 * @brief common definitions which create a scope for automatic error handling
 */

#ifndef __FAPI2_COMMON_ERROR_SCOPE__
#define __FAPI2_COMMON_ERROR_SCOPE__

#include <stdint.h>
#include <plat_error_scope.H>
#include <hwp_ffdc_classes.H>

/// @cond
#define FAPI_VA_NARGS_IMPL(_1, _2, _3, _4, _5, N, ...) N
#define FAPI_VA_NARGS(...) FAPI_VA_NARGS_IMPL(__VA_ARGS__, 5, 4, 3, 2, 1)

#define FAPI_TRY_IMPL2(count, ...) FAPI_TRY ## count (__VA_ARGS__)
#define FAPI_TRY_IMPL(count, ...) FAPI_TRY_IMPL2(count, __VA_ARGS__)

#define FAPI_TRY_NO_TRACE( __operation__ ) PLAT_FAPI_TRY_NO_TRACE( __operation__ )
#define FAPI_TRY_TRACE( __operation__, ... ) PLAT_FAPI_TRY_TRACE( __operation__, __VA_ARGS__ )

#define FAPI_TRY1 FAPI_TRY_NO_TRACE
#define FAPI_TRY2 FAPI_TRY_TRACE
#define FAPI_TRY3 FAPI_TRY_TRACE
#define FAPI_TRY4 FAPI_TRY_TRACE
#define FAPI_TRY5 FAPI_TRY_TRACE
/// @endcond

///
/// @brief Wrapper to check an operation for an error state
/// and jump to the label clean_up if there is an error.
/// @param[in] \__operation__ an operation which returns a fapi::ReturnCode
/// @param[in] ... vararg format/agruments for trace output (optional)
/// @note This implementation does not support PIB error masks or
/// FSP operational states.
///
#ifdef DOXYGEN
    #define FAPI_TRY(__operation__, ...) FAPI_TRY_IMPL
#else
    #define FAPI_TRY(...) FAPI_TRY_IMPL(FAPI_VA_NARGS(__VA_ARGS__), __VA_ARGS__)
#endif

///
/// @brief Assert a conditional is true.
/// If it is not, the FFDC gathering function is called and the
/// trace is output as a FAPI error trace.
/// @param[in] \__conditional__ the condition to assert
/// @param[in] \__ffdc__ the FFDC gathering function
/// @param[in] ... varargs, as input to FAPI_ERR
///
#define FAPI_ASSERT( __conditional__, __ffdc__, ... ) \
    PLAT_FAPI_ASSERT( __conditional__, __ffdc__, __VA_ARGS__ )

///
/// @brief Create an eror log, commit it, but do not exit the hwp because of
///        the error condition.
/// @param[in] \__conditional__ the condition to assert
/// @param[in] \__ffdc__ the FFDC gathering function
/// @param[in] ... varargs, as input to FAPI_ERR
///
#define FAPI_ASSERT_NOEXIT( __conditional__, __ffdc__, ... ) \
    PLAT_FAPI_ASSERT_NOEXIT( __conditional__, __ffdc__, __VA_ARGS__ )

#endif
