/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_DECODER_H_
#define _MSS_SPD_DECODER_H_

// std lib
#include <cstdint>
#include <map>
#include <memory>

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/spd/spd_decoder_def.H>
#include <generic/memory/lib/spd/common/dimm_module_decoder.H>
#include <generic/memory/lib/spd/common/rcw_settings.H>
#include <generic/memory/lib/spd/common/spd_decoder_base.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/spd/spd_checker.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>

namespace mss
{

namespace spd
{

///
/// @brief sdram package types. Follows encodings in SPD
///
enum sdram_package_type : uint8_t
{
    // Package Type
    MONOLITHIC = 0,           ///< Monolithic DRAM device
    NON_MONOLITHIC = 1,       ///< NonMonolithic DRAM device (3DS, Dual/Quad Die, etc)

    // Signal loading
    UNSPECIFIED = MONOLITHIC, ///< Not specified
    MULTI_LOAD_STACK = 1,     ///< Multi laod stack
    SINGLE_LOAD_STACK = 2,    ///< Single load stack (3DS)
};

///
/// @brief module type DDR4 encoding
///
enum module_type
{
    NOT_HYBRID = 0,
    HYBRID = 1,
    NVDIMM_HYBRID = 1,
    MDS_HYBRID = 3
};

///
/// @brief enum for voltage information. Encoding comes from SPD
///
enum nominal_voltage : uint8_t
{
    NOT_OPERABLE = 0, ///< Not operable at 1.2V
    OPERABLE = 1,     ///< Operable at 1.2V

    NOT_ENDURANT = 0, ///< Not endurant at 1.2V
    ENDURANT = 1      ///< Endurant at 1.2 V
};

///
/// @brief Connector to SDRAM Bit Mapping field positions
/// @note Bytes 60 - 77 . Mapping to Package rank map and
/// nibble map starting and length positions for SPD field extraction.
///
enum connector_to_sdram
{
    PACKAGE_RANK_MAP_START = 0,
    PACKAGE_RANK_MAP_LEN = 2,

    NIBBLE_MAP_START = 2,
    NIBBLE_MAP_LEN = 6,
};

///
/// @brief Connector to SDRAM Bit Mapping fields
/// @note template selector for traits and function API
///
enum connector_field
{
    NIBBLE_MAP,
    PKG_RANK_MAP,
};

///
/// @brief Connector to SDRAM Bit Mapping connector bits
/// @note template selYYector for traits and function API.
/// DQ0_31 represnts DQ nibbles for DQ bits 0 - 31.
/// DQ32_63 represnts DQ nibbles for DQ bits 32 - 63.
/// CB0_7 represents DQ nibbles for DQ bits 64 - 71.
///
enum connector_bits
{
    DQ0_31,
    DQ32_63,
    CB0_7,
};

///
/// @brief Helper function threshold check for nibble map
/// @param[in] i_target the DIMM target
/// @param[in] i_byte the SPD byte
/// @param[in] i_bit_order the nibble bit order from SPD
/// @return FAPI2_RC_SUCCESS iff okay
///
static fapi2::ReturnCode nibble_map_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_byte,
        const uint8_t i_bit_order )
{
    // SPD limits on what the value for the nibble map can be,
    // taken from the SPD JEDEC spec.
    constexpr uint64_t LOW_BIT_ORDER_MIN = 0x01;
    constexpr uint64_t LOW_BIT_ORDER_MAX = 0x18;

    constexpr uint64_t UP_BIT_ORDER_MIN = 0x21;
    constexpr uint64_t UP_BIT_ORDER_MAX = 0x38;

    // SPD JEDEC thresholds - protects against reserved values
    const bool VALID_LOWER_NIBBLE = (i_bit_order >= LOW_BIT_ORDER_MIN) && (i_bit_order <= LOW_BIT_ORDER_MAX);
    const bool VALID_UPPER_NIBBLE = (i_bit_order >= UP_BIT_ORDER_MIN) && (i_bit_order <= UP_BIT_ORDER_MAX);

    FAPI_TRY(mss::check::invalid_value(i_target,
                                       (VALID_LOWER_NIBBLE || VALID_UPPER_NIBBLE),
                                       i_byte,
                                       i_bit_order,
                                       mss::BAD_SPD_DATA,
                                       "Failed check on the NIBBLE_MAP field") );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function threshold check for package rank map
/// @param[in] i_target the DIMM target
/// @param[in] i_byte the SPD byte
/// @param[in] i_pkg_rank_map pakcage rank map value
/// @return FAPI2_RC_SUCCESS iff okay
///
static fapi2::ReturnCode package_rank_map_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_byte,
        const uint8_t i_pkg_rank_map )
{
    // Taken from the SPD JEDEC spec, only valid encoding, the rest are reserved
    constexpr uint64_t VALID_VALUE = 0;
    FAPI_TRY(mss::check::invalid_value(i_target,
                                       (i_pkg_rank_map == VALID_VALUE),
                                       i_byte,
                                       i_pkg_rank_map,
                                       mss::BAD_SPD_DATA,
                                       "Failed check on Package Rank Map") );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @class connectorTraits
/// @brief a collection of traits associated with the connector to SDRAM
/// @tparam T the connector_bits representing the DQ bits
/// @tparam OT the connector_field representing the SPD field
///
template< connector_bits T, connector_field OT >
class connectorTraits;

///
/// @class connectorTraits
/// @brief a collection of traits associated with the connector to SDRAM
/// @note DQ0_31, NIBBLE_MAP specialization
///
template< >
class connectorTraits<DQ0_31, NIBBLE_MAP>
{
    public:
        enum
        {
            START = 60,
            END = 67,
            EXTRACT_START = NIBBLE_MAP_START,
            EXTRACT_LEN = NIBBLE_MAP_LEN,

        };

        ///
        /// @brief SPD byte field threshold check
        /// @param[in] i_target the DIMM target
        /// @param[in] i_byte the SPD byte
        /// @param[in] i_bit_order the nibble bit order from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode fail_check( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint8_t i_byte,
                                             const uint8_t i_bit_order )
        {
            FAPI_TRY(nibble_map_helper(i_target, i_byte, i_bit_order) );

        fapi_try_exit:
            return fapi2::current_err;

        }
};

///
/// @class connectorTraits
/// @brief a collection of traits associated with the connector to SDRAM
/// @note DQ0_31, PKG_RANK_MAP specialization
///
template< >
class connectorTraits<DQ0_31, PKG_RANK_MAP>
{
    public:
        enum
        {
            START = 60,
            END = 67,
            EXTRACT_START = PACKAGE_RANK_MAP_START,
            EXTRACT_LEN = PACKAGE_RANK_MAP_LEN,
        };

        ///
        /// @brief SPD byte field threshold check
        /// @param[in] i_target the DIMM target
        /// @param[in] i_byte the SPD byte
        /// @param[in] i_pkg_rank_map pakcage rank map value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode fail_check( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint8_t i_byte,
                                             const uint8_t i_pkg_rank_map )
        {
            FAPI_TRY( package_rank_map_helper(i_target, i_byte, i_pkg_rank_map) );

        fapi_try_exit:
            return fapi2::current_err;

        }
};

///
/// @class connectorTraits
/// @brief a collection of traits associated with the connector to SDRAM
/// @note DQ32_63, NIBBLE_MAP specialization
///
template< >
class connectorTraits<DQ32_63, NIBBLE_MAP>
{
    public:
        enum
        {
            START = 70,
            END = 77,
            EXTRACT_START = NIBBLE_MAP_START,
            EXTRACT_LEN = NIBBLE_MAP_LEN,
        };

        ///
        /// @brief SPD byte field threshold check
        /// @param[in] i_target the DIMM target
        /// @param[in] i_byte the SPD byte
        /// @param[in] i_bit_order the nibble bit order from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode fail_check( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint8_t i_byte,
                                             const uint8_t i_bit_order )
        {
            FAPI_TRY(nibble_map_helper(i_target, i_byte, i_bit_order) );

        fapi_try_exit:
            return fapi2::current_err;

        }
};

///
/// @class connectorTraits
/// @brief a collection of traits associated with the connector to SDRAM
/// @note DQ32_63, PKG_RANK_MAP specialization
///
template< >
class connectorTraits<DQ32_63, PKG_RANK_MAP>
{
    public:
        enum
        {
            START = 70,
            END = 77,
            EXTRACT_START = PACKAGE_RANK_MAP_START,
            EXTRACT_LEN = PACKAGE_RANK_MAP_LEN,
        };

        ///
        /// @brief SPD byte field threshold check
        /// @param[in] i_target the DIMM target
        /// @param[in] i_byte the SPD byte
        /// @param[in] i_pkg_rank_map pakcage rank map value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode fail_check( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint8_t i_byte,
                                             const uint8_t i_pkg_rank_map )
        {
            FAPI_TRY( package_rank_map_helper(i_target, i_byte, i_pkg_rank_map) );

        fapi_try_exit:
            return fapi2::current_err;

        }
};

///
/// @class connectorTraits
/// @brief a collection of traits associated with the connector to SDRAM
/// @note CB0_7, NIBBLE_MAP specialization
///
template< >
class connectorTraits<CB0_7, NIBBLE_MAP>
{
    public:
        enum
        {
            START = 68,
            END = 69,
            EXTRACT_START = NIBBLE_MAP_START,
            EXTRACT_LEN = NIBBLE_MAP_LEN,
        };

        ///
        /// @brief SPD byte field threshold check
        /// @param[in] i_target the DIMM target
        /// @param[in] i_byte the SPD byte
        /// @param[in] i_bit_order the nibble bit order from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode fail_check( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint8_t i_byte,
                                             const uint8_t i_bit_order )
        {
            FAPI_TRY(nibble_map_helper(i_target, i_byte, i_bit_order) );

        fapi_try_exit:
            return fapi2::current_err;

        }
};

///
/// @class connectorTraits
/// @brief a collection of traits associated with the connector to SDRAM
/// @note CB0_7, PKG_RANK_MAP specialization
///
template< >
class connectorTraits<CB0_7, PKG_RANK_MAP>
{
    public:
        enum
        {
            START = 68,
            END = 69,
            EXTRACT_START = PACKAGE_RANK_MAP_START,
            EXTRACT_LEN = PACKAGE_RANK_MAP_LEN,
        };

        ///
        /// @brief SPD byte field threshold check
        /// @param[in] i_target the DIMM target
        /// @param[in] i_byte the SPD byte
        /// @param[in] i_pkg_rank_map pakcage rank map value
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode fail_check( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint8_t i_byte,
                                             const uint8_t i_pkg_rank_map )
        {
            FAPI_TRY( package_rank_map_helper(i_target, i_byte, i_pkg_rank_map) );

        fapi_try_exit:
            return fapi2::current_err;

        }
};

///
/// @class decoder
/// @tparam R SPD revision - partial specialization
/// @brief Base SPD DRAM decoder
///
template < rev R >
class decoder<DDR4, BASE_CNFG, R> : public base_cnfg_decoder
{
    private:

        using fields_t = fields<DDR4, BASE_CNFG>;
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        std::vector<uint8_t> iv_data;

        ///
        /// @brief SPD byte field threshold check
        /// @param[out] o_value list of connector_field values from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        template< connector_bits T, connector_field OT, typename TT = connectorTraits<T, OT> >
        fapi2::ReturnCode sdram_connector_helper( std::vector<uint8_t>& o_value ) const
        {
            for( size_t byte = TT::START; byte <= TT::END; ++byte )
            {
                uint8_t l_field = 0;

                fapi2::buffer<uint8_t> l_buffer(iv_data[byte]);
                l_buffer.extractToRight<TT::EXTRACT_START, TT::EXTRACT_LEN>(l_field);

                FAPI_DBG("%s SPD byte %d, data: %d, field value: %d, starting bit: %d, bit length: %d",
                         spd::c_str(iv_target), byte, iv_data[byte], l_field, TT::EXTRACT_START, TT::EXTRACT_LEN);

                FAPI_TRY( TT::fail_check(iv_target, byte, l_field) );

                o_value.push_back(l_field);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @class proxy
        /// @brief Nested class to help specialize certain decoder methods
        /// @tparam U SPD revision
        /// @tparam B dummy var to faciliate partial specialization - defaulted to true
        /// @note explicit specialization of a class isn't allowed on the HB compiler.
        /// This is a helper class to workaround specialization for just a few methods
        /// instead of having the explicitly specialize the entire class itself.
        /// Since nested classes also can't be explicitly specialized...we use a bool
        /// template param to facilitate partial specialzation of the nested helper class.
        ///
        template< rev U, bool B = true >
        struct proxy
        {
            ///
            /// @brief Decodes Minimum Write Recovery Time
            /// @param[in] i_target dimm target
            /// @param[in] i_data SPD data vector
            /// @param[out] o_value tWRmin in MTB units
            /// @return FAPI2_RC_SUCCESS iff okay
            ///
            static fapi2::ReturnCode min_twr( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                              const std::vector<uint8_t>& i_data,
                                              int64_t& o_value )
            {
                uint8_t l_twrmin_msn = 0;
                uint8_t l_twrmin_lsb = 0;

                FAPI_TRY( (mss::spd::reader<fields_t::TWRMIN_MSN, U>(i_target, i_data, l_twrmin_msn)) );
                FAPI_TRY( (mss::spd::reader<fields_t::TWRMIN_LSB, U>(i_target, i_data, l_twrmin_lsb)) );

                {
                    fapi2::buffer<int64_t> l_buffer;
                    right_aligned_insert(l_buffer, l_twrmin_msn, l_twrmin_lsb);

                    // Update output only after check passes
                    FAPI_TRY( check::max_timing_range<BITS12>(i_target, l_buffer, U, TWRMIN));
                    o_value = l_buffer;

                    FAPI_INF("%s. Minimum Write Recovery Time (tWRmin) in MTB units: %d",
                             spd::c_str(i_target),
                             o_value);
                }
            fapi_try_exit:
                return fapi2::current_err;
            }

            ///
            /// @brief Decodes Minimum Write to Read Time - Same Bank Group
            /// @param[in] i_target dimm target
            /// @param[in] i_data SPD data vector
            /// @param[out] o_value tWRT_Lmin in MTB units
            /// @return FAPI2_RC_SUCCESS iff okay
            ///
            static fapi2::ReturnCode min_twtr_l( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                 const std::vector<uint8_t>& i_data,
                                                 int64_t& o_value )
            {
                uint8_t l_twtr_lmin_msn = 0;
                uint8_t l_twtr_lmin_lsb = 0;

                FAPI_TRY( (mss::spd::reader<fields_t::TWTRMIN_L_MSN, U>(i_target, i_data, l_twtr_lmin_msn)) );
                FAPI_TRY( (mss::spd::reader<fields_t::TWTRMIN_L_LSB, U>(i_target, i_data, l_twtr_lmin_lsb)) );

                {
                    fapi2::buffer<int64_t> l_buffer;
                    right_aligned_insert(l_buffer, l_twtr_lmin_msn, l_twtr_lmin_lsb);

                    // Update output only after check passes
                    FAPI_TRY( check::max_timing_range<BITS12>(i_target, l_buffer, U, TWTR_L_MIN));
                    o_value = l_buffer;

                    FAPI_INF("%s. Minimum Write to Read Time - Different Bank Group (tWTR_Lmin) in MTB units: %d",
                             spd::c_str(i_target),
                             o_value);
                }

            fapi_try_exit:
                return fapi2::current_err;
            }

            ///
            /// @brief Decodes Minimum Write to Read Time - Different Bank Group
            /// @param[in] i_target dimm target
            /// @param[in] i_data SPD data vector
            /// @param[out] o_value tWRT_Smin in MTB units
            /// @return FAPI2_RC_SUCCESS iff okay
            ///
            static fapi2::ReturnCode min_twtr_s( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                 const std::vector<uint8_t>& i_data,
                                                 int64_t& o_value )
            {
                uint8_t l_twtr_smin_msn = 0;
                uint8_t l_twtr_smin_lsb = 0;

                FAPI_TRY( (mss::spd::reader<fields_t::TWTRMIN_S_MSN, U>(i_target, i_data, l_twtr_smin_msn)) );
                FAPI_TRY( (mss::spd::reader<fields_t::TWTRMIN_S_LSB, U>(i_target, i_data, l_twtr_smin_lsb)) );

                {
                    fapi2::buffer<int64_t> l_buffer;
                    right_aligned_insert(l_buffer, l_twtr_smin_msn, l_twtr_smin_lsb);

                    // Update output only after check passes
                    FAPI_TRY( check::max_timing_range<BITS12>(i_target, l_buffer, U, TWTR_S_MIN));
                    o_value = l_buffer;

                    FAPI_INF("%s. Minimum Write to Read Time - Different Bank Group (tWTR_Smin) in MTB units: %d",
                             spd::c_str(i_target),
                             o_value);
                }

            fapi_try_exit:
                return fapi2::current_err;
            }
        };

        ///
        /// @class proxy - rev::V1_0 specialization
        /// @brief Nested class to help specialize certain decoder methods
        /// @tparam B dummy var to faciliatate partial specialization
        /// @note If the decoder methods are rev::v1_0 hardcode them to these values
        ///
        template< bool B >
        struct proxy<rev::V1_0, B>
        {

            ///
            /// @brief Decodes Minimum Write Recovery Time
            /// @param[in] i_target dimm target
            /// @param[in] i_data SPD data vector
            /// @param[out] o_value tWRmin in MTB units
            /// @return FAPI2_RC_SUCCESS iff okay
            ///
            static fapi2::ReturnCode min_twr( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                              const std::vector<uint8_t>& i_data,
                                              int64_t& o_value )
            {
                // For General Section rev 1.0 of the SPD,
                // SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0) were reserved
                // and coded as zeros.
                // Default as 0x78 for all DDR4 bins for rev 1.0
                o_value = 0x78;
                return fapi2::FAPI2_RC_SUCCESS;
            }

            ///
            /// @brief Decodes Minimum Write to Read Time - Same Bank Group
            /// @param[in] i_target dimm target
            /// @param[in] i_data SPD data vector
            /// @param[out] o_value tWRT_Lmin in MTB units
            /// @return FAPI2_RC_SUCCESS iff okay
            ///
            static fapi2::ReturnCode min_twtr_l( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                 const std::vector<uint8_t>& i_data,
                                                 int64_t& o_value )
            {
                // For General Section rev 1.0 of the SPD,
                // SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0) were reserved
                // and coded as zeros.
                // Default as 0x3C for all DDR4 bins for rev 1.0
                o_value = 0x3C;
                return fapi2::FAPI2_RC_SUCCESS;
            }

            ///
            /// @brief Decodes Minimum Write to Read Time - Different Bank Group
            /// @param[in] i_target dimm target
            /// @param[in] i_data SPD data vector
            /// @param[out] o_value tWRT_Smin in MTB units
            /// @return FAPI2_RC_SUCCESS iff okay
            ///
            static fapi2::ReturnCode min_twtr_s( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                 const std::vector<uint8_t>& i_data,
                                                 int64_t& o_value )
            {
                // For General Section rev 1.0 of the SPD,
                // SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0) were reserved
                // and coded as zeros.
                // Default as 0x14 for all DDR4 bins for rev 1.0
                o_value = 0x14;
                return fapi2::FAPI2_RC_SUCCESS;
            }

        };

    public:

        ///
        /// @brief default ctor
        ///
        decoder() = default;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data SPD data vector
        ///
        decoder(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const std::vector<uint8_t>& i_spd_data):
            base_cnfg_decoder(i_target, i_spd_data),
            iv_target(i_target),
            iv_data(i_spd_data)
        {
            static_assert( R <= rev::GEN_SEC_MAX, " R > rev::GEN_SEC_MAX");
        }

        ///
        /// @brief Default dtor
        ///
        virtual ~decoder() = default;

        /////////////////////////
        // Member Methods
        /////////////////////////

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
        virtual fapi2::ReturnCode number_of_used_bytes( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::BYTES_USED, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes total number of SPD bytes
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode number_of_total_bytes( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TOTAL_BYTES, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDP revision
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode revision( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::REVISION, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM device type
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode device_type( uint8_t& o_value ) const override
        {
            // Sparsed reserved bits within valid SPD field range
            static const std::vector<uint8_t> l_reserved_bits{0x00, 0x0D};
            FAPI_TRY( (mss::spd::reader<fields_t::DEVICE_TYPE, R>(iv_target, iv_data, o_value)) );
            FAPI_TRY( check::reserved_values(iv_target, l_reserved_bits, DEVICE_TYPE, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes base module type
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode base_module( uint8_t& o_value ) const override
        {
            // Sparsed reserved bits within valid SPD field range
            static const std::vector<uint8_t> l_reserved_bits{0b0111, 0b1011, 0b1110, 0b1111};
            FAPI_TRY( (mss::spd::reader<fields_t::BASE_MODULE, R>(iv_target, iv_data, o_value)) );
            FAPI_TRY( check::reserved_values(iv_target, l_reserved_bits, BASE_MODULE_TYPE, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes hybrid media
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode hybrid_media( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::HYBRID_MEDIA, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes hybrid
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode hybrid( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::HYBRID, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM density from SPD
        /// @param[out] o_value SDRAM density in GBs
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sdram_density( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SDRAM_CAPACITY, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of SDRAM banks bits from SPD
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode bank_bits( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::BANKS_ADDR_BITS, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of SDRAM bank groups bits from SPD
        /// @param[out] o_value Number of SDRAM bank groups bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode bank_group_bits( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::BANK_GROUP_BITS, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of SDRAM column address bits
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode column_address_bits( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::COL_ADDR_BITS, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of SDRAM row address bits
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode row_address_bits( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::ROW_ADDR_BITS, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Primary SDRAM signal loading
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode prim_sdram_signal_loading( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PRIM_SIGNAL_LOADING, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Primary SDRAM die count
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual  fapi2::ReturnCode prim_sdram_die_count( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PRIM_DIE_COUNT, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Primary SDRAM package type
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode prim_sdram_package_type( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PRIM_PACKAGE_TYPE, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode SDRAM Maximum activate count
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode maximum_activate_count( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MAC, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode SDRAM Maximum activate window (multiplier), tREFI uknown at this point
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode maximum_activate_window_multiplier( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TMAW, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Post package repair (PPR)
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode post_package_repair( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PPR, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Soft post package repair (soft PPR)
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode soft_post_package_repair( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SOFT_PPR, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary SDRAM signal loading
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sec_sdram_signal_loading( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SEC_SIGNAL_LOADING, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary DRAM Density Ratio
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sec_dram_density_ratio( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SEC_DENSITY_RATIO, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary SDRAM die count
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sec_sdram_die_count( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SEC_DIE_COUNT, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Secondary SDRAM package type
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode sec_sdram_package_type( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SEC_PACKAGE_TYPE, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[out] o_value enum representing if 1.2V is operable
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode operable_nominal_voltage( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OPERABLE_FLD, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[out] o_value enum representing if 1.2V is endurant
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode endurant_nominal_voltage( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::ENDURANT_FLD, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM device width
        /// @param[out] o_value device width in bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode device_width( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::SDRAM_WIDTH, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes number of package ranks per DIMM
        /// @param[out] o_value number of package ranks per DIMM
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode num_package_ranks_per_dimm( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::PACKAGE_RANKS, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Rank Mix
        /// @param[out] o_value rank mix value from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode rank_mix( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::RANK_MIX, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes primary bus width
        /// @param[out] o_value primary bus width in bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode prim_bus_width( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::BUS_WIDTH, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes bus width extension
        /// @param[out] o_value bus width extension in bits
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode bus_width_extension( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::BUS_EXT_WIDTH, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Module Thermal Sensor
        /// @param[out] o_value thermal sensor value from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode thermal_sensor( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::THERM_SENSOR, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Extended Base Module Type
        /// @param[out] o_value extended base module type value from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode extended_base_module_type( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::EXTENDED_MODULE_TYPE, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Fine Timebase
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_timebase( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::FINE_TIMEBASE, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode Medium Timebase
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode medium_timebase( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MEDIUM_TIMEBASE, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        ///
        /// @brief Decodes SDRAM Minimum Cycle Time in MTB
        /// @param[out] o_value tCKmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_tck( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TCK_MIN, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Maximum Cycle Time in MTB
        /// @param[out] o_value tCKmax in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode max_tck( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TCK_MAX, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decode CAS Latencies Supported
        /// @param[out] o_value bitmap of supported CAS latencies
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode supported_cas_latencies( uint64_t& o_value ) const override
        {
            uint8_t l_first_raw_byte = 0;
            uint8_t l_sec_raw_byte = 0;
            uint8_t l_third_raw_byte = 0;
            uint8_t l_fourth_raw_byte = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::CL_FIRST_BYTE, R>(iv_target, iv_data, l_first_raw_byte)) );
            FAPI_TRY( (mss::spd::reader<fields_t::CL_SECOND_BYTE, R>(iv_target, iv_data, l_sec_raw_byte)) );
            FAPI_TRY( (mss::spd::reader<fields_t::CL_THIRD_BYTE, R>(iv_target, iv_data, l_third_raw_byte)) );
            FAPI_TRY( (mss::spd::reader<fields_t::CL_FOURTH_BYTE, R>(iv_target, iv_data, l_fourth_raw_byte)) );

            {
                // Buffers used for bit manipulation
                // Combine Bytes to create bitmap - right aligned
                fapi2::buffer<uint64_t> l_buffer;
                right_aligned_insert(l_buffer, l_fourth_raw_byte, l_third_raw_byte, l_sec_raw_byte, l_first_raw_byte);

                // According to the JEDEC spec:
                // Byte 22 (Bits 7~0) and Byte 23 are reserved in the base revision SPD general section
                // Only bit 6 (right-aligned) for Byte 23 is reserved for subsequent SPD revisions
                // Check for a valid value, and that reserved bit is not set
                // We return Byte 23 arbitrarily as the failed byte, but any byte (20 - 23) would work
                constexpr size_t MAX_VALID_VAL = (R == rev::V1_0) ? 0x0003FFFF : 0xBFFFFFFF;

                constexpr uint64_t DATA_START_OFFSET  = 32;
                constexpr uint64_t RESERVED_BIT = DATA_START_OFFSET + 1;
                // Bit 6 of byte 23 must be 0 (reserved for future use)
                const bool RESERVED_BIT_VALUE = l_buffer.getBit<RESERVED_BIT>();

                FAPI_TRY( mss::check::invalid_value(iv_target,
                                                    l_buffer <= MAX_VALID_VAL && !RESERVED_BIT_VALUE,
                                                    23,
                                                    l_buffer,
                                                    mss::BAD_SPD_DATA,
                                                    "Failed check on CAS latencies supported") );

                // Update output value only if range check passes
                o_value = int64_t(l_buffer);

                FAPI_INF("%s. CAS latencies supported (bitmap): 0x%llX",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum CAS Latency Time in MTB
        /// @param[out] o_value tAAmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_taa( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TAA_MIN, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum RAS to CAS Delay Time in MTB
        /// @param[out] o_value tRCDmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trcd( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TRCD_MIN, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Row Precharge Delay Time in MTB
        /// @param[out] o_value tRPmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trp( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TRP_MIN, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Active to Precharge Delay Time in MTB
        /// @param[out] o_value tRASmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_tras( int64_t& o_value ) const override
        {
            uint8_t l_tRASmin_msn = 0;
            uint8_t l_tRASmin_lsb = 0;
            FAPI_TRY( (mss::spd::reader<fields_t::TRASMIN_MSN, R>(iv_target, iv_data, l_tRASmin_msn)) );
            FAPI_TRY( (mss::spd::reader<fields_t::TRASMIN_LSB, R>(iv_target, iv_data, l_tRASmin_lsb)) );

            {
                fapi2::buffer<int64_t> l_buffer;
                right_aligned_insert(l_buffer, l_tRASmin_msn, l_tRASmin_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS12>(iv_target, l_buffer, R, TRASMIN));
                o_value = l_buffer;

                FAPI_INF("%s. Minimum Active to Precharge Delay Time (tRASmin) in MTB units: %d",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Active to Active/Refresh Delay Time in MTB
        /// @param[out] o_value tRCmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trc( int64_t& o_value ) const override
        {
            uint8_t l_trcmin_msn = 0;
            uint8_t l_trcmin_lsb = 0;
            FAPI_TRY( (mss::spd::reader<fields_t::TRCMIN_MSN, R>(iv_target, iv_data, l_trcmin_msn)) );
            FAPI_TRY( (mss::spd::reader<fields_t::TRCMIN_LSB, R>(iv_target, iv_data, l_trcmin_lsb)) );

            {
                // Combining bits to create timing value (in a buffer)
                fapi2::buffer<int64_t> l_buffer;
                right_aligned_insert(l_buffer, l_trcmin_msn, l_trcmin_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS12>(iv_target, l_buffer, R, TRCMIN));
                o_value = l_buffer;

                FAPI_INF("%s. Minimum Active to Active/Refresh Delay Time (tRCmin) in MTB units: %d",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 1
        /// @param[out] o_value tRFC1min in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trfc1( int64_t& o_value ) const override
        {
            uint8_t l_trfc1min_msb = 0;
            uint8_t l_trfc1min_lsb = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::TRFC1MIN_MSB, R>(iv_target, iv_data, l_trfc1min_msb)) );
            FAPI_TRY( (mss::spd::reader<fields_t::TRFC1MIN_LSB, R>(iv_target, iv_data, l_trfc1min_lsb)) );

            {
                // Combining bits to create timing value (in a buffer)
                fapi2::buffer<int64_t> l_buffer;
                right_aligned_insert(l_buffer, l_trfc1min_msb, l_trfc1min_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS16>(iv_target, l_buffer, R, TRFC1MIN));
                o_value = l_buffer;

                FAPI_INF("%s. Minimum Refresh Recovery Delay Time 1 (tRFC1min) in MTB units: %d",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 2
        /// @param[out] o_value tRFC2min in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trfc2( int64_t& o_value ) const override
        {
            uint8_t l_trfc2min_msb = 0;
            uint8_t l_trfc2min_lsb = 0;
            FAPI_TRY( (mss::spd::reader<fields_t::TRFC2MIN_MSB, R>(iv_target, iv_data, l_trfc2min_msb)) );
            FAPI_TRY( (mss::spd::reader<fields_t::TRFC2MIN_LSB, R>(iv_target, iv_data, l_trfc2min_lsb)) );

            {
                // Combining bits to create timing value (in a buffer)
                fapi2::buffer<int64_t> l_buffer;
                right_aligned_insert(l_buffer, l_trfc2min_msb, l_trfc2min_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS16>(iv_target, l_buffer, R, TRFC2MIN));
                o_value = l_buffer;

                FAPI_INF("%s. Minimum Refresh Recovery Delay Time 2 (tRFC2min) in MTB units: %d",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 4
        /// @param[out] o_value tRFC4min in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trfc4( int64_t& o_value ) const override
        {
            uint8_t l_trfc4min_msb = 0;
            uint8_t l_trfc4min_lsb = 0;
            FAPI_TRY( (mss::spd::reader<fields_t::TRFC4MIN_MSB, R>(iv_target, iv_data, l_trfc4min_msb)) );
            FAPI_TRY( (mss::spd::reader<fields_t::TRFC4MIN_LSB, R>(iv_target, iv_data, l_trfc4min_lsb)) );

            {
                // Combining bits to create timing value (in a buffer)
                fapi2::buffer<int64_t> l_buffer;
                right_aligned_insert(l_buffer, l_trfc4min_msb, l_trfc4min_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS16>(iv_target, l_buffer, R, TRFC4MIN));
                o_value = l_buffer;

                FAPI_INF("%s. Minimum Refresh Recovery Delay Time 4 (tRFC4min) in MTB units: %d",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes SDRAM Minimum Four Activate Window Delay Time
        /// @param[out] o_value tFAWmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_tfaw( int64_t& o_value ) const override
        {
            uint8_t l_tfawmin_msn = 0;
            uint8_t l_tfawmin_lsb = 0;
            FAPI_TRY( (mss::spd::reader<fields_t::TFAWMIN_MSN, R>(iv_target, iv_data, l_tfawmin_msn)) );
            FAPI_TRY( (mss::spd::reader<fields_t::TFAWMIN_LSB, R>(iv_target, iv_data, l_tfawmin_lsb)) );

            {
                // Combining bits to create timing value (in a buffer)
                fapi2::buffer<int64_t> l_buffer;
                right_aligned_insert(l_buffer, l_tfawmin_msn, l_tfawmin_lsb);

                // Update output only after check passes
                FAPI_TRY( check::max_timing_range<BITS12>(iv_target, l_buffer, R, TFAWMIN));
                o_value = l_buffer;

                FAPI_INF("%s. Minimum Four Activate Window Delay Time (tFAWmin) in MTB units: %d",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[out] o_value tRRD_Smin MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trrd_s( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TRRD_S_MIN, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[out] o_value tRRD_Lmin MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_trrd_l( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TRRD_L_MIN, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[out] o_value tCCD_Lmin MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_tccd_l( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::TCCD_L_MIN, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum Write Recovery Time
        /// @param[out] o_value tWRmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_twr( int64_t& o_value ) const override
        {
            FAPI_TRY( proxy<R>::min_twr(iv_target, iv_data, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Minimum Write to Read Time - Different Bank Group
        /// @param[out] o_value tWRT_Smin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_twtr_s( int64_t& o_value ) const override
        {
            FAPI_TRY( proxy<R>::min_twtr_s(iv_target, iv_data, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Decodes Minimum Write to Read Time - Same Bank Group
        /// @param[out] o_value tWRT_Lmin in MTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode min_twtr_l( int64_t& o_value ) const override
        {
            FAPI_TRY( proxy<R>::min_twtr_l(iv_target, iv_data, o_value) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Package Rank Map
        /// @param[out] o_value vector of package rank maps for SPD bytes 60 - 77
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode package_rank_map( std::vector<uint8_t>& o_value ) const override
        {
            o_value.clear();

            FAPI_TRY( (sdram_connector_helper<DQ0_31, PKG_RANK_MAP>(o_value)),
                      "%s Failed to sdram_connector_helper for DQ0_31, PKG_RANK_MAP", spd::c_str(iv_target) );

            FAPI_TRY( (sdram_connector_helper<DQ32_63, PKG_RANK_MAP>(o_value)),
                      "%s Failed to sdram_connector_helper for DQ32_63, PKG_RANK_MAP", spd::c_str(iv_target) );

            FAPI_TRY( (sdram_connector_helper<CB0_7, PKG_RANK_MAP>(o_value)),
                      "%s Failed to sdram_connector_helper for CB0_7, PKG_RANK_MAP", spd::c_str(iv_target) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Nibble Map
        /// @param[out] o_value vector of nibble map encoding for SPD bytes 60 - 77
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode nibble_map( std::vector<uint8_t>& o_value ) const override
        {
            o_value.clear();

            FAPI_TRY( (sdram_connector_helper<DQ0_31, NIBBLE_MAP>(o_value)),
                      "%s Failed to sdram_connector_helper for DQ0_31, NIBBLE_MAP", spd::c_str(iv_target) );

            FAPI_TRY( (sdram_connector_helper<DQ32_63, NIBBLE_MAP>(o_value)),
                      "%s Failed to sdram_connector_helper for DQ32_63, NIBBLE_MAP", spd::c_str(iv_target) );

            FAPI_TRY( (sdram_connector_helper<CB0_7, NIBBLE_MAP>(o_value)),
                      "%s Failed to sdram_connector_helper for CB0_7, NIBBLE_MAP", spd::c_str(iv_target) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[out] o_value tCCD_Lmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_tccd_l( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OFFSET_TCCD_L_MIN, R>(iv_target, iv_data, o_value)) );
            o_value = static_cast<int8_t>(o_value);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[out] o_value tRRD_Lmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_l( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OFFSET_TRRD_L_MIN, R>(iv_target, iv_data, o_value)) );
            o_value = static_cast<int8_t>(o_value);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[out] o_value tRRD_Smin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_s( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OFFSET_TRRD_S_MIN, R>(iv_target, iv_data, o_value)) );
            o_value = static_cast<int8_t>(o_value);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Active to Active/Refresh Delay Time
        /// @param[out] o_value tRCmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trc( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OFFSET_TRC_MIN, R>(iv_target, iv_data, o_value)) );
            o_value = static_cast<int8_t>(o_value);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for Minimum Row Precharge Delay Time
        /// @param[out] o_value tRPmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trp( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OFFSET_TRP_MIN, R>(iv_target, iv_data, o_value)) );
            o_value = static_cast<int8_t>(o_value);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum RAS to CAS Delay Time
        /// @param[out] o_value tRCDmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_trcd( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OFFSET_TRCD_MIN, R>(iv_target, iv_data, o_value)) );
            o_value = static_cast<int8_t>(o_value);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum CAS Latency Time
        /// @param[out] o_value tAAmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_taa( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OFFSET_TAA_MIN, R>(iv_target, iv_data, o_value)) );
            o_value = static_cast<int8_t>(o_value);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Maximum Cycle Time
        /// @param[out] o_value tCKmax offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_max_tck( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OFFSET_TCK_MAX, R>(iv_target, iv_data, o_value)) );
            o_value = static_cast<int8_t>(o_value);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum Cycle Time
        /// @param[out] o_value tCKmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode fine_offset_min_tck( int64_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::OFFSET_TCK_MIN, R>(iv_target, iv_data, o_value)) );
            o_value = static_cast<int8_t>(o_value);

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Cyclical Redundancy Code (CRC) for Base Configuration Section
        /// @param[out] o_value crc value from SPD
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode cyclical_redundancy_code( uint16_t& o_value ) const override
        {
            uint8_t l_crc_msb = 0;
            uint8_t l_crc_lsb = 0;
            FAPI_TRY( (mss::spd::reader<fields_t::CRC_MSB, R>(iv_target, iv_data, l_crc_msb)) );
            FAPI_TRY( (mss::spd::reader<fields_t::CRC_LSB, R>(iv_target, iv_data, l_crc_lsb)) );

            {
                // Combining bits to create timing value (in a buffer)
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_crc_msb, l_crc_lsb);

                // This value isn't bounded in the SPD document
                o_value = l_buffer;

                FAPI_INF("%s. Cyclical Redundancy Code (CRC): %d",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes module manufacturer ID code
        /// @param[out] o_output module manufacturing id code
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode module_manufacturer_id_code( uint16_t& o_value ) const override
        {
            uint8_t l_cont_codes = 0;
            uint8_t l_last_nonzero_byte = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::CONTINUATION_CODES, R>(iv_target, iv_data, l_cont_codes)) );
            FAPI_TRY( (mss::spd::reader<fields_t::LAST_NON_ZERO_BYTE, R>(iv_target, iv_data, l_last_nonzero_byte)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_last_nonzero_byte, l_cont_codes);

                o_value = l_buffer;

                FAPI_INF("%s.Module Manufacturer ID Code: %x",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Manufacturing Location
        /// @param[out] o_value uint8_t identifier for manufacturing location of memory module
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode module_manufacturing_location( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_MFG_LOCATION, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodesmodule manufacturing date
        /// @param[out] o_value the 2 byte date of manufacturing in BCD format
        /// @return FAPI2_RC_SUCCESS iff okay
        virtual fapi2::ReturnCode module_manufacturing_date( uint16_t& o_value ) const override
        {
            uint8_t l_date_msb = 0;
            uint8_t l_date_lsb = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_MFG_DATE_MSB, R>(iv_target, iv_data, l_date_msb)) );
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_MFG_DATE_LSB, R>(iv_target, iv_data, l_date_lsb)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_date_msb, l_date_lsb);

                o_value = l_buffer;

                FAPI_INF("%s.Module Manufacturer ID date: %x",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes module's unique serial number
        /// @param[out] o_value module's serial number
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode module_serial_number( uint32_t& o_value ) const override
        {
            uint8_t l_sn_byte_0 = 0;
            uint8_t l_sn_byte_1 = 0;
            uint8_t l_sn_byte_2 = 0;
            uint8_t l_sn_byte_3 = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_SERIAL_NUM_BYTE1, R>(iv_target, iv_data, l_sn_byte_0)) );
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_SERIAL_NUM_BYTE2, R>(iv_target, iv_data, l_sn_byte_1)) );
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_SERIAL_NUM_BYTE3, R>(iv_target, iv_data, l_sn_byte_2)) );
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_SERIAL_NUM_BYTE4, R>(iv_target, iv_data, l_sn_byte_3)) );

            {
                fapi2::buffer<uint32_t> l_buffer;
                right_aligned_insert(l_buffer, l_sn_byte_3, l_sn_byte_2, l_sn_byte_1, l_sn_byte_0);

                o_value = l_buffer;

                FAPI_INF("%s.Module Serial Number : 0x%08x",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes Module Revision Code
        /// @param[out] o_value uint8_t identifier for revision code
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode module_revision_code( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::MODULE_REV_CODE, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM Manufacturer ID code
        /// @param[out] o_value dram manufacturing id code
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode dram_manufacturer_id_code( uint16_t& o_value ) const override
        {
            uint8_t l_mfgid_msb = 0;
            uint8_t l_mfgid_lsb = 0;

            FAPI_TRY( (mss::spd::reader<fields_t::DRAM_MFR_ID_CODE_LSB, R>(iv_target, iv_data, l_mfgid_lsb)) );
            FAPI_TRY( (mss::spd::reader<fields_t::DRAM_MFR_ID_CODE_MSB, R>(iv_target, iv_data, l_mfgid_msb)) );

            {
                fapi2::buffer<uint16_t> l_buffer;
                right_aligned_insert(l_buffer, l_mfgid_msb, l_mfgid_lsb);

                o_value = l_buffer;

                FAPI_INF("%s.DRAM Manufacturer ID Code: %x",
                         spd::c_str(iv_target),
                         o_value);
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Decodes DRAM Stepping
        /// @param[out] o_value uint8_t DRAM Stepping val
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        virtual fapi2::ReturnCode dram_stepping( uint8_t& o_value ) const override
        {
            FAPI_TRY( (mss::spd::reader<fields_t::DRAM_STEPPING, R>(iv_target, iv_data, o_value)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

};// decoder

}// spd
}// mss

#endif //_MSS_SPD_DECODER_H_
