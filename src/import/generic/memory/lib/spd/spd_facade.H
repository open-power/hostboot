/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_facade.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

    FAPI_DBG( "SPD size %d for %s", l_size, spd::c_str(i_target) );

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
        uint8_t iv_dimm_type;

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

            // Variable to deal with dimm modules (e.g. DDIMM) that has
            // fields that are not disjoint between the
            // general and dimm module section of the SPD (i.e. a hack variable)
            FAPI_TRY( iv_base_cnfg_decoder->base_module(iv_dimm_type) );

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
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> get_target() const
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
        /// @brief Decodes Fine Offset for Minimum Write to Read Time - Same Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @warning not an actual SPD field, defaulted to zero to simplify calculations
        ///
        fapi2::ReturnCode fine_offset_min_twtr_l( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_twtr_l(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Write to Read Time - Different Bank Group
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @warning not an actual SPD field, defaulted to zero to simplify calculations
        ///
        fapi2::ReturnCode fine_offset_min_twtr_s( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_twtr_s(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum Four Activate Window Delay Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @warning not an actual SPD field, defaulted to zero to simplify calculations
        ///
        fapi2::ReturnCode fine_offset_min_tfaw( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_tfaw(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum Active to Precharge Delay Time in MTB
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        /// @warning not an actual SPD field, defaulted to zero to simplify calculations
        ///
        fapi2::ReturnCode fine_offset_min_tras( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_tras(o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Write Recovery Time
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode fine_offset_min_twr( int64_t& o_value ) const
        {
            FAPI_TRY( iv_base_cnfg_decoder->fine_offset_min_twr(o_value) );

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
        /// @brief Decodes Module Manufacturer ID code
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode module_manufacturer_id_code( uint16_t& o_value ) const
        {
            // Some module fields are duplicated in the general section and
            // dimm module sections of the SPD.  For DDIMMs, we want get it
            // from the dimm module section instead of the general section.
            if( iv_dimm_type == spd::DDIMM )
            {
                FAPI_TRY( iv_dimm_module_decoder->module_manufacturer_id_code(o_value) );
            }
            else
            {
                FAPI_TRY( iv_base_cnfg_decoder->module_manufacturer_id_code(o_value) );
            }

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
            // Some module fields are duplicated in the general section and
            // dimm module sections of the SPD.  For DDIMMs, we want get it
            // from the dimm module section instead of the general section.
            if( iv_dimm_type == spd::DDIMM )
            {
                FAPI_TRY( iv_dimm_module_decoder->dram_manufacturer_id_code(o_value) );
            }
            else
            {
                FAPI_TRY( iv_base_cnfg_decoder->dram_manufacturer_id_code(o_value) );
            }

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
        /// @brief Decodes module base height
        /// @param[out] o_value SPD encoded value
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode module_base_height(uint8_t& o_value) const
        {
            FAPI_TRY( iv_dimm_module_decoder->module_base_height(o_value) );

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

        ///
        /// @brief Decodes SPD Revision for bytes 192->447 -> SPD_REV_DDIMM_MODULE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ddimm_module_spd_revision(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->ddimm_module_spd_revision(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DIMM attributes -> NUM_BUFFERS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode num_buffers_used(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->num_buffers_used(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DMB Manfacture ID code 2nd byte
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 198: CONTINUATION_CODE
        /// Byte 199: LAST_NON_ZERO
        ///
        fapi2::ReturnCode dmb_manufacturer_id_code(uint16_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->dmb_manufacturer_id_code(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DMB Revision Number -> DMB_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dmb_rev_num(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->dmb_rev_num(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DIMM Module Oranization -> PACKAGE_RANK
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode package_ranks_per_channel(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->package_ranks_per_channel(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DIMM Module Oranization -> DATA_WIDTH
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_component_width_per_channel(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->dram_component_width_per_channel(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Memory Channel Bus Width -> NUM_DIMM_CHANNELS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode num_channels_per_dimm(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->num_channels_per_dimm(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Memory Channel Bus Width -> DEVICE_WIDTH
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode memory_width_per_channel(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->memory_width_per_channel(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Thermal Sensors -> MOD_THERMAL_SENSOR
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode module_thermal_sensors(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->module_thermal_sensors(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Host Interface Protocols -> PROTOCOL_SUPPORT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode host_protocol_support(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->host_protocol_support(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Host Interface Speed Supported -> SPEED_SUPPORTED_LSB
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode host_speed_supported(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->host_speed_supported(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Address Mirroring -> ADDRESS_MIRROR
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode address_mirroring(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->address_mirroring(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Byte enables MSB
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 208: BYTE_ENABLES_LSB
        /// Byte 209: BYTE_ENABLES_MSB
        ///
        fapi2::ReturnCode byte_enables(uint16_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->byte_enables(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Nibble enables LSB1
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 210: NIBBLE_ENABLES_LSB0
        /// Byte 211: NIBBLE_ENABLES_MSB0
        /// Byte 212: NIBBLE_ENABLES_LSB1
        ///
        fapi2::ReturnCode nibble_enables(uint32_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->nibble_enables(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Four Rank Mode - DDP Compatibility - TSV 8 High Support - MRAM Support -> DDIMM_COMPAT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode compatabilty_modes(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->compatabilty_modes(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Number of P-States -> NUM_P_STATES
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode num_p_states(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->num_p_states(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Spare Device Mapping LSB1
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 216: SPARE_DEVICE_LSB0
        /// Byte 217: SPARE_DEVICE_MSB0
        /// Byte 218: SPARE_DEVICE_LSB1
        ///
        fapi2::ReturnCode spare_device_mapping(uint32_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->spare_device_mapping(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Host Interface Speed to DDR Interface Speed Ratio -> HI_DDR_SPEED_RATIO
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode host_to_ddr_speed_ratio(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->host_to_ddr_speed_ratio(o_output) );


        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SPD Content Revision -> SPD_CONTENT_REVISION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode spd_content_revision(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->spd_content_revision(o_output) );


        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_MTG Edge connector -> VIN_MGMT_NOMINAL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vin_mgmt_nominal(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->vin_mgmt_nominal(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_MTG Edge connector -> VIN_MGMT_OPERABLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vin_mgmt_operable(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->vin_mgmt_operable(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_MTG Edge connector -> VIN_MGMT_ENDURANT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vin_mgmt_endurant(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->vin_mgmt_endurant(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_BULK Edge Connecto -> VIN_BULK_NOMINAL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vin_bulk_nominal(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->vin_bulk_nominal(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_BULK Edge Connecto -> VIN_BULK_OPERABLE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vin_bulk_operable(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->vin_bulk_operable(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Voltage VIN_BULK Edge Connecto -> VIN_BULK_ENDURANT
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vin_bulk_endurant(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->vin_bulk_endurant(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes VDD_Core PMIC0 -> VDD_CORE_PMIC0
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vdd_core_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->vdd_core_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Manfacture ID code 2nd byte
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 227: PMIC0_CONT_CODE
        /// Byte 228: PMIC0_LAST_NON_ZERO
        ///
        fapi2::ReturnCode mfg_id_pmic0(uint16_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->mfg_id_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Revision Number -> PMIC0_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode revision_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->revision_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes VDD_Core PMIC1 -> VDD_CORE_PMIC1
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vdd_core_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->vdd_core_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Manfacture ID code 2nd byte
        /// @param[out] o_output encoding from SPD - multiple fields used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Uses the following bytes and fields to build up the combined data:
        /// Byte 231: PMIC1_CONT_CODE
        /// Byte 232: PMIC1_LAST_NON_ZERO
        ///
        fapi2::ReturnCode mfg_id_pmic1(uint16_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->mfg_id_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Revision Number -> PMIC1_REV
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode revision_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->revision_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Setting -> PMIC0_SWA_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_swa_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_swa_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Setting -> PMIC0_SWA_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_range_swa_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_range_swa_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Offset -> PMIC0_SWA_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_swa_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_swa_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Voltage Offset -> PMIC0_SWA_OFF_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_direction_swa_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_direction_swa_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Delay -> PMIC0_SWA_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_delay_swa_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_delay_swa_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWA Sequence Order -> PMIC0_SWA_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_order_swa_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_order_swa_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Setting -> PMIC0_SWB_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_swb_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_swb_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Setting -> PMIC0_SWB_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_range_swb_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_range_swb_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Offset -> PMIC0_SWB_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_swb_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_swb_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Voltage Offset -> PMIC0_SWB_OFF_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_direction_swb_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_direction_swb_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Delay -> PMIC0_SWB_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_delay_swb_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_delay_swb_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWB Sequence Order -> PMIC0_SWB_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_order_swb_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_order_swb_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Setting -> PMIC0_SWC_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_swc_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_swc_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Setting -> PMIC0_SWC_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_range_swc_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_range_swc_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Offset -> PMIC0_SWC_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_swc_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_swc_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Voltage Offset -> PMIC0_SWC_OFF_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_direction_swc_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_direction_swc_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Delay -> PMIC0_SWC_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_delay_swc_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_delay_swc_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWC Sequence Order -> PMIC0_SWC_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_order_swc_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_order_swc_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Setting -> PMIC0_SWD_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_swd_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_swd_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Setting -> PMIC0_SWD_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_range_swd_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_range_swd_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Offset -> PMIC0_SWD_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_swd_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_swd_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Voltage Offset -> PMIC0_SWD_OFF_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_direction_swd_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_direction_swd_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Delay -> PMIC0_SWD_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_delay_swd_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_delay_swd_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 SWD Sequence Order -> PMIC0_SWD_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_order_swd_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_order_swd_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Redundancy -> PMIC0_REDUNDANCY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode pmic0_redundancy(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->pmic0_redundancy(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Phase Combination -> PMIC0_PHASE_COMBIN
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode phase_combination_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->phase_combination_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Sequence -> PMIC0_SEQUENCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode sequence_pmic0(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->sequence_pmic0(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Setting -> PMIC1_SWA_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_swa_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_swa_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Setting -> PMIC1_SWA_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_range_swa_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_range_swa_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Offset -> PMIC1_SWA_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_swa_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_swa_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Voltage Offset -> PMIC1_SWA_OFF_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_direction_swa_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_direction_swa_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Delay -> PMIC1_SWA_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_delay_swa_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_delay_swa_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWA Sequence Order -> PMIC1_SWA_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_order_swa_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_order_swa_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Setting -> PMIC1_SWB_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_swb_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_swb_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Setting -> PMIC1_SWB_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_range_swb_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_range_swb_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Offset -> PMIC1_SWB_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_swb_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_swb_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Voltage Offset -> PMIC1_SWB_OFF_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_direction_swb_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_direction_swb_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Delay -> PMIC1_SWB_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_delay_swb_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_delay_swb_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWB Sequence Order -> PMIC1_SWB_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_order_swb_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_order_swb_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Setting -> PMIC1_SWC_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_swc_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_swc_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Setting -> PMIC1_SWC_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_range_swc_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_range_swc_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Offset -> PMIC1_SWC_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_swc_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_swc_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Voltage Offset -> PMIC1_SWC_OFF_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_direction_swc_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_direction_swc_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Delay -> PMIC1_SWC_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_delay_swc_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_delay_swc_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWC Sequence Order -> PMIC1_SWC_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_order_swc_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_order_swc_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Setting -> PMIC1_SWD_VOLT_SET
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_swd_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_swd_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Setting -> PMIC1_SWD_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_setpoint_range_swd_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_setpoint_range_swd_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Offset -> PMIC1_SWD_VOLT_OFF
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_swd_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_swd_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Voltage Offset -> PMIC1_SWD_OFF_RANGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_offset_direction_swd_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_offset_direction_swd_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Delay -> PMIC1_SWD_DELAY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_delay_swd_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_delay_swd_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 SWD Sequence Order -> PMIC1_SWD_ORDER
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode volt_order_swd_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->volt_order_swd_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Redundancy -> PMIC1_REDUNDANCY
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode pmic1_redundancy(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->pmic1_redundancy(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC1 Phase Combination -> PMIC1_PHASE_COMBIN
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode phase_combination_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->phase_combination_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes PMIC0 Sequence -> PMIC0_SEQUENCE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode sequence_pmic1(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->sequence_pmic1(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module RCD
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode module_rcd(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->module_rcd(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Availability -> THERM_SENSOR_0_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_0_availability(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_0_availability(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Secondary Sensor Availability -> THERM_SENSOR_0_SECOND_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_0_secondary_availability(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_0_secondary_availability(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Type -> THERM_SENSOR_0_TYPE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_0_type(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_0_type(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Usage -> THERM_SENSOR_0_USAGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_0_usage(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_0_usage(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 I2C Address -> THERM_SENSOR_0_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_0_i2c_address(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_0_i2c_address(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Availability -> THERM_SENSOR_1_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_1_availability(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_1_availability(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Availability -> THERM_SENSOR_1_SECOND_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_1_secondary_availability(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_1_secondary_availability(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Type -> THERM_SENSOR_1_TYPE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_1_type(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_1_type(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Usage -> THERM_SENSOR_1_USAGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_1_usage(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_1_usage(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 I2C Address -> THERM_SENSOR_1_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_1_i2c_address(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_1_i2c_address(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor Differential Availability -> THERM_SENSOR_DIFF_AVAIL
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_differential_availability(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_differential_availability(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor Differential Type -> THERM_SENSOR_DIFF_TYPE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_differential_type(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_differential_type(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor Differential Usage -> THERM_SENSOR_DIFF_USAGE
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_differential_usage(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_differential_usage(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Differential Thermal Sensor I2C Address -> THERM_SENSOR_DIFF_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_differential_i2c_address(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_differential_i2c_address(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 0 I2C Address -> THERM_SENSOR_0_SECOND_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_0_secondary_i2c_address(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_0_secondary_i2c_address(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 1 I2C Address -> THERM_SENSOR_1_SECOND_I2C_ADDRESS
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_1_secondary_i2c_address(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_1_secondary_i2c_address(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 1 Location -> THERM_SENSOR_1_SECOND_LOCATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_1_secondary_location(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_1_secondary_location(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary Thermal Sensor 0 Location -> THERM_SENSOR_0_SECOND_LOCATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_0_secondary_location(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_0_secondary_location(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 1 Location -> THERM_SENSOR_1_LOCATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_1_location(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_1_location(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Thermal Sensor 0 Location -> THERM_SENSOR_0_LOCATION
        /// @param[out] o_output encoding from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode therm_sensor_0_location(uint8_t& o_output) const
        {
            FAPI_TRY( iv_dimm_module_decoder->therm_sensor_0_location(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes the module partnumber
        /// @param[out] o_output partnumber value as read from the SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Needed for LRDIMM decodes to workaround a specific PN's SI issues
        ///
        fapi2::ReturnCode module_partnumber(uint8_t o_output[mss::MODULE_PARTNUMBER_ATTR]) const
        {
            FAPI_TRY( iv_dimm_module_decoder->module_partnumber(o_output) );

        fapi_try_exit:
            return fapi2::current_err;
        }
        ///
        /// @brief Decodes the IBM 11S barcode
        /// @param[out] o_serial_number 11S barcode information
        /// @return FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode ibm_serial_number(fapi2::ATTR_MSS_EXP_SERIAL_NUMBER_Type o_serial_number) const
        {
            return iv_dimm_module_decoder->ibm_serial_number(o_serial_number);
        }

};

///
/// @brief Helper function to append SPD decoder to the end of a vector
/// @param[in] i_target the DIMM target
/// @param[in] i_spd_data SPD data in a vector reference
/// @param[in,out] io_spd_decoder reference to std::vector of SPD facades
/// @return FAPI2_RC_SUCCESS iff okay
///
static inline fapi2::ReturnCode add_decoder_to_list( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
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
        FAPI_TRY( get_raw_data(l_dimm, l_spd), "%s Failed get_raw_data", mss::c_str(l_dimm) );

        FAPI_TRY( add_decoder_to_list(l_dimm, l_spd, o_spd_decoder), "%s Failed add_decoder_to_list", mss::c_str(l_dimm) );
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
