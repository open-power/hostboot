/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_utils.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
#include <p9_perv_scom_addresses.H>

/// Byte-reverse a 16-bit integer if on a little-endian machine

uint16_t
revle16(const uint16_t i_x)
{
    uint16_t rx;

#ifndef _BIG_ENDIAN
    uint8_t* pix = (uint8_t*)(&i_x);
    uint8_t* prx = (uint8_t*)(&rx);

    prx[0] = pix[1];
    prx[1] = pix[0];
#else
    rx = i_x;
#endif

    return rx;
}

/// Byte-reverse a 32-bit integer if on a little-endian machine

uint32_t
revle32(const uint32_t i_x)
{
    uint32_t rx;

#ifndef _BIG_ENDIAN
    uint8_t* pix = (uint8_t*)(&i_x);
    uint8_t* prx = (uint8_t*)(&rx);

    prx[0] = pix[3];
    prx[1] = pix[2];
    prx[2] = pix[1];
    prx[3] = pix[0];
#else
    rx = i_x;
#endif

    return rx;
}


/// Byte-reverse a 64-bit integer if on a little-endian machine

uint64_t
revle64(const uint64_t i_x)
{
    uint64_t rx;

#ifndef _BIG_ENDIAN
    uint8_t* pix = (uint8_t*)(&i_x);
    uint8_t* prx = (uint8_t*)(&rx);

    prx[0] = pix[7];
    prx[1] = pix[6];
    prx[2] = pix[5];
    prx[3] = pix[4];
    prx[4] = pix[3];
    prx[5] = pix[2];
    prx[6] = pix[1];
    prx[7] = pix[0];
#else
    rx = i_x;
#endif

    return rx;
}

fapi2::ReturnCode p9_pm_glob_fir_trace(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const char* i_msg)
{
    FAPI_DBG(">> p9_pm_glob_fir_trace");

    // Multicast read addresses
    const uint64_t READ_GLOB_XSTOP_FIR_MC =  RULL(0x570F001C);
    const uint64_t READ_GLOB_RECOV_FIR_MC =  RULL(0x570F001B);

    //  Note: i_msg is put on on each record to allow for trace "greps"
    //  so as to see the "big picture" across when
    uint8_t l_traceEnFlag = false;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::buffer<uint64_t> l_data64;


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_GLOBAL_FIR_TRACE_EN,
                           FAPI_SYSTEM,
                           l_traceEnFlag),
             "FAPI_ATTR_GET for attribute ATTR_PM_GLOBAL_FIR_TRACE_EN");

    // Continue if trace is enabled.
    if (!l_traceEnFlag)
    {
        goto fapi_try_exit;
    }

    //  ******************************************************************
    //  Check for xstops and recoverables and put in the trace
    //  ******************************************************************
    {
        FAPI_TRY(fapi2::getScom(i_target,
                                READ_GLOB_XSTOP_FIR_MC,
                                l_data64));

        if(l_data64)
        {
            FAPI_INF("Xstop is **ACTIVE** %s", i_msg);
        }
    }

    {
        FAPI_TRY(fapi2::getScom(i_target,
                                READ_GLOB_RECOV_FIR_MC,
                                l_data64));

        if(l_data64)
        {
            FAPI_INF("Recoverable attention is **ACTIVE** %s", i_msg);
        }
    }

    {
        FAPI_TRY(fapi2::getScom(i_target,
                                PERV_TP_XFIR,
                                l_data64));

        if(l_data64)
        {
            FAPI_INF("Glob Xstop FIR is **ACTIVE** %s", i_msg);
        }
    }

    {
        FAPI_TRY(fapi2::getScom(i_target,
                                PERV_TP_RFIR,
                                l_data64));

        if(l_data64)
        {
            FAPI_INF("Glob Recov FIR is **ACTIVE** %s", i_msg);
        }
    }

    {
        FAPI_TRY(fapi2::getScom(i_target,
                                PERV_TP_LOCAL_FIR,
                                l_data64));

        if(l_data64)
        {
            FAPI_INF("TP LFIR is **ACTIVE** %s", i_msg);
        }
    }

fapi_try_exit:
    FAPI_DBG("<< p9_pm_glob_fir_trace");
    return fapi2::current_err;
}

fapi2::ReturnCode special_wakeup_all(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_enable)
{
    FAPI_DBG(">> special_wakeup_all");

    fapi2::ReturnCode l_rc;
    auto l_exChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EX>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

    // For each EX target
    for (auto l_ex_chplt : l_exChiplets)
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_ex_num;
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                l_ex_chplt,
                                l_ex_num));
        FAPI_DBG("Running special wakeup on ex chiplet 0x%08X ", l_ex_num);

        FAPI_TRY( fapi2::specialWakeup( l_ex_chplt, i_enable ) );
    }

fapi_try_exit:
    FAPI_DBG("<< special_wakeup_all");
    return fapi2::current_err;
}
