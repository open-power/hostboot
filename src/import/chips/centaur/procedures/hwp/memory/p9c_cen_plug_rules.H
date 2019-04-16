/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_cen_plug_rules.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p9c_cen_plug_ruiles.H
/// @brief  Takes in spd and configures effective attrs
///
/// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef P9C_CEN_PLUG_RULES_H_
#define P9C_CEN_PLUG_RULES_H_

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <dimmConsts.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{
namespace cen
{

///
/// @Brief Enumeration for the attributes to check
///
enum attr
{
    ROWS = 0,
    COLS = 1,
    DENSITY = 2,
    WIDTH = 3,
    MASTER_RANKS = 4,
    NUM_RANKS = 5,

    // Dispatcher parameters
    START = ROWS,
    END = NUM_RANKS + 1,
};

///
/// @brief Traits class for each attribute
/// @tparam attribute traits
///
template<attr A>
class attr_traits
{};

///
/// @brief Traits class for each attribute - ROWS specialization
///
template<>
class attr_traits<attr::ROWS>
{
    public:
        static constexpr bool IS_DIMM_TYPE = false;
        static constexpr const char* STR = "ROWS";

        ///
        /// @brief attribute getter helper
        /// @param[in] i_target MBA target
        /// @param[out] o_data data from the attr
        /// @return fapi2::ReturnCode
        ///
        static fapi2::ReturnCode getter(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, uint8_t& o_data)
        {
            return FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ROWS, i_target, o_data);
        }
};

///
/// @brief Traits class for each attribute - COLS specialization
///
template<>
class attr_traits<attr::COLS>
{
    public:
        static constexpr bool IS_DIMM_TYPE = false;
        static constexpr const char* STR = "COLS";

        ///
        /// @brief attribute getter helper
        /// @param[in] i_target MBA target
        /// @param[out] o_data data from the attr
        /// @return fapi2::ReturnCode
        ///
        static fapi2::ReturnCode getter(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, uint8_t& o_data)
        {
            return FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_COLS, i_target, o_data);
        }
};

///
/// @brief Traits class for each attribute - DENSITY specialization
///
template<>
class attr_traits<attr::DENSITY>
{
    public:
        static constexpr bool IS_DIMM_TYPE = false;
        static constexpr const char* STR = "DENSITY";

        ///
        /// @brief attribute getter helper
        /// @param[in] i_target MBA target
        /// @param[out] o_data data from the attr
        /// @return fapi2::ReturnCode
        ///
        static fapi2::ReturnCode getter(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, uint8_t& o_data)
        {
            return FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DENSITY, i_target, o_data);
        }
};

///
/// @brief Traits class for each attribute - WIDTH specialization
///
template<>
class attr_traits<attr::WIDTH>
{
    public:
        static constexpr bool IS_DIMM_TYPE = false;
        static constexpr const char* STR = "WIDTH";

        ///
        /// @brief attribute getter helper
        /// @param[in] i_target MBA target
        /// @param[out] o_data data from the attr
        /// @return fapi2::ReturnCode
        ///
        static fapi2::ReturnCode getter(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, uint8_t& o_data)
        {
            return FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, o_data);
        }
};

///
/// @brief Traits class for each attribute - MASTER_RANKS specialization
///
template<>
class attr_traits<attr::MASTER_RANKS>
{
    public:
        static constexpr bool IS_DIMM_TYPE = true;
        static constexpr const char* STR = "MASTER_RANKS";

        ///
        /// @brief attribute getter helper
        /// @param[in] i_target MBA target
        /// @param[out] o_data data from the attr
        /// @return fapi2::ReturnCode
        ///
        static fapi2::ReturnCode getter(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                        uint8_t (&o_data)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT])
        {
            return FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, o_data);
        }
};


///
/// @brief Traits class for each attribute - NUM_RANKS specialization
///
template<>
class attr_traits<attr::NUM_RANKS>
{
    public:
        static constexpr bool IS_DIMM_TYPE = true;
        static constexpr const char* STR = "NUM_RANKS";

        ///
        /// @brief attribute getter helper
        /// @param[in] i_target MBA target
        /// @param[out] o_data data from the attr
        /// @return fapi2::ReturnCode
        ///
        static fapi2::ReturnCode getter(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                        uint8_t (&o_data)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT])
        {
            return FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target, o_data);
        }
};

///
/// @brief Checks if a configuration is balanced for all attr
/// @param[in] i_data the attribute data for a centaur
/// @return true if the configuration is balanced
///
inline bool is_data_equivalent(const std::vector<uint8_t>& i_data)
{
    // Default to a balanced config - if we don't have any MBA's on this centaur, that's balanced
    bool l_balanced = true;

    // Make sure we have real data
    if(!i_data.empty())
    {
        // Find if the data is all the same
        const auto l_start = i_data[0];
        const auto l_it = std::find_if(i_data.begin(), i_data.end(), [&l_start]( const uint8_t& i_rhs) -> bool
        {
            return l_start != i_rhs;
        });

        // Data is balanced if all of data is equal (didn't find an unequal piece of data)
        l_balanced = l_it == i_data.end();
    }

    return l_balanced;
}

///
/// @brief Assembles the attribute into a vector for processing
/// @tparam attr A attribute on which to operate
/// @tparam attr_traits TT traits for the associated attribute
/// @param[in] i_target centaur target on which to operate
/// @param[in] std::false_type dispatch helper for MBA attribute types
/// @param[out] o_data vectorized attribute data
/// @return fapi2::ReturnCode
///
template<attr A, typename TT = attr_traits<A>>
inline fapi2::ReturnCode vectorize_attr_data(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
        std::false_type, std::vector<uint8_t>& o_data)
{
    o_data.clear();

    // Loops through all MBA
    for(const auto& l_mba : i_target.getChildren<fapi2::TARGET_TYPE_MBA>())
    {
        // Gets the attribute in question
        uint8_t l_attr_data = 0;
        FAPI_TRY(TT::getter(l_mba, l_attr_data));
        o_data.push_back(l_attr_data);
        FAPI_DBG("%s adding data0x%02x to vector size:%u for attr %u",
                 mss::spd::c_str(l_mba), l_attr_data, o_data.size(), A);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Assembles the attribute into a vector for processing
/// @tparam attr A attribute on which to operate
/// @tparam attr_traits TT traits for the associated attribute
/// @param[in] i_target centaur target on which to operate
/// @param[in] std::true_type dispatch helper for DIMM attribute types
/// @param[out] o_data vectorized attribute data
/// @return fapi2::ReturnCode
///
template<attr A, typename TT = attr_traits<A>>
inline fapi2::ReturnCode vectorize_attr_data(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
        std::true_type, std::vector<uint8_t>& o_data)
{
    o_data.clear();

    // Loops through all MBA
    for(const auto& l_mba : i_target.getChildren<fapi2::TARGET_TYPE_MBA>())
    {
        // Gets the attribute in question
        uint8_t l_attr_data[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        FAPI_TRY(TT::getter(l_mba, l_attr_data));

        // Loops through all DIMM's so we only get valid data
        for(const auto& l_dimm : l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>())
        {
            uint32_t l_dimm_pos = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, l_dimm, l_dimm_pos));
            {
                // Converts the DIMM pos into the relative position compared to the MBA
                const auto l_relative_pos = l_dimm_pos % MAX_DIMM_PER_MBA;

                const auto l_port_index = l_relative_pos / MAX_PORTS_PER_MBA;
                const auto l_dimm_index = l_relative_pos % MAX_DIMM_PER_PORT;
                o_data.push_back(l_attr_data[l_port_index][l_dimm_index]);
                FAPI_DBG("%s adding data0x%02x to vector port%u dimm%u size:%u",
                         mss::spd::c_str(l_mba), l_attr_data[l_port_index][l_dimm_index],
                         l_port_index, l_dimm_index, o_data.size());
            }
        }

    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if a configuration for a specific attribute is balanced over both MBA - recursion helper
/// @tparam attr A the attribute on which to operate
/// @tparam attr_traits TT traits for the associated attribute
/// @param[in] i_target centaur target on which to operate
/// @return fapi2::ReturnCode
///
template<attr A, typename TT = attr_traits<A>>
inline fapi2::ReturnCode check_for_balanced_config_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    // Helper for the FFDC below - FFDC doesnt like constexpr
    const auto ATTR = A;

    // Vector of attribute data
    std::vector<uint8_t> l_attr_data;

    // Gets the attribute data
    FAPI_TRY(vectorize_attr_data<A>(i_target, std::integral_constant<bool, TT::IS_DIMM_TYPE> {},
                                    l_attr_data));

    // Assert out if we're not balanced
    FAPI_ASSERT(is_data_equivalent(l_attr_data),
                fapi2::CEN_MSS_PLUG_RULES_MBA_MISMATCH()
                .set_TARGET_CEN(i_target)
                .set_ATTR(ATTR),
                "%s has an unbalanced config for %s",
                mss::c_str(i_target), TT::STR);

    return check_for_balanced_config_helper < static_cast<attr>(A + 1u) > (i_target);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if a configuration for a specific attribute is balanced over both MBA - ending specialization
/// @param[in] i_target centaur target on which to operate
/// @return fapi2::ReturnCode
///
template<>
inline fapi2::ReturnCode check_for_balanced_config_helper<attr::END>(const
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_INF("%s has a balanced configuration between the MBA's", mss::c_str(i_target));
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief mss_eff_config_verify_plug_rules(): Verifies plugrules on a per-Centaur basis
/// @param[in] i_target_mba: the fapi2 target
/// @return fapi2::ReturnCode
/// @note We pass in an MBA specifically to see if we're running on MBA23
/// We only need to run this plug rules test if we have two MBA's
///
inline fapi2::ReturnCode mss_eff_config_verify_centaur_plug_rules(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
{
    const auto& l_cen = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
    uint8_t l_mba_pos = 0;

    // First, check if we're MBA23 - if not, exit sucessfully
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mba_pos));

    if(l_mba_pos % MAX_MBA_PER_CEN == 0)
    {
        FAPI_INF("%s is MBA01, exiting succesfully", mss::spd::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_INF("%s is MBA23, checking that MBA01's configuration == MBA23's configuration", mss::spd::c_str(i_target));

    return check_for_balanced_config_helper<attr::START>(l_cen);

fapi_try_exit:
    return fapi2::current_err;
}

} // ns
} // cen

#endif
