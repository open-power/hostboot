/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/eff_config_workarounds.C $ */
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


#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/workarounds/eff_config_workarounds.H>
#include <lib/shared/mss_const.H>

namespace mss
{

namespace workarounds
{

namespace eff_config
{

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

} // ns eff_config
} // ns workarounds
} // ns mss
