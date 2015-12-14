/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_utils.C $                    */
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
/// @file p9_pm_utils.C
/// @brief Utility functions for PM FAPIs
///

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm.H>
#include <p9_pm_utils.H>
#include <p9_const_common.H>

fapi2::ReturnCode p9_pm_glob_fir_trace(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const char* i_msg)
{
    FAPI_INF("p9_pm_glob_fir_trace Enter");

#if 0 // The CONST_UINT64_T definition in P9 const_common.H takes 4 arguments -
    // CONST_UINT64_T(name, expr, unit, meth). Need to figure out the values
    // for "unit" and "meth" for the below declarations.
    CONST_UINT64_T( GLOB_XSTOP_FIR_0x01040000, ULL(0x01040000) );
    CONST_UINT64_T( GLOB_RECOV_FIR_0x01040001, ULL(0x01040001) );
    CONST_UINT64_T( TP_LFIR_0x0104000A, ULL(0x0104000A) );
#endif

    //  Note: i_msg is put on on each record to allow for trace "greps"
    //  so as to see the "big picture" across when

    uint8_t l_traceEnFlag = false;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::buffer<uint64_t> l_data64;

#if 0 // Uncomment when attribute ATTR_PM_GLOBAL_FIR_TRACE_EN is ready
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_GLOBAL_FIR_TRACE_EN,
                           FAPI_SYSTEM,
                           l_traceEnFlag),
             "FAPI_ATTR_GET for attribute ATTR_PM_GLOBAL_FIR_TRACE_EN");
#endif

    // Continue if trace is enabled.
    if (false == l_traceEnFlag)
    {
        goto fapi_try_exit;
    }

    //  ******************************************************************
    //  Check for xstops and recoverables and put in the trace
    //  ******************************************************************
    {
#if 0 // Uncomment when the scom address is defined
        FAPI_TRY(fapi2::getScom(i_target,
                                READ_GLOBAL_XSTOP_FIR_0x570F001B,
                                l_data64));
#endif

        if(l_data64)
        {
            FAPI_INF("Xstop is **ACTIVE** %s", i_msg);
        }
    }

    {
#if 0 // Uncomment when the scom address is defined
        FAPI_TRY(fapi2::getScom(i_target,
                                READ_GLOBAL_RECOV_FIR_0x570F001C,
                                l_data64));
#endif

        if(l_data64)
        {
            FAPI_INF("Recoverable attention is **ACTIVE** %s", i_msg);
        }
    }

    {
#if 0 // Uncomment when the scom address is defined
        FAPI_TRY(fapi2::getScom(i_target,
                                GLOB_XSTOP_FIR_0x01040000,
                                l_data64));
#endif

        if(l_data64)
        {
            FAPI_INF("Glob Xstop FIR is **ACTIVE** %s", i_msg);
        }
    }

    {
#if 0 // Uncomment when the scom address is defined
        FAPI_TRY(fapi2::getScom(i_target,
                                GLOB_RECOV_FIR_0x01040001,
                                l_data64));
#endif

        if(l_data64)
        {
            FAPI_INF("Glob Recov FIR is **ACTIVE** %s", i_msg);
        }
    }

    {
#if 0 // Uncomment when the scom address is defined
        FAPI_TRY(fapi2::getScom(i_target,
                                TP_LFIR_0x0104000A,
                                l_data64));
#endif

        if(l_data64)
        {
            FAPI_INF("TP LFIR is **ACTIVE** %s", i_msg);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}
