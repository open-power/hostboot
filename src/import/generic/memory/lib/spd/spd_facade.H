/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_facade.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#ifndef _MSS_SPD_FACADE_H_
#define _MSS_SPD_FACADE_H_

#include <generic/memory/lib/spd/spd_factory_pattern.H>
#include <generic/memory/lib/utils/find.H>
#include <fapi2_spd_access.H>

namespace mss
{
namespace spd
{

///
/// @brief Retrieve SPD data
/// @param[in] i_target the DIMM target
/// @param[out] o_spd reference to std::vector
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode get_raw_data(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      std::vector<uint8_t>& o_spd)
{
    // Get SPD blob size
    size_t l_size = 0;
    FAPI_TRY( fapi2::getSPD(i_target, nullptr, l_size),
              "%s. Failed to retrieve SPD blob size", spd::c_str(i_target) );

    // Reassign container size with the retrieved size
    // Arbitrarily set the data to zero since it will be overwritten
    o_spd.assign(l_size, 0);

    // Retrieve SPD data content
    FAPI_TRY( fapi2::getSPD(i_target, o_spd.data(), l_size),
              "%s. Failed to retrieve SPD data", spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @class facade
/// @brief SDP facade to simplify decoder interface
/// @note the facade should be a pass through class,
/// shouldn't be subclassed. Factories should be the work horse.
///
class facade final
{
    private:

        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        std::vector<uint8_t> iv_data;
        std::shared_ptr<dimm_module_decoder> iv_dimm_module_decoder;
        std::shared_ptr<base_cnfg_decoder> iv_base_cnfg_decoder;

    public:

        ///
        /// @brief ctor
        /// @param[in] i_target the DIMM target
        /// @param[in] i_spd_data SPD data in a vector reference
        /// @param[out] o_rc FAPI2_RC_SUCCESS iff okay
        ///
        facade( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const std::vector<uint8_t>& i_spd_data,
                fapi2::ReturnCode& o_rc):
            iv_target(i_target),
            iv_data(i_spd_data)
        {
            factories l_factories(i_target, i_spd_data, o_rc);
            FAPI_TRY(o_rc, "Failed to instantiate factories object for %s", spd::c_str(i_target));

            FAPI_TRY(l_factories.create_decoder(iv_dimm_module_decoder));
            FAPI_TRY(l_factories.create_decoder(iv_base_cnfg_decoder));

            o_rc = fapi2::FAPI2_RC_SUCCESS;
            return;

        fapi_try_exit:
            o_rc = fapi2::current_err;
        }

        ///
        /// @brief dtor
        ///
        ~facade() = default;

        ///
        /// @brief Gets facade target
        /// @return fapi2::Target<fapi2::TARGET_TYPE_DIMM>
        ///
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> get_dimm_target() const
        {
            return iv_target;
        }

        ///
        /// @brief Gets facade SPD data
        /// @return std::vector<uint8_t>
        ///
        std::vector<uint8_t> get_data() const
        {
            return iv_data;
        }

        ///
        /// @brief Sets facade SPD data
        /// @param[in] i_spd_data SPD data in a vector reference
        ///
        void set_data(const std::vector<uint8_t>& i_spd_data)
        {
            // Keep SPD data changes consistent through decoders
            iv_data = i_spd_data;
            iv_base_cnfg_decoder->set_data(i_spd_data);
            iv_dimm_module_decoder->set_data(i_spd_data);
        }

        ///
        /// @brief Decodes number of used SPD bytes
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode number_of_used_bytes( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->number_of_used_bytes(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes total SPD encoding for total bytes
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode number_of_total_bytes( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->number_of_total_bytes(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDP revision
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode revision( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->revision(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM device type
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode device_type( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->device_type(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes base module type
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode base_module( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->base_module(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM density from SPD
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode sdram_density( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->sdram_density(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes hybrid media
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode hybrid_media( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->hybrid_media(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes hybrid
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode hybrid( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->hybrid(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of SDRAM banks bits from SPD
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode bank_bits( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->bank_bits(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of SDRAM bank groups bits from SPD
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode bank_group_bits( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->bank_group_bits(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of SDRAM column address bits
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode column_address_bits( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->column_address_bits(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of SDRAM row address bits
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode row_address_bits( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->row_address_bits(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Primary SDRAM signal loading
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode prim_sdram_signal_loading( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->prim_sdram_signal_loading(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Primary SDRAM die count
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode prim_sdram_die_count( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->prim_sdram_die_count(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Primary SDRAM package type
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode prim_sdram_package_type( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->prim_sdram_package_type(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode SDRAM Maximum activate count
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode maximum_activate_count( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->maximum_activate_count(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode SDRAM Maximum activate window (multiplier), tREFI uknown at this point
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode maximum_activate_window_multiplier( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->maximum_activate_window_multiplier(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Post package repair (PPR)
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode post_package_repair( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->post_package_repair(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Soft post package repair (soft PPR)
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode soft_post_package_repair( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->soft_post_package_repair(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary SDRAM signal loading
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode sec_sdram_signal_loading( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->sec_sdram_signal_loading(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary DRAM Density Ratio
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode sec_dram_density_ratio( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->sec_dram_density_ratio(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary SDRAM die count
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode sec_sdram_die_count( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->sec_sdram_die_count(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary SDRAM package type
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode sec_sdram_package_type( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->sec_sdram_package_type(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode operable_nominal_voltage( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->operable_nominal_voltage(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode endurant_nominal_voltage( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->endurant_nominal_voltage(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM device width
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode device_width( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->device_width(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of package ranks per DIMM
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode num_package_ranks_per_dimm( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->num_package_ranks_per_dimm(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Rank Mix
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode rank_mix( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->rank_mix(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes primary bus width
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode prim_bus_width( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->prim_bus_width(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes bus width extension
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode bus_width_extension( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->bus_width_extension(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Module Thermal Sensor
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode thermal_sensor( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->thermal_sensor(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Extended Base Module Type
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode extended_base_module_type( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->extended_base_module_type(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Fine Timebase
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_timebase( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_timebase(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Medium Timebase
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode medium_timebase( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->medium_timebase(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        ///
        /// @brief Decodes SDRAM Minimum Cycle Time in MTB
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_tck( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_tck(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Maximum Cycle Time in MTB
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode max_tck( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->max_tck(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode CAS Latencies Supported
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode supported_cas_latencies( uint64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->supported_cas_latencies(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum CAS Latency Time in MTB
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_taa( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_taa(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum RAS to CAS Delay Time in MTB
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_trcd( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_trcd(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Row Precharge Delay Time in MTB
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_trp( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_trp(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Active to Precharge Delay Time in MTB
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_tras( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_tras(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Active to Active/Refresh Delay Time in MTB
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_trc( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_trc(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 1
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_trfc1( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_trfc1(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 2
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_trfc2( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_trfc2(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 4
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_trfc4( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_trfc4(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Four Activate Window Delay Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_tfaw( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_tfaw(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_trrd_s( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_trrd_s(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_trrd_l( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_trrd_l(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_tccd_l( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_tccd_l(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum Write Recovery Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_twr( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_twr(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum Write to Read Time - Different Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_twtr_s( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_twtr_s(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum Write to Read Time - Same Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode min_twtr_l( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->min_twtr_l(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Package Rank Map
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode package_rank_map( std::vector<uint8_t>& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->package_rank_map(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Nibble Map
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode nibble_map( std::vector<uint8_t>& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->nibble_map(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_min_tccd_l( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_tccd_l(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_min_trrd_l( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_trrd_l(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_min_trrd_s( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_trrd_s(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Active to Active/Refresh Delay Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_min_trc( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_trc(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Row Precharge Delay Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_min_trp( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_trp(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum RAS to CAS Delay Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_min_trcd( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_trcd(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum CAS Latency Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_min_taa( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_taa(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Maximum Cycle Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_max_tck( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_max_tck(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum Cycle Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_min_tck( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_tck(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Cyclical Redundancy Code (CRC) for Base Configuration Section
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode cyclical_redundancy_code( uint16_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->cyclical_redundancy_code(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes module manufacturer ID code
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode module_manufacturer_id_code( uint16_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->module_manufacturer_id_code(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Manufacturing Location
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode module_manufacturing_location( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->module_manufacturing_location(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodesmodule manufacturing date
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        fapi2::ReturnCode module_manufacturing_date( uint16_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->module_manufacturing_date(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes module's unique serial number
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode module_serial_number( uint32_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->module_serial_number(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Revision Code
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode module_revision_code( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->module_revision_code(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM Manufacturer ID code
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode dram_manufacturer_id_code( uint16_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->dram_manufacturer_id_code(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM Stepping
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode dram_stepping( uint8_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->dram_stepping(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }
        ///
        /// @brief Decodes module nominal height max
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode max_module_nominal_height(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->max_module_nominal_height(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes raw card extension
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode raw_card_extension(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->raw_card_extension(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes front module maximum thickness max
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode front_module_max_thickness(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->front_module_max_thickness(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes back module maximum thickness max
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode back_module_max_thickness(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->back_module_max_thickness(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes reference raw card used
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode reference_raw_card(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->reference_raw_card(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of registers used on RDIMM
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode num_registers_used(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->num_registers_used(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of rows of DRAMs on RDIMM
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode num_rows_of_drams(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->num_rows_of_drams(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register and buffer type for LRDIMMs
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode register_and_buffer_type(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->register_and_buffer_type(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes heat spreader thermal characteristics
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCEawSS if okay
        ///
        fapi2::ReturnCode heat_spreader_thermal_char(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->heat_spreader_thermal_char(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes heat spreader solution
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode heat_spreader_solution(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->heat_spreader_solution(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register manufacturer ID code
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode reg_manufacturer_id_code(uint16_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->reg_manufacturer_id_code(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register revision number
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode register_rev_num(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->register_rev_num(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes address mapping from register to dram
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode register_to_dram_addr_mapping(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->register_to_dram_addr_mapping(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for CKE signal
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode cke_signal_output_driver(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->cke_signal_output_driver(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for ODT signal
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode odt_signal_output_driver(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->odt_signal_output_driver(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for command/address (CA) signal
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ca_signal_output_driver(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->ca_signal_output_driver(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for control signal (CS) signal
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode cs_signal_output_driver(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->cs_signal_output_driver(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for clock (B side)
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode b_side_clk_output_driver(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->b_side_clk_output_driver(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for clock (A side)
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode a_side_clk_output_driver(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->a_side_clk_output_driver(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for data buffer control (BCOM, BODT, BKCE)
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode bcom_bcke_bodt_drive_strength(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->bcom_bcke_bodt_drive_strength(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes register output drive strength for data buffer control (BCK)
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode bck_output_drive_strength(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->bck_output_drive_strength(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes RCD output slew rate control
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode slew_rate_control(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->slew_rate_control(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes data buffer revision number
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode data_buffer_rev(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->data_buffer_rev(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 0
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_vref_dq_rank0(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->dram_vref_dq_rank0(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 1
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_vref_dq_rank1(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->dram_vref_dq_rank1(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 2
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_vref_dq_rank2(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->dram_vref_dq_rank2(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM VrefDQ for Package Rank 3
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_vref_dq_rank3(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->dram_vref_dq_rank3(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes data buffer VrefDQ for DRAM interface
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode data_buffer_vref_dq(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->data_buffer_vref_dq(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM interface MDQ Drive Strenth
        /// of the data buffer component for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode data_buffer_mdq_drive_strength(const uint64_t i_dimm_speed, uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->data_buffer_mdq_drive_strength(i_dimm_speed, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM interface MDQ read termination strength
        /// of the data buffer component for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode data_buffer_mdq_rtt(const uint64_t i_dimm_speed, uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->data_buffer_mdq_rtt(i_dimm_speed, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM drive strenth
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_drive_strength(const uint64_t i_dimm_speed, uint8_t& o_value) const
        {
            FAPI_TRY(  iv_dimm_module_decoder->dram_drive_strength(i_dimm_speed, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM ODT for RTT_NOM
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_rtt_nom(const uint64_t i_dimm_speed, uint8_t& o_value) const
        {
            FAPI_TRY(  iv_dimm_module_decoder->dram_rtt_nom(i_dimm_speed, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM ODT for RTT_WR
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_rtt_wr(const uint64_t i_dimm_speed, uint8_t& o_value) const
        {
            FAPI_TRY(  iv_dimm_module_decoder->dram_rtt_wr(i_dimm_speed, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM ODT for RTT_PARK, package ranks 0 & 1
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_rtt_park_ranks0_1(const uint64_t i_dimm_speed, uint8_t& o_value) const
        {
            FAPI_TRY(  iv_dimm_module_decoder->dram_rtt_park_ranks0_1(i_dimm_speed, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM ODT for RTT_PARK, package ranks 2 & 3
        /// for a particular dimm speed
        /// @param[in] i_dimm_speed the dimm speed in MT/s
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_rtt_park_ranks2_3(const uint64_t i_dimm_speed, uint8_t& o_value) const
        {
            FAPI_TRY(  iv_dimm_module_decoder->dram_rtt_park_ranks2_3(i_dimm_speed, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes VrefDQ range for DRAM interface range
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_vref_dq_range(uint8_t& o_value) const
        {
            FAPI_TRY(  iv_dimm_module_decoder->dram_vref_dq_range(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes data buffer VrefDQ range for DRAM interface range
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode data_buffer_vref_dq_range(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->data_buffer_vref_dq_range(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes data buffer gain adjustment
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode data_buffer_gain_adjustment(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->data_buffer_gain_adjustment(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes data buffer Decision Feedback Equalization (DFE)
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode data_buffer_dfe(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->data_buffer_dfe(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Helper function to append SPD decoder to the end of a vector
/// @param[in] i_target the DIMM target
/// @param[in] i_spd_data SPD data in a vector reference
/// @param[in,out] io_spd_decoder reference to std::vector of SPD facades
/// @return FAPI2_RC_SUCCESS iff okay
///
static fapi2::ReturnCode add_decoder_to_list( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::vector<uint8_t>& i_spd_data,
        std::vector< facade >& io_spd_decoder )
{
    fapi2::ReturnCode l_rc;
    facade l_spd_decoder(i_target, i_spd_data, l_rc);
    FAPI_TRY(l_rc, "Failed to instantiate SPD facade for %s", spd::c_str(i_target));

    io_spd_decoder.push_back(l_spd_decoder);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Creates a list of SPD decoder from target
/// @tparam T the fapi2 target
/// @param[in] i_target the DIMM target
/// @param[out] o_spd_decoder reference to std::vector of SPD facades
/// @return FAPI2_RC_SUCCESS iff okay
///
template < fapi2::TargetType T >
fapi2::ReturnCode get_spd_decoder_list( const fapi2::Target<T>& i_target,
                                        std::vector< facade >& o_spd_decoder )
{
    o_spd_decoder.clear();

    for( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        std::vector<uint8_t> l_spd;
        FAPI_TRY( get_raw_data(l_dimm, l_spd) );

        FAPI_TRY( add_decoder_to_list(l_dimm, l_spd, o_spd_decoder) );
    }// dimms

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Creates a list of SPD decoder of SPD data to target
/// @tparam T the fapi2 target
/// @param[in] i_target the DIMM target
/// @param[in] i_spd_data SPD data
/// @param[out] o_spd_decoder reference to std::vector of SPD facades
/// @return FAPI2_RC_SUCCESS iff okay
///
template < fapi2::TargetType T >
fapi2::ReturnCode get_spd_decoder_list( const fapi2::Target<T>& i_target,
                                        const std::vector<uint8_t>& i_spd_data,
                                        std::vector< facade >& o_spd_decoder )
{
    o_spd_decoder.clear();

    for( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        FAPI_TRY( add_decoder_to_list(l_dimm, i_spd_data, o_spd_decoder) );
    }// dimms

fapi_try_exit:
    return fapi2::current_err;
}

}// spd
}// mss

#endif //_MSS_SPD_FACADE_H_
