/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_factory_pattern.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file spd_factory_pattern.H
/// @brief SPD factory pattern declaration
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_FACTORY_PATTERN_H_
#define _MSS_SPD_FACTORY_PATTERN_H_

#include <fapi2.H>
#include <cstdint>
#include <map>
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <generic/memory/lib/spd/rdimm/ddr4/rdimm_decoder_ddr4.H>
#include <generic/memory/lib/spd/lrdimm/ddr4/lrdimm_decoder_ddr4.H>
#include <generic/memory/lib/spd/ddimm/ddr4/ddimm_decoder_ddr4.H>
#include <generic/memory/lib/spd/spd_checker.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
///
/// @class moduleFactoryTraits
/// @brief class that holds module factory traits
/// @tparam T the decoder type we want the factory to generate
///
template < typename T >
struct moduleFactoryTraits;

///
/// @class moduleFactoryTraits - base_cnfg_decoder specialization
/// @brief class that holds module factory traits
///
template< >
struct moduleFactoryTraits<spd::base_cnfg_decoder>
{
    static constexpr generic_ffdc_codes MODULE_FACTORY_FFDC_CODE = BASE_CFG_FACTORY;
};

///
/// @class moduleFactoryTraits - dimm_module_decoder specialization
/// @brief class that holds module factory traits
///
template< >
struct moduleFactoryTraits<spd::dimm_module_decoder>
{
    static constexpr generic_ffdc_codes MODULE_FACTORY_FFDC_CODE = DIMM_MODULE_FACTORY;
};

namespace spd
{

///
/// @class module_key
/// @brief SPD module key for factory
///
struct module_key
{
    uint8_t iv_rev;
    uint8_t iv_dram_gen;
    module_params iv_module_type;

    ///
    /// @brief default ctor
    ///
    module_key() = default;

    ///
    /// @brief constexpr ctor
    /// @param[in] i_dram_gen DRAM generation
    /// @param[in] i_spd_param DIMM type
    /// @param[in] i_rev SPD revision
    ///
    module_key(const uint8_t i_dram_gen,
               const module_params i_spd_param,
               const uint8_t i_rev);

    ///
    /// @brief default dtor
    ///
    ~module_key() = default;

    ///
    /// @brief less-than operator
    /// @param[in] i_rhs the module_key
    /// @return true or false
    ///
    bool operator<(const module_key& i_rhs) const;

};// module_key

///
/// @brief Class that performs revision fallback
/// @class rev_fallback
///
class rev_fallback
{
    public:

        ///
        /// @brief ctor
        /// @param[in] i_target the DIMM target
        /// @param[in] i_key the module_key
        ///
        rev_fallback(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                     const module_key& i_key);

        ///
        /// @brief dtor
        ///
        ~rev_fallback() = default;

        ///
        /// @brief Retrieves highest supported SPD revision
        /// @param[out] o_rev SPD revision
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode get_supported_rev(uint8_t& o_rev) const;

    private:

        enum
        {
            LEN = 4,
            ENCODINGS_REV_START = 0,
            ADDITIONS_REV_START = 4,
        };

        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        module_key iv_key;
        uint8_t iv_encoding_level;
        uint8_t iv_additions_level;

        // Constants convenient for map indexing
        const module_key LRDIMM_DDR4_V1_0;
        const module_key LRDIMM_DDR4_V1_1;
        const module_key LRDIMM_DDR4_V1_2;

        const module_key RDIMM_DDR4_V1_0;
        const module_key RDIMM_DDR4_V1_1;

        const module_key NVDIMM_DDR4_V1_0;
        const module_key NVDIMM_DDR4_V1_1;

        const module_key DDIMM_DDR4_V0_3;

        std::map<module_key, uint8_t> iv_lrdimm_rev_map;
        std::map<module_key, uint8_t> iv_rdimm_rev_map;
        std::map<module_key, uint8_t> iv_nvdimm_rev_map;
        std::map<module_key, uint8_t> iv_ddimm_rev_map;
        std::map< module_params, std::map<module_key, uint8_t> > iv_spd_param_map;

        ///
        /// @brief Helper function to select the largest SPD revision
        /// @param[in] i_map a map of supported SPD revisions for a certain SPD param
        /// @param[out] o_rev the SPD Revision
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        void select_highest_rev( const std::map<module_key, uint8_t>& i_map,
                                 uint8_t& o_rev) const;

        ///
        /// @brief Helper function to check non-backward compatible encoding level changes
        /// @param[in] i_map Map of supported SPD revisions for a certain SPD param
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode check_encoding_level(const std::map<module_key, uint8_t>& i_map) const;
};

///
/// @class module_factory
/// @tparam T module decoder type (e.g. base_cnfg_decoder, dimm_module_decoder)
/// @tparam TT defaulted to moduleFactoryTraits<T>
/// @brief Factory method for SPD module module_params
///
template < typename T, typename TT = moduleFactoryTraits<T> >
class module_factory
{
    public:

        ///
        /// @brief ctor
        /// @param[in] i_target the DIMM target
        /// @param[in] i_spd_data SPD data in a vector reference
        ///
        module_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                       const std::vector<uint8_t>& i_spd_data):
            iv_target(i_target),
            LRDIMM_DDR4_REV_1_0 {DDR4, LRDIMM_MODULE, rev::V1_0},
            LRDIMM_DDR4_REV_1_1 {DDR4, LRDIMM_MODULE, rev::V1_1},
            LRDIMM_DDR4_REV_1_2 {DDR4, LRDIMM_MODULE, rev::V1_2},
            RDIMM_DDR4_REV_1_0  {DDR4, RDIMM_MODULE,  rev::V1_0},
            RDIMM_DDR4_REV_1_1  {DDR4, RDIMM_MODULE,  rev::V1_1},
            NVDIMM_DDR4_REV_1_0 {DDR4, NVDIMM_MODULE, rev::V1_0},
            NVDIMM_DDR4_REV_1_1 {DDR4, NVDIMM_MODULE, rev::V1_1},
            DDIMM_DDR4_REV_0_3  {DDR4, DDIMM_MODULE,  rev::V0_3}
        {
            // Setup pre-defined maps available to search through
            init_map_vars(i_spd_data, iv_decoder_map);
        }

        ///
        /// @brief default dtor
        ///
        ~module_factory() = default;

        ///
        /// @brief creates module_decoder object from key
        /// @param[in,out] io_key the module key
        /// @param[out] o_decoder_ptr the dimm_module_decoder object ptr
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode make_object(module_key& io_key,
                                      std::shared_ptr<T>& o_decoder_ptr) const
        {
            auto it = iv_decoder_map.find(io_key);

            // If we found matching key, return that associated decoder
            if(it != iv_decoder_map.end())
            {
                o_decoder_ptr = it->second;
                return fapi2::FAPI2_RC_SUCCESS;
            }

            // If we are here that means we didn't find a matching key-value pair.
            // So we will dig deeper to evaluate the issue and try to fallback to
            // a supported (backward compatible) SPD revision.
            FAPI_TRY( try_fallback(io_key, o_decoder_ptr) );

        fapi_try_exit:
            return fapi2::current_err;
        }

    private:

        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;

        // Indexing member vars for convenient map indexing
        const module_key LRDIMM_DDR4_REV_1_0;
        const module_key LRDIMM_DDR4_REV_1_1;
        const module_key LRDIMM_DDR4_REV_1_2;
        const module_key RDIMM_DDR4_REV_1_0;
        const module_key RDIMM_DDR4_REV_1_1;
        const module_key NVDIMM_DDR4_REV_1_0;
        const module_key NVDIMM_DDR4_REV_1_1;
        const module_key DDIMM_DDR4_REV_0_3;

        std::map< module_key, std::shared_ptr<T> > iv_decoder_map;

        ///
        /// @brief Helper function to initialize base_cnfg_decoder map
        /// @param[out] o_map base_cnfg_decoder map
        ///
        void init_map_vars(const std::vector<uint8_t>& i_spd_data,
                           std::map< module_key, std::shared_ptr<base_cnfg_decoder> >& o_map)
        {
            //
            // RDIMMs
            //

            // Rev 1.0
            // Life starts out at base revision level
            o_map[RDIMM_DDR4_REV_1_0] = std::make_shared< decoder<DDR4, BASE_CNFG, rev::V1_0> >(iv_target, i_spd_data);

            // Rev 1.1
            // Changes to both the general section & rdimm section occured
            o_map[RDIMM_DDR4_REV_1_1] = std::make_shared< decoder<DDR4, BASE_CNFG, rev::V1_1> >(iv_target, i_spd_data);

            //
            // LRDIMMs
            //

            // Rev 1.0
            // Life starts out at base revision level
            o_map[LRDIMM_DDR4_REV_1_0] = std::make_shared< decoder<DDR4, BASE_CNFG, rev::V1_0> >(iv_target, i_spd_data);

            // Rev 1.1
            // Changes to both the general section & lrdimm section occured
            o_map[LRDIMM_DDR4_REV_1_1] = std::make_shared< decoder<DDR4, BASE_CNFG, rev::V1_1> >(iv_target, i_spd_data);

            // Rev 1.2
            // Changes lrdimm section occured
            // General section remained the same
            o_map[LRDIMM_DDR4_REV_1_2] = std::make_shared< decoder<DDR4, BASE_CNFG, rev::V1_1> >(iv_target, i_spd_data);

            //
            // NVDIMMs
            //

            // Rev 1.0
            // NVDIMMs start out life w/the updated general section (not a base level).
            o_map[NVDIMM_DDR4_REV_1_0] = std::make_shared< decoder<DDR4, BASE_CNFG, rev::V1_1> >(iv_target, i_spd_data);

            // Rev 1.1
            // Changes to the NVDIMM module occured, general section remains the same
            o_map[NVDIMM_DDR4_REV_1_1] = std::make_shared< decoder<DDR4, BASE_CNFG, rev::V1_1> >(iv_target, i_spd_data);

            //
            // DDIMMs
            //

            // Current emulation level
            // Rev 0.3
            // DDIMMs start out life w/the latest general SPD section
            // From rev 0.0 to 0.3 New thermal sensor fields and pmic redundancy fields
            o_map[DDIMM_DDR4_REV_0_3] = std::make_shared< decoder<DDR4, BASE_CNFG, rev::V0_3> >(iv_target, i_spd_data);

        }

        ///
        /// @brief Helper function to initialize dimm_module_decoder map
        /// @param[out] o_map dimm_module_decoder map
        ///
        void init_map_vars(const std::vector<uint8_t>& i_spd_data,
                           std::map< module_key, std::shared_ptr<dimm_module_decoder> >& o_map)
        {
            //
            // RDIMMs
            //

            // Rev 1.0
            // Life starts out at base revision level
            o_map[RDIMM_DDR4_REV_1_0] = std::make_shared< decoder<DDR4, RDIMM_MODULE, rev::V1_0> >(iv_target, i_spd_data);

            // Rev 1.1
            // Changes to both the general section & rdimm section occured
            o_map[RDIMM_DDR4_REV_1_1] = std::make_shared< decoder<DDR4, RDIMM_MODULE, rev::V1_1> >(iv_target, i_spd_data);

            //
            // LRDIMMs
            //

            // Rev 1.0
            // Life starts out at base revision level
            o_map[LRDIMM_DDR4_REV_1_0] = std::make_shared< decoder<DDR4, LRDIMM_MODULE, rev::V1_0> >(iv_target, i_spd_data);

            // Rev 1.1
            // Changes to both the general section & lrdimm section occured
            o_map[LRDIMM_DDR4_REV_1_1] = std::make_shared< decoder<DDR4, LRDIMM_MODULE, rev::V1_1> >(iv_target, i_spd_data);

            // Rev 1.2
            // Changes lrdimm section occured
            // General section remained the same
            o_map[LRDIMM_DDR4_REV_1_2] = std::make_shared< decoder<DDR4, LRDIMM_MODULE, rev::V1_2> >(iv_target, i_spd_data);

            //
            // DDIMMs
            //

            // Current emulation level
            // Rev 0.3
            // Life starts out at base revision level
            // DDIMMs start out life w/the latest general SPD section
            // From rev 0.0 to 0.3 New thermal sensor fields and pmic redundancy fields
            o_map[DDIMM_DDR4_REV_0_3] = std::make_shared< decoder<DDR4, DDIMM_MODULE, rev::V0_3> >(iv_target, i_spd_data);
        }

        ///
        /// @brief Try to fallback to a supported backward compatible decoder
        /// @param[in,out] io_key the module key
        /// @param[out] o_rev SPD revision we are falling back to
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode find_backward_compatible_rev(module_key& io_key) const
        {
            const rev_fallback l_rev_fallback(iv_target, io_key);

            // Overwrite io_key.iv_rev with a supported revision
            FAPI_TRY(l_rev_fallback.get_supported_rev(io_key.iv_rev));

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Create a decoder with the fallback module_key
        /// @param[in] i_key the module key
        /// @param[out] o_decoder_ptr decoder ptr
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode create_fallback_decoder(const module_key& i_key,
                std::shared_ptr<T>& o_decoder_ptr) const
        {
            auto it = iv_decoder_map.find(i_key);

            // Sanity check, should never fail unless it's a programming error...
            constexpr generic_ffdc_codes FFDC_CODE = TT::MODULE_FACTORY_FFDC_CODE;

            FAPI_ASSERT( it != iv_decoder_map.end(),
                         fapi2::MSS_FAILED_SPD_REVISION_FALLBACK()
                         .set_FAILED_REVISION(i_key.iv_rev)
                         .set_FUNCTION_CODE(FFDC_CODE)
                         .set_TARGET(iv_target),
                         "Failed to find a map value for the key (rev 0x%02, param %d, dram gen: %d",
                         i_key.iv_rev, i_key.iv_module_type, i_key.iv_dram_gen);

            // Update SPD rev to fallback rev
            {
                constexpr size_t REV_BYTE = 1;
                o_decoder_ptr = it->second;
                std::vector<uint8_t> l_spd_data = o_decoder_ptr->get_data();
                l_spd_data[REV_BYTE] = i_key.iv_rev;
                o_decoder_ptr->set_data(l_spd_data);
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Try to fallback to a supported backward compatible decoder
        /// @param[in,out] io_key the module key
        /// @param[out] o_decoder_ptr the o_decoder_ptr object ptr
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode try_fallback(module_key& io_key,
                                       std::shared_ptr<T>& o_decoder_ptr) const
        {
            // Invalid DRAM gen is a hard fail
            FAPI_TRY(check::dram_gen(iv_target, io_key.iv_dram_gen, TT::MODULE_FACTORY_FFDC_CODE));

            {
                const uint8_t l_dimm_type = io_key.iv_module_type == RDIMM_MODULE ? RDIMM : LRDIMM;
                // Invalid DIMM type is a hard fail
                FAPI_TRY(check::dimm_type(iv_target, l_dimm_type, TT::MODULE_FACTORY_FFDC_CODE));
            }

            // We can circumvent SPD revision fails by using backward compatible revisions
            FAPI_TRY(find_backward_compatible_rev(io_key));

            // Let's create a new decoder that we can fall back to
            FAPI_TRY(create_fallback_decoder(io_key, o_decoder_ptr));

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @class factories
/// @brief Factory method that creates the right decoder based on SPD data
///
class factories
{
    public:

        ///
        /// @brief ctor
        /// @param[in] i_target the DIMM target
        /// @param[in] i_spd_data SPD data in a vector reference
        /// @param[out] o_rc FAPI2_RC_SUCCESS iff okay
        ///
        factories(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                  const std::vector<uint8_t>& i_spd_data,
                  fapi2::ReturnCode& o_rc);

        ///
        /// @brief default dtor
        ///
        ~factories() = default;


        ///
        /// @brief creates base_cnfg_decoder object
        /// @param[out] o_decoder_ptr the base_cnfg_decoder object ptr
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode create_decoder( std::shared_ptr<base_cnfg_decoder>& o_decoder_ptr ) const;

        ///
        /// @brief creates dimm_module_decoder object
        /// @param[out] o_decoder_ptr the dimm_module_decoder object ptr
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode create_decoder( std::shared_ptr<dimm_module_decoder>& o_decoder_ptr ) const;

    private:

        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        std::vector<uint8_t> iv_spd_data;
        uint8_t iv_rev;
        uint8_t iv_dram_gen;
        uint8_t iv_base_module_type;
        uint8_t iv_hybrid;
        uint8_t iv_hybrid_media;

        ///
        /// @brief Helper to select SPD parameter for the dimm module
        /// @param[out] o_param SPD parameter
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode dimm_module_select_param(module_params& o_param) const;

        ///
        /// @brief Helper to select SPD parameter for the base cfg
        /// @param[out] o_param SPD parameter
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode base_cfg_select_param(module_params& o_param) const;

};

}// spd
}// mss

#endif //_MSS_SPD_FACTORY_PATTERN_H_
