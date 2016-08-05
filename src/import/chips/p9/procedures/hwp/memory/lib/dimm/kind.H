/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/kind.H $   */
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
/// @file dimm.H
/// @brief Encapsulation for dimms of all types
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_DIMM_H_
#define _MSS_DIMM_H_

#include <fapi2.H>

#include <lib/mss_attribute_accessors.H>
#include <lib/utils/c_str.H>

namespace mss
{

namespace dimm
{

///
/// @class mss::dimm::kind
/// @brief A class containing information about a dimm like ranks, density, configuration - what kind of dimm is it?
///
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
        /// @brief operator==() - are two kinds the same?
        /// @param[in] i_rhs the right hand side of the comparison statement
        /// @return boll true iff the two kind are of the same kind
        /// @warning this does not compare the targets (iv_target,) just the values
        ///
        inline bool operator==(const kind& i_rhs) const
        {
            return ((iv_master_ranks == i_rhs.iv_master_ranks) &&
                    (iv_slave_ranks == i_rhs.iv_slave_ranks) &&
                    (iv_dram_density == i_rhs.iv_dram_density) &&
                    (iv_dram_width == i_rhs.iv_dram_width) &&
                    (iv_dram_generation == i_rhs.iv_dram_generation) &&
                    (iv_dimm_type == i_rhs.iv_dimm_type) &&
                    (iv_rows == i_rhs.iv_rows) &&
                    (iv_size == i_rhs.iv_size));
        }

        ///
        /// @brief Construct a dimm::kind data structure - information about the kind of DIMM this is
        /// @param[in] i_target a DIMM target
        ///
        kind(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target):
            iv_target(i_target)
        {
            uint8_t l_ranks = 0;

            FAPI_TRY( mss::eff_dram_gen(i_target, iv_dram_generation) );
            FAPI_TRY( mss::eff_dimm_type(i_target, iv_dimm_type) );
            FAPI_TRY( mss::eff_dram_density(i_target, iv_dram_density) );
            FAPI_TRY( mss::eff_dram_width(i_target, iv_dram_width) );
            FAPI_TRY( mss::eff_num_master_ranks_per_dimm(i_target, iv_master_ranks) );
            FAPI_TRY( mss::eff_num_ranks_per_dimm(i_target, l_ranks) );
            FAPI_TRY( mss::eff_dram_row_bits(i_target, iv_rows) );
            FAPI_TRY( mss::eff_dimm_size(i_target, iv_size) );

            iv_slave_ranks = l_ranks - iv_master_ranks;

            return;

        fapi_try_exit:
            // Not 100% sure what to do here ...
            FAPI_ERR("error initializing DIMM structure: %s 0x%016lx", mss::c_str(i_target), uint64_t(fapi2::current_err));
            fapi2::Assert(false);
        }

        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        uint8_t iv_master_ranks;
        uint8_t iv_slave_ranks;
        uint8_t iv_dram_density;
        uint8_t iv_dram_width;
        uint8_t iv_dram_generation;
        uint8_t iv_dimm_type;
        uint8_t iv_rows;
        uint32_t iv_size;
};

}

}
#endif
