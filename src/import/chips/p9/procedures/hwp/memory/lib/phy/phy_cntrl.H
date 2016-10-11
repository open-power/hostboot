/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/phy_cntrl.H $ */
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
/// @file phy_cntrl.H
/// @brief Subroutines for the PHY phy control registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_PHY_CNTRL_H_
#define _MSS_PHY_CNTRL_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/shared/mss_const.H>
#include <lib/utils/scom.H>

namespace mss
{

// I have a dream that the PHY code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class pcTraits
/// @brief a collection of traits associated with the PHY phy control
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class pcTraits;

///
/// @class pcTraits
/// @brief a collection of traits associated with the Centaur PHY
///
template<>
class pcTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class pcTraits
/// @brief a collection of traits associated with the Nimbus PHY phy control
///
template<>
class pcTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        // MCA phy control registers
        static const uint64_t PC_ERROR_STATUS0_REG = MCA_DDRPHY_PC_ERROR_STATUS0_P0;
        static const uint64_t PC_INIT_CAL_ERROR_REG = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0;
        static const uint64_t PC_DLL_ZCAL_CAL_STATUS_REG = MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS_P0;
        static const uint64_t PC_RESETS_REG = MCA_DDRPHY_PC_RESETS_P0;
        static const uint64_t PC_CONFIG0_REG = MCA_DDRPHY_PC_CONFIG0_P0;
        static const uint64_t PC_CONFIG1_REG = MCA_DDRPHY_PC_CONFIG1_P0;

        enum
        {
            INIT_CAL_ERROR_WR_LEVEL = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_WR_LEVEL,
            INIT_CAL_ERROR_INITIAL_PAT_WRITE = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_INITIAL_PAT_WRITE,
            INIT_CAL_ERROR_DQS_ALIGN = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_DQS_ALIGN,
            INIT_CAL_ERROR_RDCLK_ALIGN = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RDCLK_ALIGN,
            INIT_CAL_ERROR_READ_CTR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_READ_CTR,
            INIT_CAL_ERROR_WRITE_CTR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_WRITE_CTR,
            INIT_CAL_ERROR_INITIAL_COARSE_WR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_INITIAL_COARSE_WR,
            INIT_CAL_ERROR_COARSE_RD = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_COARSE_RD,
            INIT_CAL_ERROR_CUSTOM_RD = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_CUSTOM_RD,
            INIT_CAL_ERROR_CUSTOM_WR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_CUSTOM_WR,
            INIT_CAL_ERROR_DIGITAL_EYE = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_DIGITAL_EYE,
            INIT_CAL_ERROR_VREF = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_VREF,
            INIT_CAL_ERROR_RANK_PAIR = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RANK_PAIR,
            INIT_CAL_ERROR_RANK_PAIR_LEN = MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RANK_PAIR_LEN,

            // How many bits are in the field running from INIT_CAL_ERROR_WR_LEVEL to INIT_CAL_ERROR_VREF
            // Needed to pull the entire field out of the register.
            CAL_ERROR_FIELD_LEN = 11,

            DLL_CAL_STATUS_DP_GOOD = MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS_P0_DP_GOOD,
            DLL_CAL_STATUS_DP_ERROR = MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS_P0_DP_ERROR,
            DLL_CAL_STATUS_DP_ERROR_FINE = MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS_P0_DP_ERROR_FINE,
            DLL_CAL_STATUS_ADR_GOOD = MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS_P0_ADR_GOOD,
            DLL_CAL_STATUS_ADR_ERROR = MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS_P0_ADR_ERROR,
            DLL_CAL_STATUS_ADR_ERROR_FINE = MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS_P0_ADR_ERROR_FINE,
            ZCAL_CAL_STATUS_DONE = MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS_P0_DONE,

            SYSCLK_RESET = MCA_DDRPHY_PC_RESETS_P0_SYSCLK_RESET,
            PVT_OVERRIDE = MCA_DDRPHY_PC_RESETS_P0_PVT_OVERRIDE,
            ENABLE_ZCAL = MCA_DDRPHY_PC_RESETS_P0_ENABLE_ZCAL,

            WRITE_LATENCY_OFFSET = MCA_DDRPHY_PC_CONFIG1_P0_WRITE_LATENCY_OFFSET,
            WRITE_LATENCY_OFFSET_LEN = MCA_DDRPHY_PC_CONFIG1_P0_WRITE_LATENCY_OFFSET_LEN,
            READ_LATENCY_OFFSET = MCA_DDRPHY_PC_CONFIG1_P0_READ_LATENCY_OFFSET,
            READ_LATENCY_OFFSET_LEN = MCA_DDRPHY_PC_CONFIG1_P0_READ_LATENCY_OFFSET_LEN,
            MEMCTL_CIC_FAST = MCA_DDRPHY_PC_CONFIG1_P0_MEMCTL_CIC_FAST,
            MEMCTL_CTRN_IGNORE = MCA_DDRPHY_PC_CONFIG1_P0_MEMCTL_CTRN_IGNORE,
            DISABLE_MEMCTL_CAL = MCA_DDRPHY_PC_CONFIG1_P0_DISABLE_MEMCTL_CAL,
            MEMORY_TYPE = MCA_DDRPHY_PC_CONFIG1_P0_MEMORY_TYPE,
            MEMORY_TYPE_LEN = MCA_DDRPHY_PC_CONFIG1_P0_MEMORY_TYPE_LEN,
            DDR4_LATENCY_SW = MCA_DDRPHY_PC_CONFIG1_P0_DDR4_LATENCY_SW,
            RETRAIN_PERCAL_SW = MCA_DDRPHY_PC_CONFIG1_P0_RETRAIN_PERCAL_SW,


//            // PC Config0 Protocol has been re-purposed for PDA enable.
//            // repurposed to pda_enable_override, so zero per John Bialas 4/16 JJM
//            PDA_ENABLE = MCA_DDRPHY_PC_CONFIG0_P0_PROTOCOL,
//            PDA_ENABLE_LEN = MCA_DDRPHY_PC_CONFIG0_P0_PROTOCOL_LEN,

            DATA_MUX4_1MODE = MCA_DDRPHY_PC_CONFIG0_P0_DATA_MUX4_1MODE,
            DDR4_CMD_SIG_REDUCTION = MCA_DDRPHY_PC_CONFIG0_P0_DDR4_CMD_SIG_REDUCTION,
            SYSCLK_2X_MEMINTCLKO = MCA_DDRPHY_PC_CONFIG0_P0_SYSCLK_2X_MEMINTCLKO,
            RANK_OVERRIDE = MCA_DDRPHY_PC_CONFIG0_P0_RANK_OVERRIDE,
            RANK_OVERRIDE_VALUE = MCA_DDRPHY_PC_CONFIG0_P0_RANK_OVERRIDE_VALUE,
            RANK_OVERRIDE_VALUE_LEN = MCA_DDRPHY_PC_CONFIG0_P0_RANK_OVERRIDE_VALUE_LEN,
            LOW_LATENCY = MCA_DDRPHY_PC_CONFIG0_P0_LOW_LATENCY,
            DDR4_IPW_LOOP_DIS = MCA_DDRPHY_PC_CONFIG0_P0_DDR4_IPW_LOOP_DIS,
            DDR4_VLEVEL_BANK_GROUP = MCA_DDRPHY_PC_CONFIG0_P0_DDR4_VLEVEL_BANK_GROUP,
            VPROTH_PSEL_MODE = MCA_DDRPHY_PC_CONFIG0_P0_VPROTH_PSEL_MODE,
        };

};

namespace pc
{

///
/// @brief read PC_CONFIG1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode read_config1( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::PC_CONFIG1_REG, o_data) );
    FAPI_INF("pc_config1: 0x%016llx", o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write PC_CONFIG1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode write_config1( const fapi2::Target<T>& i_target,
                                        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_INF("pc_config1: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::PC_CONFIG1_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset pc_config1
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
fapi2::ReturnCode reset_config1( const fapi2::Target<T>& i_target );

///
/// @brief read PC_CONFIG0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode read_config0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::PC_CONFIG0_REG, o_data) );
    FAPI_INF("pc_config0: 0x%016llx", o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write PC_CONFIG0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode write_config0( const fapi2::Target<T>& i_target,
                                        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_INF("pc_config0: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::PC_CONFIG0_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset pc_config0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
fapi2::ReturnCode reset_config0( const fapi2::Target<T>& i_target );

///
/// @brief read MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode read_dll_zcal_status( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::PC_DLL_ZCAL_CAL_STATUS_REG, o_data) );
    FAPI_INF("pc_dll_zcal_status: 0x%016llx", o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get DP DLL Cal Status
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// Combine the processing of Good, Error and Error Fine into one functional interface
/// @param[in] fapi2::buffer representing the status register to interrogate
/// @return mss::states; YES == success, NO == fail, INVALID == still running
/// @note Since the these indicators are a summary of all DLLs, all must be started to make
/// them valid.
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = pcTraits<T> >
inline mss::states get_dll_cal_status( fapi2::buffer<uint64_t>& i_data )
{
    const bool l_dp_good =  i_data.getBit<TT::DLL_CAL_STATUS_DP_GOOD>();
    const bool l_dp_error = i_data.getBit<TT::DLL_CAL_STATUS_DP_ERROR>();
    const bool l_dp_error_fine = i_data.getBit<TT::DLL_CAL_STATUS_DP_ERROR_FINE>();

    FAPI_INF("pc_dll_status: 0x%016llx", i_data);

    // Full calibration is still going on in at least 1 DLL while all 3 signals are 0.
    if ((l_dp_good == mss::LOW) && (l_dp_error == mss::LOW) && (l_dp_error_fine == mss::LOW))
    {
        return mss::INVALID;
    }

    // Full calibration was successful in all DLLs if CAL_GOOD = 1 and both CAL_ERROR and CAL_ERROR_FINE are 0.
    if ((l_dp_good == mss::HIGH) && (l_dp_error == mss::LOW) && (l_dp_error_fine == mss::LOW))
    {
        return mss::YES;
    }

    // Full calibration failed in at least 1 DLL if either CAL_ERROR or CAL_ERROR_FINE are 1.
    // Full calibration was successful in all DLLs if CAL_GOOD = 1 and both CAL_ERROR and CAL_ERROR_FINE are 0.
    if ((l_dp_error == mss::HIGH) || (l_dp_error_fine == mss::HIGH))
    {
        return mss::NO;
    }

    // Not reached ... right?
    FAPI_ERR("pc_dll_cal_status: 0x%016llx unable to calculate state", i_data);
    fapi2::Assert(false);
    return mss::NO;
}

// MCA_DDRPHY_PC_DLL_ZCAL_CAL_STATUS is read-only

///
/// @brief Get ZCAL Cal Status
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] fapi2::buffer representing the status register to interrogate
/// @return mss::states; YES == success, NO == fail
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = pcTraits<T> >
inline mss::states get_zcal_status( const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_INF("zcal_status: 0x%016lx", i_data);
    return (i_data.getBit<TT::ZCAL_CAL_STATUS_DONE>() == true) ? mss::YES : mss::NO;
}

///
/// @brief read PC_ERROR_STATUS0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode read_error_status0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::PC_ERROR_STATUS0_REG, o_data) );
    FAPI_INF("pc_error_status0: 0x%016llx", o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write PC_ERROR_STATUS0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode write_error_status0( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_INF("pc_error_status0: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::PC_ERROR_STATUS0_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset pc_error_status0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode reset_error_status0( const fapi2::Target<T>& i_target )
{
    FAPI_TRY( write_error_status0(i_target, 0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief read PC_INIT_CAL_ERROR
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode read_init_cal_error( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::PC_INIT_CAL_ERROR_REG, o_data) );
    FAPI_INF("pc_init_cal_error: 0x%016llx", o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write PC_INIT_CAL_ERROR
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode write_init_cal_error( const fapi2::Target<T>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_INF("pc_init_cal_error: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::PC_INIT_CAL_ERROR_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset pc_init_cal_error
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode reset_init_cal_error( const fapi2::Target<T>& i_target )
{
    FAPI_TRY( write_init_cal_error(i_target, 0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset rc
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode reset( const fapi2::Target<T>& i_target )
{
    // Note that PC_CONFIG0 is statically configured in the initfile - we don't need to reset it.
    FAPI_TRY( reset_config1(i_target) );
    FAPI_TRY( reset_error_status0(i_target) );
    FAPI_TRY( reset_init_cal_error(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief read PC_RESETS
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[in] i_target the fapi2 target of the port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode read_resets( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::PC_RESETS_REG, o_data) );
    FAPI_INF("pc_resets: 0x%016llx", o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write PC_RESETS
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = pcTraits<T> >
inline fapi2::ReturnCode write_resets( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_INF("pc_resets: 0x%016llx", i_data);
    FAPI_TRY( mss::putScom(i_target, TT::PC_RESETS_REG, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ENABLE_ZCAL in PC_RESETS
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to dp16Traits<T>
/// @param[out] o_data the value of the register
/// @param[in] i_state mss::HIGH or mss::LOW
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = pcTraits<T> >
inline void set_enable_zcal( fapi2::buffer<uint64_t>& o_data, const states i_state )
{
    FAPI_INF("set_enable_zcal %s", (i_state == mss::LOW ? "low" : "high"));
    o_data.writeBit<TT::ENABLE_ZCAL>(i_state);
}

} // close namespace pc
} // close namespace mss

#endif
