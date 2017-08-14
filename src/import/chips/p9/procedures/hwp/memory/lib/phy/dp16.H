/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/dp16.H $    */
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
/// @file dp16.H
/// @brief Subroutines to control the DP16 logic blocks
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_DP16_H_
#define _MSS_DP16_H_

#include <vector>
#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/shared/mss_const.H>

namespace mss
{

///
/// @brief Enumeration of DD2_BLUE_EXTEND_RANGE settings in DP16_DRIFT_LIMITS reg
/// @note Each name denotes the RDCLK phase shift lower and upper bounds, with
///       setting '2' being invalid.
///
enum blue_waterfall_range : uint64_t
{
    ZERO_TO_THREE = 0,
    ONE_TO_FOUR   = 1,
    RESERVED      = 2,
    TWO_TO_FIVE   = 3
};

///
/// @brief Given a mt/s, create a PHY 'standard' bit field for that freq.
/// @param[in] i_freq the value from mss::freq for your target
/// @return uint64_t a right-aligned bitfield which can be inserted in to a buffer
///
inline uint64_t freq_bitfield_helper( const uint64_t i_freq )
{
    fapi2::buffer<uint64_t> l_data(0b1000);

    FAPI_DBG("freq_bitfield_helper seeing MT/s: %d", i_freq);

    // Shift l_data over based on freq.
    switch(i_freq)
    {
        // We don't support 1866 on Nimbus.
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            l_data >>= 3;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            l_data >>= 2;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            l_data >>= 1;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            l_data >>= 0;
            break;

        default:
            FAPI_ERR("Unkown MT/s: %d", i_freq);
            fapi2::Assert(false);
            break;
    };

    return l_data;
}

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class dp16Traits
/// @brief a collection of traits associated with the PHY DP16 block
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class dp16Traits;

///
/// @class dp16Traits
/// @brief a collection of traits associated with the Centaur PHY
///
template<>
class dp16Traits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class dp16Traits
/// @brief a collection of traits associated with the Nimbus PHY DP16 block
///
template<>
class dp16Traits<fapi2::TARGET_TYPE_MCA>
{

    public:
        // Number of DP instances
        static constexpr uint64_t DP_COUNT = 5;

        // Maximum number of DRAM's per DP
        static constexpr uint64_t MAX_DRAM_PER_DP = 4;

        // Number of quads per DP16
        static constexpr uint64_t NUM_QUAD_PER_DP16  = 4;

        // Number of instances of the DLL per DP16. Used for checking parameters, the rest of the
        // code assumes 2 DLL per DP16. There are no DLL in Centaur so we don't need to worry about
        // any of this for some time.
        static constexpr uint64_t DLL_PER_DP16 = 2;

        // Maximum and minimum RD_VREF percentage of VDD. We only test against max and min because
        // there are so many allowable values.
        static constexpr uint64_t MAX_RD_VREF = fapi2::ENUM_ATTR_MSS_VPD_MT_VREF_MC_RD_VDD91875;
        static constexpr uint64_t MIN_RD_VREF = fapi2::ENUM_ATTR_MSS_VPD_MT_VREF_MC_RD_VDD31208;

        // Constants used for converting RD_VREF percentage to DAC settings, normalized to integers
        static constexpr uint64_t RD_VREF_DVDD = 12;
        static constexpr uint64_t RD_VREF_DAC_STEP = 6500;

        // Vectors of DP16 registers. The pair represents the two DLL in per DP16
        static const std::vector< uint64_t > DLL_CNFG_REG;
        static const std::vector< uint64_t > RD_VREF_CAL_ENABLE_REG;
        static const std::vector< uint64_t > RD_VREF_CAL_ERROR_REG;
        static const std::vector< uint64_t > DATA_BIT_DIR1_REG;
        static const std::vector< uint64_t > PR_STATIC_OFFSET_REG;
        static const std::vector< uint64_t > IO_TX_FET_SLICE_REG;
        static const std::vector< uint64_t > IO_TX_PFET_TERM_REG;
        static const std::vector< uint64_t > READ_DELAY_OFFSET_REG;

        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_CNTRL_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_DAC_LOWER_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_DAC_UPPER_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_SLAVE_LOWER_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_SLAVE_UPPER_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_EXTRA_REG;

        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_SW_CNTRL_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_VREG_COARSE_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_VREG_CNTRL_REG;

        static const std::vector< std::pair<uint64_t, uint64_t> > AC_BOOST_CNTRL_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > CTLE_CNTRL_REG;
        static const std::vector< uint64_t > DD1_RD_VREF_CNTRL_REG;
        static const std::vector< uint64_t > DD2_RD_VREF_CNTRL_REG;
        static const std::vector< uint64_t > DRIFT_LIMITS_REG;
        static const std::vector< uint64_t > DP16_RX_REGS;

        static const std::vector<std::vector<std::pair<uint64_t, uint64_t>>> BIT_DISABLE_REG;

        // WR VREF registers
        static const std::vector< uint64_t > WR_VREF_CONFIG0_REG;
        static const std::vector< uint64_t > WR_VREF_CONFIG1_REG;
        static const std::vector< uint64_t > WR_VREF_STATUS0_REG;
        static const std::vector< uint64_t > WR_VREF_STATUS1_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > WR_VREF_ERROR_MASK_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > WR_VREF_ERROR_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > WR_VREF_VALUE_RP0_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > WR_VREF_VALUE_RP1_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > WR_VREF_VALUE_RP2_REG;
        static const std::vector< std::pair<uint64_t, uint64_t> > WR_VREF_VALUE_RP3_REG;

        static const std::vector< uint64_t > RD_DIA_CONFIG5_REG;
        static const std::vector< uint64_t > DATA_BIT_ENABLE0_REG;
        static const std::vector< uint64_t > DATA_BIT_ENABLE1_REG;

        // Reset on read in DD1 registers
        static const std::vector< uint64_t > RD_LVL_STATUS0_REG;
        static const std::vector< uint64_t > RD_LVL_STATUS2_REG;
        static const std::vector< uint64_t > RD_STATUS0_REG;
        static const std::vector< uint64_t > WR_ERROR0_REG;


        // Definitions of the gate delay and waterfall bits' locations
        constexpr static const uint64_t GATE_DELAY_BIT_POS[NUM_QUAD_PER_DP16] =
        {
            MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_0_01_N0,
            MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_0_01_N1,
            MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_0_01_N2,
            MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_0_01_N3,
        };
        constexpr static const uint64_t BLUE_WATERFALL_BIT_POS[NUM_QUAD_PER_DP16] =
        {
            MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT0,
            MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT1,
            MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT2,
            MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT3,
        };

        enum
        {
            // Name changes for dd2 to P9N2_MCA_DDRPHY_DP16_RX_CONFIG0_P0_0
            READ_CENTERING_MODE = MCA_DDRPHY_DP16_RX_PEAK_AMP_P0_0_01_READ_CENTERING_MODE,
            READ_CENTERING_MODE_LEN = MCA_DDRPHY_DP16_RX_PEAK_AMP_P0_0_01_READ_CENTERING_MODE_LEN,

            DLL_CNTL_INIT_RXDLL_CAL_RESET = MCA_DDRPHY_DP16_DLL_CNTL0_P0_0_01_INIT_RXDLL_CAL_RESET,
            DLL_CNTL_INIT_RXDLL_CAL_SKIP = MCA_DDRPHY_DP16_DLL_CNTL0_P0_1_01_REGS_RXDLL_CAL_SKIP,
            DLL_CNTL_INIT_RXDLL_CAL_SKIP_LEN = MCA_DDRPHY_DP16_DLL_CNTL0_P0_1_01_REGS_RXDLL_CAL_SKIP_LEN,
            FLUSH = MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_01_FLUSH,
            INIT_IO = MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_01_INIT_IO,
            ADV_PP = MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_01_ADVANCE_PING_PONG,
            DELAY_PP_HALF = MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_01_DELAY_PING_PONG_HALF,
            DISABLE_PING_PONG = MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_01_DISABLE_PING_PONG,

            TSYS_DATA = MCA_DDRPHY_DP16_WRCLK_PR_P0_0_01_TSYS,
            TSYS_DATA_LEN = MCA_DDRPHY_DP16_WRCLK_PR_P0_0_01_TSYS_LEN,

            AC_BOOST_WR_DOWN = MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_0_01_S0ACENSLICENDRV_DC,
            AC_BOOST_WR_DOWN_LEN = MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_0_01_S0ACENSLICENDRV_DC_LEN,
            AC_BOOST_WR_UP = MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_0_01_S0ACENSLICEPDRV_DC,
            AC_BOOST_WR_UP_LEN = MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_0_01_S0ACENSLICEPDRV_DC_LEN,
            AC_BOOST_RD_UP = MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_1_01_S0ACENSLICEPTERM_DC,
            AC_BOOST_RD_UP_LEN = MCA_DDRPHY_DP16_ACBOOST_CTL_BYTE0_P0_1_01_S0ACENSLICEPTERM_DC_LEN,

            CTLE_EVEN_CAP = MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0_01_NIB_2_DQSEL_CAP,
            CTLE_EVEN_CAP_LEN = MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0_01_NIB_2_DQSEL_CAP_LEN,
            CTLE_EVEN_RES = MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0_01_NIB_2_DQSEL_RES,
            CTLE_EVEN_RES_LEN = MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0_01_NIB_2_DQSEL_RES_LEN,
            CTLE_ODD_CAP = MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0_01_NIB_1_3_DQSEL_CAP,
            CTLE_ODD_CAP_LEN = MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0_01_NIB_1_3_DQSEL_CAP_LEN,
            CTLE_ODD_RES = MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0_01_NIB_1_3_DQSEL_RES,
            CTLE_ODD_RES_LEN = MCA_DDRPHY_DP16_CTLE_CTL_BYTE0_P0_0_01_NIB_1_3_DQSEL_RES_LEN,

            RD_VREF_BYTE0_NIB0 = MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB0,
            RD_VREF_BYTE0_NIB0_LEN = MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB0_LEN,
            RD_VREF_BYTE0_NIB1 = MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB1,
            RD_VREF_BYTE0_NIB1_LEN = MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB1_LEN,
            RD_VREF_BYTE1_NIB2 = MCA_DDRPHY_DP16_RD_VREF_BYTE1_DAC_P0_0_01_NIB2,
            RD_VREF_BYTE1_NIB2_LEN = MCA_DDRPHY_DP16_RD_VREF_BYTE1_DAC_P0_0_01_NIB2_LEN,
            RD_VREF_BYTE1_NIB3 = MCA_DDRPHY_DP16_RD_VREF_BYTE1_DAC_P0_0_01_NIB3,
            RD_VREF_BYTE1_NIB3_LEN = MCA_DDRPHY_DP16_RD_VREF_BYTE1_DAC_P0_0_01_NIB3_LEN,

            IO_TX_FET_SLICE = MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0,
            IO_TX_FET_SLICE_EN_N_WR = MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_01_EN_N_WR,
            IO_TX_FET_SLICE_EN_N_WR_LEN = MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_01_EN_N_WR_LEN,
            IO_TX_FET_SLICE_EN_P_WR = MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_01_EN_P_WR,
            IO_TX_FET_SLICE_EN_P_WR_LEN = MCA_DDRPHY_DP16_IO_TX_FET_SLICE_P0_0_01_EN_P_WR_LEN,

            IO_TX_PFET_TERM = MCA_DDRPHY_DP16_IO_TX_PFET_TERM_P0_0,
            IO_TX_PFET_TERM_EN_P_WR = MCA_DDRPHY_DP16_IO_TX_PFET_TERM_P0_0_01_EN_P_WR,
            IO_TX_PFET_TERM_EN_P_WR_LEN = MCA_DDRPHY_DP16_IO_TX_PFET_TERM_P0_0_01_EN_P_WR_LEN,

            GATE_DELAY_LEN = MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_0_01_N0_LEN,
            // Both blue and red waterfalls are the same number of bits
            WATERFALL_LEN = MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT0_LEN,

            // These are only valid on Nimbus DD2 and later
            DD2_WATERFALL_RNG = MCA_DDRPHY_DP16_DRIFT_LIMITS_P0_0_01_DD2_BLUE_EXTEND_RANGE,
            DD2_WATERFALL_RNG_LEN = MCA_DDRPHY_DP16_DRIFT_LIMITS_P0_0_01_DD2_BLUE_EXTEND_RANGE_LEN,

            ////////////////////////////////////////
            // WR VREF register field information //
            ////////////////////////////////////////
            // CONFIG0
            WR_VREF_CONFIG0_1D_ONLY_SWITCH = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_1D_CHICKEN_SWITCH,
            WR_VREF_CONFIG0_FULL_1D = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_RUN_FULL_1D,
            WR_VREF_CONFIG0_2D_SMALL_STEP_VAL    = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_2D_SMALL_STEP_VAL    ,
            WR_VREF_CONFIG0_2D_SMALL_STEP_VAL_LEN = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_2D_SMALL_STEP_VAL_LEN,
            WR_VREF_CONFIG0_2D_BIG_STEP_VAL    = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_2D_BIG_STEP_VAL,
            WR_VREF_CONFIG0_2D_BIG_STEP_VAL_LEN = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_2D_BIG_STEP_VAL_LEN,
            WR_VREF_CONFIG0_NUM_BITS_TO_SKIP    = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_NUM_BITS_TO_SKIP,
            WR_VREF_CONFIG0_NUM_BITS_TO_SKIP_LEN = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_NUM_BITS_TO_SKIP_LEN,
            WR_VREF_CONFIG0_NUM_NO_INC_COMP    = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_NUM_NO_INC_COMP,
            WR_VREF_CONFIG0_NUM_NO_INC_COMP_LEN = MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_NUM_NO_INC_COMP_LEN,

            // CONFIG1
            WR_VREF_CONFIG1_CTR_RANGE_SELECT         = MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_0_01_CTR_RANGE_SELECT,
            WR_VREF_CONFIG1_CTR_RANGE_CROSSOVER      = MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_0_01_CTR_RANGE_CROSSOVER,
            WR_VREF_CONFIG1_CTR_RANGE_CROSSOVER_LEN  = MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_0_01_CTR_RANGE_CROSSOVER_LEN,
            WR_VREF_CONFIG1_CTR_SINGLE_RANGE_MAX     = MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_0_01_CTR_SINGLE_RANGE_MAX,
            WR_VREF_CONFIG1_CTR_SINGLE_RANGE_MAX_LEN = MCA_DDRPHY_DP16_WR_VREF_CONFIG1_P0_0_01_CTR_SINGLE_RANGE_MAX_LEN,

            // ERROR_MASK0/1 - note: all of these are one bit masks for error flags
            WR_VREF_ERROR_MASK_MAX_RANGE_DRAM_EVEN       = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_MAX_RANGE   ,
            WR_VREF_ERROR_MASK_MIN_RANGE_DRAM_EVEN       = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_MIN_RANGE   ,
            WR_VREF_ERROR_MASK_TWO_RANGE_BEST_CASE_DRAM_EVEN = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_TWO_RANGE_BEST_CASE ,
            WR_VREF_ERROR_MASK_BIT_STEP_DELTA_DRAM_EVEN      = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_BIT_STEP_DELTA ,
            WR_VREF_ERROR_MASK_STEP_RANGE_EDGE_DRAM_EVEN     = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_STEP_RANGE_EDGE ,
            WR_VREF_ERROR_MASK_NO_INCREASE_DRAM_EVEN         = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_NO_INCREASE ,
            WR_VREF_ERROR_MASK_1D_EYE_NOISE_DRAM_EVEN        = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_1D_EYE_NOISE ,
            WR_VREF_ERROR_MASK_BAD_BIT_DRAM_EVEN         = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_BAD_BIT   ,
            WR_VREF_ERROR_MASK_MAX_RANGE_MASK_DRAM_ODD       = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_MAX_RANGE_MASK1 ,
            WR_VREF_ERROR_MASK_MIN_RANGE_DRAM_ODD        = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_MIN_RANGE_MASK1 ,
            WR_VREF_ERROR_MASK_TWO_RANGE_BEST_CASE_DRAM_ODD  = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_TWO_RANGE_BEST_CASE_MASK1,
            WR_VREF_ERROR_MASK_BIT_STEP_DELTA_DRAM_ODD       = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_BIT_STEP_DELTA_MASK1 ,
            WR_VREF_ERROR_MASK_STEP_RANGE_EDGE_DRAM_ODD      = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_STEP_RANGE_EDGE_MASK1 ,
            WR_VREF_ERROR_MASK_NO_INCREASE_DRAM_ODD      = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_NO_INCREASE_MASK1 ,
            WR_VREF_ERROR_MASK_1D_EYE_NOISE_DRAM_ODD         = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_1D_EYE_NOISE_MASK1 ,
            WR_VREF_ERROR_MASK_BAD_BIT_DRAM_ODD          = MCA_DDRPHY_DP16_WR_VREF_ERROR_MASK0_P0_0_01_BAD_BIT_MASK1 ,

            // ERROR0/1 - note: all of these are one bit error flags
            WR_VREF_ERROR_MAX_RANGE_DRAM_EVEN           = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_MAX_RANGE_ERR0   ,
            WR_VREF_ERROR_MIN_RANGE_DRAM_EVEN           = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_MIN_RANGE_ERR0   ,
            WR_VREF_ERROR_TWO_RANGE_BEST_CASE_DRAM_EVEN = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_TWO_RANGE_BEST_CASE_ERR0 ,
            WR_VREF_ERROR_BIT_STEP_DELTA_DRAM_EVEN      = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_BIT_STEP_DELTA_ERR0 ,
            WR_VREF_ERROR_STEP_RANGE_EDGE_DRAM_EVEN     = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_STEP_RANGE_EDGE_ERR0 ,
            WR_VREF_ERROR_NO_INCREASE_DRAM_EVEN         = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_NO_INCREASE_ERR0 ,
            WR_VREF_ERROR_1D_EYE_NOISE_DRAM_EVEN        = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_1D_EYE_NOISE_ERR0 ,
            WR_VREF_ERROR_BAD_BIT_DRAM_EVEN             = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_BAD_BIT_ERR0     ,
            WR_VREF_ERROR_MAX_RANGE_MASK_DRAM_ODD       = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_MAX_RANGE_ERR1        ,
            WR_VREF_ERROR_MIN_RANGE_DRAM_ODD            = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_MIN_RANGE_ERR1   ,
            WR_VREF_ERROR_TWO_RANGE_BEST_CASE_DRAM_ODD  = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_TWO_RANGE_BEST_CASE_ERR1 ,
            WR_VREF_ERROR_BIT_STEP_DELTA_DRAM_ODD       = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_BIT_STEP_DELTA_ERR1 ,
            WR_VREF_ERROR_STEP_RANGE_EDGE_DRAM_ODD      = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_STEP_RANGE_EDGE_ERR1 ,
            WR_VREF_ERROR_NO_INCREASE_DRAM_ODD          = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_NO_INCREASE_ERR1 ,
            WR_VREF_ERROR_1D_EYE_NOISE_DRAM_ODD         = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_1D_EYE_NOISE_ERR1 ,
            WR_VREF_ERROR_BAD_BIT_DRAM_ODD              = MCA_DDRPHY_DP16_WR_VREF_ERROR0_P0_0_01_BAD_BIT_ERR1         ,

            // STATUS0
            WR_VREF_STATUS0_WRRD_CNT     = MCA_DDRPHY_DP16_WR_VREF_STATUS0_P0_0_01_CTR_NUM_WRRDREQ_CNT ,
            WR_VREF_STATUS0_WRRD_CNT_LEN = MCA_DDRPHY_DP16_WR_VREF_STATUS0_P0_0_01_CTR_NUM_WRRDREQ_CNT_LEN ,

            // STATUS1
            WR_VREF_STATUS1_VREFREQ_CNT     = MCA_DDRPHY_DP16_WR_VREF_STATUS1_P0_0_01_CTR_NUM_VREFREQ_CNT ,
            WR_VREF_STATUS1_VREFREQ_CNT_LEN = MCA_DDRPHY_DP16_WR_VREF_STATUS1_P0_0_01_CTR_NUM_VREFREQ_CNT_LEN ,
            WR_VREF_STATUS1_CUR_VREF        = MCA_DDRPHY_DP16_WR_VREF_STATUS1_P0_0_01_CTR_CUR      ,
            WR_VREF_STATUS1_CUR_VREF_LEN    = MCA_DDRPHY_DP16_WR_VREF_STATUS1_P0_0_01_CTR_CUR_LEN,

            // VALUE0/1 for all rankpairs
            WR_VREF_VALUE_RANGE_DRAM_EVEN     = MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_0_01_RANGE_DRAM0 ,
            WR_VREF_VALUE_VALUE_DRAM_EVEN     = MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_0_01_VALUE_DRAM0 ,
            WR_VREF_VALUE_VALUE_DRAM_EVEN_LEN = MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_0_01_VALUE_DRAM0_LEN ,
            WR_VREF_VALUE_RANGE_DRAM_ODD      = MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_0_01_RANGE_DRAM1 ,
            WR_VREF_VALUE_VALUE_DRAM_ODD      = MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_0_01_VALUE_DRAM1 ,
            WR_VREF_VALUE_VALUE_DRAM_ODD_LEN  = MCA_DDRPHY_DP16_WR_VREF_VALUE0_RANK_PAIR0_P0_0_01_VALUE_DRAM1_LEN ,

            // Read Delay fields.
            READ_OFFSET_LOWER = MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR0_P0_0_01,
            READ_OFFSET_LOWER_LEN = MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR0_P0_0_01_LEN,
            READ_OFFSET_UPPER = MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR0_P0_0_01_OFFSET1,
            READ_OFFSET_UPPER_LEN = MCA_DDRPHY_DP16_READ_DELAY_OFFSET0_RANK_PAIR0_P0_0_01_OFFSET1_LEN,

            // Read Diagnostic Config 5 (same bit for all MCAs)
            FORCE_FIFO_CAPTURE = MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_0_01_FORCE_FIFO_CAPTURE,

            DATA_BIT_ENABLE0 = MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_0_01_ENABLE_15,
            DATA_BIT_ENABLE0_LEN = MCA_DDRPHY_DP16_DATA_BIT_ENABLE0_P0_0_01_ENABLE_15_LEN,
            DFT_FORCE_OUTPUTS = MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_DFT_FORCE_OUTPUTS,
        };
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
        uint64_t& o_bitfield );

namespace dp16
{

///
/// @brief Read TSYS_DATA
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_tsys_data( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_TRY( mss::getScom(i_target, TT::PR_STATIC_OFFSET_REG[I], o_data) );
    FAPI_INF("tsys_data dp16%d: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write TSYS_DATA
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_tsys_data( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_INF("tsys_data dp16%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::PR_STATIC_OFFSET_REG[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset tsys_data
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode reset_tsys_data( const fapi2::Target<T>& i_target )
{
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_tsys_data = 0;

    FAPI_TRY( mss::vpd_mr_tsys_data(mss::find_target<fapi2::TARGET_TYPE_MCS>(i_target), l_tsys_data) );
    l_data.insertFromRight<TT::TSYS_DATA, TT::TSYS_DATA_LEN>(l_tsys_data);

    for (const auto r : TT::PR_STATIC_OFFSET_REG)
    {
        // TODO RTC:160358 Suspect duplicated scoms in ddr initfile
        FAPI_INF("reset tsys_data 0x%016lx: 0x%016lx", r, l_data);
        FAPI_TRY( mss::putScom(i_target, r, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read DLL_CNTL
/// @tparam I DP16 instance
/// @tparam D DLL instance in the specified DP16
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_dll_cntl( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::DLL_PER_DP16, "dll instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own DLL registers
    const uint64_t& l_addr = (D == 0) ? TT::DLL_CNTRL_REG[I].first : TT::DLL_CNTRL_REG[I].second;

    FAPI_TRY( mss::getScom(i_target, l_addr, o_data) );
    FAPI_INF("dll_cntl dp16<%d, %d>: 0x%016lx", I, D, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write DLL_CNTL
/// @tparam I DP16 instance
/// @tparam D DLL instance in the specified DP16
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_dll_cntl( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::DLL_PER_DP16, "dll instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own DLL registers
    const uint64_t& l_addr = (D == 0) ? TT::DLL_CNTRL_REG[I].first : TT::DLL_CNTRL_REG[I].second;

    FAPI_INF("dll_cntl dp16<%d,%d>: 0x%016lx", I, D, i_data);
    FAPI_TRY( mss::putScom(i_target, l_addr, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset all of the DLL registers - Nimbus only
/// @param[in] i_target an MCA
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_dll( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Read AC_BOOST_CNTL
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam P the type of the std::pair elements
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of both of the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_ac_boost_cntl( const fapi2::Target<T>& i_target,
        std::pair<P, P>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own boost registers
    FAPI_TRY( mss::getScom(i_target, TT::AC_BOOST_CNTRL_REG[I].first, o_data.first) );
    FAPI_TRY( mss::getScom(i_target, TT::AC_BOOST_CNTRL_REG[I].second, o_data.second) );
    FAPI_INF("ac_boost_cntl dp16<%d>: 0x%016lx, 0x%016lx", I, o_data.first, o_data.second);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read AC_BOOST_CNTL
/// @tparam T fapi2 Target Type - derived
/// @tparam P the type of the std::pair elements
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_dp the dp16 instance's index
/// @param[out] o_data the value of both of the the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_ac_boost_cntl( const fapi2::Target<T>& i_target,
        const uint64_t i_dp,
        std::pair<P, P>& o_data )
{
    switch (i_dp)
    {
        case(0):
            return ( read_ac_boost_cntl<0>( i_target, o_data ) );

        case(1):
            return ( read_ac_boost_cntl<1>( i_target, o_data ) );

        case(2):
            return ( read_ac_boost_cntl<2>( i_target, o_data ) );

        case(3):
            return ( read_ac_boost_cntl<3>( i_target, o_data ) );

        case(4):
            return ( read_ac_boost_cntl<4>( i_target, o_data ) );

        default:
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }
}

///
/// @brief Write AC_BOOST_CNTL
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam P the type of the std::pair elements
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of both of the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_ac_boost_cntl( const fapi2::Target<T>& i_target,
        const std::pair<P, P>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own boost registers
    FAPI_INF("ac_boost_cntl dp16<%d>: 0x%016lx, 0x%016lx", I, i_data.first, i_data.second);
    FAPI_TRY( mss::putScom(i_target, TT::AC_BOOST_CNTRL_REG[I].first, i_data.first) );
    FAPI_TRY( mss::putScom(i_target, TT::AC_BOOST_CNTRL_REG[I].second, i_data.second) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write AC_BOOST_CNTL
/// @tparam T fapi2 Target Type - derived
/// @tparam P the type of the std::pair elements
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_dp the dp16 instance's index
/// @param[in] i_data the value of both of the the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_ac_boost_cntl( const fapi2::Target<T>& i_target,
        const uint64_t i_dp,
        const std::pair<P, P>& i_data )
{
    switch (i_dp)
    {
        case(0):
            return ( write_ac_boost_cntl<0>( i_target, i_data ) );

        case(1):
            return ( write_ac_boost_cntl<1>( i_target, i_data ) );

        case(2):
            return ( write_ac_boost_cntl<2>( i_target, i_data ) );

        case(3):
            return ( write_ac_boost_cntl<3>( i_target, i_data ) );

        case(4):
            return ( write_ac_boost_cntl<4>( i_target, i_data ) );

        default:
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }
}

///
/// @brief Reset AC_BOOST_CNTL - for all DP16 in the target
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_ac_boost_cntl( const fapi2::Target<T>& i_target );

///
/// @brief Read CTLE
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam P the type of the std::pair elements
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of both of the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_ctle_cntl( const fapi2::Target<T>& i_target,
        std::pair<P, P>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own boost registers
    FAPI_TRY( mss::getScom(i_target, TT::CTLE_CNTRL_REG[I].first, o_data.first) );
    FAPI_TRY( mss::getScom(i_target, TT::CTLE_CNTRL_REG[I].second, o_data.second) );
    FAPI_INF("ctle_cntl dp16<%d>: 0x%016lx, 0x%016lx", I, o_data.first, o_data.second);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write CTLE
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam P the type of the std::pair elements
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of both of the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_ctle_cntl( const fapi2::Target<T>& i_target,
        const std::pair<P, P>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own boost registers
    FAPI_INF("ctle_cntl dp16<%d>: 0x%016lx, 0x%016lx", I, i_data.first, i_data.second);
    FAPI_TRY( mss::putScom(i_target, TT::CTLE_CNTRL_REG[I].first, i_data.first) );
    FAPI_TRY( mss::putScom(i_target, TT::CTLE_CNTRL_REG[I].second, i_data.second) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset CTLE - for all DP16 in the target
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_ctle_cntl( const fapi2::Target<T>& i_target );

///
/// @brief Set the DLL cal reset (begins DLL cal operations)
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[out] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
/// @note Default state is 'low' as writing a 0 forces the cal to begin.
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_dll_cal_reset( fapi2::buffer<uint64_t>& o_data, const states i_state = mss::LOW )
{
    FAPI_INF("set_dll_cal_reset %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::DLL_CNTL_INIT_RXDLL_CAL_RESET>(i_state);
}

///
/// @brief Set the DLL cal skip reset
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in,out] io_data the value of the register
/// @param[in] i_value the value to write
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_dll_cal_skip( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    FAPI_INF("set_dll_cal_skip to %d", i_value);
    io_data.insertFromRight<TT::DLL_CNTL_INIT_RXDLL_CAL_SKIP,
                            TT::DLL_CNTL_INIT_RXDLL_CAL_SKIP_LEN>(i_value);
}

///
/// @brief Read DATA_BIT_DIR1
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_data_bit_dir1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_TRY( mss::getScom(i_target, TT::DATA_BIT_DIR1_REG[I], o_data) );
    FAPI_INF("data_bit_dir1 dp16%d: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Write DATA_BIT_DIR1
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_data_bit_dir1( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_INF("data_bit_dir1 dp16%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::DATA_BIT_DIR1_REG[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Set the output flush
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[out] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_output_flush( fapi2::buffer<uint64_t>& o_data, const states i_state )
{
    FAPI_INF("set_output_flush %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::FLUSH>(i_state);
}

///
/// @brief Set the init IO state
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[out] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_init_io( fapi2::buffer<uint64_t>& o_data, const states i_state )
{
    FAPI_INF("set_init_io %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::INIT_IO>(i_state);
}

///
/// @brief Set advance_ping_pong
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[out] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_adv_pp( fapi2::buffer<uint64_t>& o_data, const states i_state )
{
    FAPI_INF("set_adv_pp %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::ADV_PP>(i_state);
}

///
/// @brief Set delay ping pong half
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[out] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_delay_pp_half( fapi2::buffer<uint64_t>& o_data, const states i_state )
{
    FAPI_INF("set_delay_pp_half %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::DELAY_PP_HALF>(i_state);
}

///
/// @brief Set the ping pong disable IO state
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in,out] io_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_disable_ping_pong( fapi2::buffer<uint64_t>& io_data, const states i_state )
{
    FAPI_INF("set_init_io %s", (i_state == mss::LOW ? "low" : "high"));
    io_data.writeBit<TT::DISABLE_PING_PONG>(i_state);
}

///
/// @brief Get the ping pong disable IO state
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_data the value of the register
/// @return value of the ping pong disable bit
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline bool get_disable_ping_pong( const fapi2::buffer<uint64_t>& i_data )
{
    return i_data.getBit<TT::DISABLE_PING_PONG>();
}

///
/// @brief Configure the DP16 sysclk
/// @tparam T the fapi2 target type
/// @tparam TT the target traits
/// @param[in] i_target a target
/// @return FAPI2_RC_SUCCESs iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_sysclk( const fapi2::Target<T>& i_target );

///
/// @brief Reset the training delay configureation
/// @tparam T the type of the port
/// @tparam TT the target traits
/// @param[in] i_target the port target
/// @param[in] l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_delay_values( const fapi2::Target<T>& i_target,
                                      const std::vector< uint64_t >& l_rank_pairs );

///
/// @brief Reset the read clock enable registers
/// @tparam T the type of the port
/// @tparam TT the target traits
/// @param[in] i_target a port target
/// @param[in] l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_read_clock_enable( const fapi2::Target<T>& i_target,
        const std::vector< uint64_t >& l_rank_pairs );

///
/// @brief Resets the write clock enable registers
/// @tparam T the type of the port
/// @tparam TT the target traits
/// @param[in] i_target  a port target
/// @param[in] l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_write_clock_enable( const fapi2::Target<T>& i_target,
        const std::vector< uint64_t >& l_rank_pairs );

///
/// @brief Reset the data bit enable registers
/// @tparam T the type of the port
/// @tparam TT the target traits
/// @param[in] i_target a port target
/// @return FAPI2_RC_SUCCESs iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_data_bit_enable( const fapi2::Target<T>& i_target );


///
/// @brief Reset the bad-bits masks for a port
/// @note Read the bad bits from the f/w attributes and stuff them in the
/// appropriate registers.
/// @param[in] i_target the fapi2 target of the port
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode reset_bad_bits(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Reset the bad-bits masks for a port - helper for testing
/// @note The magic 10 is because there are 80 bits represented in this attribute, and each element is 8 bits.
/// So to get to 80, we need 10 bytes.
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_bad_dq array representing the data from the bad dq bitmap
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode reset_bad_bits_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint8_t i_bad_dq[MAX_RANK_PER_DIMM][BAD_DQ_BYTE_COUNT]);

///
/// @brief Configure the DP16 io_tx config0 registers
/// @tparam T the fapi2::TargetType
/// @tparam TT the target traits
/// @param[in] i_target a fapi2 target
/// @return FAPI2_RC_SUCCESs iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_io_tx_config0( const fapi2::Target<T>& i_target );

///
/// @brief Configure ADR DLL/VREG Config 1
/// @tparam T the fapi2::TargetType
/// @tparam TT the target traits
/// @param[in] i_target a fapi2 target
/// @return FAPI2_RC_SUCCESs iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_dll_vreg_config1( const fapi2::Target<T>& i_target );

///
/// @brief Configure Read VREF Registers
/// @tparam T the fapi2::TargetType
/// @tparam TT the target traits
/// @param[in] i_target a fapi2 target
/// @return FAPI2_RC_SUCCESs iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_rd_vref( const fapi2::Target<T>& i_target );

///
/// Specializations
///

///
/// @brief Configure the DP16 sysclk
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_sysclk( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Reset the training delay configureation
/// @param[in] i_target the port target
/// @param[in]  l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_delay_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                      const std::vector< uint64_t >& l_rank_pairs );

///
/// @brief Reset the read clock enable registers
/// @param[in] i_target a port target
/// @param[in] l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_read_clock_enable( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const std::vector< uint64_t >& l_rank_pairs );

///
/// @brief Reset the write clock enable registers
/// @param[in] i_target a port target
/// @param[in] l_rank_pairs vector of rank pairs
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_write_clock_enable( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const std::vector< uint64_t >& l_rank_pairs );

///
/// @brief Reset the data bit enable registers
/// @param[in] i_target a port target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_data_bit_enable( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Configure the DP16 io_tx config0 registers
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_io_tx_config0( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Configure ADR DLL/VREG Config 1
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_dll_vreg_config1( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Configure Read VREF Registers
/// @param[in] i_target a MCA target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode reset_rd_vref( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief sets up the DQ/DQS driver impedances
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_dq_dqs_drv_imp( const fapi2::Target<T>& i_target );

///
/// @brief sets the register value for DQ/DQS driver impedance from the VPD value
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @param[out] o_reg_value values to push into the registers
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode get_dq_dqs_drv_imp_field_value( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint8_t>* o_reg_value );

///
/// @brief Read dq_dqs_drv_imp
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of both of the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_dq_dqs_drv_imp( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    //one register per DP
    FAPI_TRY( mss::getScom(i_target, TT::IO_TX_FET_SLICE_REG[I], o_data) );
    FAPI_INF("dq_dqs_drv_imp dp16<%d>: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write dq_dqs_drv_imp
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of both of the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_dq_dqs_drv_imp( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    //one register per DP
    FAPI_INF("dq_dqs_drv_imp dp16<%d>: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::IO_TX_FET_SLICE_REG[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief sets up the DQ/DQS receiver impedances
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_dq_dqs_rcv_imp( const fapi2::Target<T>& i_target );

///
/// @brief sets the register value for DQ/DQS receiver impedance from the VPD value
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @param[out] o_reg_value values to push into the registers
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode get_dq_dqs_rcv_imp_field_value( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint8_t>* o_reg_value );

///
/// @brief Read dq_dqs_rcv_imp
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of both of the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_dq_dqs_rcv_imp( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    //one register per DP
    FAPI_TRY( mss::getScom(i_target, TT::IO_TX_PFET_TERM_REG[I], o_data) );
    FAPI_INF("dq_dqs_rcv_imp dp16<%d>: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write dq_dqs_rcv_imp
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of both of the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_dq_dqs_rcv_imp( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    //one register per DP
    FAPI_INF("dq_dqs_rcv_imp dp16<%d>: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::IO_TX_PFET_TERM_REG[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read DRIFT_LIMITS
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_drift_limits( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_TRY( mss::getScom(i_target, TT::DRIFT_LIMITS_REG[I], o_data) );
    FAPI_INF("drift_limits dp16<%d>: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read DRIFT_LIMITS
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_dp the DP16 instance
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_drift_limits( const fapi2::Target<T>& i_target,
        const uint64_t i_dp,
        fapi2::buffer<uint64_t>& o_data )
{
    switch (i_dp)
    {
        case(0):
            return ( read_drift_limits<0>(i_target, o_data) );

        case(1):
            return ( read_drift_limits<1>(i_target, o_data) );

        case(2):
            return ( read_drift_limits<2>(i_target, o_data) );

        case(3):
            return ( read_drift_limits<3>(i_target, o_data) );

        case(4):
            return ( read_drift_limits<4>(i_target, o_data) );

        default:
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }
}

///
/// @brief Write DRIFT_LIMITS
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_drift_limits( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_INF("drift_limits dp16<%d>: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::DRIFT_LIMITS_REG[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write DRIFT_LIMITS
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_dp the DP16 instance
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_drift_limits( const fapi2::Target<T>& i_target,
        const uint64_t i_dp,
        const fapi2::buffer<uint64_t>& i_data )
{
    switch (i_dp)
    {
        case(0):
            return ( write_drift_limits<0>(i_target, i_data) );

        case(1):
            return ( write_drift_limits<1>(i_target, i_data) );

        case(2):
            return ( write_drift_limits<2>(i_target, i_data) );

        case(3):
            return ( write_drift_limits<3>(i_target, i_data) );

        case(4):
            return ( write_drift_limits<4>(i_target, i_data) );

        default:
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }
}

///
/// @brief Reset blue waterfall range in DRIFT_LIMITS register
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_drift_limits( const fapi2::Target<T>& i_target );

////////////////////////////////////////
//   all the WR VREF scom accessors   //
////////////////////////////////////////
///
/// @brief Read WR_VREF_CONFIG0 register
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_config0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_TRY( mss::getScom(i_target, TT::WR_VREF_CONFIG0_REG[I], o_data) );
    FAPI_INF("WR VREF config0 dp16%d: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WR_VREF_CONFIG1 register
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_config1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_TRY( mss::getScom(i_target, TT::WR_VREF_CONFIG1_REG[I], o_data) );
    FAPI_INF("WR VREF config1 dp16%d: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WR_VREF_STATUS0 register
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_status0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_TRY( mss::getScom(i_target, TT::WR_VREF_STATUS0_REG[I], o_data) );
    FAPI_INF("WR VREF status0 dp16%d: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WR_VREF_STATUS1 register
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_status1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_TRY( mss::getScom(i_target, TT::WR_VREF_STATUS1_REG[I], o_data) );
    FAPI_INF("WR VREF status1 dp16%d: 0x%016lx", I, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WR_VREF_ERROR_MASK register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_error_mask( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_ERROR_MASK_REG[I].first : TT::WR_VREF_ERROR_MASK_REG[I].second);
    FAPI_TRY( mss::getScom(i_target, l_addr, o_data) );

    FAPI_INF("WR VREF Error mask reg dp16%d, DRAM%d: 0x%016lx", I, D, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WR_VREF_ERROR register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_error( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_ERROR_REG[I].first : TT::WR_VREF_ERROR_REG[I].second);
    FAPI_TRY( mss::getScom(i_target, l_addr, o_data) );

    FAPI_INF("WR VREF Error reg dp16%d, DRAM%d: 0x%016lx", I, D, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WR_VREF_VALUE_RP0 register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_value_rp0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_VALUE_RP0_REG[I].first : TT::WR_VREF_VALUE_RP0_REG[I].second);
    FAPI_TRY( mss::getScom(i_target, l_addr, o_data) );

    FAPI_INF("WR VREF Value reg RP0 dp16%d, DRAM%d: 0x%016lx", I, D, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WR_VREF_VALUE_RP1 register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_value_rp1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_VALUE_RP1_REG[I].first : TT::WR_VREF_VALUE_RP1_REG[I].second);
    FAPI_TRY( mss::getScom(i_target, l_addr, o_data) );

    FAPI_INF("WR VREF Value reg RP1 dp16%d, DRAM%d: 1x%116lx", I, D, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WR_VREF_VALUE_RP2 register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_value_rp2( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_VALUE_RP2_REG[I].first : TT::WR_VREF_VALUE_RP2_REG[I].second);
    FAPI_TRY( mss::getScom(i_target, l_addr, o_data) );

    FAPI_INF("WR VREF Value reg RP2 dp16%d, DRAM%d: 2x%216lx", I, D, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read WR_VREF_VALUE_RP3 register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_wr_vref_value_rp3( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_VALUE_RP3_REG[I].first : TT::WR_VREF_VALUE_RP3_REG[I].second);
    FAPI_TRY( mss::getScom(i_target, l_addr, o_data) );

    FAPI_INF("WR VREF Value reg RP3 dp16%d, DRAM%d: 3x%316lx", I, D, o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_CONFIG0 register
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_config0( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_INF("WR VREF config0 dp16%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::WR_VREF_CONFIG0_REG[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_CONFIG1 register
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_config1( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_INF("WR VREF config1 dp16%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::WR_VREF_CONFIG1_REG[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_STATUS0 register
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_status0( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_INF("WR VREF status0 dp16%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::WR_VREF_STATUS0_REG[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_STATUS1 register
/// @tparam I DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_status1( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    FAPI_INF("WR VREF status1 dp16%d: 0x%016lx", I, i_data);
    FAPI_TRY( mss::putScom(i_target, TT::WR_VREF_STATUS1_REG[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_ERROR_MASK register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_error_mask( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    FAPI_INF("WR VREF Error mask reg dp16%d, DRAM%d: 0x%016lx", I, D, i_data);

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_ERROR_MASK_REG[I].first : TT::WR_VREF_ERROR_MASK_REG[I].second);
    FAPI_TRY( mss::putScom(i_target, l_addr, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_ERROR register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_error( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    FAPI_INF("WR VREF Error reg dp16%d, DRAM%d: 0x%016lx", I, D, i_data);

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_ERROR_REG[I].first : TT::WR_VREF_ERROR_REG[I].second);
    FAPI_TRY( mss::putScom(i_target, l_addr, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_VALUE_RP0 register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_value_rp0( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    FAPI_INF("WR VREF Value reg RP0 dp16%d, DRAM%d: 0x%016lx", I, D, i_data);

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_VALUE_RP0_REG[I].first : TT::WR_VREF_VALUE_RP0_REG[I].second);
    FAPI_TRY( mss::putScom(i_target, l_addr, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_VALUE_RP1 register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_value_rp1( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    FAPI_INF("WR VREF Value reg RP1 dp16%d, DRAM%d: 1x%116lx", I, D, i_data);

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_VALUE_RP1_REG[I].first : TT::WR_VREF_VALUE_RP1_REG[I].second);
    FAPI_TRY( mss::putScom(i_target, l_addr, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_VALUE_RP2 register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_value_rp2( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    FAPI_INF("WR VREF Value reg RP2 dp16%d, DRAM%d: 2x%216lx", I, D, i_data);

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_VALUE_RP2_REG[I].first : TT::WR_VREF_VALUE_RP2_REG[I].second);
    FAPI_TRY( mss::putScom(i_target, l_addr, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write WR_VREF_VALUE_RP3 register
/// @tparam I DP16 instance
/// @tparam D DRAM within the DP16 instance
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value to set into the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, uint64_t D, fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_wr_vref_value_rp3( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");
    static_assert( D < TT::MAX_DRAM_PER_DP, "number of DRAM out of range");

    FAPI_INF("WR VREF Value reg RP3 dp16%d, DRAM%d: 3x%316lx", I, D, i_data);

    // DRAM 0/1 vs 2/s's address
    const uint64_t l_addr = ((D < 2) ? TT::WR_VREF_VALUE_RP3_REG[I].first : TT::WR_VREF_VALUE_RP3_REG[I].second);
    FAPI_TRY( mss::putScom(i_target, l_addr, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

////////////////////////////////////////////////////
// reset procedures for all the WR VREF registers //
////////////////////////////////////////////////////
///
/// @brief Reset wr vref config0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_config0( const fapi2::Target<T>& i_target );

///
/// @brief Reset wr vref config1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_config1( const fapi2::Target<T>& i_target );

///
/// @brief Reset wr vref status0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_status0( const fapi2::Target<T>& i_target );

///
/// @brief Reset wr vref status1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_status1( const fapi2::Target<T>& i_target );

///
/// @brief Reset wr vref error_mask
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_error_mask( const fapi2::Target<T>& i_target );

///
/// @brief Reset wr vref error
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_error( const fapi2::Target<T>& i_target );

///
/// @brief Reset wr vref value rank pair 0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_value_rp0( const fapi2::Target<T>& i_target );

///
/// @brief Reset wr vref value rank pair 1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_value_rp1( const fapi2::Target<T>& i_target );

///
/// @brief Reset wr vref value rank pair 2
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_value_rp2( const fapi2::Target<T>& i_target );

///
/// @brief Reset wr vref value rank pair3
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_value_rp3( const fapi2::Target<T>& i_target );


///
/// @brief Resets all WR VREF registers
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_wr_vref_registers( const fapi2::Target<T>& i_target );

///
/// @brief Resets all read delay offset registers
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
// TODO RTC:162136 implement read, write, set and get for the read delay offset registers
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode reset_read_delay_offset_registers( const fapi2::Target<T>& i_target );

///
/// @brief Process disable bits
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_dimm the fapi2 target of the failed DIMM
/// @param[in] i_rp the rank pairs to check as a bit-map
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode process_bad_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                                    const uint64_t l_rp );

///
/// @brief Write disable bits
/// @note This is different than a register write as it writes attributes which
/// cause firmware to act on the disabled bits.
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode record_bad_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Write disable bits - helper for testing
/// @note This is different than a register write as it writes attributes which
/// cause firmware to act on the disabled bits.
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_bad_dq an array of [MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM][BAD_DQ_BYTE_COUNT] containing the attribute information
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode record_bad_bits_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&o_bad_dq)[MAX_RANK_PER_DIMM][BAD_DQ_BYTE_COUNT] );

///
/// @brief Process read vref calibration errors
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode process_rdvref_cal_errors( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Process write vref calibration errors
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
fapi2::ReturnCode process_wrvref_cal_errors( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Write FORCE_FIFO_CAPTURE
/// Force DQ capture in Read FIFO to support DDR4 LRDIMM calibration
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_state mss::states::ON or mss::states::OFF
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note '1'b Forces DQ capture in Read FIFO to support DDR4 LRDIMM calibration.
/// '0'b Normal operation
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode write_force_dq_capture( const fapi2::Target<T>& i_target,
        const mss::states i_state);

///
/// @brief Write DATA_BIT_ENABLE0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_state mss::states::ON or mss::states::OFF
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode write_data_bit_enable0( const fapi2::Target<T>& i_target,
        const mss::states i_state);

///
/// @brief Write DFT_FORCE_OUTPUTS
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_state mss::states::ON or mss::states::OFF
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode write_dft_force_outputs( const fapi2::Target<T>& i_target,
        const mss::states i_state);

///
/// @brief Get the blue waterfall for the given quad
/// @tparam uint64_t QUAD - which quad to access
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_data the value of the register
/// @return value of the blue waterfall
///
template< uint64_t QUAD, fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline uint64_t get_blue_waterfall( const fapi2::buffer<uint64_t>& i_data )
{

    static_assert(QUAD < TT::NUM_QUAD_PER_DP16, "Inserted quad value is not less than the maximum value");
    uint64_t l_waterfall = 0;
    i_data.extractToRight<TT::BLUE_WATERFALL_BIT_POS[QUAD], TT::WATERFALL_LEN>(l_waterfall);
    return l_waterfall;
}

///
/// @brief Get the gate delay for the given quad
/// @tparam uint64_t QUAD - which quad to access
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_data the value of the register
/// @return value of the gate delay
///
template< uint64_t QUAD, fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline uint64_t get_gate_delay( const fapi2::buffer<uint64_t>& i_data )
{

    static_assert(QUAD < TT::NUM_QUAD_PER_DP16, "Inserted quad value is not less than the maximum value");
    uint64_t l_gate_delay = 0;
    i_data.extractToRight<TT::GATE_DELAY_BIT_POS[QUAD], TT::GATE_DELAY_LEN>(l_gate_delay);
    return l_gate_delay;
}

///
/// @brief Set the blue waterfall for the given quad
/// @tparam uint64_t QUAD - which quad to access
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in,out] io_data the value of the register
/// @param[in] value of the blue waterfall
///
template< uint64_t QUAD, fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_blue_waterfall( fapi2::buffer<uint64_t>& io_data, const uint64_t i_waterfall )
{

    static_assert(QUAD < TT::NUM_QUAD_PER_DP16, "QUAD value is not less than the maximum value");
    io_data.insertFromRight<TT::BLUE_WATERFALL_BIT_POS[QUAD], TT::WATERFALL_LEN>(i_waterfall);
}

///
/// @brief Set the gate delay for the given quad
/// @tparam uint64_t QUAD - which quad to access
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in,out] io_data the value of the register
/// @param[in] value of the gate delay
///
template< uint64_t QUAD, fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_gate_delay( fapi2::buffer<uint64_t>& io_data, const uint64_t i_gate_delay )
{

    static_assert(QUAD < TT::NUM_QUAD_PER_DP16, "QUAD value is not less than the maximum value");
    io_data.insertFromRight<TT::GATE_DELAY_BIT_POS[QUAD], TT::GATE_DELAY_LEN>(i_gate_delay);
}

///
/// @brief Get the blue waterfall extended range setting (DD2 and later only)
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @param[out] o_value the enumerated value of the range
/// @note this will return the ZERO_TO_THREE enumeration for DD1
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline void get_blue_waterfall_range( const fapi2::Target<T>& i_target,
                                      const fapi2::buffer<uint64_t>& i_data,
                                      blue_waterfall_range& o_value )
{
    if (mss::chip_ec_nimbus_lt_2_0(i_target))
    {
        o_value = blue_waterfall_range::ZERO_TO_THREE;
        FAPI_ERR("get_blue_waterfall_range called on DD1 part");
        return;
    }

    uint64_t l_out = 0;
    i_data.extractToRight<TT::DD2_WATERFALL_RNG, TT::DD2_WATERFALL_RNG_LEN>(l_out);
    FAPI_INF("get_blue_waterfall_range: 0x%01lx", l_out);
    o_value = static_cast<blue_waterfall_range>(l_out);
}

///
/// @brief Set the blue waterfall extended range setting (DD2 and later only)
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in, out] io_data the value of the register
/// @param[in] i_value the enumerated value of the range
/// @note this will do nothing for a DD1 part
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline void set_blue_waterfall_range( const fapi2::Target<T>& i_target,
                                      fapi2::buffer<uint64_t>& io_data,
                                      const blue_waterfall_range i_value )
{
    if (mss::chip_ec_nimbus_lt_2_0(i_target))
    {
        FAPI_ERR("set_blue_waterfall_range called on DD1 part");
        return;
    }

    io_data.insertFromRight<TT::DD2_WATERFALL_RNG, TT::DD2_WATERFALL_RNG_LEN>(i_value);
    FAPI_INF("set_blue_waterfall_range: 0x%01lx", i_value);
}

///
/// @brief Set RX_CONFIG0_P0_DP16_0_READ_CENTERING_MODE
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
fapi2::ReturnCode setup_custom_read_centering_mode( const fapi2::Target<T>& i_target );

///
/// @brief Reset rd_lvl_status0 registers
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode reset_rd_lvl_status0( const fapi2::Target<T>& i_target )
{
    FAPI_TRY(mss::scom_blastah(i_target, TT::RD_LVL_STATUS0_REG, 0));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset rd_lvl_status2 registers
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode reset_rd_lvl_status2( const fapi2::Target<T>& i_target )
{
    FAPI_TRY(mss::scom_blastah(i_target, TT::RD_LVL_STATUS2_REG, 0));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset rd_status0 registers
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode reset_rd_status0( const fapi2::Target<T>& i_target )
{
    FAPI_TRY(mss::scom_blastah(i_target, TT::RD_STATUS0_REG, 0));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reset wr_error0 registers
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode reset_wr_error0( const fapi2::Target<T>& i_target )
{
    FAPI_TRY(mss::scom_blastah(i_target, TT::WR_ERROR0_REG, 0));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Resets the RD VREF error registers
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode reset_rd_vref_errors( const fapi2::Target<T>& i_target )
{
    // Indiscrementantly blast all errors to 0's
    FAPI_TRY(mss::scom_blastah(i_target, TT::RD_VREF_CAL_ERROR_REG, 0));

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace dp16
} // close namespace mss

#endif
