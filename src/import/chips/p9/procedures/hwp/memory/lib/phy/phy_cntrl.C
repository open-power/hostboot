/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/phy_cntrl.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file phy_cntrl.C
/// @brief Subroutines for the PHY PC registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/phy/phy_cntrl.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/index.H>

#include <lib/mss_attribute_accessors.H>

using fapi2::TARGET_TYPE_MCA;

namespace mss
{

// Definition of the PHY PC MR shadow registers
// indexed by [rank_pair][MR index]
const std::vector< std::vector<uint64_t> > pcTraits<TARGET_TYPE_MCA>::PC_MR_SHADOW_REGS =
{
    {
        MCA_DDRPHY_PC_MR0_PRI_RP0_P0,
        MCA_DDRPHY_PC_MR1_PRI_RP0_P0,
        MCA_DDRPHY_PC_MR2_PRI_RP0_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP0_P0,
        MCA_DDRPHY_PC_MR0_SEC_RP0_P0,
        MCA_DDRPHY_PC_MR1_SEC_RP0_P0,
        MCA_DDRPHY_PC_MR2_SEC_RP0_P0,
    },
    {
        MCA_DDRPHY_PC_MR0_PRI_RP1_P0,
        MCA_DDRPHY_PC_MR1_PRI_RP1_P0,
        MCA_DDRPHY_PC_MR2_PRI_RP1_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP1_P0,
        MCA_DDRPHY_PC_MR0_SEC_RP1_P0,
        MCA_DDRPHY_PC_MR1_SEC_RP1_P0,
        MCA_DDRPHY_PC_MR2_SEC_RP1_P0,
    },
    {
        MCA_DDRPHY_PC_MR0_PRI_RP2_P0,
        MCA_DDRPHY_PC_MR1_PRI_RP2_P0,
        MCA_DDRPHY_PC_MR2_PRI_RP2_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP2_P0,
        MCA_DDRPHY_PC_MR0_SEC_RP2_P0,
        MCA_DDRPHY_PC_MR1_SEC_RP2_P0,
        MCA_DDRPHY_PC_MR2_SEC_RP2_P0,
    },
    {
        MCA_DDRPHY_PC_MR0_PRI_RP3_P0,
        MCA_DDRPHY_PC_MR1_PRI_RP3_P0,
        MCA_DDRPHY_PC_MR2_PRI_RP3_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP3_P0,
        MCA_DDRPHY_PC_MR0_SEC_RP3_P0,
        MCA_DDRPHY_PC_MR1_SEC_RP3_P0,
        MCA_DDRPHY_PC_MR2_SEC_RP3_P0,
    },
};

namespace pc
{

///
/// @brief Reset the PC CONFIG0 register
/// @param[in] i_target the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode reset_config0(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    typedef pcTraits<TARGET_TYPE_MCA> TT;

    fapi2::buffer<uint64_t> l_data;

    l_data.setBit<TT::DDR4_CMD_SIG_REDUCTION>();
    l_data.setBit<TT::DDR4_VLEVEL_BANK_GROUP>();

    FAPI_TRY( write_config0(i_target, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the PC CONFIG1 register
/// @param[in] i_target <the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode reset_config1(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    typedef pcTraits<TARGET_TYPE_MCA> TT;

    // Static table of PHY config values for MEMORY_TYPE.
    // [EMPTY, RDIMM, CDIMM, or LRDIMM][EMPTY, DDR3 or DDR4]
    constexpr uint64_t memory_type[4][3] =
    {
        { 0, 0,     0     },  // Empty, never really used.
        { 0, 0b001, 0b101 },  // RDIMM
        { 0, 0b000, 0b000 },  // CDIMM bits, UDIMM enum (placeholder, never used on Nimbus)
        { 0, 0b011, 0b111 },  // LRDIMM
    };

    fapi2::buffer<uint64_t> l_data;

    uint8_t l_rlo = 0;
    uint8_t l_wlo = 0;
    uint8_t l_dram_gen[MAX_DIMM_PER_PORT]    = {0};
    uint8_t l_dimm_type[MAX_DIMM_PER_PORT]   = {0};
    uint8_t l_type_index = 0;
    uint8_t l_gen_index = 0;

    FAPI_TRY( mss::vpd_mr_dphy_rlo(i_target, l_rlo) );
    FAPI_TRY( mss::vpd_mr_dphy_wlo(i_target, l_wlo) );
    FAPI_TRY( mss::eff_dram_gen(i_target, &(l_dram_gen[0])) );
    FAPI_TRY( mss::eff_dimm_type(i_target, &(l_dimm_type[0])) );

    // There's no way to configure the PHY for more than one value. However, we don't know if there's
    // a DIMM in one slot, the other or double drop. So we do a little gyration here to make sure
    // we have one of the two values (and assume effective config caught a bad config)
    l_type_index = l_dimm_type[0] | l_dimm_type[1];
    l_gen_index = l_dram_gen[0] | l_dram_gen[1];

    // FOR NIMBUS PHY (as the protocol choice above is) BRS
    FAPI_TRY( mss::getScom(i_target, MCA_DDRPHY_PC_CONFIG1_P0, l_data) );

    l_data.insertFromRight<TT::MEMORY_TYPE, TT::MEMORY_TYPE_LEN>(memory_type[l_type_index][l_gen_index]);
    l_data.insertFromRight<TT::WRITE_LATENCY_OFFSET, TT::WRITE_LATENCY_OFFSET_LEN>(l_wlo);

    // Always set this bit. It forces the PHY to use A12 when figuring out latency. This makes sense in
    // all cases as A12 is 0 for non-3DS in MR0.
    l_data.setBit<TT::DDR4_LATENCY_SW>();

    // If we are 2N mode we add one to the RLO (see also Centaur initfile)
    l_data.insertFromRight<TT::READ_LATENCY_OFFSET, TT::READ_LATENCY_OFFSET_LEN>(
        mss::two_n_mode_helper(i_target) ? l_rlo + 1 : l_rlo);

    FAPI_TRY( write_config1(i_target, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}


} // close namespace pc
} // close namespace mss

