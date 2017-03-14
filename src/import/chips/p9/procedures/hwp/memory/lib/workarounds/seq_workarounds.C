/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/seq_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file workarounds/seq_workarounds.C
/// @brief Workarounds for the SEQ logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>

#include <generic/memory/lib/utils/scom.H>
#include <lib/workarounds/seq_workarounds.H>

namespace mss
{

namespace workarounds
{

namespace seq
{

///
/// @brief ODT Config workaround
/// For Nimbus DD1, ODT2 and ODT3 bits are swapped in each of the PHY config registers
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called during the phy scom init procedure, after the initfile is
/// processed.
///
fapi2::ReturnCode odt_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // skip the workaroud if attribute is not set
    if (! mss::chip_ec_feature_mss_odt_config(i_target) )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_INF("Running ODT Config workaround on %s", mss::c_str(i_target));

    std::vector<fapi2::buffer<uint64_t>> l_read;

    static const std::vector<uint64_t> ODT_REGS =
    {
        MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0, MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0,
        MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0, MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0
    };

    FAPI_TRY(mss::scom_suckah(i_target, ODT_REGS, l_read));

    for (auto& l_data : l_read)
    {
        // Note these bit positions are the same in RD_CONFIG* and WR_CONFIG*
        constexpr uint64_t EVEN_RANK_ODT2 = 50;
        constexpr uint64_t EVEN_RANK_ODT3 = 51;
        constexpr uint64_t ODD_RANK_ODT2 = 58;
        constexpr uint64_t ODD_RANK_ODT3 = 59;

        bool l_odt2 = 0;
        bool l_odt3 = 0;

        // swap even rank ODT2 and ODT3
        l_odt2 = l_data.getBit<EVEN_RANK_ODT2>();
        l_odt3 = l_data.getBit<EVEN_RANK_ODT3>();
        l_data.writeBit<EVEN_RANK_ODT2>(l_odt3).writeBit<EVEN_RANK_ODT3>(l_odt2);
        // swap odd rank ODT2 and ODT3
        l_odt2 = l_data.getBit<ODD_RANK_ODT2>();
        l_odt3 = l_data.getBit<ODD_RANK_ODT3>();
        l_data.writeBit<ODD_RANK_ODT2>(l_odt3).writeBit<ODD_RANK_ODT3>(l_odt2);
    }

    FAPI_TRY(mss::scom_blastah(i_target, ODT_REGS, l_read));

fapi_try_exit:
    return fapi2::current_err;
}


} // close namespace seq
} // close namespace workarounds
} // close namespace mss
