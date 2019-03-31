/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_query_core_access_state.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file  p9_query_core_access_state.C
/// @brief Check the stop level for a core and set boolean scanable, scomable parameters
///
// *HWP HWP Owner: Brian Vanderpool <vanderp@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS:SBE
///
///
///
/// @verbatim
/// High-level procedure flow:
///     - For the core target, read the Stop State History register in the PPM
///       and use the actual stop level to determine if the core has power and is being
///       clocked.
/// @endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p9_query_core_access_state.H"

#define SSHSRC_STOP_GATED 0
#define NET_CTRL0_FENCED  18

// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------

fapi2::ReturnCode
p9_query_core_access_state(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    bool& o_is_scomable,
    bool& o_is_scanable)
{

    fapi2::buffer<uint64_t> l_csshsrc, l_sisr, l_netCtrl0;
    fapi2::buffer<uint64_t> l_data64;
    uint32_t l_coreStopLevel        =   0;
    uint8_t  c_exec_hasclocks       =   0;
    uint8_t  c_pc_hasclocks         =   0;
    uint8_t  l_chpltNumber          =   0;
    o_is_scomable                   =   false;
    o_is_scanable                   =   false;
    fapi2::ReturnCode   l_tempRc    =   fapi2::FAPI2_RC_SUCCESS;


    FAPI_INF("> p9_query_core_access_state...");
    auto l_eq_target = i_target.getParent<fapi2::TARGET_TYPE_EQ>();

    //Check if quad/core is powered off; if so, indicate
    //not scomable or scannable
    FAPI_TRY(fapi2::getScom(l_eq_target, EQ_PPM_PFSNS, l_data64),
             "Error reading data from EQ_PPM_PFSNS");

    if (l_data64.getBit<EQ_PPM_PFSNS_VDD_PFETS_DISABLED_SENSE>())
    {
        goto fapi_try_exit;
    }

    FAPI_TRY(fapi2::getScom(i_target, C_PPM_PFSNS, l_data64),
             "Error reading data from C_PPM_PFSNS" );

    if (l_data64.getBit<C_PPM_PFSNS_VDD_PFETS_DISABLED_SENSE>())
    {
        goto fapi_try_exit;
    }

    o_is_scanable       =   true;

    // Get the stop state from the SSHRC in the CPPM
    FAPI_TRY(fapi2::getScom(i_target, C_PPM_SSHSRC, l_csshsrc),
             "Error reading data from CPPM SSHSRC" );

    // A unit is scomable if clocks are running
    // A unit is scannable if the unit is powered up.

    // Extract the core stop state
    if (l_csshsrc.getBit<SSHSRC_STOP_GATED>() == 1)
    {
        l_csshsrc.extractToRight<uint32_t>(l_coreStopLevel, 8, 4);
    }

    if (l_coreStopLevel == 0)
    {
        // Double check the core isn't in stop 1
        auto l_ex_target = i_target.getParent<fapi2::TARGET_TYPE_EX>();

        FAPI_TRY(fapi2::getScom(l_ex_target, EX_CME_LCL_SISR_SCOM, l_sisr),
                 "Error reading data from CME SISR register" );

        FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_chpltNumber);

        uint32_t l_pos = l_chpltNumber % 2;

        if (l_pos == 0 && l_sisr.getBit<EX_CME_LCL_SISR_PM_STATE_ACTIVE_C0>())
        {
            l_sisr.extractToRight<uint32_t>(l_coreStopLevel, EX_CME_LCL_SISR_PM_STATE_C0, EX_CME_LCL_SISR_PM_STATE_C0_LEN);
        }

        if (l_pos == 1 && l_sisr.getBit<EX_CME_LCL_SISR_PM_STATE_ACTIVE_C1>())
        {
            l_sisr.extractToRight<uint32_t>(l_coreStopLevel, EX_CME_LCL_SISR_PM_STATE_C1, EX_CME_LCL_SISR_PM_STATE_C1_LEN);
        }
    }

    FAPI_INF("Core Stop State: C(%d)", l_coreStopLevel);

    // STOP1 - NAP
    //  VSU, ISU are clocked off
    if (l_coreStopLevel < 1)
    {
        o_is_scomable   =   1;
    }

    //----------------------------------------------------------------------------------
    // Read clock status and pfet_sense_disabled to confirm stop state history is accurate
    // If we trust the stop state history, this could be removed to save on code size
    //----------------------------------------------------------------------------------

    // By this time we know core is powered.
    // Get the fence bit for this core from C_NET_CTRL0
    l_tempRc    =   fapi2::getScom(i_target, C_NET_CTRL0, l_netCtrl0);

    if( l_tempRc != fapi2::FAPI2_RC_SUCCESS )
    {
        FAPI_INF( "Error reading data from C_NET_CTRL0" );
        //unable to read fence status. Set core state to Non-Scomable.
        o_is_scomable       =   false;
        goto fapi_try_exit;
    }

    if (l_netCtrl0.getBit<NET_CTRL0_FENCED>() == 0)
    {
        FAPI_DBG(" Read Core EPS clock status for core" );
        l_tempRc    =   fapi2::getScom(i_target, C_CLOCK_STAT_SL,  l_data64) ;

        if( l_tempRc != fapi2::FAPI2_RC_SUCCESS )
        {
            FAPI_ERR( "Error reading data from C_CLOCK_STAT_SL" );
            //unable to read fence status. Set core state to Non-Scomable.
            o_is_scomable       =   false;
            goto fapi_try_exit;
        }

        l_data64.extractToRight<uint8_t>(c_exec_hasclocks, 6, 1);
        l_data64.extractToRight<uint8_t>(c_pc_hasclocks,   5, 1);

        // Inverted logic in the HW
        c_exec_hasclocks = !c_exec_hasclocks;
        c_pc_hasclocks   = !c_pc_hasclocks;
    }
    else
    {
        FAPI_INF("Core Fences are up, so skipped reading the C_CLOCK_STAT_SL Register");
    }

    FAPI_INF("Core Clock Status : PC_HASCLOCKS(%d) EXEC_HASCLOCKS(%d)", c_pc_hasclocks, c_exec_hasclocks);
    FAPI_DBG("Core Is Scanable STOP_STATE(%d)  ", o_is_scanable );

    FAPI_DBG("Comparing Stop State vs Actual HW settings for scomable state");

    FAPI_DBG("Core Is Scomable STOP_STATE(%d)  CLKSTAT(%d)", o_is_scomable, (c_pc_hasclocks && c_exec_hasclocks));

    //----------------------------------------------------------------------------------
    // Compare Hardware status vs stop state status.   If there is a mismatch, the HW value overrides the stop state
    //----------------------------------------------------------------------------------

    //If we could reach this far, we know core is powered and hence scanable.

    //Let us revalidate SCOMable status

    if ( o_is_scomable != ( c_pc_hasclocks && c_exec_hasclocks ) )
    {
        FAPI_INF("Clock status didn't match stop state, overriding is_scomable status");
        o_is_scomable = (c_pc_hasclocks && c_exec_hasclocks);
    }

fapi_try_exit:
    FAPI_INF("< p9_query_core_access_state...");
    fapi2::current_err  =   fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}
