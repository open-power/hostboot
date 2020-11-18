/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/common/spd_decoder_base.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
/// @file spd_decoder.H
/// @brief SPD decoder declarations
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_BASE_SPD_DECODER_H_
#define _MSS_BASE_SPD_DECODER_H_

#include <cstdint>
#include <memory>
#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/spd/spd_reader.H>

namespace mss
{

namespace spd
{

class base_cnfg_decoder
{
    private:

        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        std::vector<uint8_t> iv_data;

    public:

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data SPD data vector
        ///
        base_cnfg_decoder(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const std::vector<uint8_t>& i_spd_data)
            : iv_target(i_target),
              iv_data(i_spd_data)
        {
        }

        ///
        /// @brief dtor
        ///
        virtual ~base_cnfg_decoder() = default;

        ///
        /// @brief Gets decoder target
        /// @return fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        ///
        virtual fapi2::Target<fapi2::TARGET_TYPE_DIMM> get_target() const
        {
            return iv_target;
        }

        ///
        /// @brief Gets decoder SPD data
        /// @return std::vector<uint8_t>
        ///
        virtual std::vector<uint8_t> get_data() const
        {
            return iv_data;
        }

        ///
        /// @brief Sets decoder SPD data
        /// @param[in] i_spd_data SPD data in a vector reference
        ///
        virtual void set_data(const std::vector<uint8_t>& i_spd_data)
        {
            iv_data = i_spd_data;
        }

        ///
        /// @brief Decodes number of used SPD bytes
        /// @param[out] o_value number of SPD bytes used
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode number_of_used_bytes( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDP revision
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode revision( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes total number of SPD bytes
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode number_of_total_bytes( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM device type
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode device_type( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes base module type
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode base_module( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes hybrid media
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode hybrid_media( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes hybrid
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode hybrid( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM density from SPD
        /// @param[out] o_value SDRAM density in GBs
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sdram_density( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of SDRAM banks bits from SPD
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode bank_bits( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of SDRAM bank groups bits from SPD
        /// @param[out] o_value Number of SDRAM bank groups bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode bank_group_bits( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of SDRAM column address bits
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode column_address_bits( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of SDRAM row address bits
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode row_address_bits( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Primary SDRAM signal loading
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode prim_sdram_signal_loading( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Primary SDRAM die count
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual  fapi2::ReturnCode prim_sdram_die_count( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Primary SDRAM package type
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode prim_sdram_package_type( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode SDRAM Maximum activate count
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode maximum_activate_count( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode SDRAM Maximum activate window (multiplier), tREFI uknown at this point
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode maximum_activate_window_multiplier( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode Post package repair (PPR)
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode post_package_repair( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode Soft post package repair (soft PPR)
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode soft_post_package_repair( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Secondary SDRAM signal loading
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sec_sdram_signal_loading( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Secondary DRAM Density Ratio
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sec_dram_density_ratio( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Secondary SDRAM die count
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sec_sdram_die_count( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Secondary SDRAM package type
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sec_sdram_package_type( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[out] o_value enum representing if 1.2V is operable
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode operable_nominal_voltage( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[out] o_value enum representing if 1.2V is endurant
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode endurant_nominal_voltage( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM device width
        /// @param[out] o_value device width in bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode device_width( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes number of package ranks per DIMM
        /// @param[out] o_value number of package ranks per DIMM
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode num_package_ranks_per_dimm( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Rank Mix
        /// @param[out] o_value rank mix value from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode rank_mix( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes primary bus width
        /// @param[out] o_value primary bus width in bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode prim_bus_width( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes bus width extension
        /// @param[out] o_value bus width extension in bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode bus_width_extension( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode Module Thermal Sensor
        /// @param[out] o_value thermal sensor value from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode thermal_sensor( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode Extended Base Module Type
        /// @param[out] o_value extended base module type value from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode extended_base_module_type( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode Fine Timebase
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_timebase( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode Medium Timebase
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode medium_timebase( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        ///
        /// @brief Decodes SDRAM Minimum Cycle Time in MTB
        /// @param[out] o_value tCKmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_tck( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Maximum Cycle Time in MTB
        /// @param[out] o_value tCKmax in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode max_tck( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decode CAS Latencies Supported
        /// @param[out] o_value bitmap of supported CAS latencies
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode supported_cas_latencies( uint64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Minimum CAS Latency Time in MTB
        /// @param[out] o_value tAAmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_taa( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Minimum RAS to CAS Delay Time in MTB
        /// @param[out] o_value tRCDmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trcd( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Minimum Row Precharge Delay Time in MTB
        /// @param[out] o_value tRPmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trp( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Minimum Active to Precharge Delay Time in MTB
        /// @param[out] o_value tRASmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_tras( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Minimum Active to Active/Refresh Delay Time in MTB
        /// @param[out] o_value tRCmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trc( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 1
        /// @param[out] o_value tRFC1min in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trfc1( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 2
        /// @param[out] o_value tRFC2min in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trfc2( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 4
        /// @param[out] o_value tRFC4min in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trfc4( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes SDRAM Minimum Four Activate Window Delay Time
        /// @param[out] o_value tFAWmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_tfaw( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[out] o_value tRRD_Smin MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trrd_s( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[out] o_value tRRD_Lmin MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trrd_l( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[out] o_value tCCD_Lmin MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_tccd_l( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Minimum Write Recovery Time
        /// @param[out] o_value tWRmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_twr( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Minimum Write to Read Time - Different Bank Group
        /// @param[out] o_value tWRT_Smin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_twtr_s( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Minimum Write to Read Time - Same Bank Group
        /// @param[out] o_value tWRT_Lmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_twtr_l( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Package Rank Map
        /// @param[out] o_value vector of package rank maps for SPD bytes 60 - 77
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode package_rank_map( std::vector<uint8_t>& o_value ) const
        {
            o_value.clear();
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Nibble Map
        /// @param[out] o_value vector of nibble map encoding for SPD bytes 60 - 77
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode nibble_map( std::vector<uint8_t>& o_value ) const
        {
            o_value.clear();
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[out] o_value tCCD_Lmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_tccd_l( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[out] o_value tRRD_Lmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_l( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[out] o_value tRRD_Smin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_s( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Active to Active/Refresh Delay Time
        /// @param[out] o_value tRCmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trc( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Row Precharge Delay Time
        /// @param[out] o_value tRPmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trp( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum RAS to CAS Delay Time
        /// @param[out] o_value tRCDmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trcd( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum CAS Latency Time
        /// @param[out] o_value tAAmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_taa( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Maximum Cycle Time
        /// @param[out] o_value tCKmax offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_max_tck( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum Cycle Time
        /// @param[out] o_value tCKmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_tck( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for tWTR_L
        /// @param[out] o_value tWTR_L offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @warning not an actual SPD field, defaulted to zero to simplify calculations
        ///
        virtual fapi2::ReturnCode fine_offset_min_twtr_l( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for twtr_s
        /// @param[out] o_value twtr_s offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @warning not an actual SPD field, defaulted to zero to simplify calculations
        ///
        virtual fapi2::ReturnCode fine_offset_min_twtr_s( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for tfaw
        /// @param[out] o_value tfaw offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @warning not an actual SPD field, defaulted to zero to simplify calculations
        ///
        virtual fapi2::ReturnCode fine_offset_min_tfaw( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for tras
        /// @param[out] o_value tras offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @warning not an actual SPD field, defaulted to zero to simplify calculations
        ///
        virtual fapi2::ReturnCode fine_offset_min_tras( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Fine Offset for twr
        /// @param[out] o_value twr offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @warning not an actual SPD field, defaulted to zero to simplify calculations
        ///
        virtual fapi2::ReturnCode fine_offset_min_twr( int64_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Cyclical Redundancy Code (CRC) for Base Configuration Section
        /// @param[out] o_value crc value from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode cyclical_redundancy_code( uint16_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes module manufacturer ID code
        /// @param[out] o_output module manufacturing id code
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode module_manufacturer_id_code( uint16_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Module Manufacturing Location
        /// @param[out] o_value uint8_t identifier for manufacturing location of memory module
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode module_manufacturing_location( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodesmodule manufacturing date
        /// @param[out] o_value the 2 byte date of manufacturing in BCD format
        /// @return FAPI2_RC_SUCCESS iff okay
        virtual fapi2::ReturnCode module_manufacturing_date( uint16_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes module's unique serial number
        /// @param[out] o_value module's serial number
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode module_serial_number( uint32_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes Module Revision Code
        /// @param[out] o_value uint8_t identifier for revision code
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode module_revision_code( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM Manufacturer ID code
        /// @param[out] o_value dram manufacturing id code
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode dram_manufacturer_id_code( uint16_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Decodes DRAM Stepping
        /// @param[out] o_value uint8_t DRAM Stepping val
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode dram_stepping( uint8_t& o_value ) const
        {
            o_value = 0;
            return fapi2::FAPI2_RC_SUCCESS;
        }
};

}// spd
}// mss

#endif
