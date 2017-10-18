/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/ccs_workarounds.C $ */
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
/// @file ccs_workarounds.H
/// @brief Contains CCS workarounds
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#include <lib/workarounds/ccs_workarounds.H>
#include <lib/dimm/rank.H>
#include <p9_mc_scom_addresses.H>
#include <generic/memory/lib/utils/scom.H>

namespace mss
{

namespace ccs
{

namespace workarounds
{

///
/// @brief Re-enables PDA mode on a given rank in the shadow registers
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
fapi2::ReturnCode enable_pda_shadow_reg( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank )
{
    static const std::vector<uint64_t> RP_TO_REG =
    {
        MCA_DDRPHY_PC_MR3_PRI_RP0_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP1_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP2_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP3_P0,
    };

    uint64_t l_rp = 0;
    FAPI_TRY( mss::rank::get_pair_from_rank( i_target, i_rank, l_rp ), "%s failed to get pair from rank %lu",
              mss::c_str(i_target), i_rank );

    // Reads, modifies, and writes the value back out
    {
        // The bits in the shadow register are one block, we only want to set the PDA enable bit, which corresponds to bit 59
        constexpr uint64_t PDA_BIT = 59;
        fapi2::buffer<uint64_t> l_data;

        // Read
        FAPI_TRY(mss::getScom(i_target, RP_TO_REG[l_rp], l_data));

        // Modify
        l_data.setBit<PDA_BIT>();

        // Write
        FAPI_TRY(mss::putScom(i_target, RP_TO_REG[l_rp], l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Issues the PDA exit command
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[in,out] io_program - the CCS program
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
/// @note The PHY traps both the a-side and b-side MRS's into the same shadow register
/// After the a-side MRS exits PDA, the b-side MRS will not be taken out of PDA mode
/// To workaround this problem, a-side MRS is issued, then the shadow register is modified to have PDA mode enabled
/// Then the b-side MRS is issued
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const uint64_t i_rank,
                        ccs::program<fapi2::TARGET_TYPE_MCBIST>& io_program )
{
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    // Issues A-side MRS
    {
        auto l_a_side = io_program;
        l_a_side.iv_instructions.clear();
        l_a_side.iv_instructions.push_back(io_program.iv_instructions[0]);

        FAPI_TRY( ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                               l_a_side,
                               l_mca),
                  "unable to execute CCS for MR03 a-side PDA exit rank %d %s",
                  i_rank, mss::c_str(i_target) );
    }

    // Re-enable PDA mode in the PHY
    {
        FAPI_TRY(enable_pda_shadow_reg(l_mca, i_rank));
    }

    // Sets up the B-side MRS - the outside code will issue it
    // This allows the workaround to be encapuslated and the exit code to function properly for cases where the workaround should not be executed
    {
        auto l_b_side = io_program;
        l_b_side.iv_instructions.clear();
        l_b_side.iv_instructions.push_back(io_program.iv_instructions[1]);
        io_program = l_b_side;
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns workarounds

} // ns ccs

} // ns mss
