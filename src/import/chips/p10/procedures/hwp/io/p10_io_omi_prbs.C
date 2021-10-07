/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_omi_prbs.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target,
    const bool& i_on)
{
    FAPI_DBG("Begin");
    using namespace scomt::omi;
    using namespace scomt::omic;
    int l_num_lanes = P10_IO_LIB_NUMBER_OF_OMI_LANES;
    fapi2::buffer<uint64_t> l_data = 0;

    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_omi_target, l_tgt_str, sizeof(l_tgt_str));


    uint32_t l_pattern_sel = 0;
    uint32_t l_pattern_enable = 0;

    if (i_on)
    {
        l_pattern_sel = 6; // PRBS23
        l_pattern_enable = 1;

        // tx_pattern_sel = 6 (PRBS23), tx_ctl_cntl1_pg
        auto l_omic_target = i_omi_target.getParent<fapi2::TARGET_TYPE_OMIC>();
        FAPI_TRY(GET_CTL_REGS_TX_CNTL1_PG(l_omic_target, l_data));
        SET_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(l_pattern_sel, l_data);
        FAPI_TRY(PUT_CTL_REGS_TX_CNTL1_PG(l_omic_target, l_data));


        // tx_pattern_enable = 1, pl, tx_cntl3_pl
        FAPI_TRY(p10_io_omi_put_pl_regs(i_omi_target,
                                        TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL,
                                        TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
                                        1,
                                        l_num_lanes,
                                        l_pattern_enable));
    }
    else // OFF
    {
        // If we are turning PRBS OFF, we need to disable the lanes fist, then reset the pattern.
        // - Otherwise, we will be driving stale data for a period of time.
        // - If we have DLs observing this data, there is a chance that stale data could look like
        //   a valid pattern.

        // tx_pattern_sel = 1 (1010), tx_ctl_cntl1_pg
        l_pattern_sel = 1;
        auto l_omic_target = i_omi_target.getParent<fapi2::TARGET_TYPE_OMIC>();
        FAPI_TRY(GET_CTL_REGS_TX_CNTL1_PG(l_omic_target, l_data));
        SET_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(l_pattern_sel, l_data);
        FAPI_TRY(PUT_CTL_REGS_TX_CNTL1_PG(l_omic_target, l_data));

        // tx_pattern_enable = 1, pl, tx_cntl3_pl
        FAPI_TRY(p10_io_omi_put_pl_regs(i_omi_target,
                                        TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL,
                                        TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE,
                                        1,
                                        l_num_lanes,
                                        l_pattern_enable));

        // tx_pattern_sel = 6 (PRBS23), tx_ctl_cntl1_pg
        l_pattern_sel = 0;
        FAPI_TRY(GET_CTL_REGS_TX_CNTL1_PG(l_omic_target, l_data));
        SET_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL(l_pattern_sel, l_data);
        FAPI_TRY(PUT_CTL_REGS_TX_CNTL1_PG(l_omic_target, l_data));
    }



fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
