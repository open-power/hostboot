/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_target.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file plat_target.H
/// @brief Define FAPI2 target functions for the platform layer.
///

#ifndef __FAPI2_PLAT_TARGET__
#define __FAPI2_PLAT_TARGET__

// HB platform support
#include <targeting/common/target.H>
#include <multicast_defs.H>
#include <multicast_group_defs.H>

namespace fapi2
{
    /**
     * @brief plat_target_handle_t class
     *
     * This class serves as a wrapper for TARGETING::Target and multicast-
     * specific attributes. This class allows conversion from fapi2::Target
     * to TARGETING::Target and in the other direction via overloaded
     * constructors and conversion operators.
     * Conversion examples:
     * fapi2::Target<fapi2::TARGET_TYPE_CORE>l_fapiCore(l_targetingCore)
     * TARGETING::Target* l_targetingCore = l_fapiCore.get()
     */
    class plat_target_handle_t
    {
        private:
        const TARGETING::Target* iv_pTarget; // Hostboot target type
        bool iv_multicast;                   // Whether a multicast SCOM op
                                             // is to be executed on this target
        MulticastGroup iv_group;             // The selected group for multicast
        MulticastType iv_multicastOp;        // The type of multicast operation

        public:

        /**
         * @brief Parametrized constructor for plat_target_handle_t
         *
         * @param[in] i_target the const target for which to construct
         *            plat_target_handle_t
         * @param[in] i_multicast whether the plat_target_handle_t is
         *            a multicast target wrapper
         * @param[in] i_group the multicast group
         * @param[in] i_op the type of multicast operation
         */
        plat_target_handle_t(const TARGETING::Target* i_target = nullptr,
                             bool i_multicast = false,
                             MulticastGroup i_group = MCGROUP_ALL,
                             MulticastType i_op = MULTICAST_OR):
                             iv_pTarget(i_target),
                             iv_multicast(i_multicast),
                             iv_group(i_group),
                             iv_multicastOp(i_op)
        {
        }

        /**
         * @brief fapi2::Target to TARGETING::Target* converter
         *
         * @return the underlying TARGETING::Target*
         */
        operator TARGETING::Target*() const
        {
            return const_cast<TARGETING::Target*>(iv_pTarget);
        }

        /**
         * @brief fapi2::Target to const TARGETING::Target* converter
         *
         * @return the underlying const TARGETING::Target*
         */
        operator const TARGETING::Target*() const
        {
            return iv_pTarget;
        }

        /**
         * @brief Overloaded equality operator (allows to compare plat_target_t
         *        to nullptr)
         *
         * @param[in] i_rhs the right side of equality operation
         *
         * @return whether the passed pointer is equal to the underlying
         *         TARGETING::Target* pointer of plat_target_t
         */
        bool operator==(const TARGETING::Target* const i_rhs) const
        {
            return (iv_pTarget == i_rhs);
        }

        /**
         * @brief Overloaded less than operator
         *
         * @param[in] i_rhs the right-side plat_target_handle_t
         *
         * @return whether this class' Target* is less that right-side's
         */
        bool operator<(const plat_target_handle_t& i_rhs) const
        {
            return iv_pTarget < i_rhs.iv_pTarget;
        }

        /**
         * @brief The getter function for internal iv_multicast member
         *
         * @return true if target supports multicast; false otherwise
         */
        bool isMulticast() const
        {
            return iv_multicast;
        }

        /**
         * @brief The getter function for internal iv_group member
         *
         * @return The multicast group requested for this target
         * @note The returned value only makes sense if isMulticast is true
         */
        MulticastGroup getMulticastGroup() const
        {
            return iv_group;
        }

        /**
         * @brief The getter function for internal iv_multicastOp member
         *
         * @return The type of multicast operation requested
         */
        MulticastType getMulticastOp() const
        {
            return iv_multicastOp;
        }

    }; //class plat_target_handle_t
} // End namespace fapi2

#endif // __FAPI2_PLAT_TARGET__
