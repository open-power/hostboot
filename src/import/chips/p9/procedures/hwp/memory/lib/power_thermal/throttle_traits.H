/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/throttle_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p9_mss_utils_to_throttle.H
/// @brief throttle API
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_POWER_THROTTLE_TRAITS_
#define _MSS_POWER_THROTTLE_TRAITS_

#include <fapi2.H>
#include <generic/memory/lib/utils/power_thermal/gen_throttle_traits.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

namespace mss
{
namespace power_thermal
{

///
/// @class Traits and policy class for throttle code - specialization for the NIMBUS mc type
///
template<>
class throttle_traits<mss::mc_type::NIMBUS>
{
    public:
        //////////////////////////////////////////////////////////////
        // Target types
        //////////////////////////////////////////////////////////////
        static constexpr fapi2::TargetType MC_TARGET_TYPE = fapi2::TARGET_TYPE_MCS;
        static constexpr fapi2::TargetType PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MCA;

        // MIN_UTIL is  in c%
        static const uint64_t MIN_UTIL = 2500;
        // IDLE_UTIL is  in c%
        static const uint64_t IDLE_UTIL = 0;
        // Minimum throttle allowed for the port and or slot. If we set to 0, we brick the port
        static const uint64_t  MIN_THROTTLE = 1;

        enum size_of_attrs : size_t
        {
            SIZE_OF_POWER_CURVES_ATTRS = 100,
            SIZE_OF_THERMAL_ATTR = 10,
        };

        enum default_power
        {
            //Values are the worst case defaults for power curves
            //They are the default/ catch-all values from the power curve attributes
            //Shouldn't be used if system is set up correctly and attributes are available
            //This will throttle the DIMMs to ~76% dram data bus utilization
            //(using the mrw regulator power limit of 1700 cW and thermal power limit here of 1940 cW).
            VDDR_SLOPE = 0x41A,
            VDDR_INT = 0x384,
            TOTAL_SLOPE = 0x44C,
            TOTAL_INT = 0x44C,
            THERMAL_LIMIT = 0x794,
        };

        enum
        {
            PORTS_PER_MC = 2,
            DIMMS_PER_PORT = 2,
        };

        //Bit positions for different section of the attribute
        //first 32 bits are the encoding, second are for values
        enum DECODE_BUFFER_POS
        {
            ENCODING_START = 0,
            ENCODING_LENGTH = 32,
            VDDR_START = 32,
            VDDR_LENGTH = 16,
            TOTAL_START = 48,
            TOTAL_LENGTH = 16,
            THERMAL_POWER_START = 32,
            THERMAL_POWER_LENGTH = 32,
        };

        //Positions and lengths of the encodings
        enum ATTR_DECODE_INFO
        {
            DIMM_SIZE_START = 0,
            DIMM_SIZE_LEN = 4,

            DRAM_GEN_START = 4,
            DRAM_GEN_LEN = 2,

            DIMM_TYPE_START = 6,
            DIMM_TYPE_LEN = 2,

            DRAM_WIDTH_START = 8,
            DRAM_WIDTH_LEN = 3,

            DRAM_DENSITY_START = 11,
            DRAM_DENSITY_LEN = 3,

            DRAM_STACK_TYPE_START = 14,
            DRAM_STACK_TYPE_LEN = 2,

            DRAM_MFGID_START = 16,
            DRAM_MFGID_LEN = 3,

            DIMMS_PER_PORT_START = 19,
            DIMMS_PER_PORT_LEN = 2,

            // Invalid for Nimbus but compile will fail without them
            DIMM_MODULE_HEIGHT_START = 0,
            DIMM_MODULE_HEIGHT_LEN = 1,
        };


        // Definition is in chip folder
        static const std::vector< std::pair<uint8_t , uint8_t> > DIMM_TYPE_MAP;

        // Throttle values
        static constexpr uint64_t NM_RAS_WEIGHT = 0b000;
        static constexpr uint64_t NM_CAS_WEIGHT = 0b001;

        static constexpr uint64_t MAXALL_MINALL = 0b000;

        // Wait 959 refresh intervals of idle before powering down all ranks
        static constexpr uint64_t MIN_DOMAIN_REDUCTION_TIME = 959;

        // Wait 1023 refresh intervals of idle before going into STR on all ranks
        // 1023 is the max allowed value
        static constexpr uint64_t ENTER_STR_TIME = 1023;

        // Set to disable permanently due to hardware design bug (HW403028) that won't be changed
        static constexpr bool CFG_NM_CHANGE_AFTER_SYNC_VALUE = false;

        // Scom register definitions
        static constexpr uint64_t MBARPC0Q_REG = MCA_MBARPC0Q;
        static constexpr uint64_t FARB3Q_REG = MCA_MBA_FARB3Q;
        static constexpr uint64_t FARB4Q_REG = MCA_MBA_FARB4Q;
        static constexpr uint64_t STR0Q_REG = MCA_MBASTR0Q;

        // Scom register field definition
        enum
        {
            RUNTIME_N_SLOT = MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT,
            RUNTIME_N_SLOT_LEN = MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT_LEN,
            RUNTIME_N_PORT = MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT,
            RUNTIME_N_PORT_LEN = MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT_LEN,
            RUNTIME_M = MCA_MBA_FARB3Q_CFG_NM_M,
            RUNTIME_M_LEN = MCA_MBA_FARB3Q_CFG_NM_M_LEN,
            CFG_RAS_WEIGHT = MCA_MBA_FARB3Q_CFG_NM_RAS_WEIGHT,
            CFG_RAS_WEIGHT_LEN = MCA_MBA_FARB3Q_CFG_NM_RAS_WEIGHT_LEN,
            CFG_CAS_WEIGHT = MCA_MBA_FARB3Q_CFG_NM_CAS_WEIGHT,
            CFG_CAS_WEIGHT_LEN = MCA_MBA_FARB3Q_CFG_NM_CAS_WEIGHT_LEN,
            CFG_NM_CHANGE_AFTER_SYNC = MCA_MBA_FARB3Q_CFG_NM_CHANGE_AFTER_SYNC,

            EMERGENCY_M = MCA_MBA_FARB4Q_EMERGENCY_M,
            EMERGENCY_M_LEN = MCA_MBA_FARB4Q_EMERGENCY_M_LEN,
            EMERGENCY_N = MCA_MBA_FARB4Q_EMERGENCY_N,
            EMERGENCY_N_LEN = MCA_MBA_FARB4Q_EMERGENCY_N_LEN,

            CFG_MIN_MAX_DOMAINS = MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS,
            CFG_MIN_MAX_DOMAINS_LEN = MCA_MBARPC0Q_CFG_MIN_MAX_DOMAINS_LEN,
            CFG_MIN_DOMAIN_REDUCTION_ENABLE = MCA_MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_ENABLE,
            CFG_MIN_DOMAIN_REDUCTION_TIME = MCA_MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_TIME,
            CFG_MIN_DOMAIN_REDUCTION_TIME_LEN = MCA_MBARPC0Q_CFG_MIN_DOMAIN_REDUCTION_TIME_LEN,

            // Note these are not implemented in Nimbus, so should not be used!
            // These are only included to allow the generic function to compile
            CFG_LP_CTRL_ENABLE = MCA_MBARPC0Q_RESERVED_0_1,
            CFG_LP_DATA_ENABLE = MCA_MBARPC0Q_RESERVED_0_1,

            CFG_STR_ENABLE = MCA_MBASTR0Q_CFG_STR_ENABLE,
            CFG_ENTER_STR_TIME = MCA_MBASTR0Q_CFG_ENTER_STR_TIME,
            CFG_ENTER_STR_TIME_LEN = MCA_MBASTR0Q_CFG_ENTER_STR_TIME_LEN,
            CFG_DIS_CLK_IN_STR = MCA_MBASTR0Q_CFG_DIS_CLK_IN_STR,
        };
};
}//power_thermal
}// mss

#endif
