/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/adr.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file adr.C
/// @brief Subroutines for the PHY ADR registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/phy/adr.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;

namespace mss
{
//ADR clock registers - one pair per clock leg
const std::vector< std::pair<uint64_t, uint64_t> > adrTraits<TARGET_TYPE_MCA>::IO_TX_FET_SLICE_CLK_REG =
{
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE3_POS },
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE2_POS },
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE6_POS },
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE7_POS },
};
//ADR command/address registers
const std::vector< std::pair<uint64_t, uint64_t> > adrTraits<TARGET_TYPE_MCA>::IO_TX_FET_SLICE_CMD_ADDR_REG =
{
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE0_POS }, //ADDR0
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE5_POS }, //ADDR1
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE2_POS }, //ADDR2
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE4_POS }, //ADDR3
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE6_POS }, //ADDR4
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE3_POS }, //ADDR5
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE1_POS }, //ADDR6
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE7_POS }, //ADDR7
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE2_POS }, //ADDR8
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE0_POS }, //ADDR9
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE5_POS }, //ADDR10
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE1_POS }, //ADDR11
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE3_POS }, //ADDR12
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE0_POS }, //ADDR13
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE1_POS }, //ADDR14/WEN
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE3_POS }, //ADDR15/CAS
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE1_POS }, //ADDR16/RAS
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE4_POS }, //ADDR17/RAS
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE7_POS }, //BA0
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE4_POS }, //BA1
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE2_POS }, //BG0
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE5_POS }, //BG1
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE0_POS }, //ACT_N

};
//ADR control registers
const std::vector< std::pair<uint64_t, uint64_t> > adrTraits<TARGET_TYPE_MCA>::IO_TX_FET_SLICE_CNTL_REG =
{
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE3_POS }, //CKE0
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE2_POS }, //CKE1
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE6_POS }, //CKE2
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE4_POS }, //CKE3
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE2_POS }, //ODT0
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE6_POS }, //ODT1
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE1_POS }, //ODT2
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE2_POS }, //ODT3
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE3_POS }, //PARITY
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR3, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE7_POS }, //RESET_N
};
//ADR chip select chip id registers
const std::vector< std::pair<uint64_t, uint64_t> > adrTraits<TARGET_TYPE_MCA>::IO_TX_FET_SLICE_CSCID_REG =
{
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE0_POS }, //CS0
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE0_POS }, //CS1
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR2, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE1_POS }, //CS2
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE3_POS }, //CS3
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP0_P0_ADR0, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE5_POS }, //CID0
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE0_POS }, //CID1
    { MCA_DDRPHY_ADR_IO_FET_SLICE_EN_MAP1_P0_ADR1, adrTraits<TARGET_TYPE_MCA>::ADR_IO_FET_SLICE_EN_LANE1_POS }, //CID2

};
namespace adr
{

///
/// @brief Reset the ADR Delay Lines
/// @param[in] i_target the fapi2 target of the MCA
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note reads VPD and resets the delay lines. This is very controller specific, so we have
/// a one function for each controller (er ... but just one now)
///
fapi2::ReturnCode reset_delay( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    typedef adrTraits<TARGET_TYPE_MCA> TT;

    uint8_t is_sim = 0;

    // A nice table representing the swizzles we need to swizzle. Make sure to keep these in pairs, using a nullptr
    // to represent the even/odd half which doesn't get a setting. ADR delays come in lane pairs in each register.
    // The even lane and odd lane (0,1; 3,4; ...) have a field in the register (EVEN and ODD). We read the attribute
    // which represents the delay for that signal, and insert it in to the appropriate lane.
    constexpr size_t DESTINATION_COUNT = 22;
    constexpr adr_data l_destinations[DESTINATION_COUNT] =
    {
    // *INDENT-OFF*
              // Register name               // Even Lane Attribute Getter               // Odd Lane Attribute Getter
            { MCA_DDRPHY_ADR_DELAY0_P0_ADR0, mss::vpd_mr_mc_phase_rot_cntl_d0_csn0, mss::vpd_mr_mc_phase_rot_cmd_addr_wen_a14 },
            { MCA_DDRPHY_ADR_DELAY1_P0_ADR0, mss::vpd_mr_mc_phase_rot_cntl_d1_odt1, mss::vpd_mr_mc_phase_rot_addr_c0 },
            { MCA_DDRPHY_ADR_DELAY2_P0_ADR0, mss::vpd_mr_mc_phase_rot_addr_ba1, mss::vpd_mr_mc_phase_rot_addr_a10 },
            { MCA_DDRPHY_ADR_DELAY3_P0_ADR0, mss::vpd_mr_mc_phase_rot_cntl_d0_odt1, mss::vpd_mr_mc_phase_rot_addr_ba0 },
            { MCA_DDRPHY_ADR_DELAY4_P0_ADR0, mss::vpd_mr_mc_phase_rot_addr_a00, mss::vpd_mr_mc_phase_rot_cntl_d1_odt0 },
            { MCA_DDRPHY_ADR_DELAY5_P0_ADR0, mss::vpd_mr_mc_phase_rot_cntl_d0_odt0, mss::vpd_mr_mc_phase_rot_cmd_addr_casn_a15 },

            { MCA_DDRPHY_ADR_DELAY0_P0_ADR1, mss::vpd_mr_mc_phase_rot_addr_a13, mss::vpd_mr_mc_phase_rot_cntl_d0_csn1 },
            { MCA_DDRPHY_ADR_DELAY1_P0_ADR1, mss::vpd_mr_mc_phase_rot_d0_clkn, mss::vpd_mr_mc_phase_rot_d0_clkp },
            { MCA_DDRPHY_ADR_DELAY2_P0_ADR1, mss::vpd_mr_mc_phase_rot_addr_a17, mss::vpd_mr_mc_phase_rot_addr_c1 },
            { MCA_DDRPHY_ADR_DELAY3_P0_ADR1, mss::vpd_mr_mc_phase_rot_d1_clkn, mss::vpd_mr_mc_phase_rot_d1_clkp },
            { MCA_DDRPHY_ADR_DELAY4_P0_ADR1, mss::vpd_mr_mc_phase_rot_addr_c2, mss::vpd_mr_mc_phase_rot_cntl_d1_csn1 },
            { MCA_DDRPHY_ADR_DELAY5_P0_ADR1, mss::vpd_mr_mc_phase_rot_addr_a02, mss::vpd_mr_mc_phase_rot_cmd_par },

            { MCA_DDRPHY_ADR_DELAY0_P0_ADR2, mss::vpd_mr_mc_phase_rot_cntl_d1_csn0, mss::vpd_mr_mc_phase_rot_cmd_addr_rasn_a16 },
            { MCA_DDRPHY_ADR_DELAY1_P0_ADR2, mss::vpd_mr_mc_phase_rot_addr_a08, mss::vpd_mr_mc_phase_rot_addr_a05 },
            { MCA_DDRPHY_ADR_DELAY2_P0_ADR2, mss::vpd_mr_mc_phase_rot_addr_a03, mss::vpd_mr_mc_phase_rot_addr_a01 },
            { MCA_DDRPHY_ADR_DELAY3_P0_ADR2, mss::vpd_mr_mc_phase_rot_addr_a04, mss::vpd_mr_mc_phase_rot_addr_a07 },
            { MCA_DDRPHY_ADR_DELAY4_P0_ADR2, mss::vpd_mr_mc_phase_rot_addr_a09, mss::vpd_mr_mc_phase_rot_addr_a06 },
            { MCA_DDRPHY_ADR_DELAY5_P0_ADR2, mss::vpd_mr_mc_phase_rot_cntl_d0_cke1, mss::vpd_mr_mc_phase_rot_addr_a12 },

            { MCA_DDRPHY_ADR_DELAY0_P0_ADR3, mss::vpd_mr_mc_phase_rot_cmd_actn, mss::vpd_mr_mc_phase_rot_addr_a11 },
            { MCA_DDRPHY_ADR_DELAY1_P0_ADR3, mss::vpd_mr_mc_phase_rot_addr_bg0, mss::vpd_mr_mc_phase_rot_cntl_d0_cke0 },
            { MCA_DDRPHY_ADR_DELAY2_P0_ADR3, mss::vpd_mr_mc_phase_rot_cntl_d1_cke1, mss::vpd_mr_mc_phase_rot_addr_bg1 },
            { MCA_DDRPHY_ADR_DELAY3_P0_ADR3, mss::vpd_mr_mc_phase_rot_cntl_d1_cke0, nullptr },
        };
    // *INDENT-ON*

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    // Nothing to do here if we're running on a sim; no adjustment to the ADR delay makes sense
    if (is_sim)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // All we need to do now is cram the table down into ye' ol' PHY.
    for (size_t i = 0; i < DESTINATION_COUNT; ++i)
    {
        fapi2::buffer<uint64_t> l_data;
        const adr_data& l_dest = l_destinations[i];

        // Fetch the even side attribute, and stuff it in the register
        {
            uint8_t l_attr = 0;

            if (l_dest.iv_even_func != nullptr)
            {
                FAPI_TRY( l_dest.iv_even_func(i_target, l_attr) );
            }

            l_data.insertFromRight(l_attr, TT::ADR_DELAY_EVEN, TT::ADR_DELAY_LEN);
            FAPI_INF("adr delay (even) reg: 0x%016lx val: 0x%016lx atr: 0x%0x", l_dest.iv_reg, l_data, l_attr);
        }

        // Fetch the odd side attribute, and stuff it in the register
        {
            uint8_t l_attr = 0;

            if (l_dest.iv_odd_func != nullptr)
            {
                FAPI_TRY( l_dest.iv_odd_func(i_target, l_attr) );
            }

            l_data.insertFromRight(l_attr, TT::ADR_DELAY_ODD, TT::ADR_DELAY_LEN);
            FAPI_INF("adr delay (odd) reg: 0x%016lx val: 0x%016lx atr: 0x%0x", l_dest.iv_reg, l_data, l_attr);
        }

        FAPI_TRY( mss::putScom(i_target, l_dest.iv_reg, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the clock driver impedances - MCS specialization
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode reset_imp_clk( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    //defines traits class
    typedef adrTraits<TARGET_TYPE_MCA> TT;

    //gets the termination value for the attribute
    uint8_t l_attr_value = 0;
    FAPI_TRY(mss::vpd_mt_mc_drv_imp_clk(i_target, l_attr_value));

    //checks the attr value
    if(l_attr_value != fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK_OHM30 &&
       l_attr_value != fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK_OHM40 )
    {
        FAPI_ASSERT(false,
                    fapi2::MSS_INVALID_VPD_MT_MC_DRV_IMP_CLK()
                    .set_VALUE(l_attr_value)
                    .set_MCA_TARGET(i_target),
                    "%s value is not valid: %u",
                    c_str(i_target),
                    l_attr_value);
    }

    //loops and sets the value in each register
    //Note: does RMW as other functions set the other lanes
    for(const auto& l_reg_info : TT::IO_TX_FET_SLICE_CLK_REG)
    {
        fapi2::buffer<uint64_t> l_value;

        //read
        FAPI_TRY(mss::getScom(i_target,
                              l_reg_info.first,
                              l_value));

        //modify
        if(l_attr_value == fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK_OHM30)
        {
            l_value.setBit(l_reg_info.second);
        }
        else
        {
            l_value.clearBit(l_reg_info.second);
        }

        //write
        FAPI_TRY(mss::putScom(i_target,
                              l_reg_info.first,
                              l_value));

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the command/address driver impedances - MCS specialization
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode reset_imp_cmd_addr( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    //defines traits class
    typedef adrTraits<TARGET_TYPE_MCA> TT;

    //gets the termination value for the attribute
    uint8_t l_attr_value = 0;
    FAPI_TRY(mss::vpd_mt_mc_drv_imp_cmd_addr(i_target, l_attr_value));

    //checks the attr value
    if(l_attr_value != fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CMD_ADDR_OHM30 &&
       l_attr_value != fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CMD_ADDR_OHM40 )
    {
        FAPI_ASSERT(false,
                    fapi2::MSS_INVALID_VPD_MT_MC_DRV_IMP_CMD_ADDR()
                    .set_VALUE(l_attr_value)
                    .set_MCA_TARGET(i_target),
                    "%s value is not valid: %u",
                    c_str(i_target),
                    l_attr_value);
    }

    //loops and sets the value in each register
    //Note: does RMW as other functions set the other lanes
    for(const auto& l_reg_info : TT::IO_TX_FET_SLICE_CMD_ADDR_REG)
    {
        fapi2::buffer<uint64_t> l_value;

        //read
        FAPI_TRY(mss::getScom(i_target,
                              l_reg_info.first,
                              l_value));

        //modify
        if(l_attr_value == fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CMD_ADDR_OHM30)
        {
            l_value.setBit(l_reg_info.second);
        }
        else
        {
            l_value.clearBit(l_reg_info.second);
        }

        //write
        FAPI_TRY(mss::putScom(i_target,
                              l_reg_info.first,
                              l_value));

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the control driver impedances - MCS specialization
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode reset_imp_cntl( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    //defines traits class
    typedef adrTraits<TARGET_TYPE_MCA> TT;

    //gets the termination value for the attribute
    uint8_t l_attr_value = 0;
    FAPI_TRY(mss::vpd_mt_mc_drv_imp_cntl(i_target, l_attr_value));

    //checks the attr value
    if(l_attr_value != fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL_OHM30 &&
       l_attr_value != fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL_OHM40 )
    {
        FAPI_ASSERT(false,
                    fapi2::MSS_INVALID_VPD_MT_MC_DRV_IMP_CNTL()
                    .set_VALUE(l_attr_value)
                    .set_MCA_TARGET(i_target),
                    "%s value is not valid: %u",
                    c_str(i_target),
                    l_attr_value);
    }

    //loops and sets the value in each register
    //Note: does RMW as other functions set the other lanes
    for(const auto& l_reg_info : TT::IO_TX_FET_SLICE_CNTL_REG)
    {
        fapi2::buffer<uint64_t> l_value;

        //read
        FAPI_TRY(mss::getScom(i_target,
                              l_reg_info.first,
                              l_value));

        //modify
        if(l_attr_value == fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL_OHM30)
        {
            l_value.setBit(l_reg_info.second);
        }
        else
        {
            l_value.clearBit(l_reg_info.second);
        }

        //write
        FAPI_TRY(mss::putScom(i_target,
                              l_reg_info.first,
                              l_value));

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the chip select/chip id driver impedances - MCS specialization
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode reset_imp_cscid( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    //defines traits class
    typedef adrTraits<TARGET_TYPE_MCA> TT;

    //gets the termination value for the attribute
    uint8_t l_attr_value = 0;
    FAPI_TRY(mss::vpd_mt_mc_drv_imp_cscid(i_target, l_attr_value));

    //checks the attr value
    if(l_attr_value != fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CSCID_OHM30 &&
       l_attr_value != fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CSCID_OHM40 )
    {
        FAPI_ASSERT(false,
                    fapi2::MSS_INVALID_VPD_MT_MC_DRV_IMP_CSCID()
                    .set_VALUE(l_attr_value)
                    .set_MCA_TARGET(i_target),
                    "%s value is not valid: %u",
                    c_str(i_target),
                    l_attr_value);
    }

    //loops and sets the value in each register
    //Note: does RMW as other functions set the other lanes
    for(const auto& l_reg_info : TT::IO_TX_FET_SLICE_CSCID_REG)
    {
        fapi2::buffer<uint64_t> l_value;

        //read
        FAPI_TRY(mss::getScom(i_target,
                              l_reg_info.first,
                              l_value));

        //modify
        if(l_attr_value == fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_CSCID_OHM30)
        {
            l_value.setBit(l_reg_info.second);
        }
        else
        {
            l_value.clearBit(l_reg_info.second);
        }

        //write
        FAPI_TRY(mss::putScom(i_target,
                              l_reg_info.first,
                              l_value));

    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns adr

} // ns mss

