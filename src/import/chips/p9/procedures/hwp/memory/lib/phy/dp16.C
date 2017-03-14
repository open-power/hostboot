/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/dp16.C $    */
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
#include <map>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/mss_attribute_accessors.H>

#include <lib/phy/dp16.H>
#include <lib/phy/write_cntrl.H>

#include <lib/utils/bit_count.H>
#include <lib/dimm/rank.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/c_str.H>

#include <lib/workarounds/dp16_workarounds.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_SYSTEM;

namespace mss
{

// Definition of the DP16 DLL Config registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Config Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::DLL_CNFG_REG =
{
    MCA_DDRPHY_DP16_DLL_CONFIG1_P0_0,
    MCA_DDRPHY_DP16_DLL_CONFIG1_P0_1,
    MCA_DDRPHY_DP16_DLL_CONFIG1_P0_2,
    MCA_DDRPHY_DP16_DLL_CONFIG1_P0_3,
    MCA_DDRPHY_DP16_DLL_CONFIG1_P0_4,
};

// Definition of the DP16 DLL Control registers
// DP16 DLL registers all come in pairs - DLL per 8 bits
// 5 DLL per MCA gives us 10 DLL Control Registers.
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::DLL_CNTRL_REG =
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
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::DATA_BIT_DIR1_REG
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

// Definition of the DP16 RD_VREF Calibration enable registers
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::RD_VREF_CAL_ENABLE_REG =
{
    MCA_DDRPHY_DP16_RD_VREF_CAL_EN_P0_0,
    MCA_DDRPHY_DP16_RD_VREF_CAL_EN_P0_1,
    MCA_DDRPHY_DP16_RD_VREF_CAL_EN_P0_2,
    MCA_DDRPHY_DP16_RD_VREF_CAL_EN_P0_3,
    MCA_DDRPHY_DP16_RD_VREF_CAL_EN_P0_4,
};

// Definition of the DP16 RD_VREF Calibration enable registers
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::RD_VREF_CAL_ERROR_REG =
{
    MCA_DDRPHY_DP16_RD_VREF_CAL_ERROR_P0_0,
    MCA_DDRPHY_DP16_RD_VREF_CAL_ERROR_P0_1,
    MCA_DDRPHY_DP16_RD_VREF_CAL_ERROR_P0_2,
    MCA_DDRPHY_DP16_RD_VREF_CAL_ERROR_P0_3,
    MCA_DDRPHY_DP16_RD_VREF_CAL_ERROR_P0_4,
};


// Definition of the DP16 Phase Rotator Static Offset registers
// All-caps (as opposed to the others) as it's really in the dp16Traits class which is all caps <shrug>)
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::PR_STATIC_OFFSET_REG
{
    MCA_DDRPHY_DP16_WRCLK_PR_P0_0,
    MCA_DDRPHY_DP16_WRCLK_PR_P0_1,
    MCA_DDRPHY_DP16_WRCLK_PR_P0_2,
    MCA_DDRPHY_DP16_WRCLK_PR_P0_3,
    MCA_DDRPHY_DP16_WRCLK_PR_P0_4,
};

//////////////////////////////////////
// Defines all WR VREF registers    //
//////////////////////////////////////
// Definition of the WR VREF config0 register
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_CONFIG0_REG =
{
    MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0,
    MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_1,
    MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_2,
    MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_3,
    MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_4,
};
// Definition of the WR VREF config1 register
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_CONFIG1_REG =
{
    MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_0,
    MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_1,
    MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_2,
    MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_3,
    MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_4,
};
// Definition of the WR VREF status0 register
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_STATUS0_REG =
{
    MCA_DDRPHY_DP16_WR_VREF_STATUS0_P0_0,
    MCA_DDRPHY_DP16_WR_VREF_STATUS0_P0_1,
    MCA_DDRPHY_DP16_WR_VREF_STATUS0_P0_2,
    MCA_DDRPHY_DP16_WR_VREF_STATUS0_P0_3,
    MCA_DDRPHY_DP16_WR_VREF_STATUS0_P0_4,
};
// Definition of the WR VREF status1 register
const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_STATUS1_REG =
{
    MCA_DDRPHY_DP16_WR_VREF_STATUS1_P0_0,
    MCA_DDRPHY_DP16_WR_VREF_STATUS1_P0_1,
    MCA_DDRPHY_DP16_WR_VREF_STATUS1_P0_2,
    MCA_DDRPHY_DP16_WR_VREF_STATUS1_P0_3,
    MCA_DDRPHY_DP16_WR_VREF_STATUS1_P0_4,
};

// Definition of the error mask registers element is DP16 number, first is mask 0 second is mask 1
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_ERROR_MASK_REG =
{
    { MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0, MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK1_P0_0 },
    { MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_1, MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK1_P0_1 },
    { MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_2, MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK1_P0_2 },
    { MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_3, MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK1_P0_3 },
    { MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_4, MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK1_P0_4 },
};
// Definition of the error registers element is DP16 number, first is error 0 second is error 1
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_ERROR_REG =
{
    { MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0, MCA_DDRPHY_DP16_WR_VREF_ERROR1_P0_0 },
    { MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_1, MCA_DDRPHY_DP16_WR_VREF_ERROR1_P0_1 },
    { MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_2, MCA_DDRPHY_DP16_WR_VREF_ERROR1_P0_2 },
    { MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_3, MCA_DDRPHY_DP16_WR_VREF_ERROR1_P0_3 },
    { MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_4, MCA_DDRPHY_DP16_WR_VREF_ERROR1_P0_4 },
};
// Definition of the VREF value registers for RP0 element is DP16 number, first is value 0 second is value 1
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_VALUE_RP0_REG =
{
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_0, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR0_P0_0 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_1, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR0_P0_1 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_2, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR0_P0_2 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_3, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR0_P0_3 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_4, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR0_P0_4 },
};
// Definition of the VREF value registers for RP1 element is DP16 number, first is value 0 second is value 1
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_VALUE_RP1_REG =
{
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR1_P0_0, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR1_P0_0 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR1_P0_1, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR1_P0_1 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR1_P0_2, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR1_P0_2 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR1_P0_3, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR1_P0_3 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR1_P0_4, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR1_P0_4 },
};
// Definition of the VREF value registers for RP2 element is DP16 number, first is value 0 second is value 1
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_VALUE_RP2_REG =
{
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR2_P0_0, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR2_P0_0 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR2_P0_1, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR2_P0_1 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR2_P0_2, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR2_P0_2 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR2_P0_3, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR2_P0_3 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR2_P0_4, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR2_P0_4 },
};

// Definition of the VREF value registers for RP3 element is DP16 number, first is value 0 second is value 1
const std::vector< std::pair<uint64_t, uint64_t> > dp16Traits<TARGET_TYPE_MCA>::WR_VREF_VALUE_RP3_REG =
{
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR3_P0_0, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR3_P0_0 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR3_P0_1, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR3_P0_1 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR3_P0_2, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR3_P0_2 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR3_P0_3, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR3_P0_3 },
    { MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR3_P0_4, MCA_DDRPHY_DP16_WR_VREF_VALUE1_RANK_PAIR3_P0_4 },
};

// Definition of the windage value registers per MCA. These are per rank pair, per DP16 and there are 2.
const std::vector<uint64_t> dp16Traits<TARGET_TYPE_MCA>::READ_DELAY_OFFSET_REG =
{
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR0_P0_0,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR0_P0_1,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR0_P0_2,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR0_P0_3,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR0_P0_4,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR1_P0_0,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR1_P0_1,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR1_P0_2,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR1_P0_3,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR1_P0_4,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR2_P0_0,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR2_P0_1,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR2_P0_2,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR2_P0_3,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR2_P0_4,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR3_P0_0,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR3_P0_1,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR3_P0_2,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR3_P0_3,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR3_P0_4,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR0_P0_0,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR0_P0_1,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR0_P0_2,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR0_P0_3,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR0_P0_4,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR1_P0_0,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR1_P0_1,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR1_P0_2,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR1_P0_3,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR1_P0_4,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR2_P0_0,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR2_P0_1,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR2_P0_2,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR2_P0_3,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR2_P0_4,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR3_P0_0,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR3_P0_1,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR3_P0_2,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR3_P0_3,
    MCA_DDRPHY_DP16_READ_DELAY_OFFSET1_RANK_PAIR3_P0_4,
};

// Definition of the DISABLE registers, per dp per rank pair
const std::vector< std::vector<std::pair<uint64_t, uint64_t>> > dp16Traits<TARGET_TYPE_MCA>::BIT_DISABLE_REG =
{
    {
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP0_P0_0, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP0_P0_0 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP0_P0_1, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP0_P0_1 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP0_P0_2, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP0_P0_2 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP0_P0_3, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP0_P0_3 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP0_P0_4, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP0_P0_4 },
    },
    {
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP1_P0_0, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP1_P0_0 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP1_P0_1, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP1_P0_1 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP1_P0_2, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP1_P0_2 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP1_P0_3, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP1_P0_3 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP1_P0_4, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP1_P0_4 },
    },
    {
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP2_P0_0, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP2_P0_0 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP2_P0_1, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP2_P0_1 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP2_P0_2, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP2_P0_2 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP2_P0_3, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP2_P0_3 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP2_P0_4, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP2_P0_4 },
    },
    {
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP3_P0_0, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP3_P0_0 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP3_P0_1, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP3_P0_1 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP3_P0_2, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP3_P0_2 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP3_P0_3, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP3_P0_3 },
        { MCA_DDRPHY_DP16_DATA_BIT_DISABLE0_RP3_P0_4, MCA_DDRPHY_DP16_DATA_BIT_DISABLE1_RP3_P0_4 },
    },
};

// we need these declarations here in order for the linker to see the definitions
constexpr const uint64_t dp16Traits<fapi2::TARGET_TYPE_MCA>::GATE_DELAY_BIT_POS[];
constexpr const uint64_t dp16Traits<fapi2::TARGET_TYPE_MCA>::BLUE_WATERFALL_BIT_POS[];

const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::DATA_BIT_ENABLE0_REG =
{
    MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_0,
    MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_1,
    MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_2,
    MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_3,
    MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_4,
};

const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::DATA_BIT_ENABLE1_REG =
{
    MCA_0_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0,
    MCA_0_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1,
    MCA_0_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2,
    MCA_0_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3,
    MCA_0_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_4,
};

const std::vector< uint64_t > dp16Traits<TARGET_TYPE_MCA>::RD_DIA_CONFIG5_REG =
{
    MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_0,
    MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_1,
    MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_2,
    MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_3,
    MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_4,
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

typedef std::pair< uint64_t, uint64_t > register_data_pair;
typedef std::vector< register_data_pair > register_data_vector;

// Why the tables you ask? Because these bits need to be controlled
// depending on phy, packaging, board swizzling and it's just eaiser
// to see the bits like this than in a more compact algorithmic arrangement.

// Systems without Spare Bytes (or with deconfigured spares)
static const register_data_vector data_bit_enable_no_spare[] =
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
    }
};

static const register_data_vector wrclk_enable_no_spare_x8[] =
{
    // Port 0 settings
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0xC0C0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0x0F00},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0x0C00},
    },

    // Port 1 settings
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0xC0C0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0x0F00},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0xC300},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0x0C00},
    },

    // Port 2 settings
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0xC300},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0xC0C0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0xC0C0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0x0F00},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0x0C00},
    },

    // Port 3 settings
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0x0F00},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0x0F00},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0xC300},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0xC300},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0xC000},
    },

    // Port 4 settings
    // This is flipped w/the settings from the rosetta stone
    // due to the port 4 & 6 view from the PHY
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0xC0C0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x0F00},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0x0F00},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0xC000},
    },

    // Port 5 settings
    // This is flipped w/the settings from the rosetta stone
    // due to the port 5 & 7 view from the PHY
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0xC300},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0xC300},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0xC000},
    },

    // Port 6 settings
    // This is flipped w/the settings from the rosetta stone
    // due to the port 4 & 6 view from the PHY
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0xC0C0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0x0C00},
    },

    // Port 7 settings
    // This is flipped w/the settings from the rosetta stone
    // due to the port 5 & 7 view from the PHY
    {
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0, 0x0CC0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_1, 0xC0C0},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_2, 0x0F00},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_3, 0xC300},
        {MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_4, 0xC000},
    },
};

// Some compile constants to define expected sizes
constexpr size_t CLK_ENABLE_X4_SIZE = 1;
constexpr size_t CLK_ENABLE_X8_SIZE = 8;

// Rank Pair will be added to the register address before writing
static const register_data_vector rdclk_enable_no_spare_x4[] =
{
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0x8640},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0x8400},
    },
};

static const register_data_vector rdclk_enable_no_spare_x8[] =
{
    // Port 0 settings
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0xC0C0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0x0F00},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0x0C00},
    },

    // Port 1 settings
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0xC0C0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0x0F00},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0xC300},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0x0C00},
    },

    // Port 2 settings
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0xC300},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0xC0C0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0xC0C0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0x0F00},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0x0C00},
    },

    // Port 3 settings
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x0F00},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0x0F00},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0xC300},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0xC300},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0xC000},
    },

    // Port 4 settings
    // This is flipped w/the settings from the rosetta stone
    // due to the port 4 & 6 view from the PHY
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0xC0C0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x0F00},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0x0F00},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0xC000},
    },

    // Port 5 settings
    // This is flipped w/the settings from the rosetta stone
    // due to the port 5 & 7 view from the PHY
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0xC300},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0xC300},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0xC000},
    },

    // Port 6 settings
    // This is flipped w/the settings from the rosetta stone
    // due to the port 4 & 6 view from the PHY
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0xC0C0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0x0C00},
    },

    // Port 7 settings
    // This is flipped w/the settings from the rosetta stone
    // due to the port 5 & 7 view from the PHY
    {
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0, 0x0CC0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_1, 0xC0C0},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_2, 0x0F00},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_3, 0xC300},
        {MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_4, 0xC000},
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

static const register_data_vector rdclk_enable_spare_x4[] =
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
/// @brief Helper function to select rdclk/wrclk enable settings
/// @tparam N size of x4 register_data_vectors
/// @tparam M size of x8 register_data_vectors
/// @param[in] i_target a port target
/// @param[in] i_clk_enable_data_x4 array of register_data_vectors
/// @param[in] i_clk_enable_data_x8 array of register_data_vectors
/// @param[out] o_reg_data rdclk settings
/// @return FAPI2_RC_SUCCES iff ok
///
template < size_t N, size_t M >
static fapi2::ReturnCode clock_enable_helper( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        const register_data_vector (&i_clk_enable_data_x4)[N],
        const register_data_vector (&i_clk_enable_data_x8)[M],
        register_data_vector& o_reg_data )
{

    // Compile-time checks to assure we don't seg fault
    static_assert( (N == CLK_ENABLE_X4_SIZE) &&
                   (M == CLK_ENABLE_X8_SIZE),
                   "Expected register_data_vector size for x4 is 1,"
                   " register_data_vector size for x8 is 8");

    // Retrieving DRAM width accessor to determine our device width
    // to set appropriate settings for x8 and x4 cases
    uint8_t l_dram_width[mss::MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( mss::eff_dram_width(i_target, &l_dram_width[0]) );

    // I am iterating over functional DIMMs to skip empty DIMM slots
    // I'm looking for the 1st instance of whether to use x4 or x8 settings
    // This should be fine since 2 DIMMs w/the same width use the same settings
    // and DIMM mixing isn't allowed and would error out due to our plug_rules
    // before getting here in eff_config
    for( const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        const auto l_sdram_width = l_dram_width[mss::index(d)];

        switch(l_sdram_width)
        {
            case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8:
                // Settings for x8 mappings were created for all 8 ports and DP instances
                // under a proc since they vary. So are indexing with mss::pos versus mss::index
                o_reg_data = i_clk_enable_data_x8[mss::pos(i_target)];
                return fapi2::FAPI2_RC_SUCCESS;
                break;

            case fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4:
                // Settings for x4 mapping are the same for all 8 ports and DP instances
                // so we only use one setting, only the first index is defined
                o_reg_data = i_clk_enable_data_x4[0];
                return fapi2::FAPI2_RC_SUCCESS;
                break;

            default:
                FAPI_ASSERT( false,
                             fapi2::MSS_INVALID_DRAM_WIDTH().
                             set_DRAM_WIDTH(l_sdram_width).
                             set_TARGET(d),
                             "Received in valid DRAM width: x%d for %s. "
                             "Expected x8 or x4 configuration.",
                             l_sdram_width, mss::c_str(d) );
                break;
        }// switch
    }// dimm

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the read clock enable registers
/// @param[in] i_target
/// @param[in] i_rank_pairs
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_read_clock_enable( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        const std::vector< uint64_t >& i_rank_pairs )
{
    register_data_vector l_reg_data;
    FAPI_TRY( clock_enable_helper(i_target, rdclk_enable_no_spare_x4, rdclk_enable_no_spare_x8, l_reg_data),
              "Failed clock_enable_helper() on %s", mss::c_str(i_target) );

    for (const auto& rp : i_rank_pairs)
    {
        for (const auto& rdp : l_reg_data)
        {
            // Grab the register and add the rank pair in
            constexpr size_t RP_ADDR_START = 22;
            constexpr size_t RP_ADDR_LEN = 2;

            fapi2::buffer<uint64_t> l_address(rdp.first);
            l_address.insertFromRight<RP_ADDR_START, RP_ADDR_LEN>(rp);

            fapi2::buffer<uint64_t> l_data;
            constexpr size_t QUAD_LEN = 16;
            l_data.insertFromRight<MCA_DDRPHY_DP16_READ_CLOCK_RANK_PAIR0_P0_0_01_QUAD0_CLK16, QUAD_LEN>(rdp.second);

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
/// @param[in] i_rank_pairs
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_write_clock_enable( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        const std::vector< uint64_t >& i_rank_pairs )
{
    register_data_vector l_reg_data;
    FAPI_TRY( clock_enable_helper(i_target, wrclk_enable_no_spare_x4, wrclk_enable_no_spare_x8, l_reg_data),
              "Failed clock_enable_helper() on %s", mss::c_str(i_target) );

    for (const auto& rp : i_rank_pairs)
    {
        for (const auto& rdp : l_reg_data)
        {
            // Grab the register and add the rank pair in
            constexpr size_t RP_ADDR_START = 22;
            constexpr size_t RP_ADDR_LEN = 2;

            fapi2::buffer<uint64_t> l_address(rdp.first);
            l_address.insertFromRight<RP_ADDR_START, RP_ADDR_LEN>(rp);

            fapi2::buffer<uint64_t> l_data;
            constexpr size_t QUAD_LEN = 16;
            l_data.insertFromRight<MCA_DDRPHY_DP16_WRCLK_EN_RP0_P0_0_01_QUAD0_CLK16, QUAD_LEN>(rdp.second);

            FAPI_INF( "Setting up WRCLK RP%d 0x%llx (0x%llx) %s", rp, l_address, l_data, mss::c_str(i_target) );
            FAPI_TRY( mss::putScom(i_target, l_address, l_data) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the training delay configuration
/// @param[in] i_target the port target
/// @param[in] i_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_delay_values( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                      const std::vector< uint64_t >& i_rank_pairs )
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

#if 0    // Don't reset the write level values before calibration, per S. Wyatt
    // Reset the write level values
    FAPI_INF( "Resetting write level values %s", mss::c_str(i_target) );
    FAPI_TRY( mss::wc::read_config2(i_target, l_data) );
    mss::wc::set_reset_wr_delay_wl(l_data);
    FAPI_TRY( mss::wc::write_config2(i_target, l_data) );
#endif

    for (const auto& rp : i_rank_pairs)
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
    uint8_t l_sim = 0;
    FAPI_TRY( mss::is_simulation( l_sim) );

    l_data.setBit<MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0_01_ENABLE>();

    if (l_sim)
    {
        l_data.setBit<MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0_01_ROT_OVERRIDE_EN>();
    }

    // Need to run on the magic port too
    for (const auto& p : mss::find_targets_with_magic<TARGET_TYPE_MCA>(i_target))
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
/// @brief Helper to write and trace ctle cap and res
/// @tparam S the start of the insertion
/// @tparam L the length of the insertion
/// @param[in] l_ctle_cap the value of the CAP attribute
/// @param[in] l_start_bit the bit in the attribute to start at
/// @param[in,out] the ctle buffer to write
/// @return FAPI2_RC_SUCCESS iff OK
///
template< uint64_t S, uint64_t L >
fapi2::ReturnCode ctle_helper( const fapi2::buffer<uint64_t> i_ctle_cap,
                               const uint64_t l_start_bit,
                               fapi2::buffer<uint64_t>& io_ctle)
{
    fapi2::buffer<uint64_t> l_scratch;

    FAPI_DBG("ctle start: %d len: %d, insert start: %d len: %d", l_start_bit, L, S, L);

    FAPI_TRY(i_ctle_cap.extractToRight(l_scratch, l_start_bit, L),
             "unable to extract ctle cap");
    io_ctle.insertFromRight<S, L>(l_scratch);

fapi_try_exit:
    return fapi2::current_err;
};

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
    uint64_t l_cap_start_bit = 0;
    uint64_t l_res_start_bit = 0;
    constexpr uint64_t CAP_BIT_FIELD_LEN = 2;
    constexpr uint64_t RES_BIT_FIELD_LEN = 3;

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

        // I didn't make an inner loop here as the nibbles even, odd, etc. end up just different enough to make
        // keeping track of the cap/res starts, buffers, a mess. This, while a bit unrolled, is far esier to undertand.

        // Byte 0
        {
            // DP16 Block 0 Nibble 0
            {
                fapi2::buffer<uint64_t> l_scratch_0;
                fapi2::buffer<uint64_t> l_scratch_1;

                FAPI_TRY((ctle_helper<TT::CTLE_EVEN_CAP, TT::CTLE_EVEN_CAP_LEN>(l_ctle_cap, l_cap_start_bit, l_ctle_0)));
                FAPI_TRY((ctle_helper<TT::CTLE_EVEN_RES, TT::CTLE_EVEN_RES_LEN>(l_ctle_res, l_res_start_bit, l_ctle_0)));

                FAPI_INF("ctle nibble %d for %s dp16 %d: 0x%016lx, 0x%016lx",
                         0, mss::c_str(i_target), l_which_dp16, l_ctle_0, l_ctle_1);

            }

            // DP16 Block 0 Nibble 1
            {
                fapi2::buffer<uint64_t> l_scratch_0;
                fapi2::buffer<uint64_t> l_scratch_1;

                l_cap_start_bit += CAP_BIT_FIELD_LEN;
                l_res_start_bit += RES_BIT_FIELD_LEN;

                FAPI_TRY((ctle_helper<TT::CTLE_ODD_CAP, TT::CTLE_ODD_CAP_LEN>(l_ctle_cap, l_cap_start_bit, l_ctle_0)));
                FAPI_TRY((ctle_helper<TT::CTLE_ODD_RES, TT::CTLE_ODD_RES_LEN>(l_ctle_res, l_res_start_bit, l_ctle_0)));

                FAPI_INF("ctle nibble %d for %s dp16 %d: 0x%016lx, 0x%016lx",
                         1, mss::c_str(i_target), l_which_dp16, l_ctle_0, l_ctle_1);
            }
            // DP16 Block 0 Nibble 2
            {
                fapi2::buffer<uint64_t> l_scratch_0;
                fapi2::buffer<uint64_t> l_scratch_1;

                l_cap_start_bit += CAP_BIT_FIELD_LEN;
                l_res_start_bit += RES_BIT_FIELD_LEN;

                FAPI_TRY((ctle_helper<TT::CTLE_EVEN_CAP, TT::CTLE_EVEN_CAP_LEN>(l_ctle_cap, l_cap_start_bit, l_ctle_1)));
                FAPI_TRY((ctle_helper<TT::CTLE_EVEN_RES, TT::CTLE_EVEN_RES_LEN>(l_ctle_res, l_res_start_bit, l_ctle_1)));

                FAPI_INF("ctle nibble %d for %s dp16 %d: 0x%016lx, 0x%016lx",
                         2, mss::c_str(i_target), l_which_dp16, l_ctle_0, l_ctle_1);
            }

            // DP16 Block 0 Nibble 3
            {
                fapi2::buffer<uint64_t> l_scratch_0;
                fapi2::buffer<uint64_t> l_scratch_1;

                l_cap_start_bit += CAP_BIT_FIELD_LEN;
                l_res_start_bit += RES_BIT_FIELD_LEN;

                FAPI_TRY((ctle_helper<TT::CTLE_ODD_CAP, TT::CTLE_ODD_CAP_LEN>(l_ctle_cap, l_cap_start_bit, l_ctle_1)));
                FAPI_TRY((ctle_helper<TT::CTLE_ODD_RES, TT::CTLE_ODD_RES_LEN>(l_ctle_res, l_res_start_bit, l_ctle_1)));

                FAPI_INF("ctle nibble %d for %s dp16 %d: 0x%016lx, 0x%016lx",
                         3, mss::c_str(i_target), l_which_dp16, l_ctle_0, l_ctle_1);
            }
        }

        // Write
        FAPI_TRY( mss::putScom(i_target, r.first, l_ctle_0) );
        FAPI_TRY( mss::putScom(i_target, r.second, l_ctle_1) );

        // Jump over the 3rd nibble so the start bits are correct at the top of the loop
        l_cap_start_bit += CAP_BIT_FIELD_LEN;
        l_res_start_bit += RES_BIT_FIELD_LEN;

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

    // For DD1.0 we have some workarounds. We send the magic
    // number in to the work around and it fixes it up as needed.
    uint64_t l_vreg_cnrtl = mss::workarounds::dp16::vreg_control0(i_target, 0x6740);

    // Magic numbers are from the PHY team (see the ddry phy initfile, too.) They are, in fact,
    // magic numbers ...

    // TK How about a little broadcast action here? BRS
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_CNFG_REG,        0x0060) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_CNTRL_REG,       0x8100) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_DAC_LOWER_REG,   0x8000) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_DAC_UPPER_REG,   0xffe0) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_SLAVE_LOWER_REG, 0x8000) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_SLAVE_UPPER_REG, 0xffe0) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_EXTRA_REG,       0x2020) );
    FAPI_TRY( mss::scom_blastah(i_target, TT::DLL_VREG_CNTRL_REG,  l_vreg_cnrtl) );
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
    uint8_t l_sim = 0;
    uint32_t l_vref = 0;

    FAPI_TRY( mss::vpd_mt_vref_mc_rd(i_target, l_vref) );

    FAPI_TRY( rd_vref_bitfield_helper(i_target, l_vref, l_vref_bitfield) );

    FAPI_TRY( mss::is_simulation( l_sim) );

    // Leave the values as-is if we're on VBU or Awan, since we know that works. Use the real value for unit test and HW
    if (!l_sim)
    {
        // Setup the rd vref from VPD
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

        // Turn on the rd vref calibration. We leverage an attribute to control this.
        {
            uint16_t l_vref_cal_enable = 0;
            FAPI_TRY( mss::vref_cal_enable(i_target, l_vref_cal_enable) );
            FAPI_TRY( mss::scom_blastah(i_target, TT::RD_VREF_CAL_ENABLE_REG, l_vref_cal_enable) );
        }
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
        FAPI_INF("%s DQ/DQS %s impedance for DP[%u] VPD: %u register value 0x%02x", c_str(i_target), "DRV", dp, l_vpd_value[dp],
                 o_reg_value[dp]);
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
        FAPI_INF("%s DQ/DQS %s impedance for DP[%u] VPD: %u register value 0x%02x", c_str(i_target), "RCV", dp, l_vpd_value[dp],
                 o_reg_value[dp]);

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

////////////////////////////////////////////////////
// reset procedures for all the WR VREF registers //
////////////////////////////////////////////////////
///
/// @brief Reset wr vref config0 - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_config0( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // builds up the base register value
    fapi2::buffer<uint64_t> l_config0_data;
    l_config0_data.clearBit<TT::WR_VREF_CONFIG0_FULL_1D>()
    // TK putting hardcoded defaults here - revisit how to handle this (values should be obtained through characterization)
    // smallest available step size - algorithm adds 1 so this is a 1 not a 0
    .insertFromRight<TT::WR_VREF_CONFIG0_2D_SMALL_STEP_VAL, TT::WR_VREF_CONFIG0_2D_SMALL_STEP_VAL_LEN>(0b000)
    // step size of 4 - algorithm adds 1 so this is a 4, not a 3
    .insertFromRight<TT::WR_VREF_CONFIG0_2D_BIG_STEP_VAL, TT::WR_VREF_CONFIG0_2D_BIG_STEP_VAL_LEN>(0b0011)
    // for intermediary bits, skip all 7, aka only run one bit on each DRAM for intermediary bits
    .insertFromRight<TT::WR_VREF_CONFIG0_NUM_BITS_TO_SKIP, TT::WR_VREF_CONFIG0_NUM_BITS_TO_SKIP_LEN>(0b111)
    // run for two VREFs looking for an increase - this is register value + 1 to the algorithm, so it's a 1, not a 0
    .insertFromRight<TT::WR_VREF_CONFIG0_NUM_NO_INC_COMP, TT::WR_VREF_CONFIG0_NUM_NO_INC_COMP_LEN>(0b001);

    // Whether the 2D VREF is enabled or not varies by the calibration attribute
    constexpr uint16_t WR_VREF_CAL_ENABLED_BIT = 7;
    fapi2::buffer<uint16_t> l_cal_steps_enabled;
    FAPI_TRY( mss::cal_step_enable(i_target, l_cal_steps_enabled) );

    // adds the information to the buffer
    l_config0_data.writeBit<TT::WR_VREF_CONFIG0_1D_ONLY_SWITCH>(l_cal_steps_enabled.getBit<WR_VREF_CAL_ENABLED_BIT>());

    //blast out the scoms
    FAPI_TRY( mss::scom_blastah(i_target, TT::WR_VREF_CONFIG0_REG, l_config0_data) );

    // return success
    return fapi2::FAPI2_RC_SUCCESS;

    // handle errors
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset wr vref config1 - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_config1( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    //constants to make the compiler happy
    constexpr uint64_t RANGE_CROSSOVER  = 0b0011000;
    constexpr uint64_t SINGLE_RANGE_MAX = 0b0110010;

    // builds up the base register value
    fapi2::buffer<uint64_t> l_config1_data;
    // default to algorithm to use range 1
    l_config1_data.clearBit<TT::WR_VREF_CONFIG1_CTR_RANGE_SELECT>()
    // JEDEC standard value for Range 2 to 1 crossover
    .insertFromRight<TT::WR_VREF_CONFIG1_CTR_RANGE_CROSSOVER, TT::WR_VREF_CONFIG1_CTR_RANGE_CROSSOVER_LEN>(RANGE_CROSSOVER)
    // JEDEC standard value for a single range max
    .insertFromRight<TT::WR_VREF_CONFIG1_CTR_SINGLE_RANGE_MAX,
                     TT::WR_VREF_CONFIG1_CTR_SINGLE_RANGE_MAX_LEN>(SINGLE_RANGE_MAX);

    // blast out the scoms
    return  mss::scom_blastah(i_target, TT::WR_VREF_CONFIG1_REG, l_config1_data) ;
}


///
/// @brief Reset wr vref status0 - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_status0( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // reset to all 0's
    return mss::scom_blastah(i_target, TT::WR_VREF_STATUS0_REG, 0x0000 ) ;
}

///
/// @brief Reset wr vref status1 - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_status1( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // reset to all 0's
    return mss::scom_blastah(i_target, TT::WR_VREF_STATUS1_REG, 0x0000 ) ;
}

///
/// @brief Reset wr vref error_mask - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_error_mask( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // set all errors to be informational - masked off
    // TK update this post characterization
    // Note: the 0xffff includes the workaround for HW375535 - Error register latching
    return mss::scom_blastah(i_target, TT::WR_VREF_ERROR_MASK_REG, 0xFFFF ) ;
}

///
/// @brief Reset wr vref error - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_error( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // clears all errors
    return mss::scom_blastah(i_target, TT::WR_VREF_ERROR_REG, 0x0000 ) ;
}

///
/// @brief Resets the WR VREF values by rank pair for given registers
/// @tparam uint64_t RP the rankpair to reset
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp_registers registers to reset
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t RP >
fapi2::ReturnCode reset_wr_vref_value_by_rp( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const std::vector< std::pair<uint64_t, uint64_t> >& i_rp_registers )
{
    // traits definition
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

    // declares constants for the VREF train attributes - UT will fail if the ATTR changes
    // Value start location and length
    constexpr uint8_t VREF_VALUE_LOC = 2;
    constexpr uint8_t VREF_VALUE_LEN = TT::WR_VREF_VALUE_VALUE_DRAM_EVEN_LEN;
    // VREF range start location - it's only one bit
    constexpr uint8_t VREF_RANGE_LOC = 7;

    // declares variables
    uint64_t l_dimm = 0;
    uint64_t l_rank = 0;
    std::vector< uint64_t > l_prp;
    uint8_t l_vref_value[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    uint8_t l_vref_range[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {};
    fapi2::buffer<uint64_t> l_vref_reg_data;

    // sets up the rank pair information
    FAPI_TRY(mss::rank::primary_ranks(i_target, l_prp));

    // if this rank is declared, set up it's values
    // if not use the defaults of dimm = 0, rank = 0 - doesn't matter as this rank won't be calibrated
    if(l_prp.size() > RP)
    {
        l_dimm = l_prp[RP] / MAX_RANK_PER_DIMM;
        l_rank = l_prp[RP] % MAX_RANK_PER_DIMM;
    }

    FAPI_INF("%s %s RP %d found! using DIMM%d and Rank%d",
             mss::c_str(i_target), ((l_prp.size() <= RP) ? "no" : ""), RP, 0, 0);

    // gets the VREF information
    FAPI_TRY( mss::eff_vref_dq_train_value(i_target, &l_vref_value[0][0]));
    FAPI_TRY( mss::eff_vref_dq_train_range(i_target, &l_vref_range[0][0]));

    //sets up the data
    {
        uint64_t l_value = 0;
        const fapi2::buffer<uint8_t> l_vref_val_buf = l_vref_value[l_dimm][l_rank];
        l_vref_val_buf.extractToRight<VREF_VALUE_LOC, VREF_VALUE_LEN>(l_value);

        const fapi2::buffer<uint8_t> l_vref_range_buf = l_vref_range[l_dimm][l_rank];
        const auto l_range = l_vref_range_buf.getBit<VREF_RANGE_LOC>();

        l_vref_reg_data.writeBit<TT::WR_VREF_VALUE_RANGE_DRAM_EVEN>(l_range)
        .writeBit<TT::WR_VREF_VALUE_RANGE_DRAM_ODD>(l_range)
        .insertFromRight<TT::WR_VREF_VALUE_VALUE_DRAM_EVEN, TT::WR_VREF_VALUE_VALUE_DRAM_EVEN_LEN>(l_value)
        .insertFromRight<TT::WR_VREF_VALUE_VALUE_DRAM_ODD, TT::WR_VREF_VALUE_VALUE_DRAM_ODD_LEN>(l_value);
    }

    //blasts out the scoms
    FAPI_INF("%s RP %d getting reset to values 0x%04lx", mss::c_str(i_target), RP, l_vref_value);
    FAPI_TRY(mss::scom_blastah(i_target, i_rp_registers, l_vref_reg_data ));

    // return success
    return fapi2::FAPI2_RC_SUCCESS;

    // handle errorss
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset wr vref value rank pair 0 - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_value_rp0( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    return reset_wr_vref_value_by_rp<0>(i_target, TT::WR_VREF_VALUE_RP0_REG);
}

///
/// @brief Reset wr vref value rank pair 1 - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_value_rp1( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    return reset_wr_vref_value_by_rp<1>(i_target, TT::WR_VREF_VALUE_RP1_REG);
}

///
/// @brief Reset wr vref value rank pair 2 - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_value_rp2( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    return reset_wr_vref_value_by_rp<2>(i_target, TT::WR_VREF_VALUE_RP2_REG);
}

///
/// @brief Reset wr vref value rank pair3 - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_value_rp3( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // traits definition
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    return reset_wr_vref_value_by_rp<3>(i_target, TT::WR_VREF_VALUE_RP3_REG);
}

///
/// @brief Resets all WR VREF registers - specialization for MCA
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_wr_vref_registers( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // resets all of the below registers
    FAPI_TRY( reset_wr_vref_config0(i_target));
    FAPI_TRY( reset_wr_vref_config1(i_target));
    FAPI_TRY( reset_wr_vref_status0(i_target));
    FAPI_TRY( reset_wr_vref_status1(i_target));
    FAPI_TRY( reset_wr_vref_error_mask(i_target));
    FAPI_TRY( reset_wr_vref_error(i_target));
    FAPI_TRY( reset_wr_vref_value_rp0(i_target));
    FAPI_TRY( reset_wr_vref_value_rp1(i_target));
    FAPI_TRY( reset_wr_vref_value_rp2(i_target));
    FAPI_TRY( reset_wr_vref_value_rp3(i_target));

    // return success
    return fapi2::FAPI2_RC_SUCCESS;

    // handle errors
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Resets all read delay offset registers
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_read_delay_offset_registers( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // We grab the information from the VPD and blast it in to all the registers. Note the
    // VPD is picoseconds but the register wants clocks - so we convert. Likewise, the VPD
    // is per port so we can easily cram the data in to the port using the blastah.
    fapi2::buffer<uint64_t> l_data;
    int64_t l_clocks = 0;
    int16_t l_windage = 0;

    FAPI_TRY( mss::vpd_mt_windage_rd_ctr(i_target, l_windage) );
    l_clocks = mss::ps_to_cycles(i_target, l_windage);

    l_data
    .insertFromRight<TT::READ_OFFSET_LOWER, TT::READ_OFFSET_LOWER_LEN>(l_clocks)
    .insertFromRight<TT::READ_OFFSET_UPPER, TT::READ_OFFSET_UPPER_LEN>(l_clocks);

    FAPI_TRY( mss::scom_blastah(i_target, TT::READ_DELAY_OFFSET_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Process disable bits and setup controller as necessary
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_dimm the fapi2 target of the failed DIMM
/// @param[in] i_rp the rank pairs to check as a bit-map
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode process_bad_bits( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                    const fapi2::Target<TARGET_TYPE_DIMM>& i_dimm,
                                    const uint64_t l_rp )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // In a x4 configuration, all bits in the disable registers are used.
    // Named like a local variable so it matches the x8 vector <shrug>
    constexpr uint8_t l_x4_mask = 0b11111111;

    // Vector of DQS maps different for x8.
    // Inner vector is bit-map representing valid DQS in the Disable 1 register. Nimbus
    // has no spares so we never check the lower DQS for DP4
    std::vector< std::vector<uint8_t> > l_x8_dqs =
    {
        // Port 0
        // DP    16,17    18,19    20,21    22,23
        // 0                Y                 Y
        // 1       Y                          Y
        // 2                Y                 Y
        // 3                Y        Y
        // 4                Y        X        X (no spares)
        //   DP0         DP1         DP2         DP3          DP4
        { 0b00110011, 0b11000011, 0b00110011, 0b00111100, 0b00110000 },

        // Port 1
        // DP    16,17    18,19    20,21    22,23
        // 0       Y                          Y
        // 1                Y        Y
        // 2                Y                 Y
        // 3       Y                 Y
        // 4                Y        X        X (no spares)
        //   DP0         DP1         DP2         DP3          DP4
        { 0b11000011, 0b00111100, 0b00110011, 0b11001100, 0b00110000 },

        // Port 2
        // DP    16,17    18,19    20,21    22,23
        // 0       Y                 Y
        // 1       Y                          Y
        // 2       Y                          Y
        // 3                Y        Y
        // 4                Y        X        X (no spares)
        //   DP0         DP1         DP2         DP3          DP4
        { 0b11001100, 0b11000011, 0b11000011, 0b00111100, 0b00110000 },

        // Port 3
        // DP    16,17    18,19    20,21    22,23
        // 0                Y        Y
        // 1                Y        Y
        // 2       Y                 Y
        // 3       Y                 Y
        // 4       Y                 X        X (no spares)
        //   DP0         DP1         DP2         DP3          DP4
        { 0b00111100, 0b00111100, 0b11001100, 0b11001100, 0b11000000 },

        // Port 4 (possibly port 6)
        // DP    16,17    18,19    20,21    22,23
        // 0                Y                 Y
        // 1                Y                 Y
        // 2                Y                 Y
        // 3       Y                          Y
        // 4                Y        X        X (no spares)
        //   DP0         DP1         DP2         DP3          DP4
        { 0b00110011, 0b00110011, 0b11001100, 0b11000011, 0b00110000 },

        // Port 5 (possibly port 7)
        // DP    16,17    18,19    20,21    22,23
        // 0                Y                 Y
        // 1       Y                          Y
        // 2                Y        Y
        // 3       Y        Y
        // 4       Y                 X        X (no spares)
        //   DP0         DP1         DP2         DP3          DP4
        { 0b11001100, 0b11000011, 0b00111100, 0b11110000, 0b11000000 },

        // Port 6 (possibly port 4)
        // DP    16,17    18,19    20,21    22,23
        // 0                Y                 Y
        // 1       Y                          Y
        // 2                Y        Y
        // 3                Y        Y
        // 4       Y                 X        X (no spares)
        //   DP0         DP1         DP2         DP3          DP4
        { 0b00110011, 0b11000011, 0b00111100, 0b00111100, 0b11000000 },

        // Port 7 (possibly port 5)
        // DP    16,17    18,19    20,21    22,23
        // 0       Y                 Y
        // 1                Y                 Y
        // 2                Y                 Y
        // 3       Y                 Y
        // 4       Y                 X        X (no spares)
        //   DP0         DP1         DP2         DP3          DP4
        { 0b11001100, 0b00110011, 0b00110011, 0b11001100, 0b11000000 },
    };

    // The field in the disable bit register address which specifies which rp the register is for.
    constexpr uint64_t RP_OFFSET = 60;

    // The DQS bits (disable 1) are left aligned in a 16 bit register and we have a
    // right aligned mask so this is the number of bits to shift right to right align
    // disable 1.
    constexpr uint64_t DQS_SHIFT = 8;

    // If we have this number of bad bits, there's no way we can use this rank pair
    // Note, if we have 5 bad bits we might have one nibble and one bit ...
    constexpr uint64_t MIN_BAD_BITS = 6;
    constexpr uint64_t MIN_BAD_X4_DQS = 3;
    constexpr uint64_t MIN_BAD_X8_DQS = 1;

    // We can handle 1 bad nibble + 1 bad bit. If we see 2 bad bits but no bad nibbles
    // that's basically the same as one of the bad bits can be considered a bad nibble.
    // This is a sly way to handle two bad bits ... hence the name
    constexpr uint64_t MAX_BAD_NIBBLES = 1;
    constexpr uint64_t MAX_BAD_BITS = 1;
    constexpr uint64_t SLY_BAD_BITS = 2;

    uint64_t l_which_port = mss::pos(i_target);

    fapi2::buffer<uint64_t> l_rpb(l_rp);
    std::vector< std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> > > l_read;

    while (l_rpb != 0)
    {
        // We increment l_which_dp as soon as we enter the loop below
        uint64_t l_which_dp = ~0;

        // A map of the indexes of the bad nibbles. We do bad nibble checking in two phases;
        // the DQS and the DQ. Since bad bits in the DQ/DQS of the nibble are the same nibble,
        // we use a map to consolodate the findings. In the end all we care about is whether there
        // is more than one entry in this map.
        std::map<uint64_t, uint64_t> l_bad_nibbles;
        uint64_t l_bad_bits = 0;

        // Find the first bit set in the rank pairs - this will tell us which rank pair has a fail
        const auto l_fbs = mss::first_bit_set(uint64_t(l_rpb)) - RP_OFFSET;

        FAPI_INF("checking bad bits for RP%d", l_fbs);
        FAPI_TRY( mss::scom_suckah(i_target, TT::BIT_DISABLE_REG[l_fbs], l_read) );

        // Loop over the read information for the DP
        for (auto& v : l_read)
        {
            uint8_t l_width = 0;
            uint8_t l_dqs_mask = 0;
            uint64_t l_dq_bad_bit_count = 0;
            uint64_t l_dqs_bad_bit_count = 0;

            l_which_dp += 1;
            const uint64_t l_which_nibble = l_which_dp * BITS_PER_NIBBLE;

            FAPI_INF("read disable0 0x%016lx disable1 0x%016lx", v.first, v.second);

            //
            // Before we mess around, check for a simple pass
            //
            if ((v.first == 0) && (v.second == 0))
            {
                FAPI_INF("port %d DP%d all bits good", l_which_port, l_which_dp);
                continue;
            }

            //
            // Check for a simple fail. In all cases if we see 6 or more bits set in the
            // disable 0, we have a dead nibble + more than one bit. We don't need to worry about
            // disable bits because this port will be deconfigured all together.
            //
            l_dq_bad_bit_count = mss::bit_count(uint64_t(v.first));
            FAPI_INF("bad DQ count for port %d DP%d %d", l_which_port, l_which_dp, l_dq_bad_bit_count);
            FAPI_ASSERT(l_dq_bad_bit_count < MIN_BAD_BITS,
                        fapi2::MSS_DISABLED_BITS().set_TARGET_IN_ERROR(i_target),
                        "port %d DP%d too many bad DQ bits 0x%016lx", l_which_port, l_which_dp, v.first);

            //
            // Find the DQS mask for this DP.
            //
            FAPI_TRY( mss::eff_dram_width(i_dimm, l_width) );
            l_dqs_mask = (l_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ? l_x8_dqs[l_which_port][l_which_dp] : l_x4_mask;

            FAPI_INF("DQS mask for port %d DP%d 0x%x (0x%016lx)", l_which_port, l_which_dp, l_dqs_mask, v.second);

            //
            // Check for a simple DQS fail. For x4 if we have 3 DQS bad, we're cooked (that's
            // at least 2 nibbles.) For x8 of we have 1 DQS bad we're cooked (that's at least 1 byte
            // or at least 2 nibbles.)
            //
            if (v.second != 0)
            {
                l_dqs_bad_bit_count = mss::bit_count((v.second >> DQS_SHIFT) & l_dqs_mask);
                FAPI_INF("bad DQS count for port %d DP%d %d", l_which_port, l_which_dp, l_dqs_bad_bit_count);
                FAPI_ASSERT(l_dqs_bad_bit_count <
                            ((l_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ? MIN_BAD_X8_DQS : MIN_BAD_X4_DQS),
                            fapi2::MSS_DISABLED_BITS().set_TARGET_IN_ERROR(i_target),
                            "port %d DP%d too many bad DQS bits 0x%016lx", l_which_port, l_which_dp, v.second);

                // So there's no way to get here if we have a x8 config. Either we had no bad DQS, in which case
                // we didn't come down here at all, or we have at least one bad DQS. And for x8 that means we have
                // at least one bad byte and that's 2 nibbles so we're cooked. The only thing we need to check
                // here is x4 DQS. We know that we have fewer than 3 bad DQS. If both DQS are on the same nibble
                // that's just one bad nibble. If the DQS are a P/N of different nibbles then we're cooked.

                // Loop over the read information for each nibble. Need index to do the shift.
                // Don't get fancy and try to incorporate the DQ checking in here too. Notice that
                // this DQS checking is only valid for x4 - x8 was taken care of with the bit_count check.
                for (size_t n = 0; n < NIBBLES_PER_DP; ++n)
                {
                    // DQS disable are in disable 1 which is a left-aligned 16 bit register.
                    // We shift it over to mask off the nibble we're checking
                    const uint16_t l_dqs_nibble_mask = 0b1100000000000000 >> (n * BITS_PER_DQS);

                    FAPI_INF("port %d DP%d nibble %d (%d) mask: 0x%x dqs: 0x%x",
                             l_which_port, l_which_dp, n, n + l_which_nibble, l_dqs_nibble_mask, v.second);

                    if ((l_dqs_nibble_mask & v.second) != 0)
                    {
                        FAPI_INF("dqs check indicating %d as a bad nibble", n);
                        l_bad_nibbles[n + l_which_nibble] = 1;
                    }

                }

                // Check to see if the DQ nibble processing found more than one bad nibble. If it did,
                // we're done.
                FAPI_ASSERT(l_bad_nibbles.size() <= MAX_BAD_NIBBLES,
                            fapi2::MSS_DISABLED_BITS().set_TARGET_IN_ERROR(i_target),
                            "port %d DP%d too many bad nibbles %d", l_which_port, l_which_nibble, l_bad_nibbles.size());
            }

            //
            // Ok, if we made it this far we don't have anything in the DQS alone which tells us we have an
            // uncorrectable situation. We can check the DQ nibbles and see what they have to say. We can do
            // x8 and x4 nibbles all the same ...
            //
            if (v.first != 0 )
            {
                for (size_t n = 0; n < NIBBLES_PER_DP; ++n)
                {
                    // DQ nibbles are in disable 0 which is a 16 bit register.
                    // We shift it over to mask off the nibble we're checking
                    const uint16_t l_dq_nibble_mask  = 0b1111000000000000 >> (n * BITS_PER_NIBBLE);

                    // DQ are a little different. We need to see how many bits are in the nibble.
                    // If we have > 2 bad bits, we kill this nibble. If we only have one bad bit
                    // we add this bit to the total of bad singleton bits.
                    const uint64_t l_bit_count = mss::bit_count(l_dq_nibble_mask & v.first);

                    FAPI_INF("port %d DP%d nibble %d (%d) mask: 0x%x dq: 0x%x c: %d",
                             l_which_port, l_which_dp, n, n + l_which_nibble, l_dq_nibble_mask, v.first, l_bit_count);


                    // If we don't have any set bits, we're good to go. If we have more than the max bad bits,
                    // then we have a bad nibble. Otherwise we must have one bad bit in the nibble. It counts
                    // as a bad bit but doesn't kill the nibble (yet.)
                    if (l_bit_count != 0)
                    {
                        if (l_bit_count > MAX_BAD_BITS)
                        {
                            FAPI_INF("dq check indicating %d (%d) as a bad nibble", n, n + l_which_nibble);
                            l_bad_nibbles[n + l_which_nibble] = 1;
                        }
                        else
                        {
                            FAPI_INF("dq check indicating nibble %d (%d) has a bad bit", n, n + l_which_nibble);
                            l_bad_bits += l_bit_count;
                        }
                    }
                }
            }
        }

        //
        // Ok, so now we know how many bad bits we have and how many bad nibbles. If we have more than
        // one bad nibble, we're cooked. If we have one bad nibble and one bad bit, we're ok. Also, if
        // we have no bad nibbles and two bad bits (a sly bad nibble) we are ok - one of those bad bits
        // counts as a bad nibble.
        //
        FAPI_ASSERT(l_bad_nibbles.size() <= MAX_BAD_NIBBLES,
                    fapi2::MSS_DISABLED_BITS().set_TARGET_IN_ERROR(i_target),
                    "port %d DP%d too many bad nibbles %d",
                    l_which_port, l_which_dp, l_bad_nibbles.size());

        // If we have one bad nibble, assert that we have one or fewer bad bits
        if (l_bad_nibbles.size() == MAX_BAD_NIBBLES)
        {
            FAPI_ASSERT(l_bad_bits <= MAX_BAD_BITS,
                        fapi2::MSS_DISABLED_BITS().set_TARGET_IN_ERROR(i_target),
                        "port %d DP%d bad nibbles %d + %d bad bits",
                        l_which_port, l_which_dp, l_bad_nibbles.size(), l_bad_bits);
        }

        // If we have no bad nibbles, assert we have 2 or fewer bad bits. This is a sly bad nibble
        // scenario; one of the bits is represents a bad nibble
        if (l_bad_nibbles.size() == 0)
        {
            FAPI_ASSERT(l_bad_bits <= SLY_BAD_BITS,
                        fapi2::MSS_DISABLED_BITS().set_TARGET_IN_ERROR(i_target),
                        "port %d DP%d %d bad bits",
                        l_which_port, l_which_dp, l_bad_bits);
        }

        // We're all done. Clear the bit
        l_rpb.clearBit(l_fbs + RP_OFFSET);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the bad-bits masks for a port
/// @note Read the bad bits from the f/w attributes and stuff them in the
/// appropriate registers.
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode reset_bad_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // The magic 10 is because there are 80 bits represented in this attribute, and each element is 8 bits.
    //  So to get to 80, we need 10 bytes.
    uint8_t l_bad_dq[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM][10] = { 0 };
    FAPI_TRY( mss::bad_dq_bitmap(i_target, &(l_bad_dq[0][0][0])) );

    return reset_bad_bits_helper(i_target, l_bad_dq);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset the bad-bits masks for a port - helper for ease of testing
/// @note Read the bad bits from the f/w attributes and stuff them in the
/// appropriate registers.
/// @note The magic 10 is because there are 80 bits represented in this attribute, and each element is 8 bits.
/// So to get to 80, we need 10 bytes.
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_bad_dq array representing the data from the bad dq bitmap
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode reset_bad_bits_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint8_t i_bad_dq[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM][10] )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    std::vector<uint64_t> l_ranks;

    // Loop over the ranks, makes things simpler than looping over the DIMM (surprisingly)
    FAPI_TRY( rank::ranks(i_target, l_ranks) );

    for (const auto& r : l_ranks)
    {
        uint64_t l_rp = 0;
        uint64_t l_dimm_index = rank::get_dimm_from_rank(r);
        FAPI_TRY( mss::rank::get_pair_from_rank(i_target, r, l_rp) );

        FAPI_INF("processing bad bits for DIMM%d rank %d (%d) rp %d", l_dimm_index, mss::index(r), r, l_rp);

        // We loop over the disable registers for this rank pair, and shift the bits from the attribute
        // array in to the disable registers
        {
            // This is the set of registers for this rank pair. It is indexed by DP. We know the bad bits
            // [0] and [1] are the 16 bits for DP0, [2],[3] are the 16 for DP1, etc.
            const auto& l_addrs = TT::BIT_DISABLE_REG[l_rp];

            // This is the section of the attribute we need to use. The result is an array of 10 bytes.
            const uint8_t* l_bad_bits = &(i_bad_dq[l_dimm_index][mss::index(r)][0]);

            // Where in the array we are, incremented by two for every DP
            size_t l_byte_index = 0;

            for (const auto& a : l_addrs)
            {
                uint64_t l_register_value = (l_bad_bits[l_byte_index] << 8) | l_bad_bits[l_byte_index + 1];

                FAPI_INF("writing %s 0x%0lX value 0x%0lX from 0x%X, 0x%X",
                         mss::c_str(i_target), a.first, l_register_value,
                         l_bad_bits[l_byte_index], l_bad_bits[l_byte_index + 1]);

                // TODO RTC: 163674 Only wriiting the DISABLE0 register - not sure what happened to the DQS?
                FAPI_TRY( mss::putScom(i_target, a.first, l_register_value) );
                l_byte_index += 2;
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write disable bits
/// @note This is different than a register write as it writes attributes which
/// cause firmware to act on the disabled bits.
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode record_bad_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    const auto& l_mcs = mss::find_target<TARGET_TYPE_MCS>(i_target);
    uint8_t l_value[PORTS_PER_MCS][MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM][10] = { 0 };

    // Process the bad bits into an array. We copy these in to their own array
    // as it allows the compiler to check indexes where a passed pointer wouldn't
    // otherwise do.
    uint8_t l_data[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM][10] = { 0 };
    FAPI_TRY( mss::dp16::record_bad_bits_helper(i_target, l_data) );

    // Read the attribute
    FAPI_TRY( mss::bad_dq_bitmap(l_mcs, &(l_value[0][0][0][0])) );

    // Modify
    memcpy( &(l_value[mss::index(i_target)][0][0][0]), &(l_data[0][0][0]),
            MAX_DIMM_PER_PORT * MAX_RANK_PER_DIMM * 10 );

    // Write
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_BAD_DQ_BITMAP, l_mcs, l_value) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write disable bits - helper for testing
/// @note This is different than a register write as it writes attributes which
/// cause firmware to act on the disabled bits.
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_bad_dq an array of [MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM][10] containing the attribute information
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode record_bad_bits_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint8_t (&o_bad_dq)[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM][10] )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    std::vector<uint64_t> l_ranks;

    // Loop over the ranks, makes things simpler than looping over the DIMM (surprisingly)
    FAPI_TRY( rank::ranks(i_target, l_ranks) );

    for (const auto& r : l_ranks)
    {
        uint64_t l_rp = 0;
        uint64_t l_dimm_index = rank::get_dimm_from_rank(r);
        FAPI_TRY( mss::rank::get_pair_from_rank(i_target, r, l_rp) );

        FAPI_INF("recording bad bits for DIMM%d rank %d (%d) rp %d", l_dimm_index, mss::index(r), r, l_rp);

        // We loop over the disable registers for this rank pair, and shift the bits from the attribute
        // array in to the disable registers
        {
            // Grab a pointer to our argument simply to make the code a little easier to read
            uint8_t* l_bad_bits = &(o_bad_dq[l_dimm_index][mss::index(r)][0]);

            // The values we'll pull from the registers in the scom suckah below. We only read the registers for
            // our current rank pair.
            std::vector< std::pair< fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> > > l_register_value;

            FAPI_TRY( mss::scom_suckah(i_target, TT::BIT_DISABLE_REG[l_rp], l_register_value) );

            // Where in the array we are, incremented by two for every DP
            size_t l_byte_index = 0;

            for (const auto& v : l_register_value)
            {
                // Grab the left and right bytes from the bad bits register and stick them in the
                // nth and nth + 1 bytes of the array
                l_bad_bits[l_byte_index]    = (v.first & 0xFF00) >> 8;
                l_bad_bits[l_byte_index + 1] = v.first & 0x00FF;

                FAPI_DBG("writing %s value 0x%0lX to 0x%X, 0x%X from 0x%016lx",
                         mss::c_str(i_target),
                         v.first,
                         l_bad_bits[l_byte_index],
                         l_bad_bits[l_byte_index + 1],
                         v.first);

                // TODO RTC: 163674 Only writing the DISABLE0 register - not sure what happened to the DQS?
                l_byte_index += 2;
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Process read vref calibration errors
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode process_rdvref_cal_errors( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // We want the index as we want to grab the register for the error log too.
    size_t l_index = 0;
    std::vector<fapi2::buffer<uint64_t>> l_data;

    // Suck all the cal error bits out ...
    FAPI_TRY( mss::scom_suckah(i_target, TT::RD_VREF_CAL_ERROR_REG, l_data) );

    FAPI_INF("processing RD_VREF_CAL_ERROR");

    for (const auto& v : l_data)
    {
        // They should all be 0's. If they're not, we have a problem we should log.
        // We don't need to fail out, as read centering will fail and we can process
        // the errors and the disables there.
        FAPI_ASSERT_NOEXIT(v == 0,
                           fapi2::MSS_FAILED_RDVREF_CAL()
                           .set_TARGET_IN_ERROR(i_target)
                           .set_REGISTER(TT::RD_VREF_CAL_ERROR_REG[l_index])
                           .set_VALUE(v),
                           "DP16 failed read vref calibration on %s. register 0x%016lx value 0x%016lx",
                           mss::c_str(i_target), TT::RD_VREF_CAL_ERROR_REG[l_index], v);
        l_index += 1;
    }

    FAPI_INF("RD_VREF_CAL_ERROR complete");
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Process write vref calibration errors
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode process_wrvref_cal_errors( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // All PHY registers are 16 bits and start at bit 48 bits 0-47 are filler
    constexpr uint64_t DATA_START = 48;
    constexpr uint64_t DATA_LEN = 16;

    // We want the index as we want to grab the register for the error log too.
    uint64_t l_index = 0;
    std::vector<std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>>> l_data;
    std::vector<std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>>> l_mask;

    // Suck all the cal error bits out ...
    FAPI_TRY( mss::scom_suckah(i_target, TT::WR_VREF_ERROR_REG, l_data) );
    FAPI_TRY( mss::scom_suckah(i_target, TT::WR_VREF_ERROR_MASK_REG, l_mask) );

    // Loop through both data and mask
    {
        // Note: ideally these would be cbegin/cend, but HB doesn't support constant iterators for vectors
        auto l_data_it = l_data.begin();
        auto l_mask_it = l_mask.begin();

        for(;
            l_data_it < l_data.end() && l_mask_it < l_mask.end();
            ++l_mask_it, ++l_data_it, ++l_index)
        {
            // Not sure if there's value add to a function to do these, but it's 2x repetition, so not bad to maintain
            // First print out the data to log all informational callouts
            // WR VREF can either escalate "error" bits as errors or informational, based upon a mask
            FAPI_INF("%s DP[%lu] WR VREF[%d] ERROR 0x%016lx MASK 0x%016lx", mss::c_str(i_target), l_index, 0, l_data_it->first,
                     l_mask_it->first);
            FAPI_INF("%s DP[%lu] WR VREF[%d] ERROR 0x%016lx MASK 0x%016lx", mss::c_str(i_target), l_index, 1, l_data_it->second,
                     l_mask_it->second);

            // Inverts as a 1 bit indicates an informational error. we only want to log true errors
            fapi2::buffer<uint64_t> l_mask_compare = l_mask_it->first;
            l_mask_compare.flipBit<DATA_START, DATA_LEN>();

            // Now does bitwise anding to determine what's an actual error w/ the masking
            FAPI_ASSERT_NOEXIT(0 == (l_mask_compare & l_data_it->first),
                               fapi2::MSS_FAILED_WRVREF_CAL()
                               .set_TARGET_IN_ERROR(i_target)
                               .set_REGISTER(TT::WR_VREF_ERROR_REG[l_index].first)
                               .set_VALUE(l_data_it->first)
                               .set_MASK(l_mask_it->first),
                               "DP16 failed write vref calibration on %s. register 0x%016lx value 0x%016lx mask 0x%016lx",
                               mss::c_str(i_target), TT::WR_VREF_ERROR_REG[l_index].first, l_data_it->first, l_mask_it->first);


            l_mask_compare = l_mask_it->second;
            l_mask_compare.flipBit<DATA_START, DATA_LEN>();

            FAPI_ASSERT_NOEXIT(0 == (l_mask_compare & l_data_it->second),
                               fapi2::MSS_FAILED_WRVREF_CAL()
                               .set_TARGET_IN_ERROR(i_target)
                               .set_REGISTER(TT::WR_VREF_ERROR_REG[l_index].second)
                               .set_VALUE(l_data_it->second)
                               .set_MASK(l_mask_it->second),
                               "DP16 failed write vref calibration on %s. register 0x%016lx value 0x%016lx mask 0x%016lx",
                               mss::c_str(i_target), TT::WR_VREF_ERROR_REG[l_index].second, l_data_it->second, l_mask_it->second);
        }
    }

    FAPI_INF("WRVREF_CAL_ERROR complete");
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write FORCE_FIFO_CAPTURE to all DP16 instances
/// Force DQ capture in Read FIFO to support DDR4 LRDIMM calibration
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_state mss::states::ON or mss::states::OFF
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode write_force_dq_capture( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const mss::states i_state)
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    fapi2::buffer<uint64_t> l_data;
    l_data.writeBit<TT::FORCE_FIFO_CAPTURE>(i_state);

    FAPI_TRY( mss::scom_blastah(i_target, TT::RD_DIA_CONFIG5_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes DATA_BIT_ENABLE0 to all DP16 instances
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_state mss::states::ON or mss::states::OFF
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode write_data_bit_enable0( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const mss::states i_state)
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // '1'b indicates the DP16 bit is enabled, and is used for sending or receiving
    // data to or from the memory device.
    // '0'b indicates the DP16 bit is not used to send or receive data
    fapi2::buffer<uint64_t> l_data;
    l_data.writeBit<TT::DATA_BIT_ENABLE0, TT::DATA_BIT_ENABLE0_LEN>(i_state);

    FAPI_TRY( mss::scom_blastah(i_target, TT::DATA_BIT_ENABLE0_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write DFT_FORCE_OUTPUTS to all DP16 instances
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_state mss::states::ON or mss::states::OFF
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode write_dft_force_outputs( const fapi2::Target< fapi2::TARGET_TYPE_MCA >& i_target,
        const mss::states i_state)
{
    typedef dp16Traits<TARGET_TYPE_MCA> TT;

    // The 24 outputs of the DP16 are forced to a low-impedance state the corresponding DATA_BIT_ENABLE bit is '1'b
    // and forced to a high-impedence state when the corresponding DATA_BIT_ENABLE bit is '0'b

    // When a DP16 output is forced to a low-z state, the value driven out, '1'b or '0'b , is determined
    // by the corresponding DATA_BIT_DIR bit value.
    // The 24 outputs of the DP16 are not forced when set with '0'b
    fapi2::buffer<uint64_t> l_data;
    l_data.writeBit<TT::DFT_FORCE_OUTPUTS>(i_state);

    FAPI_TRY( mss::scom_blastah(i_target, TT::DATA_BIT_ENABLE1_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace dp16
} // close namespace mss
