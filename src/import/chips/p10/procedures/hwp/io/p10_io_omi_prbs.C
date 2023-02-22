/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_omi_prbs.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
// EKB-Mirror-To: hostboot
///
/// @file p10_io_omi_prbs.C
/// @brief Common IO functions and constants
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <fapi2.H>
#include <vector>
#include <utils.H>
#include <p10_io_lib.H>
#include <p10_io_omi_prbs.H>
#include <p10_scom_omi.H>
#include <p10_scom_omic.H>

/// @brief Drive PRBS from PHY
/// @param[in] i_iohs_target   OMI target to get thread id for
/// @param[in] i_on            Enable/Disable PRBS
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_omi_prbs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
    const bool& i_on)
{
    FAPI_DBG("Begin");
    using namespace scomt::omi;
    using namespace scomt::omic;
    const uint64_t SCOM_LANE_BROADCAST  = 0x0000001F00000000;
    uint64_t l_cntl3_pl_addr = TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL | SCOM_LANE_BROADCAST;
    fapi2::buffer<uint64_t> l_data = 0;


    uint32_t l_pattern_sel    = i_on ? 6 : 1; // PRBS23 or 1010 Pattern (non-dl pattern)
    uint32_t l_pattern_enable = i_on ? 1 : 0;

    // Enable the tx err inject clock enable
    // - disables some clock gating in the tx fifo
    FAPI_TRY(GET_CTL_REGS_TX_CNTL2_PG(i_omic_target, l_data));
    SET_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(1, l_data);
    FAPI_TRY(PUT_CTL_REGS_TX_CNTL2_PG(i_omic_target, l_data));

    // Drive the desired pattern before enabling the per lane enables
    // ON: PRBS23
    // OFF: 1010 Pattern (non-dl pattern)
    FAPI_TRY(GET_CTL_REGS_TX_CNTL1_PG(i_omic_target, l_data));
    SET_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(l_pattern_sel, l_data);
    FAPI_TRY(PUT_CTL_REGS_TX_CNTL1_PG(i_omic_target, l_data));

    l_data.flush<0>();
    l_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE, 1>(l_pattern_enable);
    l_data.insertFromRight<TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE, 1>(0x1);
    FAPI_TRY(fapi2::putScom(i_omic_target, l_cntl3_pl_addr, l_data));

    if (i_on == false)
    {
        // Drive the desired pattern before enabling the per lane enables
        // ON: PRBS23
        // OFF: 1010 Pattern (non-dl pattern)
        FAPI_TRY(GET_CTL_REGS_TX_CNTL1_PG(i_omic_target, l_data));
        SET_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(0, l_data);
        FAPI_TRY(PUT_CTL_REGS_TX_CNTL1_PG(i_omic_target, l_data));
    }

    // Disable the tx err inject clock enable
    // - saves power
    // - by this time the fifo should be flushed
    FAPI_TRY(GET_CTL_REGS_TX_CNTL2_PG(i_omic_target, l_data));
    SET_CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE(0, l_data);
    FAPI_TRY(PUT_CTL_REGS_TX_CNTL2_PG(i_omic_target, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
