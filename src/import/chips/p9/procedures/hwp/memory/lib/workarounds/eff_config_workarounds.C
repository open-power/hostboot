/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/eff_config_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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


#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/workarounds/eff_config_workarounds.H>
#include <lib/shared/mss_const.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/nimbus_kind.H>

namespace mss
{

namespace workarounds
{

namespace eff_config
{

///
/// @brief Checks if the NVDIMM RC drive strength workaround is needed
/// @param[in] i_target DIMM target on which to operate
/// @param[out] o_is_needed true if the workaround is needed
/// @return SUCCESS if the code executes successfully
///
fapi2::ReturnCode is_nvdimm_rc_drive_strength_needed(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_is_needed)
{
    o_is_needed = false;

    uint8_t l_hybrid = 0;
    uint8_t l_hybrid_type = 0;
    uint32_t l_size = 0;

    FAPI_TRY(mss::eff_hybrid(i_target, l_hybrid));
    FAPI_TRY(mss::eff_hybrid_memory_type(i_target, l_hybrid_type));
    FAPI_TRY(mss::eff_dimm_size(i_target, l_size));

    if(l_hybrid == fapi2::ENUM_ATTR_EFF_HYBRID_IS_HYBRID &&
       l_hybrid_type == fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NVDIMM &&
       l_size == fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB)
    {
        o_is_needed = true;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates the RC drive strength if the workaround is needed
/// @param[in] i_target DIMM target on which to operate
/// @param[in] i_override_value the value to override if the workaround needs to be applied
/// @param[in,out] io_rc_value Register Control word value to update
/// @return SUCCESS if the code executes successfully
///
fapi2::ReturnCode nvdimm_rc_drive_strength(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_override_value,
        fapi2::buffer<uint8_t>& io_rc_value)
{
    bool l_is_needed = false;
    FAPI_TRY(is_nvdimm_rc_drive_strength_needed(i_target, l_is_needed));

    // If the workaround is needed, overwrite it to be ALL_MODERATE values
    // Otherwise keep it as it is
    io_rc_value = l_is_needed ? fapi2::buffer<uint8_t>(i_override_value) : io_rc_value;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Traits class for generic syncronization algorithm
/// @tparam uint64_t ATTR the fapi2 attribute ID
///
template<uint64_t ATTR>
class attributeSyncronizeTraits;

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TCCD_L
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TCCD_L>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_tccd_l(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TCCD_L, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TWR
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TWR>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_twr(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWR, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TRP
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TRP>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_trp(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRP, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TRC
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TRC>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_trc(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRC, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TWTR_L
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TWTR_L>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_twtr_l(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWTR_L, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TWTR_S
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TWTR_S>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_twtr_s(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TWTR_S, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TRRD_S
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TRRD_S>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_trrd_s(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRRD_S, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TRRD_L
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TRRD_L>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_trrd_l(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRRD_L, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TFAW
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TFAW>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_tfaw(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TFAW, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TRAS
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TRAS>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_tras(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRAS, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TRCD
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TRCD>
{
    public:

        using attr_integral_type = uint8_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_trcd(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRCD, i_target, l_set_values);
        }
};

///
/// @brief Traits class specialization for fapi2::ATTR_EFF_DRAM_TRFC
///
template<>
class attributeSyncronizeTraits<fapi2::ATTR_EFF_DRAM_TRFC>
{
    public:

        using attr_integral_type = uint16_t;

        ///
        /// @brief Gets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[out] o_get_values the values from the attribute
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode get(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type o_get_values[mss::PORTS_PER_MCS])
        {
            return mss::eff_dram_trfc(i_target, &o_get_values[0]);
        }

        ///
        /// @brief Sets the attribute
        /// @param[in] i_target the MCS on which to operate
        /// @param[in] i_set_values the values from the attribute - cannot be constant due to FAPI_ATTR_SET macro
        /// @return SUCCESS iff the code passes successfully
        ///
        static inline fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                            attr_integral_type i_set_values[mss::PORTS_PER_MCS])
        {
            attr_integral_type l_set_values[mss::PORTS_PER_MCS] = {};

            memcpy(&l_set_values[0], i_set_values, mss::PORTS_PER_MCS * sizeof(attr_integral_type));
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TRFC, i_target, l_set_values);
        }
};

///
/// @brief synchronizes a single MCA timing attribute across a list of MCA's (assumed to be MCA's in the same MCBIST)
/// @tparam uint64_t ATTR the attribute to synchronize
/// @tparam TT the traits associated with this attribute
/// @param[in] i_targets the vector of MCS targets on which to operate
/// @return SUCCESS if the code executes successfully
///
template<uint64_t ATTR, typename TT = attributeSyncronizeTraits<ATTR>>
fapi2::ReturnCode synchronize_attribute(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>>& i_targets)
{
    typename TT::attr_integral_type l_set_value = 0;

    // Gets all of the attributes and maximizes the results to get the value to set
    for(const auto& l_mcs : i_targets)
    {
        typename TT::attr_integral_type l_get_values[mss::PORTS_PER_MCS] = {};
        FAPI_TRY(TT::get(l_mcs, l_get_values));

        // Maximize each value in the attr
        for(uint8_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
        {
            l_set_value = std::max(l_set_value, l_get_values[l_index]);
        }
    }

    // Then sets the values
    for(const auto& l_mcs : i_targets)
    {
        typename TT::attr_integral_type l_get_values[mss::PORTS_PER_MCS] = {};
        FAPI_TRY(TT::get(l_mcs, l_get_values));

        // Sets each value in the attr
        for(uint8_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
        {
            // Skips setting values that are 0's in the attribute
            // This port could be deconfigured or not yet programmed, let's leave it be
            l_get_values[l_index] = (l_get_values[l_index] == 0) ? 0 : l_set_value;
        }

        FAPI_TRY(TT::set(l_mcs, l_get_values));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates timing attributes to be synchronized allowing the parts to be broadcast capable
/// @param[in] i_target MCS target on which to operate
/// @return SUCCESS if the code executes successfully
/// @note synchronizes attributes across the whole MCBIST
///
fapi2::ReturnCode synchronize_broadcast_timings(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mcss = mss::find_targets<fapi2::TARGET_TYPE_MCS>(l_mcbist);

    // Synchronizes all of the attributes across the MCA's
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TCCD_L>(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TWR   >(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TRP   >(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TRC   >(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TWTR_L>(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TWTR_S>(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TRRD_S>(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TRRD_L>(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TFAW  >(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TRAS  >(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TRCD  >(l_mcss)));
    FAPI_TRY((synchronize_attribute<fapi2::ATTR_EFF_DRAM_TRFC  >(l_mcss)));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if the 128GB WLO workaround is required
/// @param[in] i_kinds vector of DIMM kinds on which to operate
/// @return true if the workaround is needed, otherwise false
///
bool is_128gb_workaround_needed(const std::vector<mss::dimm::kind<>>& i_kinds)
{
    // Single drop? no workaround needed
    if(i_kinds.size() != 2)
    {
        return false;
    }

    // The 128GB DIMM's only need a workaround if:
    // 1. they're in a dual drop config
    // 2. they're a very specific config (seen below)
    // 3. at least one of those DIMM's is a Samsung DIMM
    static const auto AFFECTED_DIMM  = mss::dimm::kind<>(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
                                       fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
                                       fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
                                       fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
                                       fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
                                       fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
                                       fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
                                       fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB,
                                       fapi2::ENUM_ATTR_EFF_DRAM_MFG_ID_SAMSUNG);

    // Loops through the DIMM's and looks for an equivalent config + Samsung
    // If any of those cases are found, then the workaround is needed
    for(const auto& l_kind : i_kinds)
    {
        if(l_kind.equal_config(AFFECTED_DIMM) &&
           l_kind.iv_mfgid == AFFECTED_DIMM.iv_mfgid)
        {
            return true;
        }
    }

    // Otherwise, return false
    return false;
}

///
/// @brief Updates the WLO if the 128GB workaround is required
/// @param[in] i_kinds vector of DIMM kinds on which to operate
/// @param[in,out] io_wlo the WLO value to be updated
///
void update_128gb_wlo_if_needed(const std::vector<mss::dimm::kind<>>& i_kinds,
                                uint8_t& io_wlo)
{
    if(is_128gb_workaround_needed(i_kinds) == true)
    {
        io_wlo += 1;
    }
}

///
/// @brief Disables WRITE_CTR_2D_VREF if the 128GB workaround is required
/// @param[in] i_kinds vector of DIMM kinds on which to operate
/// @param[in,out] io_cal_steps the calibration steps from the attribute
///
void update_128gb_cal_steps_if_needed(const std::vector<mss::dimm::kind<>>& i_kinds,
                                      uint32_t& io_cal_steps)
{
    if(is_128gb_workaround_needed(i_kinds) == true)
    {
        fapi2::buffer<uint32_t> l_buffer(io_cal_steps);
        l_buffer.clearBit<mss::cal_steps::WRITE_CTR_2D_VREF>();
        io_cal_steps = l_buffer;
    }
}

///
/// @brief Updates the VREFDQ if the 128GB workaround is required
/// @param[in] i_kinds vector of DIMM kinds on which to operate
/// @param[in,out] io_vrefdq_train the WR VREF values to be updated
///
void update_128gb_vrefdq_if_needed(const std::vector<mss::dimm::kind<>>& i_kinds,
                                   uint8_t (&io_vrefdq_train)[2][4])
{
    if(is_128gb_workaround_needed(i_kinds) == true)
    {
        constexpr uint8_t OVERRIDE_VALUE = 0x1a;

        // Loops through and updates the VREFDQ
        for(uint8_t l_dimm = 0; l_dimm < mss::MAX_DIMM_PER_PORT; ++l_dimm)
        {
            for(uint8_t l_rank = 0; l_rank < mss::MAX_RANK_PER_DIMM; ++l_rank)
            {
                // If there is a value here, override it to our new requested WR VREF value
                io_vrefdq_train[l_dimm][l_rank] = (io_vrefdq_train[l_dimm][l_rank] == 0) ? 0 : OVERRIDE_VALUE;
            }
        }
    }
}

///
/// @brief Updates the attributes if the 128GB workaround is required
/// @param[in] i_target MCS target on which to operate
/// @return SUCCESS if the code executes successfully
/// @note synchronizes attributes across the whole MCBIST
///
fapi2::ReturnCode update_128gb_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    // Gets the attributes
    uint8_t l_wlo[mss::PORTS_PER_MCS] = {0, 0};
    uint32_t l_training_steps[mss::PORTS_PER_MCS] = {0, 0};
    uint8_t l_vref_dq[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT][mss::MAX_RANK_PER_DIMM] = {};
    FAPI_TRY(mss::eff_dphy_wlo(i_target, &(l_wlo[0])));
    FAPI_TRY(mss::cal_step_enable(i_target, &(l_training_steps[0])));
    FAPI_TRY(mss::eff_vref_dq_train_value(i_target, &(l_vref_dq[0][0][0])));

    // Loops over each MCA
    for(const auto& l_mca : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_kinds = mss::dimm::kind<>::vector(mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_mca));
        const auto l_port_index = mss::index(l_mca);
        update_128gb_wlo_if_needed(l_kinds, l_wlo[l_port_index]);
        update_128gb_cal_steps_if_needed(l_kinds, l_training_steps[l_port_index]);
        update_128gb_vrefdq_if_needed(l_kinds, l_vref_dq[l_port_index]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EFF_DPHY_WLO, i_target, l_wlo) );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_CAL_STEP_ENABLE, i_target, l_training_steps) );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_VREF_DQ_TRAIN_VALUE, i_target, l_vref_dq) );

fapi_try_exit:
    return fapi2::current_err;
}

} // ns eff_config

namespace plug_rule
{

///
/// @brief Ensures that there is no mixing between 128GB vendors
/// @param[in] i_kinds vector of DIMM kinds on which to operate
/// @return SUCCESS if the code executes successfully
/// @note Due to a vendor sensitivity that requires workarounds, we cannot mix 128GB vendors in the same MCA
///
fapi2::ReturnCode no_128gb_vendor_mixing(const std::vector<mss::dimm::kind<>>& i_kinds)
{
    // If the 128GB workaround is not needed, then we can skip the vendor mixing checks
    if(mss::workarounds::eff_config::is_128gb_workaround_needed(i_kinds) == false)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Otherwise, check for the impacted configuration check the DIMM's to ensure that there is no vendor mixing
    // Note: is_128gb_workaround_needed guarantees that there are two DIMM's plugged
    FAPI_ASSERT(i_kinds[0].iv_mfgid == i_kinds[1].iv_mfgid,
                fapi2::MSS_PLUG_RULES_128GB_VENDOR_MIXING()
                .set_DIMM_TARGET0(i_kinds[0].iv_target)
                .set_DIMM_TARGET1(i_kinds[1].iv_target)
                .set_VENDOR0(i_kinds[0].iv_mfgid)
                .set_VENDOR1(i_kinds[1].iv_mfgid),
                "%s mismatch between vendors on each DIMM. DIMM0:%u DIMM1:%u",
                mss::c_str(i_kinds[0].iv_target), i_kinds[0].iv_mfgid, i_kinds[1].iv_mfgid);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ns plug_rule
} // ns workarounds
} // ns mss
