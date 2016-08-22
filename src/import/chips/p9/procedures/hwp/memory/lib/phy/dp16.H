/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/dp16.H $    */
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
/// @file dp16.H
/// @brief Subroutines to control the DP16 logic blocks
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_DP16_H_
#define _MSS_DP16_H_

#include <vector>
#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/utils/scom.H>

namespace mss
{

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
        static const std::vector< std::pair<uint64_t, uint64_t> > DLL_CNFG_REG;
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
        static const std::vector< std::pair<uint64_t, uint64_t> > RD_VREF_CNTRL_REG;
        static const std::vector< uint64_t > DATA_BIT_DIR1;

        enum
        {
            DLL_CNTL_INIT_RXDLL_CAL_RESET = MCA_DDRPHY_DP16_DLL_CNTL0_P0_0_01_INIT_RXDLL_CAL_RESET,
            FLUSH = MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_01_FLUSH,
            INIT_IO = MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_0_01_INIT_IO,

            // Seriously PHY guys?
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

    // The pair represents the upper and lower bytes of the DP16 - each has its own DLL regiters
    const uint64_t& l_addr = (D == 0) ? TT::DLL_CNFG_REG[I].first : TT::DLL_CNFG_REG[I].second;

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

    // The pair represents the upper and lower bytes of the DP16 - each has its own DLL regiters
    const uint64_t& l_addr = (D == 0) ? TT::DLL_CNFG_REG[I].first : TT::DLL_CNFG_REG[I].second;

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
/// @param[out] o_data the value of both of the the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_ac_boost_cntl( const fapi2::Target<T>& i_target,
        std::pair<P, P>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own boost regiters
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
/// @param[in] i_data the value of both of the the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_ac_boost_cntl( const fapi2::Target<T>& i_target,
        const std::pair<P, P>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own boost regiters
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
/// @param[out] o_data the value of both of the the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode read_ctle_cntl( const fapi2::Target<T>& i_target,
        std::pair<P, P>& o_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own boost regiters
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
/// @param[in] i_data the value of both of the the registers (upper and lower bytes)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t I, fapi2::TargetType T, typename P, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode write_ctle_cntl( const fapi2::Target<T>& i_target,
        const std::pair<P, P>& i_data )
{
    static_assert( I < TT::DP_COUNT, "dp16 instance out of range");

    // The pair represents the upper and lower bytes of the DP16 - each has its own boost regiters
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
/// @param[in] o_data the value of the register
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

    FAPI_TRY( mss::getScom(i_target, TT::DATA_BIT_DIR1[I], o_data) );
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
    FAPI_TRY( mss::putScom(i_target, TT::DATA_BIT_DIR1[I], i_data) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Set the output flush
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
/// @note Default state is 'low' as writing a 0 forces the cal to begin.
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_output_flush( fapi2::buffer<uint64_t>& o_data, const states i_state )
{
    FAPI_INF("set_output_flush %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::FLUSH>(i_state);
}

///
/// @brief Set the init io state
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] o_data the value of the register
/// @param[in] i_state mss::LOW or mss::HIGH representing the state of the bit
/// @note Default state is 'low' as writing a 0 forces the cal to begin.
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dp16Traits<T> >
inline void set_init_io( fapi2::buffer<uint64_t>& o_data, const states i_state )
{
    FAPI_INF("set_init_io %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::INIT_IO>(i_state);
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
/// @tparam T the fapi2::TargetType
/// @tparam TT the target traits
/// @param[in] i_target the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T, typename TT = dp16Traits<T> >
inline fapi2::ReturnCode reset_bad_bits(const fapi2::Target<T>& i_target);

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
/// @brief Reset the bad-bits masks for a port
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode reset_bad_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    // Note: We need to do this ... BRS
    return fapi2::FAPI2_RC_SUCCESS;
}

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

} // close namespace dp16
} // close namespace mss

#endif
