/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/quad_encode_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file quad_encode_workarounds.C
/// @brief Contains workarounds having to do with quad-encode CS
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#include <lib/shared/nimbus_defaults.H>
#include <fapi2.H>
#include <p9n2_mc_scom_addresses.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/ccs/ccs.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/workarounds/quad_encode_workarounds.H>

namespace mss
{

namespace workarounds
{

const std::vector< uint64_t> shadow_regs_traits<0>::REGS =
{
    P9N2_MCA_DDRPHY_PC_MR0_RP0_P0,
    P9N2_MCA_DDRPHY_PC_MR0_RP1_P0,
    P9N2_MCA_DDRPHY_PC_MR0_RP2_P0,
    P9N2_MCA_DDRPHY_PC_MR0_RP3_P0,
};
const std::vector< uint64_t> shadow_regs_traits<1>::REGS =
{
    P9N2_MCA_DDRPHY_PC_MR1_RP0_P0,
    P9N2_MCA_DDRPHY_PC_MR1_RP1_P0,
    P9N2_MCA_DDRPHY_PC_MR1_RP2_P0,
    P9N2_MCA_DDRPHY_PC_MR1_RP3_P0,
};
const std::vector< uint64_t> shadow_regs_traits<2>::REGS =
{
    P9N2_MCA_DDRPHY_PC_MR2_RP0_P0,
    P9N2_MCA_DDRPHY_PC_MR2_RP1_P0,
    P9N2_MCA_DDRPHY_PC_MR2_RP2_P0,
    P9N2_MCA_DDRPHY_PC_MR2_RP3_P0,
};
const std::vector< uint64_t> shadow_regs_traits<3>::REGS =
{
    P9N2_MCA_DDRPHY_PC_MR3_RP0_P0,
    P9N2_MCA_DDRPHY_PC_MR3_RP1_P0,
    P9N2_MCA_DDRPHY_PC_MR3_RP2_P0,
    P9N2_MCA_DDRPHY_PC_MR3_RP3_P0,
};
const std::vector< uint64_t> shadow_regs_traits<4>::REGS =
{
    P9N2_MCA_DDRPHY_PC_MR4_RP0_P0,
    P9N2_MCA_DDRPHY_PC_MR4_RP1_P0,
    P9N2_MCA_DDRPHY_PC_MR4_RP2_P0,
    P9N2_MCA_DDRPHY_PC_MR4_RP3_P0,
};
const std::vector< uint64_t> shadow_regs_traits<5>::REGS =
{
    P9N2_MCA_DDRPHY_PC_MR5_RP0_P0,
    P9N2_MCA_DDRPHY_PC_MR5_RP1_P0,
    P9N2_MCA_DDRPHY_PC_MR5_RP2_P0,
    P9N2_MCA_DDRPHY_PC_MR5_RP3_P0,
};
const std::vector< uint64_t> shadow_regs_traits<6>::REGS =
{
    P9N2_MCA_DDRPHY_PC_MR6_RP0_P0,
    P9N2_MCA_DDRPHY_PC_MR6_RP1_P0,
    P9N2_MCA_DDRPHY_PC_MR6_RP2_P0,
    P9N2_MCA_DDRPHY_PC_MR6_RP3_P0,
};

///
/// @brief Returns true if an MRS command was run
/// @param[in] i_inst instruction to check for an MRS command
/// @return true iff the command contains an MRS command
///
bool is_command_mrs(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst)
{
    // An MRS command is
    // 1) at least one chip select active
    // 2) at ACT HI, RAS/CAS/WEN low
    // 3) not BA7

    const auto l_cs_low = !i_inst.arr0.getBit<MCBIST_CCS_INST_ARR0_00_DDR_CSN_0_1>() ||
                          !i_inst.arr0.getBit < MCBIST_CCS_INST_ARR0_00_DDR_CSN_0_1 + 1 > () ||
                          !i_inst.arr0.getBit<MCBIST_CCS_INST_ARR0_00_DDR_CSN_2_3>() ||
                          !i_inst.arr0.getBit < MCBIST_CCS_INST_ARR0_00_DDR_CSN_2_3 + 1 > ();

    const auto l_mrs_cmd = i_inst.arr0.getBit<MCBIST_CCS_INST_ARR0_00_DDR_ACTN>() &&
                           !i_inst.arr0.getBit<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_16>() &&
                           !i_inst.arr0.getBit<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_15>() &&
                           !i_inst.arr0.getBit<MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_14>();

    const auto l_mrs_ba = !i_inst.arr0.getBit<MCBIST_CCS_INST_ARR0_00_DDR_BANK_0_1>() ||
                          !i_inst.arr0.getBit < MCBIST_CCS_INST_ARR0_00_DDR_BANK_0_1 + 1 > () ||
                          !i_inst.arr0.getBit<MCBIST_CCS_INST_ARR0_00_DDR_BANK_GROUP_0>();
    return l_cs_low && l_mrs_cmd && l_mrs_ba;
}
///
/// @brief Returns true if a vector of commands contains an MRS command
/// @param[in] i_inst instruction to check for an MRS command
/// @return true iff the command contains an MRS command
///
bool contains_command_mrs(const std::vector<ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>>& i_inst)
{
    bool l_contains_mrs = false;

    for(const auto& l_inst : i_inst)
    {
        l_contains_mrs = is_command_mrs(l_inst);

        if(l_contains_mrs)
        {
            FAPI_DBG("0x%016lx is an MRS command. Exiting", uint64_t(l_inst.arr0));
            break;
        }
    }

    return l_contains_mrs;
}

///
/// @brief Fixes shadow register corruption over all ranks if needed
/// @param[in] i_target - the DIMM target on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
fapi2::ReturnCode fix_shadow_register_corruption( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    std::vector< uint64_t > l_ranks;
    FAPI_TRY(mss::rank::primary_ranks( i_target, l_ranks ));

    for(const auto l_rank : l_ranks)
    {
        FAPI_TRY(fix_shadow_register_corruption(i_target, l_rank));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Fixes shadow register corruption if needed
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
fapi2::ReturnCode fix_shadow_register_corruption( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank)
{
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
    const auto l_dimm_rank = mss::index(i_rank);
    uint64_t l_rp = 0;
    bool l_fix_needed = false;

    // In this case, the rank is really to get the DIMM in question
    FAPI_TRY(mss::rank::get_dimm_target_from_rank(i_target, i_rank, l_dimm),
             "%s failed to get DIMM from rank%u", mss::c_str(i_target), i_rank);

    FAPI_TRY(check_shadow_register_corruption(l_dimm, i_rank, l_fix_needed),
             "%s failed to check if the fix is needed", mss::c_str(i_target));

    // If the fix isn't needed, exit out
    if(!l_fix_needed)
    {
        FAPI_INF("%s workaround not needed. Skipping", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Shadow registers are on a per-rank pair basis
    FAPI_TRY(mss::rank::get_pair_from_rank(i_target, i_rank, l_rp),
             "%s rank%u failed to get RP nominal values", mss::c_str(i_target), i_rank);

    FAPI_TRY(fix_shadow_register_corruption_mr<0>(l_dimm, l_rp, l_dimm_rank),
             "%s failed to fix shadow regs on MR0",  mss::c_str(i_target));
    FAPI_TRY(fix_shadow_register_corruption_mr<1>(l_dimm, l_rp, l_dimm_rank),
             "%s failed to fix shadow regs on MR1",  mss::c_str(i_target));
    FAPI_TRY(fix_shadow_register_corruption_mr<2>(l_dimm, l_rp, l_dimm_rank),
             "%s failed to fix shadow regs on MR2",  mss::c_str(i_target));
    FAPI_TRY(fix_shadow_register_corruption_mr<3>(l_dimm, l_rp, l_dimm_rank),
             "%s failed to fix shadow regs on MR3",  mss::c_str(i_target));
    FAPI_TRY(fix_shadow_register_corruption_mr<4>(l_dimm, l_rp, l_dimm_rank),
             "%s failed to fix shadow regs on MR4",  mss::c_str(i_target));
    FAPI_TRY(fix_shadow_register_corruption_mr<5>(l_dimm, l_rp, l_dimm_rank),
             "%s failed to fix shadow regs on MR5",  mss::c_str(i_target));
    FAPI_TRY(fix_shadow_register_corruption_mr<6>(l_dimm, l_rp, l_dimm_rank),
             "%s failed to fix shadow regs on MR6",  mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[out] o_fix_needed - true iff the shadow register's could be corrupted (aka are we a 4R DIMM?)
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///

fapi2::ReturnCode check_shadow_register_corruption( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        bool& o_fix_needed)
{
    // Number of master ranks for this DIMM - if we have 4, we need the workaround
    // Also, always run the workaround if we have an LRDIMM
    constexpr uint8_t RANKS_FOR_FIX_NEEDED = 4;
    uint8_t l_master_ranks = 0;
    uint8_t l_dimm_type = 0;
    o_fix_needed = false;

    FAPI_TRY(mss::eff_num_master_ranks_per_dimm(i_target, l_master_ranks), "%s failed to get master ranks",
             mss::c_str(i_target));
    FAPI_TRY(mss::eff_dimm_type(i_target, l_dimm_type), "%s failed to get dimm_type",
             mss::c_str(i_target));
    o_fix_needed = (l_master_ranks == RANKS_FOR_FIX_NEEDED) ||
                   (l_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM);
    FAPI_INF("%s workaround %s needed. num master ranks %u dimm type %u", mss::c_str(i_target), o_fix_needed ? "is" : "not",
             l_master_ranks, l_dimm_type);

fapi_try_exit:
    return fapi2::current_err;
}

} // ns workarounds
} // ns mss
