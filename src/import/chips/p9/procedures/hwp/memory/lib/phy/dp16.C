/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/dp16.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file dp16.C
/// @brief Static data and subroutines to control the DP16 logic blocks
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <utility>
#include <vector>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/mss_attribute_accessors.H>

#include <lib/phy/dp16.H>
#include <lib/phy/write_cntrl.H>

#include <lib/utils/scom.H>
#include <lib/utils/pos.H>
#include <lib/utils/c_str.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_SYSTEM;

namespace mss
{

// Definition of the DP16 DLL Config registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_CNFG_REG =
{
    { MCA_DDRPHY_DP16_DLL_CNTL0_P0_0, MCA_DDRPHY_DP16_DLL_CNTL1_P0_0 },
    { MCA_DDRPHY_DP16_DLL_CNTL0_P0_1, MCA_DDRPHY_DP16_DLL_CNTL1_P0_1 },
    { MCA_DDRPHY_DP16_DLL_CNTL0_P0_2, MCA_DDRPHY_DP16_DLL_CNTL1_P0_2 },
    { MCA_DDRPHY_DP16_DLL_CNTL0_P0_3, MCA_DDRPHY_DP16_DLL_CNTL1_P0_3 },
    { MCA_DDRPHY_DP16_DLL_CNTL0_P0_4, MCA_DDRPHY_DP16_DLL_CNTL1_P0_4 },
};

// Definition of the DP16 DLL DAC Lower registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_DAC_LOWER_REG =
{
    { MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_0, MCA_DDRPHY_DP16_DLL_DAC_LOWER1_P0_0 },
    { MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_1, MCA_DDRPHY_DP16_DLL_DAC_LOWER1_P0_1 },
    { MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_2, MCA_DDRPHY_DP16_DLL_DAC_LOWER1_P0_2 },
    { MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_3, MCA_DDRPHY_DP16_DLL_DAC_LOWER1_P0_3 },
    { MCA_DDRPHY_DP16_DLL_DAC_LOWER0_P0_4, MCA_DDRPHY_DP16_DLL_DAC_LOWER1_P0_4 },
};

// Definition of the DP16 DLL DAC Upper registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_DAC_UPPER_REG =
{
    { MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_0, MCA_DDRPHY_DP16_DLL_DAC_UPPER1_P0_0 },
    { MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_1, MCA_DDRPHY_DP16_DLL_DAC_UPPER1_P0_1 },
    { MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_2, MCA_DDRPHY_DP16_DLL_DAC_UPPER1_P0_2 },
    { MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_3, MCA_DDRPHY_DP16_DLL_DAC_UPPER1_P0_3 },
    { MCA_DDRPHY_DP16_DLL_DAC_UPPER0_P0_4, MCA_DDRPHY_DP16_DLL_DAC_UPPER1_P0_4 },
};

// Definition of the DP16 DLL Slave Lower registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_SLAVE_LOWER_REG =
{
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER0_P0_0, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER1_P0_0 },
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER0_P0_1, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER1_P0_1 },
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER0_P0_2, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER1_P0_2 },
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER0_P0_3, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER1_P0_3 },
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER0_P0_4, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_LOWER1_P0_4 },
};

// Definition of the DP16 DLL Slave Upper registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_SLAVE_UPPER_REG =
{
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER0_P0_0, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER1_P0_0 },
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER0_P0_1, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER1_P0_1 },
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER0_P0_2, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER1_P0_2 },
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER0_P0_3, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER1_P0_3 },
    { MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER0_P0_4, MCA_DDRPHY_DP16_DLL_SLAVE_VREG_UPPER1_P0_4 },
};

// Definition of the DP16 DLL SW Control registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_SW_CNTRL_REG =
{
    { MCA_DDRPHY_DP16_DLL_SW_CONTROL0_P0_0, MCA_DDRPHY_DP16_DLL_SW_CONTROL1_P0_0 },
    { MCA_DDRPHY_DP16_DLL_SW_CONTROL0_P0_1, MCA_DDRPHY_DP16_DLL_SW_CONTROL1_P0_1 },
    { MCA_DDRPHY_DP16_DLL_SW_CONTROL0_P0_2, MCA_DDRPHY_DP16_DLL_SW_CONTROL1_P0_2 },
    { MCA_DDRPHY_DP16_DLL_SW_CONTROL0_P0_3, MCA_DDRPHY_DP16_DLL_SW_CONTROL1_P0_3 },
    { MCA_DDRPHY_DP16_DLL_SW_CONTROL0_P0_4, MCA_DDRPHY_DP16_DLL_SW_CONTROL1_P0_4 },
};

// Definition of the DP16 DLL VREG Coarse registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_VREG_COARSE_REG =
{
    { MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_0, MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_0 },
    { MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_1, MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_1 },
    { MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_2, MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_2 },
    { MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_3, MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_3 },
    { MCA_DDRPHY_DP16_DLL_VREG_COARSE0_P0_4, MCA_DDRPHY_DP16_DLL_VREG_COARSE1_P0_4 },
};

// Definition of the DP16 DLL VREG Control registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_VREG_CNTRL_REG =
{
    { MCA_DDRPHY_DP16_DLL_VREG_CONTROL0_P0_0, MCA_DDRPHY_DP16_DLL_VREG_CONTROL1_P0_0 },
    { MCA_DDRPHY_DP16_DLL_VREG_CONTROL0_P0_1, MCA_DDRPHY_DP16_DLL_VREG_CONTROL1_P0_1 },
    { MCA_DDRPHY_DP16_DLL_VREG_CONTROL0_P0_2, MCA_DDRPHY_DP16_DLL_VREG_CONTROL1_P0_2 },
    { MCA_DDRPHY_DP16_DLL_VREG_CONTROL0_P0_3, MCA_DDRPHY_DP16_DLL_VREG_CONTROL1_P0_3 },
    { MCA_DDRPHY_DP16_DLL_VREG_CONTROL0_P0_4, MCA_DDRPHY_DP16_DLL_VREG_CONTROL1_P0_4 },
};


// Definition of the DP16 DLL Extra registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_EXTRA_REG =
{
    { MCA_DDRPHY_DP16_DLL_EXTRA0_P0_0, MCA_DDRPHY_DP16_DLL_EXTRA1_P0_0 },
    { MCA_DDRPHY_DP16_DLL_EXTRA0_P0_1, MCA_DDRPHY_DP16_DLL_EXTRA1_P0_1 },
    { MCA_DDRPHY_DP16_DLL_EXTRA0_P0_2, MCA_DDRPHY_DP16_DLL_EXTRA1_P0_2 },
    { MCA_DDRPHY_DP16_DLL_EXTRA0_P0_3, MCA_DDRPHY_DP16_DLL_EXTRA1_P0_3 },
    { MCA_DDRPHY_DP16_DLL_EXTRA0_P0_4, MCA_DDRPHY_DP16_DLL_EXTRA1_P0_4 },
};

// Definition of the DP16 Data Bit Dir1 registers
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::DATA_BIT_DIR1 =
{
    MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_0,
    MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_1,
    MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_2,
    MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_3,
    MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_4,
};

// Definition of the DP16 AC Boost Control registers
// DP16 AC Boost registers all come in pairs - one per 8 bits
// 5 DP16 per MCA gives us 10  Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::AC_BOOST_CNTRL_REG =
{
    { MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_0, MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE1_P0_0 },
    { MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_1, MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE1_P0_1 },
    { MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_2, MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE1_P0_2 },
    { MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_3, MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE1_P0_3 },
    { MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_4, MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE1_P0_4 },
};

// Definition of the DP16 CTLE Control registers
// DP16 CTLE Control registers all come in pairs - one per 8 bits
// 5 DP16 per MCA gives us 10  Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::CTLE_CNTRL_REG =
{
    { MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0, MCA_DDRPHY_DP16_CTLE_CTL_BYTE1_P0_0 },
    { MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_1, MCA_DDRPHY_DP16_CTLE_CTL_BYTE1_P0_1 },
    { MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_2, MCA_DDRPHY_DP16_CTLE_CTL_BYTE1_P0_2 },
    { MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_3, MCA_DDRPHY_DP16_CTLE_CTL_BYTE1_P0_3 },
    { MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_4, MCA_DDRPHY_DP16_CTLE_CTL_BYTE1_P0_4 },
};
// Definition of the IO TX FET slice registers
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::IO_TX_FET_SLICE_REG
{
    MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0,
    MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_1,
    MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_2,
    MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_3,
    MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_4,
};

// Definition of the IO TX PFET slice registers
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::IO_TX_PFET_TERM_REG
{
    MCA_DDRPHY_DP16_IO_TX_PFET_TERM_P0_0,
    MCA_DDRPHY_DP16_IO_TX_PFET_TERM_P0_1,
    MCA_DDRPHY_DP16_IO_TX_PFET_TERM_P0_2,
    MCA_DDRPHY_DP16_IO_TX_PFET_TERM_P0_3,
    MCA_DDRPHY_DP16_IO_TX_PFET_TERM_P0_4,
};

// Definition of the DP16 RD_VREF Control registers
// DP16 RD_VREF Control registers all come in pairs - one per 8 bits
// 5 DP16 per MCA gives us 10  Registers.
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::RD_VREF_CNTRL_REG =
{
    { MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0, MCA_DDRPHY_DP16_RD_VREF_BYTE1_DAC_P0_0 },
    { MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_1, MCA_DDRPHY_DP16_RD_VREF_BYTE1_DAC_P0_1 },
    { MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_2, MCA_DDRPHY_DP16_RD_VREF_BYTE1_DAC_P0_2 },
    { MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_3, MCA_DDRPHY_DP16_RD_VREF_BYTE1_DAC_P0_3 },
    { MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_4, MCA_DDRPHY_DP16_RD_VREF_BYTE1_DAC_P0_4 },
};

///
/// @brief Given a RD_VREF value, create a PHY 'standard' bit field for that percentage.
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_vref the value from the mss_vpd_mt_vref_mc_rd attribute for your target
/// @param[out] o_bitfield value of DAC bitfield for given VREF setting
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode rd_vref_bitfield_helper( const fapi2::Target<T>& i_target,
        const uint32_t i_vref,
        uint64_t& o_bitfield )
{
    FAPI_INF("rd_vref_bitfield_helper for target %s seeing vref percentage: %d", c_str(i_target), i_vref);

    // Zero is a special "no-op" value, which we can get if the VPD attributes aren't
    // set up. This can happen for an MCA with no functional DIMM present.
    if (i_vref == 0)
    {
        o_bitfield = 0;
        return fapi2::FAPI2_RC_SUCCESS;
    }
    else if ( (i_vref > TT::MAX_RD_VREF) || (i_vref < TT::MIN_RD_VREF) )
    {
        // Set up some constexprs to work around linker error when pushing traits values into ffdc
        constexpr uint64_t l_max = TT::MAX_RD_VREF;
        constexpr uint64_t l_min = TT::MIN_RD_VREF;

        FAPI_ASSERT( false,
                     fapi2::MSS_INVALID_VPD_MT_VREF_MC_RD()
                     .set_VALUE(i_vref)
                     .set_VREF_MAX(l_max)
                     .set_VREF_MIN(l_min)
                     .set_TARGET(i_target),
                     "Target %s VPD_MT_VREF_MC_RD percentage out of bounds (%d - %d): %d",
                     c_str(i_target),
                     l_max,
                     l_min,
                     i_vref );
    }
    else
    {
        // Per R. King, VREF equation is:
        // Vref = 1.1025 for DAC < 15
        // Vref = 1.2 - .0065 * DAC for DAC >= 15
        // where DAC is simply the 7-bit field value
        // note values multiplied by 10 to make everything an integer
        o_bitfield = TT::RD_VREF_DVDD * (100000 - i_vref) / TT::RD_VREF_DAC_STEP;
        return fapi2::FAPI2_RC_SUCCESS;
    }

fapi_try_exit:
    return fapi2::current_err;
}

namespace dp16
{

typedef   std::pair< uint64_t, uint64_t >  register_data_pair;
typedef std::vector< register_data_pair >  register_data_vector;

// Why the tables you ask? Because these bits need to be controlled
// depending on phy, packaging, board swizzling and it's just eaiser
// to see the bits like this than in a more compact algorithmic arrangement.

// Systems without Spare Bytes (or with deconfigured spares)
static const register_data_vector  data_bit_enable_no_spare[] =
{
    // DHPY01
    {
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_0, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_1, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_2, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_3, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_4, 0xFF00},

        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_4, 0x0},
    },
};

// Rank Pair will be added to the register address before writing
static const register_data_vector wrclk_enable_no_spare_x4[] =
{
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0x8400},
    },
};

// Rank Pair will be added to the register address before writing
static const register_data_vector  rdclk_enable_no_spare_x4[] =
{
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0x8400},
    },
};

// Systems With Spare Bytes Enabled
static const register_data_vector data_bit_enable_spare[] =
{
    // DHPY01
    {
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_0, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_1, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_2, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_3, 0xFFFF},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_4, 0xFFFF},

        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, 0x0},
        {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_4, 0x0},
    },
};

static const register_data_vector wrclk_enable_spare_x4[] =
{
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0x8640},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0x8640},
    },
};

static const register_data_vector  rdclk_enable_spare_x4[] =
{
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0x8640},
    },
};

///
/// @brief Reset the data bit enable registers
/// @param[in] i_target  a port target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_data_bit_enable( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // Determine if we're running with spares or not. Once we know that, we can find the right vector to iterate over.
    // Note: Is this ATTR_EFF_DIMM_SPARE? Because that's per DIMM, but this is a port-level statement, right? BRS
    // Assume Nimbus for now - no spares ever. BRS
    bool l_using_spares = false;

    // Since this code is the MCA specialization, we know we never deal with DPHY23 - Nimbus PHY are
    // 4 copies of the same PHY. So we can use the DPHY01 data for all position.
    auto l_reg_data = l_using_spares ? data_bit_enable_spare[0] : data_bit_enable_no_spare[0];

    FAPI_DBG("reg/data vector %d", l_reg_data.size());

    for (const auto& rdp : l_reg_data)
    {
        // This is probably important enough to be seen all the time, not just debug
        FAPI_INF( "Setting up DATA_BIT_ENABLE 0x%llx (0x%llx) %s", rdp.first, rdp.second, mss::c_str(i_target) );
        FAPI_TRY( mss::putScom(i_target, rdp.first, rdp.second) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the read clock enable registers
/// @param[in] i_target
/// @param[in] l_rank_pairs
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_read_clock_enable( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        const std::vector< uint64_t >& l_rank_pairs )
{
    // Just slam something in here for now - we know the 'RIT DIMM' is x4, lets assume no cross-coupling for now
    bool l_using_spares = false;
    auto l_reg_data = l_using_spares ? rdclk_enable_spare_x4[0] : rdclk_enable_no_spare_x4[0];

    for (const auto& rp : l_rank_pairs)
    {
        for (const auto& rdp : l_reg_data)
        {
            // Grab the register and add the rank pair in
            fapi2::buffer<uint64_t> l_address(rdp.first);
            l_address.insertFromRight<22, 2>(rp);

            fapi2::buffer<uint64_t> l_data;
            l_data.insertFromRight<MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0_01_QUAD0_CLK16, 16>(rdp.second);

            FAPI_INF( "Setting up RDCLK RP%d 0x%llx (0x%llx) %s", rp, l_address, l_data, mss::c_str(i_target) );
            FAPI_TRY( mss::putScom(i_target, l_address, l_data) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Resets the write clock enable registers
/// @param[in] i_target
/// @param[in] l_rank_pairs
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_write_clock_enable( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        const std::vector< uint64_t >& l_rank_pairs )
{
    // Just slam something in here for now - we know the 'RIT DIMM' is x4, lets assume no cross-coupling for now
    bool l_using_spares = false;
    auto l_reg_data = l_using_spares ? wrclk_enable_spare_x4[0] : wrclk_enable_no_spare_x4[0];

    for (const auto& rp : l_rank_pairs)
    {
        for (const auto& rdp : l_reg_data)
        {
            // Grab the register and add the rank pair in
            fapi2::buffer<uint64_t> l_address(rdp.first);
            l_address.insertFromRight<22, 2>(rp);

            fapi2::buffer<uint64_t> l_data;
            l_data.insertFromRight<MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0_01_QUAD0_CLK16, 16>(rdp.second);

            FAPI_INF( "Setting up WRCLK RP%d 0x%llx (0x%llx) %s", rp, l_address, l_data, mss::c_str(i_target) );
            FAPI_TRY( mss::putScom(i_target, l_address, l_data) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the training delay configureation
/// @param[in] i_target the port target
/// @param[in] l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_delay_values( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                      const std::vector< uint64_t >& l_rank_pairs )
{
    std::vector<uint64_t> l_addrs(
    {
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_0,
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_1,
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_2,
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_3,
        MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_4,
    } );

    fapi2::buffer<uint64_t> l_data;

    // Reset the write level values
    FAPI_INF( "Resetting write level values %s", mss::c_str(i_target) );
    FAPI_TRY( mss::wc::read_config2(i_target, l_data) );
    mss::wc::set_reset_wr_delay_wl(l_data);
    FAPI_TRY( mss::wc::write_config2(i_target, l_data) );

    for (const auto& rp : l_rank_pairs)
    {
        for (const auto& a : l_addrs)
        {
            // Add the rank pair into the register to get the actual address
            fapi2::buffer<uint64_t> l_address(a);
            l_address.insertFromRight<22, 2>(rp);

            FAPI_DBG( "Resetting DP16 gate delay 0x%llx %s", l_address, mss::c_str(i_target) );
            FAPI_TRY( mss::putScom(i_target, l_address, 0) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the DP16 sysclk
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_sysclk( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    static const std::vector< std::pair<uint64_t, uint64_t> > l_addrs(
    {
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_0},
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_1, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_1},
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_2, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_2},
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_3, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_3},
        {MCA_DDRPHY_DP16_SYSCLK_PR0_P0_4, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_4},
    } );

    fapi2::buffer<uint64_t> l_data;
    uint8_t is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    l_data.setBit<MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0_01_ENABLE>();

    if (is_sim)
    {
        l_data.setBit<MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0_01_ROT_OVERRIDE_EN>();
    }

    for (const auto& p : i_target.getChildren<TARGET_TYPE_MCA>())
    {
        FAPI_DBG("set dp16_sysclk for %s", mss::c_str(p));

        for (const auto& a : l_addrs)
        {
            FAPI_TRY( mss::putScom(p, a.first, l_data) );
            FAPI_TRY( mss::putScom(p, a.second, l_data) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Configure the DP16 io_tx config0 registers
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode reset_io_tx_config0( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    static const std::vector<uint64_t> l_addrs(
    {
        MCA_DDRPHY_DP16_IO_TX_CONFIG0_P0_0,
        MCA_DDRPHY_DP16_IO_TX_CONFIG0_P0_1,
        MCA_DDRPHY_DP16_IO_TX_CONFIG0_P0_2,
        MCA_DDRPHY_DP16_IO_TX_CONFIG0_P0_3,
        MCA_DDRPHY_DP16_IO_TX_CONFIG0_P0_4,
    } );

    fapi2::buffer<uint64_t> l_data;
    uint64_t l_freq_bitfield;

    // Right now freq is per MCBIST.
    uint64_t l_freq;
    FAPI_TRY( mss::freq(i_target, l_freq) );

    l_freq_bitfield = freq_bitfield_helper(l_freq);

    l_data.insertFromRight<MCA_DDRPHY_DP16_IO_TX_CONFIG0_P0_0_01_INTERP_SIG_SLEW,
                           MCA_DDRPHY_DP16_IO_TX_CONFIG0_P0_0_01_INTERP_SIG_SLEW_LEN>(l_freq_bitfield);

    FAPI_INF("blasting 0x%016lx to dp16 io_tx", l_data);

    FAPI_TRY( mss::scom_blastah(i_target.getChildren<TARGET_TYPE_MCA>(), l_addrs, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure ADR DLL/VREG Config 1
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_dll_vreg_config1( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    static const std::vector<uint64_t> l_addrs(
    {
        MCA_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S0,
        MCA_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S1,
    } );

    fapi2::buffer<uint64_t> l_data;
    uint64_t l_freq_bitfield;

    // Right now freq is per MCBIST.
    uint64_t l_freq;
    FAPI_TRY( mss::freq(i_target, l_freq) );

    l_freq_bitfield = freq_bitfield_helper(l_freq);

    l_data.insertFromRight<MCA_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S1_ADR1_INTERP_SIG_SLEW,
                           MCA_DDRPHY_ADR_DLL_VREG_CONFIG_1_P0_ADR32S1_ADR1_INTERP_SIG_SLEW_LEN>(l_freq_bitfield);

    FAPI_INF("blasting 0x%016lx to dp16 DLL/VREG config 1", l_data);

    FAPI_TRY( mss::scom_blastah(i_target.getChildren<TARGET_TYPE_MCA>(), l_addrs, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset AC_BOOST_CNTL MCA specialization - for all DP16 in the target
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_ac_boost_cntl( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // Get the attributes which contain the information from the VPD
    fapi2::buffer<uint32_t> l_rd_up;
    fapi2::buffer<uint32_t> l_wr_down;
    fapi2::buffer<uint32_t> l_wr_up;

    // Keep track of the bit postion we start at, so we can slide thru the attributes
    // as we iterate over the registers
    uint64_t l_start_bit = 0;
    constexpr uint64_t BIT_FIELD_LEN = 3;
    constexpr uint64_t BIT_POSITION_DELTA = BIT_FIELD_LEN * 2;

    // A little DP block indicator useful for tracing
    uint64_t l_which_dp16 = 0;

    FAPI_TRY( mss::vpd_mt_mc_dq_acboost_rd_up(i_target, l_rd_up) );
    FAPI_TRY( mss::vpd_mt_mc_dq_acboost_wr_down(i_target, l_wr_down) );
    FAPI_TRY( mss::vpd_mt_mc_dq_acboost_wr_up(i_target, l_wr_up) );

    FAPI_INF("seeing acboost attributes wr_down: 0x%08lx wr_up: 0x%08lx, rd_up: 0x%08lx",
             l_wr_down, l_wr_up, l_rd_up);

    // For all of the AC Boost attributes, they're laid out in the uint32_t as such:
    // (dear OpenPOWER: remember in IBM-speak, bit 0 is the left-most bit because no
    // good reason)
    // Bit 0-2   = DP16 Block 0 (DQ Bits 0-7)
    // Bit 3-5   = DP16 Block 0 (DQ Bits 8-15)
    // Bit 6-8   = DP16 Block 1 (DQ Bits 0-7)
    // Bit 9-11  = DP16 Block 1 (DQ Bits 8-15)
    // Bit 12-14 = DP16 Block 2 (DQ Bits 0-7)
    // Bit 15-17 = DP16 Block 2 (DQ Bits 8-15)
    // Bit 18-20 = DP16 Block 3 (DQ Bits 0-7)
    // Bit 21-23 = DP16 Block 3 (DQ Bits 8-15)
    // Bit 24-26 = DP16 Block 4 (DQ Bits 0-7)
    // Bit 27-29 = DP16 Block 4 (DQ Bits 8-15)

    // For all the AC_BOOST registers on this MCA, shuffle in the bits and write
    // the registers.

    for (const auto& r : TT::AC_BOOST_CNTRL_REG)
    {
        fapi2::buffer<uint64_t> l_boost_0;
        fapi2::buffer<uint64_t> l_boost_1;

        // Read
        FAPI_TRY( mss::getScom(i_target, r.first, l_boost_0) );
        FAPI_TRY( mss::getScom(i_target, r.second, l_boost_1) );

        // Modify
        {
            // Yeah, we could do this once, however we need to flush them to 0 every time so this is the same
            fapi2::buffer<uint64_t> l_scratch_0;
            fapi2::buffer<uint64_t> l_scratch_1;

            FAPI_TRY(l_wr_down.extractToRight(l_scratch_0, l_start_bit, BIT_FIELD_LEN),
                     "unable to extract ac boost wr down 0");
            l_boost_0.insertFromRight<TT::AC_BOOST_WR_DOWN, TT::AC_BOOST_WR_DOWN_LEN>(l_scratch_0);

            FAPI_TRY(l_wr_down.extractToRight(l_scratch_1, l_start_bit + BIT_FIELD_LEN, BIT_FIELD_LEN),
                     "unable to extract ac boost wr down 1");
            l_boost_1.insertFromRight<TT::AC_BOOST_WR_DOWN, TT::AC_BOOST_WR_DOWN_LEN>(l_scratch_1);

            FAPI_INF("ac boost wr down for %s dp16 %d: 0x%08lx, 0x%08lx (0x%016lx, 0x%016lx)",
                     mss::c_str(i_target), l_which_dp16, l_scratch_0, l_scratch_1, l_boost_0, l_boost_1);
        }
        {
            fapi2::buffer<uint64_t> l_scratch_0;
            fapi2::buffer<uint64_t> l_scratch_1;

            FAPI_TRY(l_wr_up.extractToRight(l_scratch_0, l_start_bit, BIT_FIELD_LEN),
                     "unable to extract ac boost wr up 0");
            l_boost_0.insertFromRight<TT::AC_BOOST_WR_UP, TT::AC_BOOST_WR_UP_LEN>(l_scratch_0);

            FAPI_TRY(l_wr_up.extractToRight(l_scratch_1, l_start_bit + BIT_FIELD_LEN, BIT_FIELD_LEN),
                     "unable to extract ac boost wr up 1");
            l_boost_1.insertFromRight<TT::AC_BOOST_WR_UP, TT::AC_BOOST_WR_UP_LEN>(l_scratch_1);

            FAPI_INF("ac boost wr up for %s dp16 %d: 0x%08lx, 0x%08lx (0x%016lx, 0x%016lx)",
                     mss::c_str(i_target), l_which_dp16, l_scratch_0, l_scratch_1, l_boost_0, l_boost_1);
        }
        {
            fapi2::buffer<uint64_t> l_scratch_0;
            fapi2::buffer<uint64_t> l_scratch_1;

            FAPI_TRY(l_rd_up.extractToRight(l_scratch_0, l_start_bit, BIT_FIELD_LEN),
                     "unable to extract ac boost rd up 0");
            l_boost_0.insertFromRight<TT::AC_BOOST_RD_UP, TT::AC_BOOST_RD_UP_LEN>(l_scratch_0);

            FAPI_TRY(l_rd_up.extractToRight(l_scratch_1, l_start_bit + BIT_FIELD_LEN, BIT_FIELD_LEN),
                     "unable to extract ac boost rd up 1");
            l_boost_1.insertFromRight<TT::AC_BOOST_RD_UP, TT::AC_BOOST_RD_UP_LEN>(l_scratch_1);

            FAPI_INF("ac boost rd down for %s dp16 %d: 0x%08lx, 0x%08lx (0x%016lx, 0x%016lx)",
                     mss::c_str(i_target), l_which_dp16, l_scratch_0, l_scratch_1, l_boost_0, l_boost_1);
        }

        // Write
        FAPI_TRY( mss::putScom(i_target, r.first, l_boost_0) );
        FAPI_TRY( mss::putScom(i_target, r.second, l_boost_1) );

        // Slide over in the attributes, bump the dp16 trace counter, and do it again
        l_start_bit += BIT_POSITION_DELTA;
        ++l_which_dp16;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset CTLE_CNTL MCA specialization - for all DP16 in the target
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_ctle_cntl( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // Get the attributes which contain the information from the VPD
    fapi2::buffer<uint64_t> l_ctle_cap;
    fapi2::buffer<uint64_t> l_ctle_res;

    // The length of the bit fields allows us to slide along the attribute
    uint64_t l_start_bit = 0;
    constexpr uint64_t CAP_BIT_FIELD_LEN = 2;
    constexpr uint64_t RES_BIT_FIELD_LEN = 3;
    constexpr uint64_t BIT_POSITION_DELTA = 8;

    // A little DP block indicator useful for tracing
    uint64_t l_which_dp16 = 0;

    FAPI_TRY( mss::vpd_mt_mc_dq_ctle_cap(i_target, l_ctle_cap) );
    FAPI_TRY( mss::vpd_mt_mc_dq_ctle_res(i_target, l_ctle_res) );

    FAPI_INF("seeing ctle attributes cap: 0x%016lx res: 0x%016lx", l_ctle_cap, l_ctle_res);

    // For the capacitance CTLE attributes, they're laid out in the uint64_t as such. The resitance
    // attributes are the same, but 3 bits long. Notice that DP Block X Nibble 0 is DQ0:3,
    // Nibble 1 is DQ4:7, Nibble 2 is DQ8:11 and 3 is DQ12:15.
    // (dear OpenPOWER: remember in IBM-speak, bit 0 is the left-most bit because no
    // good reason)
    // Bit 0-1   = DP16 Block 0 Nibble 0     Bit 16-17 = DP16 Block 2 Nibble 0     Bit 32-33 = DP16 Block 4 Nibble 0
    // Bit 2-3   = DP16 Block 0 Nibble 1     Bit 18-19 = DP16 Block 2 Nibble 1     Bit 34-35 = DP16 Block 4 Nibble 1
    // Bit 4-5   = DP16 Block 0 Nibble 2     Bit 20-21 = DP16 Block 2 Nibble 2     Bit 36-37 = DP16 Block 4 Nibble 2
    // Bit 6-7   = DP16 Block 0 Nibble 3     Bit 22-23 = DP16 Block 2 Nibble 3     Bit 38-39 = DP16 Block 4 Nibble 3
    // Bit 8-9   = DP16 Block 1 Nibble 0     Bit 24-25 = DP16 Block 3 Nibble 0
    // Bit 10-11 = DP16 Block 1 Nibble 1     Bit 26-27 = DP16 Block 3 Nibble 1
    // Bit 12-13 = DP16 Block 1 Nibble 2     Bit 28-29 = DP16 Block 3 Nibble 2
    // Bit 14-15 = DP16 Block 1 Nibble 3     Bit 30-31 = DP16 Block 3 Nibble 3

    // For all the CTLE registers on this MCA, walk the attributes and stick the values in the right places
    // in the registers
    for (const auto& r : TT::CTLE_CNTRL_REG)
    {
        fapi2::buffer<uint64_t> l_ctle_0;
        fapi2::buffer<uint64_t> l_ctle_1;

        // Read
        FAPI_TRY( mss::getScom(i_target, r.first, l_ctle_0) );
        FAPI_TRY( mss::getScom(i_target, r.second, l_ctle_1) );

        // Modify

        // Byte 0
        {
            // DP16 Block 0 Nibble 0
            {
                fapi2::buffer<uint64_t> l_scratch_0;
                fapi2::buffer<uint64_t> l_scratch_1;

                FAPI_TRY(l_ctle_cap.extractToRight(l_scratch_0, l_start_bit + (CAP_BIT_FIELD_LEN * 0), CAP_BIT_FIELD_LEN),
                         "unable to extract ctle cap even");
                l_ctle_0.insertFromRight<TT::CTLE_EVEN_CAP, TT::CTLE_EVEN_CAP_LEN>(l_scratch_0);

                FAPI_TRY(l_ctle_res.extractToRight(l_scratch_1, l_start_bit + (RES_BIT_FIELD_LEN * 0), RES_BIT_FIELD_LEN),
                         "unable to extract ctle res even");
                l_ctle_0.insertFromRight<TT::CTLE_EVEN_RES, TT::CTLE_EVEN_RES_LEN>(l_scratch_1);

                FAPI_INF("ctle nibble %d for %s dp16 %d: 0x%08lx, 0x%08lx (0x%016lx, 0x%016lx)",
                         0, mss::c_str(i_target), l_which_dp16, l_scratch_0, l_scratch_1, l_ctle_0, l_ctle_1);

            }

            // DP16 Block 0 Nibble 1
            {
                fapi2::buffer<uint64_t> l_scratch_0;
                fapi2::buffer<uint64_t> l_scratch_1;

                FAPI_TRY(l_ctle_cap.extractToRight(l_scratch_0, l_start_bit + (CAP_BIT_FIELD_LEN * 1), CAP_BIT_FIELD_LEN),
                         "unable to extract ctle cap odd");
                l_ctle_0.insertFromRight<TT::CTLE_ODD_CAP, TT::CTLE_ODD_CAP_LEN>(l_scratch_0);

                FAPI_TRY(l_ctle_res.extractToRight(l_scratch_1, l_start_bit + (RES_BIT_FIELD_LEN * 1), RES_BIT_FIELD_LEN),
                         "unable to extract ctle res odd");
                l_ctle_0.insertFromRight<TT::CTLE_ODD_RES, TT::CTLE_ODD_RES_LEN>(l_scratch_1);

                FAPI_INF("ctle nibble %d for %s dp16 %d: 0x%08lx, 0x%08lx (0x%016lx, 0x%016lx)",
                         1, mss::c_str(i_target), l_which_dp16, l_scratch_0, l_scratch_1, l_ctle_0, l_ctle_1);
            }
        }

        // Byte 1
        {
            // DP16 Block 0 Nibble 2
            {
                fapi2::buffer<uint64_t> l_scratch_0;
                fapi2::buffer<uint64_t> l_scratch_1;

                FAPI_TRY(l_ctle_cap.extractToRight(l_scratch_0, l_start_bit + (CAP_BIT_FIELD_LEN * 2), CAP_BIT_FIELD_LEN),
                         "unable to extract ctle cap even (byte 1)");
                l_ctle_1.insertFromRight<TT::CTLE_EVEN_CAP, TT::CTLE_EVEN_CAP_LEN>(l_scratch_0);

                FAPI_TRY(l_ctle_res.extractToRight(l_scratch_1, (RES_BIT_FIELD_LEN * 2), RES_BIT_FIELD_LEN),
                         "unable to extract ctle res even (byte 1)");
                l_ctle_1.insertFromRight<TT::CTLE_EVEN_RES, TT::CTLE_EVEN_RES_LEN>(l_scratch_1);

                FAPI_INF("ctle nibble %d for %s dp16 %d: 0x%08lx, 0x%08lx (0x%016lx, 0x%016lx)",
                         2, mss::c_str(i_target), l_which_dp16, l_scratch_0, l_scratch_1, l_ctle_0, l_ctle_1);
            }

            // DP16 Block 0 Nibble 3
            {
                fapi2::buffer<uint64_t> l_scratch_0;
                fapi2::buffer<uint64_t> l_scratch_1;

                FAPI_TRY(l_ctle_cap.extractToRight(l_scratch_0, l_start_bit + (CAP_BIT_FIELD_LEN * 3), CAP_BIT_FIELD_LEN),
                         "unable to extract ctle cap odd (byte 1)");
                l_ctle_1.insertFromRight<TT::CTLE_ODD_CAP, TT::CTLE_ODD_CAP_LEN>(l_scratch_0);

                FAPI_TRY(l_ctle_res.extractToRight(l_scratch_1, l_start_bit + (RES_BIT_FIELD_LEN * 3), RES_BIT_FIELD_LEN),
                         "unable to extract ctle res odd (byte 1)");
                l_ctle_1.insertFromRight<TT::CTLE_ODD_RES, TT::CTLE_ODD_RES_LEN>(l_scratch_1);

                FAPI_INF("ctle nibble %d for %s dp16 %d: 0x%08lx, 0x%08lx (0x%016lx, 0x%016lx)",
                         3, mss::c_str(i_target), l_which_dp16, l_scratch_0, l_scratch_1, l_ctle_0, l_ctle_1);
            }
        }

        // Write
        FAPI_TRY( mss::putScom(i_target, r.first, l_ctle_0) );
        FAPI_TRY( mss::putScom(i_target, r.second, l_ctle_1) );

        // Slide over in the attributes, bump the dp16 trace counter, and do it again
        l_start_bit += BIT_POSITION_DELTA;
        ++l_which_dp16;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset all of the DLL registers - Nimbus only
/// @param[in] i_target an MCA
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_dll( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // Magic numbers are from the PHY team (see the ddry phy initfile, too.) They are, in fact,
    // magic numbers ...
    // TK How about a little broadcast action here? BRS
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_CNFG_REG,        0x8100) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_DAC_LOWER_REG,   0x8000) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_DAC_UPPER_REG,   0xffe0) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_SLAVE_LOWER_REG, 0x8000) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_SLAVE_UPPER_REG, 0xffe0) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_EXTRA_REG,       0x2020) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_VREG_CNTRL_REG,  0x0040) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_SW_CNTRL_REG,    0x0800) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_VREG_COARSE_REG, 0x0402) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure Read VREF Registers
/// @param[in] i_target a MCA target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_rd_vref( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    std::vector< std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> > > l_data;
    uint64_t l_vref_bitfield = 0;
    uint8_t is_sim = 0;
    uint32_t l_vref = 0;

    FAPI_TRY( mss::vpd_mt_vref_mc_rd(i_target, l_vref) );

    FAPI_TRY( rd_vref_bitfield_helper(i_target, l_vref, l_vref_bitfield) );

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    // Leave the values as-is if we're on VBU or Awan, since we know that works. Use the real value for unit test and HW
    if (!is_sim)
    {
        // Do a read/modify/write
        FAPI_TRY( mss::scom_suckah(i_target, TT::RD_VREF_CNTRL_REG, l_data) );

        for (auto& l_regpair : l_data)
        {
            // Write the same value for all the DQ and DQS nibbles
            l_regpair.first.insertFromRight<TT::RD_VREF_BYTE0_NIB0, TT::RD_VREF_BYTE0_NIB0_LEN>(l_vref_bitfield);
            l_regpair.first.insertFromRight<TT::RD_VREF_BYTE0_NIB1, TT::RD_VREF_BYTE0_NIB1_LEN>(l_vref_bitfield);
            l_regpair.second.insertFromRight<TT::RD_VREF_BYTE1_NIB2, TT::RD_VREF_BYTE1_NIB2_LEN>(l_vref_bitfield);
            l_regpair.second.insertFromRight<TT::RD_VREF_BYTE1_NIB3, TT::RD_VREF_BYTE1_NIB3_LEN>(l_vref_bitfield);
        }

        FAPI_INF("blasting VREF settings from VPD to dp16 RD_VREF byte0 and byte1");

        FAPI_TRY( mss::scom_blastah(i_target, TT::RD_VREF_CNTRL_REG, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets the register value for DQ/DQS driver impedance from the VPD value - TARGET_TYPE_MCA specialization
/// @param[in] i_target the port in question
/// @param[out] o_reg_value value to push into the registers
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode get_dq_dqs_drv_imp_field_value( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        fapi2::buffer<uint8_t>* o_reg_value )
{
    //traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    //disable is Hi-Z state, no slices enabled
    constexpr uint8_t REG_VALUE_DISABLE = 0x00;
    //left justifies values as that's the lower order bit for IBM
    //these registers enable 240 Ohm slices in parallel
    //the impedance becomes 240/N - N being the number of slices enabled
    //thus 34 Ohms is all seven slices enabled.
    constexpr uint8_t REG_VALUE_240OHM = 0b01000000;
    constexpr uint8_t REG_VALUE_120OHM = 0b01100000;
    constexpr uint8_t REG_VALUE_80OHM  = 0b01110000;
    constexpr uint8_t REG_VALUE_60OHM  = 0b01111000;
    constexpr uint8_t REG_VALUE_48OHM  = 0b01111100;
    constexpr uint8_t REG_VALUE_40OHM  = 0b01111110;
    constexpr uint8_t REG_VALUE_34OHM  = 0b01111111;

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_vpd_value[TT::DP_COUNT] = {};

    //goes the attr get
    FAPI_TRY(vpd_mt_mc_drv_imp_dq_dqs(i_target, l_vpd_value));

    //loops through all of the DP's
    for(uint8_t dp = 0; dp < TT::DP_COUNT; ++dp)
    {

        switch(l_vpd_value[dp])
        {
            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS_DISABLE:
                o_reg_value[dp] = REG_VALUE_DISABLE;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS_OHM240:
                o_reg_value[dp] = REG_VALUE_240OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS_OHM120:
                o_reg_value[dp] = REG_VALUE_120OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS_OHM80:
                o_reg_value[dp] = REG_VALUE_80OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS_OHM60:
                o_reg_value[dp] = REG_VALUE_60OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS_OHM48:
                o_reg_value[dp] = REG_VALUE_48OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS_OHM40:
                o_reg_value[dp] = REG_VALUE_40OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS_OHM34:
                o_reg_value[dp] = REG_VALUE_34OHM;
                break;

            //all non-enum values are errors, set current error and exit
            default:
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_VPD_VALUE_MC_DRV_IMP_DQ_DQS()
                            .set_VALUE(l_vpd_value[dp])
                            .set_DP(dp)
                            .set_MCA_TARGET(i_target),
                            "%s DQ_DQS %s impedance value is not valid: %u for DP[%u]",
                            c_str(i_target),
                            "driver",
                            l_vpd_value[dp],
                            dp);
                break;
        }

        //successfully got the value, print an info statement for debug
        FAPI_INF("%s DQ/DQS %s impedance for DP[%u] VPD: %u register value 0x%02x", c_str(i_target), "DRV", dp, l_vpd_value,
                 o_reg_value);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the DQ/DQS driver impedances - TARGET_TYPE_MCA specialization
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode reset_dq_dqs_drv_imp( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    //traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    constexpr uint64_t NFET_LOC = TT::IO_TX_FET_SLICE_EN_N_WR;
    constexpr uint64_t NFET_LEN = TT::IO_TX_FET_SLICE_EN_N_WR_LEN;
    constexpr uint64_t PFET_LOC = TT::IO_TX_FET_SLICE_EN_P_WR;
    constexpr uint64_t PFET_LEN = TT::IO_TX_FET_SLICE_EN_P_WR_LEN;

    fapi2::buffer<uint8_t> l_field_value[TT::DP_COUNT];

    //gets the field value
    FAPI_TRY(get_dq_dqs_drv_imp_field_value(i_target, l_field_value));

    //loops through all DP's and sets the register values
    for(uint8_t dp = 0; dp < TT::DP_COUNT ; ++dp)
    {
        //sets up the scom value
        const auto l_scom_value = fapi2::buffer<uint64_t>()
                                  .insertFromRight<NFET_LOC, NFET_LEN>(l_field_value[dp])
                                  .insertFromRight<PFET_LOC, PFET_LEN>(l_field_value[dp]);

        //blasts those scoms
        FAPI_TRY(mss::putScom( i_target,
                               TT::IO_TX_FET_SLICE_REG[dp],
                               l_scom_value ));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets the register value for DQ/DQS receiver impedance from the VPD value - MCA specialization
/// @param[in] i_target the port in question
/// @param[out] o_reg_value value to push into the registers
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode get_dq_dqs_rcv_imp_field_value( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        fapi2::buffer<uint8_t>* o_reg_value )
{
    //traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    //disable is Hi-Z state, no slices enabled
    constexpr uint8_t REG_VALUE_DISABLE = 0x00;
    //left justifies values as that's the lower order bit for IBM
    //these registers enable 240 Ohm slices in parallel
    //the impedance becomes 240/N - N being the number of slices enabled
    //thus 34 Ohms is all seven slices enabled.
    constexpr uint8_t REG_VALUE_240OHM = 0b01000000;
    constexpr uint8_t REG_VALUE_120OHM = 0b01100000;
    constexpr uint8_t REG_VALUE_80OHM  = 0b01110000;
    constexpr uint8_t REG_VALUE_60OHM  = 0b01111000;
    constexpr uint8_t REG_VALUE_48OHM  = 0b01111100;
    constexpr uint8_t REG_VALUE_40OHM  = 0b01111110;
    constexpr uint8_t REG_VALUE_34OHM  = 0b01111111;

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_vpd_value[TT::DP_COUNT] = {};

    //goes the attr get
    FAPI_TRY(vpd_mt_mc_rcv_imp_dq_dqs(i_target, l_vpd_value));

    //loops through and checks each value for the DP
    for(uint8_t dp = 0; dp < TT::DP_COUNT; ++dp)
    {

        switch(l_vpd_value[dp])
        {
            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS_DISABLE:
                o_reg_value[dp] = REG_VALUE_DISABLE;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS_OHM240:
                o_reg_value[dp] = REG_VALUE_240OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS_OHM120:
                o_reg_value[dp] = REG_VALUE_120OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS_OHM80:
                o_reg_value[dp] = REG_VALUE_80OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS_OHM60:
                o_reg_value[dp] = REG_VALUE_60OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS_OHM48:
                o_reg_value[dp] = REG_VALUE_48OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS_OHM40:
                o_reg_value[dp] = REG_VALUE_40OHM;
                break;

            case fapi2::ENUM_ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS_OHM34:
                o_reg_value[dp] = REG_VALUE_34OHM;
                break;

            //all non-enum values are errors, set current error and exit
            default:
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_VPD_VALUE_MC_RCV_IMP_DQ_DQS()
                            .set_VALUE(l_vpd_value[dp])
                            .set_DP(dp)
                            .set_MCA_TARGET(i_target),
                            "%s DQ_DQS %s impedance value is not valid: %u for DP[%u]",
                            c_str(i_target),
                            "receiver",
                            l_vpd_value[dp],
                            dp);
                break;
        }

        //successfully got the value, print an info statement for debug
        FAPI_INF("%s DQ/DQS %s impedance for DP[%u] VPD: %u register value 0x%02x", c_str(i_target), "RCV", dp, l_vpd_value,
                 o_reg_value);

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the DQ/DQS receiver impedances - MCA specialization
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode reset_dq_dqs_rcv_imp( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    //traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    constexpr uint64_t LOC = TT::IO_TX_PFET_TERM_EN_P_WR;
    constexpr uint64_t LEN = TT::IO_TX_PFET_TERM_EN_P_WR_LEN;

    fapi2::buffer<uint8_t> l_field_value[TT::DP_COUNT];

    //gets the field value
    FAPI_TRY(get_dq_dqs_rcv_imp_field_value(i_target, l_field_value));

    //loops through all DP's and sets the register values
    for(uint8_t dp = 0; dp < TT::DP_COUNT ; ++dp)
    {
        //sets up the scom value
        const auto l_scom_value = fapi2::buffer<uint64_t>().insertFromRight<LOC, LEN>(l_field_value[dp]);

        //blasts those scoms
        FAPI_TRY(mss::putScom( i_target,
                               TT::IO_TX_PFET_TERM_REG[dp],
                               l_scom_value ));

    }

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace dp16
} // close namespace mss
