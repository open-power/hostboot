/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/mc.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// @file mc.H
/// @brief Subroutines to manipulate the memory controller
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MC_H_
#define _MSS_MC_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/dimm/kind.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/scom.H>

namespace mss
{

// I have a dream that the xlate code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class mcTraits
/// @brief a collection of traits associated with the MC
/// @tparam T, fapi2::TargetType representing the MC
///
template< fapi2::TargetType T >
class mcTraits;

///
/// @class mcTraits
/// @brief a collection of traits associated with the Centaur controller
///
template<>
class mcTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class mcTraits
/// @brief a collection of traits associated with the Nimbus controller
///
template<>
class mcTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        enum
        {
            // Register definitions
            MBARPC0 = MCA_MBARPC0Q,
            MBASTR0 = MCA_MBASTR0Q,

            SLOT0_VALID = MCS_PORT02_MCP0XLT0_SLOT0_VALID,
            SLOT0_ROW15_VALID = MCS_PORT02_MCP0XLT0_SLOT0_ROW15_VALID,
            SLOT0_M1_VALID = MCS_PORT02_MCP0XLT0_SLOT0_M1_VALID,
            M1_BIT_MAP = MCS_PORT02_MCP0XLT0_M1_BIT_MAP,
            M1_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_M1_BIT_MAP_LEN,
            D_BIT_MAP = MCS_PORT02_MCP0XLT0_D_BIT_MAP,
            D_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN,
            R15_BIT_MAP = MCS_PORT02_MCP0XLT0_R15_BIT_MAP,
            R15_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_R15_BIT_MAP_LEN,
            COL4_BIT_MAP = MCS_PORT02_MCP0XLT1_COL4_BIT_MAP,
            COL4_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL4_BIT_MAP_LEN,
            COL5_BIT_MAP = MCS_PORT02_MCP0XLT1_COL5_BIT_MAP,
            COL5_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL5_BIT_MAP_LEN,
            COL6_BIT_MAP = MCS_PORT02_MCP0XLT1_COL6_BIT_MAP,
            COL6_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL6_BIT_MAP_LEN,
            COL7_BIT_MAP = MCS_PORT02_MCP0XLT1_COL7_BIT_MAP,
            COL7_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL7_BIT_MAP_LEN,
            COL8_BIT_MAP = MCS_PORT02_MCP0XLT2_COL8_BIT_MAP,
            COL8_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_COL8_BIT_MAP_LEN,
            COL9_BIT_MAP = MCS_PORT02_MCP0XLT2_COL9_BIT_MAP,
            COL9_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_COL9_BIT_MAP_LEN,
            BANK0_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP,
            BANK0_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP_LEN,
            BANK1_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP,
            BANK1_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP_LEN,
            BANK_GROUP0_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP,
            BANK_GROUP0_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP_LEN,
            BANK_GROUP1_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP,
            BANK_GROUP1_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP_LEN,
            RUNTIME_N_SLOT = MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT,
            RUNTIME_N_SLOT_LEN = MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT_LEN,
            RUNTIME_N_PORT = MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT,
            RUNTIME_N_PORT_LEN = MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT_LEN,
            RUNTIME_M = MCA_MBA_FARB3Q_CFG_NM_M,
            RUNTIME_M_LEN = MCA_MBA_FARB3Q_CFG_NM_M_LEN,
            EMERGENCY_N = MCA_MBA_FARB4Q_EMERGENCY_N,
            EMERGENCY_N_LEN = MCA_MBA_FARB4Q_EMERGENCY_N_LEN,
            EMERGENCY_M = MCA_MBA_FARB4Q_EMERGENCY_M,
            EMERGENCY_M_LEN = MCA_MBA_FARB4Q_EMERGENCY_M_LEN,
            CFG_STR_ENABLE = MCA_MBASTR0Q_CFG_STR_ENABLE,

            MIN_DOMAIN_REDUCTION_ENABLE = MCA_MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_ENABLE,
            MIN_MAX_DOMAINS_ENABLE = MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS_ENABLE,
            MIN_DOMAIN_REDUCTION_TIME = MCA_MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_TIME,
            MIN_DOMAIN_REDUCTION_TIME_LEN = MCA_MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_TIME_LEN,
            ENTER_STR_TIME_POS = MCA_MBASTR0Q_CFG_ENTER_STR_TIME,
            ENTER_STR_TIME_LEN = MCA_MBASTR0Q_CFG_ENTER_STR_TIME_LEN,
            RAS_WEIGHT_LEN = MCA_MBA_FARB3Q_CFG_NM_RAS_WEIGHT_LEN,
            RAS_WEIGHT_POS = MCA_MBA_FARB3Q_CFG_NM_RAS_WEIGHT,
            CAS_WEIGHT_LEN = MCA_MBA_FARB3Q_CFG_NM_CAS_WEIGHT_LEN,
            CAS_WEIGHT_POS = MCA_MBA_FARB3Q_CFG_NM_CAS_WEIGHT,
            NM_CHANGE_AFTER_SYNC = MCA_MBA_FARB3Q_CFG_NM_CHANGE_AFTER_SYNC,
            CFG_MIN_MAX_DOMAINS = MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS,
            CFG_MIN_MAX_DOMAINS_LEN = MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS_LEN,

        };

};

// Why two enums? Two reasons. First, we need these to be contiguous, and
// we can't always guarentee the symbols will be generated as such. Second,
// we want to be 0'based so that we can use a static array as a table and
// it's probably not possible for the symbols to be 0'based.
enum
{
    THIS_ENTRY_VALID = 0,
    VALUE_OF_D_BIT_INDEX = 1,
    GB12_ENABLE_INDEX = 2,
    MASTER_BIT_0_VALID_INDEX = 3,
    MASTER_BIT_1_VALID_INDEX = 4,
    SLAVE_BIT_0_VALID_INDEX = 5,
    SLAVE_BIT_1_VALID_INDEX = 6,
    SLAVE_BIT_2_VALID_INDEX = 7,
    ROW_BIT_15_VALID_INDEX = 8,
    ROW_BIT_16_VALID_INDEX = 9,
    ROW_BIT_17_VALID_INDEX = 10,
    BANK_BIT_2_VALID_INDEX = 11,
    DIMM_BIT_INDEX = 12,
    MASTER_BIT_0_INDEX = 13,
    MASTER_BIT_1_INDEX = 14,
    SLAVE_BIT_0_INDEX = 15,
    SLAVE_BIT_1_INDEX = 16,
    SLAVE_BIT_2_INDEX = 17,
    ROW_17_INDEX = 18,
    ROW_16_INDEX = 19,
    COLUMN_4_INDEX = 20,
    COLUMN_5_INDEX = 21,
    COLUMN_6_INDEX = 22,
    COLUMN_7_INDEX = 23,
    COLUMN_8_INDEX = 24,
    COLUMN_9_INDEX = 25,
    BANK_0_INDEX = 26,
    BANK_1_INDEX = 27,
    BANK_2_INDEX = 28,
    BANK_GROUP_0_BIT_INDEX = 29,
    BANK_GROUP_1_BIT_INDEX = 30,
    MAX_TRANSLATIONS = 31,
    PD_AND_STR = fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR,
    PD_AND_STR_CLK_STOP = fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP,
    POWER_DOWN = fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN,
    PD_AND_STR_OFF = fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF,
};

namespace mc
{

///
/// @brief Reads the contents of the MBARPC0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in] i_target the target on which to operate
/// @param[out] o_data the register data
/// @return fapi2::fapi2_rc_success if ok
///
template< fapi2::TargetType T, typename TT = mcTraits<T> >
inline fapi2::ReturnCode read_mbarpc0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    o_data = 0;

    FAPI_TRY( mss::getScom(i_target, TT::MBARPC0, o_data ), "%s failed to read MBARPC0 regiser", mss::c_str(i_target));
    FAPI_DBG("%s MBARPC0 has data 0x%016lx", mss::c_str(i_target), o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the contents of the MBARPC0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in] i_target the target on which to operate
/// @param[in] i_data the register data
/// @return fapi2::fapi2_rc_success if ok
///
template< fapi2::TargetType T, typename TT = mcTraits<T> >
inline fapi2::ReturnCode write_mbarpc0( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_TRY( mss::putScom(i_target, TT::MBARPC0, i_data ), "%s failed to write MBARPC0 regiser", mss::c_str(i_target));
    FAPI_DBG("%s MBARPC0 has data 0x%016lx", mss::c_str(i_target), i_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the power control enable bit
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in,out] io_data the value of the register
/// @param[in] i_state the state to write into the enable
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = mcTraits<T> >
inline void set_power_control_min_max_domains_enable( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    FAPI_DBG("set_power_control_min_max_domains_enable to %d", i_state);
    io_data.writeBit<TT::MIN_MAX_DOMAINS_ENABLE>(i_state == mss::states::ON);
}

///
/// @brief Gets the power control enable bit
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in] i_data the value of the register
/// @param[out] o_state the state to write into the enable
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = mcTraits<T> >
inline void get_power_control_min_max_domains_enable( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    o_state = i_data.getBit<TT::MIN_MAX_DOMAINS_ENABLE>() ? mss::states::ON : mss::states::OFF;
    FAPI_DBG("get_power_control_min_max_domains_enable to %d", o_state, TT::MIN_DOMAIN_REDUCTION_ENABLE);
}

///
/// @brief Sets the power control min max domains
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in,out] io_data the value of the register
/// @param[in] i_value the state to write into the enable
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = mcTraits<T> >
inline void set_power_control_min_max_domains( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    FAPI_DBG("set_power_control_min_max_domains to %d", i_value);
    io_data.insertFromRight<TT::CFG_MIN_MAX_DOMAINS, TT::CFG_MIN_MAX_DOMAINS_LEN>(i_value);
}

///
/// @brief Gets the power control min max domains
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in] i_data the value of the register
/// @param[out] o_value the state to write into the enable
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = mcTraits<T> >
inline void get_power_control_min_max_domains( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::CFG_MIN_MAX_DOMAINS, TT::CFG_MIN_MAX_DOMAINS_LEN>(o_value);
    FAPI_DBG("get_power_control_min_max_domains to %d", o_value);
}

///
/// @brief Sets the power control minimum domain reduction enable
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in,out] io_data the value of the register
/// @param[in] i_state the state to write into the enable
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = mcTraits<T> >
inline void set_power_control_min_domain_reduction_enable( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    io_data.writeBit<TT::MIN_DOMAIN_REDUCTION_ENABLE>(i_state == mss::states::ON);
    FAPI_DBG("set_power_control_min_domain_reduction_enable to %d 0x%016lx", i_state, io_data);
}

///
/// @brief Gets the power control minimum domain reduction enable
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in] i_data the value of the register
/// @param[out] o_state the state to write into the enable
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = mcTraits<T> >
inline void get_power_control_min_domain_reduction_enable( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    o_state = i_data.getBit<TT::MIN_DOMAIN_REDUCTION_ENABLE>() ? mss::states::ON : mss::states::OFF;
    FAPI_DBG("get_power_control_min_domain_reduction_enable to %d", o_state);
}

///
/// @brief Reads the contents of the MBASTR0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in] i_target the target on which to operate
/// @param[out] o_data the register data
/// @return fapi2::fapi2_rc_success if ok
///
template< fapi2::TargetType T, typename TT = mcTraits<T> >
inline fapi2::ReturnCode read_mbastr0( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    o_data = 0;

    FAPI_TRY( mss::getScom(i_target, TT::MBASTR0, o_data ), "%s failed to read MBASTR0 regiser", mss::c_str(i_target));
    FAPI_DBG("%s MBASTR0 has data 0x%016lx", mss::c_str(i_target), o_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the contents of the MBASTR0
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in] i_target the target on which to operate
/// @param[in] i_data the register data
/// @return fapi2::fapi2_rc_success if ok
///
template< fapi2::TargetType T, typename TT = mcTraits<T> >
inline fapi2::ReturnCode write_mbastr0( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_TRY( mss::putScom(i_target, TT::MBASTR0, i_data ), "%s failed to write MBASTR0 regiser", mss::c_str(i_target));
    FAPI_DBG("%s MBASTR0 has data 0x%016lx", mss::c_str(i_target), i_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the self time refresh enable bit
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in,out] io_data the value of the register
/// @param[in] i_state the state to write into the enable
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = mcTraits<T> >
inline void set_self_time_refresh_enable( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    FAPI_DBG("set_power_control_min_domain_reduction_enable to %d", i_state);
    io_data.writeBit<TT::CFG_STR_ENABLE>(i_state == mss::states::ON);
}

///
/// @brief Sets the self time refresh enable bit
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to mcTraits<T>
/// @param[in] i_data the value of the register
/// @param[out] o_state the state to write into the enable
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = mcTraits<T> >
inline void get_self_time_refresh_enable( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    o_state = i_data.getBit<TT::CFG_STR_ENABLE>() ? mss::states::ON : mss::states::OFF;
    FAPI_DBG("get_power_control_min_domain_reduction_enable to %d", o_state);
}

///
/// @brief set the PWR CNTRL register
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MCA_MBARPC0Q
///
fapi2::ReturnCode set_pwr_cntrl_reg(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief set the STR register
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MBASTR0Q
///
fapi2::ReturnCode set_str_reg(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief set the safemode throttle register
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MBA_FARB3Q
///
fapi2::ReturnCode set_nm_support (const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief set the safemode throttle register
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MBA_FARB4Q
///
fapi2::ReturnCode set_safemode_throttles(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief set the runtime throttle register to safemode values
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MBA_FARB3Q
///
fapi2::ReturnCode set_runtime_throttles_to_safe(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief safemode throttle values defined from MRW attributes
/// @param[in] i_target the MCA target
/// @return FAPI2_RC_SUCCESS iff ok
/// @note sets safemode values for emergency mode and regular throttling
///
fapi2::ReturnCode thermal_throttle_scominit (const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);
///
/// @brief Disable emergency mode throttle for thermal_init
/// @param[in] i_target the MCS target
/// @return FAPI_RC_SUCCESS iff ok
/// @note Clears MCMODE0_ENABLE_EMER_THROTTLE bit in MCSMODE0
///
fapi2::ReturnCode disable_emergency_throttle (const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target);

///
/// @brief Perform initializations of the MC performance registers
/// @note Some of these bits are taken care of in the scom initfiles
/// @param[in] i_target the target which has the MCA to map
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_perf2_register(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Calculate the value of the MC perf2 register.
/// @param[in] i_target the target which has the MCA to map
/// @param[out] o_value the perf2 value for the MCA
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode calculate_perf2(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint64_t& o_value);

///
/// @brief Helper to setup the translation map - useful for testing
/// @param[in] i_dimm_kinds std::vector of DIMM kind's representing the DIMM (Not const as we sort the vector)
/// @param[out] fapi2::buffer<uint64_t> o_xlate0  - xlt register 0's value
/// @param[out] fapi2::buffer<uint64_t> o_xlate1  - xlt register 1's value
/// @param[out] fapi2::buffer<uint64_t> o_xlate2  - xlt register 2's value
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_xlate_map_helper( std::vector<dimm::kind>& i_dimm_kinds,
        fapi2::buffer<uint64_t>& o_xlate0,
        fapi2::buffer<uint64_t>& o_xlate1,
        fapi2::buffer<uint64_t>& o_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @tparam P the fapi2::TargetType of the port
/// @tparam TT the mcTraits associated with P
/// @param[in] i_target the target which has the MCA to map
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType P,  typename TT = mcTraits<P> >
fapi2::ReturnCode setup_xlate_map(const fapi2::Target<P>& i_target);

} //mc

} //mss

#endif
