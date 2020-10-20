/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/dimm/kind.H $             */
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
/// @file kind.H
/// @brief Encapsulation for dimms of all types
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _GENERIC_KIND_H_
#define _GENERIC_KIND_H_

#include <fapi2.H>

#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief DIMM kinds of DIMM/DRAM used to descriminate in templates.
/// @note These must be contiguous and unique
///
enum kind_t
{
    // The default, base, etc. kind. Used to define the function
    // which would be in a base class. Also used to stop the
    // metaprogramming recursion of the dispatcher functions.
    DEFAULT_KIND = 0,

    // DIMM type and DRAM Generation representation
    KIND_RDIMM_EMPTY = 1,
    KIND_RDIMM_DDR4 = 2,
    KIND_LRDIMM_EMPTY = 3,
    KIND_LRDIMM_DDR4 = 4,

    // Used to force dispatching looking for overloads
    // This moust always be one more than that largest
    // kind_t.
    FORCE_DISPATCH = 4 + 1,
};

namespace dimm
{

///
/// @class mss::dimm::kind
/// @tparam MC the MC type
/// @brief A class containing information about a dimm like ranks, density, configuration - what kind of dimm is it?
///
template<mss::mc_type MC = DEFAULT_MC_TYPE>
class kind
{
    public:

        ///
        /// @brief Generate a vector of DIMM kind from a vector of DIMM
        /// @param[in] i_dimm a vector of DIMM
        /// @return std::vector of dimm::kind relating to the DIMM passed in
        ///
        static std::vector<kind> vector(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& i_dimm)
        {
            std::vector<kind> l_kinds;

            for (const auto& d : i_dimm)
            {
                l_kinds.push_back( kind(d) );
            }

            return l_kinds;
        }

        ///
        /// @brief operator=() - assign kinds (needed to sort vectors of kinds)
        /// @param[in] i_rhs the right hand side of the assignment statement
        /// @return reference to this
        ///
        inline kind& operator=(const kind& i_rhs)
        {
            iv_target = i_rhs.iv_target;
            iv_master_ranks = i_rhs.iv_master_ranks;
            iv_total_ranks = i_rhs.iv_total_ranks;
            iv_dram_density = i_rhs.iv_dram_density;
            iv_dram_width = i_rhs.iv_dram_width;
            iv_dram_generation = i_rhs.iv_dram_generation;
            iv_dimm_type = i_rhs.iv_dimm_type;
            iv_rows = i_rhs.iv_rows;
            iv_size = i_rhs.iv_size;
            iv_mfgid = i_rhs.iv_mfgid;
            iv_stack_type = i_rhs.iv_stack_type;
            iv_hybrid = i_rhs.iv_hybrid;
            iv_hybrid_memory_type = i_rhs.iv_hybrid_memory_type;
            iv_rcd_mfgid = i_rhs.iv_rcd_mfgid;
            iv_module_height = i_rhs.iv_module_height;
            return *this;
        }

        ///
        /// @brief operator==() - are two kinds the same?
        /// @param[in] i_rhs the right hand side of the comparison statement
        /// @return bool true iff the two kind are of the same kind
        /// @warning this does not compare the targets (iv_target,) just the values
        /// Also does not compare the mfgid as that's not really part of the DIMM kind but is additional information
        ///
        inline bool operator==(const kind& i_rhs) const
        {
            return ((iv_master_ranks == i_rhs.iv_master_ranks) &&
                    (iv_total_ranks == i_rhs.iv_total_ranks) &&
                    (iv_dram_density == i_rhs.iv_dram_density) &&
                    (iv_dram_width == i_rhs.iv_dram_width) &&
                    (iv_dram_generation == i_rhs.iv_dram_generation) &&
                    (iv_dimm_type == i_rhs.iv_dimm_type) &&
                    (iv_rows == i_rhs.iv_rows) &&
                    (iv_size == i_rhs.iv_size) &&
                    (iv_stack_type == i_rhs.iv_stack_type) &&
                    (iv_hybrid == i_rhs.iv_hybrid) &&
                    (iv_hybrid_memory_type == i_rhs.iv_hybrid_memory_type) &&
                    (iv_rcd_mfgid == i_rhs.iv_rcd_mfgid) &&
                    (iv_module_height == i_rhs.iv_module_height));
        }

        ///
        /// @brief operator!=() - are two kinds different?
        /// @param[in] i_rhs the right hand side of the comparison statement
        /// @return bool true iff the two kind are of different
        /// @warning this does not compare the targets (iv_target,) just the values
        ///
        inline bool operator!=(const kind& i_rhs) const
        {
            return !(this->operator==(i_rhs));
        }

        ///
        /// @brief Construct a dimm::kind data structure - information about the kind of DIMM this is
        /// @param[in] i_target a DIMM target
        ///
        kind(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target):
            iv_target(i_target)
        {
            FAPI_TRY( mss::attr::get_dram_gen(i_target, iv_dram_generation) );
            FAPI_TRY( mss::attr::get_dimm_type(i_target, iv_dimm_type) );
            FAPI_TRY( mss::attr::get_dram_density(i_target, iv_dram_density) );
            FAPI_TRY( mss::attr::get_dram_width(i_target, iv_dram_width) );
            FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(i_target, iv_master_ranks) );
            FAPI_TRY( mss::attr::get_logical_ranks_per_dimm(i_target, iv_total_ranks) );
            FAPI_TRY( mss::attr::get_dram_row_bits(i_target, iv_rows) );
            FAPI_TRY( mss::attr::get_dimm_size(i_target, iv_size) );
            FAPI_TRY( mss::attr::get_dram_mfg_id(i_target, iv_mfgid) );
            FAPI_TRY( mss::attr::get_prim_stack_type( i_target, iv_stack_type) );
            FAPI_TRY( mss::attr::get_hybrid( i_target, iv_hybrid ));
            FAPI_TRY( mss::attr::get_hybrid_memory_type( i_target, iv_hybrid_memory_type ));
            FAPI_TRY( mss::attr::get_rcd_mfg_id(i_target, iv_rcd_mfgid) );
            FAPI_TRY( mss::attr::get_dram_module_height(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target),
                      iv_module_height) );

            return;

        fapi_try_exit:
            // Not 100% sure what to do here ...
            FAPI_ERR("error initializing DIMM structure: %s 0x%016lx", mss::c_str(i_target), uint64_t(fapi2::current_err));
            fapi2::Assert(false);
        }

        ///
        /// @brief Construct a DIMM kind used to identify this DIMM for tables.
        /// @param[in] i_master_ranks number of master ranks on the DIMM
        /// @param[in] i_total_ranks total number of ranks on the DIMM
        /// @param[in] i_dram_density density of the DRAM
        /// @param[in] i_dram_width width of the DRAM
        /// @param[in] i_dram_generation DRAM generation
        /// @param[in] i_dimm_type DIMM type (e.g. RDIMM)
        /// @param[in] i_rows number of rows in the DRAM
        /// @param[in] i_size the overal size of the DIMM in GB
        /// @param[in] i_mfgid the dram manufacturer id of the dimm, defaulted to 0
        /// @param[in] i_stack_type dram die type, single die package or 3DS
        /// @param[in] i_hybrid, default not hybrid
        /// @param[in] i_hybrid_memory_type, defult none
        /// @param[in] i_rcd_mfgid dimm register and data buffer manufacturer id, default 0
        /// @note can't be constexpr as fapi2::Target doesn't have a constexpr ctor.
        ///
        kind( const uint8_t i_master_ranks,
              const uint8_t i_total_ranks,
              const uint8_t i_dram_density,
              const uint8_t i_dram_width,
              const uint8_t i_dram_generation,
              const uint8_t i_dimm_type,
              const uint8_t i_rows,
              const uint32_t i_size,
              const uint16_t i_mfgid = 0,
              const uint8_t i_stack_type = fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_SDP,
              const uint8_t i_hybrid = fapi2::ENUM_ATTR_EFF_HYBRID_NOT_HYBRID,
              const uint8_t i_hybrid_memory_type = fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NONE,
              const uint16_t i_rcd_mfgid = 0,
              const uint8_t i_module_height = 0
            ):
            iv_target(0),
            iv_master_ranks(i_master_ranks),
            iv_total_ranks(i_total_ranks),
            iv_dram_density(i_dram_density),
            iv_dram_width(i_dram_width),
            iv_dram_generation(i_dram_generation),
            iv_dimm_type(i_dimm_type),
            iv_rows(i_rows),
            // TK consider calculating size rather than requiring it be set.
            iv_size(i_size),
            iv_mfgid(i_mfgid),
            iv_stack_type(i_stack_type),
            iv_hybrid(i_hybrid),
            iv_hybrid_memory_type(i_hybrid_memory_type),
            iv_rcd_mfgid(i_rcd_mfgid),
            iv_module_height(i_module_height)
        {
            // Bit of an idiot-check to be sure a hand-crafted dimm::kind make sense wrt slaves, masters, packages, etc.
            // Both of these are checked in eff_config. If they are messed up, they should be caught there
            if (iv_master_ranks > iv_total_ranks)
            {
                FAPI_ERR("Not enough total ranks? master: %d total: %d",
                         iv_master_ranks,
                         iv_total_ranks);
                fapi2::Assert(false);
            }

            if ((iv_total_ranks % iv_master_ranks) != 0)
            {
                FAPI_ERR("total or master ranks seems incorrect. master: %d total: %d",
                         iv_master_ranks,
                         iv_total_ranks);
                fapi2::Assert(false);
            }

        }

        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        uint8_t iv_master_ranks;
        uint8_t iv_total_ranks;
        uint8_t iv_dram_density;
        uint8_t iv_dram_width;
        uint8_t iv_dram_generation;
        uint8_t iv_dimm_type;
        uint8_t iv_rows;
        uint32_t iv_size;
        uint16_t iv_mfgid;
        uint8_t iv_stack_type;
        uint8_t iv_hybrid;
        uint8_t iv_hybrid_memory_type;
        uint16_t iv_rcd_mfgid;
        uint8_t iv_module_height;

        ///
        /// @brief equal_config
        /// @param[in] i_input_compare the i_kind to compare against
        /// @return bool true iff the two kind are of the same kind for xlate purposes
        /// @warning this does not compare the targets (iv_target,), mfgid, prim_stack_type nor hybrid type
        ///
        inline bool equal_config(const kind& i_input_compare) const
        {
            return ((iv_master_ranks == i_input_compare.iv_master_ranks) &&
                    (iv_total_ranks == i_input_compare.iv_total_ranks) &&
                    (iv_dram_density == i_input_compare.iv_dram_density) &&
                    (iv_dram_width == i_input_compare.iv_dram_width) &&
                    (iv_dram_generation == i_input_compare.iv_dram_generation) &&
                    (iv_dimm_type == i_input_compare.iv_dimm_type) &&
                    (iv_rows == i_input_compare.iv_rows) &&
                    (iv_size == i_input_compare.iv_size));
        }
};

///
/// @brief Check if any dimms exist that have RCD enabled
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType (derived)
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode has_rcd( const fapi2::Target<T>& i_target,
                           bool& o_has_rcd );

///
/// @brief Check if the dimm is hybrid media type MDS
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType (derived)
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_is_mds - true iff any dimm is MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode is_mds( const fapi2::Target<T>& i_target,
                          bool& o_is_mds );


} // end dimm ns

} // end mss ns
#endif
