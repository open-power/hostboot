/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_target.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
#include <devicefw/userif.H>
#include <targeting/common/utilFilter.H>
#include <fapiPlatTrace.H>
#include <errl/errlmanager.H>

namespace fapi2
{
    // Since the EKB definition of MulticastCoreSelect does not contain
    // an "invalid"/"no core selected" enum, declare one here for initialization
    // convenience purposes.
    static const MulticastCoreSelect MCCORE_NONE =
        static_cast<MulticastCoreSelect>(0);

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
        MulticastCoreSelect iv_coreSelect;   // Which cores to run SCOM op on

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
         * @param[in] i_coreSelect which cores to run the operation on
         */
        plat_target_handle_t(const TARGETING::Target* i_target = nullptr,
                             bool i_multicast = false,
                             MulticastGroup i_group = MCGROUP_ALL,
                             MulticastType i_op = MULTICAST_OR,
                             MulticastCoreSelect i_coreSelect = MCCORE_NONE):
                             iv_pTarget(i_target),
                             iv_multicast(i_multicast),
                             iv_group(i_group),
                             iv_multicastOp(i_op),
                             iv_coreSelect(i_coreSelect)
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
         * @brief Overloaded inequality operator
         *
         * @param[in] i_rhs the right side of inequality operation
         *
         * @return whether the passed pointer is not equal to the underlying
         *         TARGETING::Target* pointer of plat_target_t
         */
        bool operator!=(const TARGETING::Target* const i_rhs) const
        {
            return (iv_pTarget != i_rhs);
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

        /**
         * @brief The getter function for internal iv_coreSelect member
         *
         * @return Which cores to run the SCOM op on
         */
        MulticastCoreSelect getCoreSelect() const
        {
            return iv_coreSelect;
        }

    }; //class plat_target_handle_t

    // Forward declaration
    uint64_t getMulticastAddr(uint64_t i_addr,
                              MulticastGroup i_group,
                              MulticastType i_op,
                              MulticastCoreSelect i_coreSelect);

    /// @brief Get the multicast children targets
    /// @param[in] i_target The parent target
    /// @param[in] i_child The child targeting type
    /// @return TargetHandleList a list of the multicast children targets
    // TODO: move function to .C in other commit
    inline TARGETING::TargetHandleList getMulticastChildren(plat_target_handle_t i_target,
                                                            TARGETING::TYPE i_child)
    {
        errlHndl_t l_errl = nullptr;
        uint64_t l_buffer = 0x0;
        size_t l_size = sizeof(l_buffer);
        // TODO: make these symbolic in other commit
        uint64_t mcastGrp1ScomAddr = 0xF0001;
        uint64_t mcastBitSelectAddr = 0xF0008;
        TARGETING::TargetHandleList l_children, o_list;
        TARGETING::Target* l_hbTarg = i_target; //force a cast operator

        // Before doing anything, make sure the target we have is a valid type
        // to be a multicast base
        assert( TARGETING::TYPE_PROC == l_hbTarg->getAttr<TARGETING::ATTR_TYPE>(),
                "getMulticastChildren: Unsupported multicast type 0x%X used",
                l_hbTarg->getAttr<TARGETING::ATTR_TYPE>() );

        uint64_t l_writeData = 0;
        l_errl = deviceWrite(l_hbTarg, &l_writeData, l_size, DEVICE_SCOM_ADDRESS(mcastBitSelectAddr));
        if (l_errl)
        {
            FAPI_ERR("getMulticastChildren: Error from deviceWrite");
            l_errl->collectTrace(FAPI_TRACE_NAME, 256 );
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 384 );
            errlCommit(l_errl, SECURE_COMP_ID);
        }
        else
        {
            assert(l_size == sizeof(l_buffer), "size of buffer changed after deviceWrite");
            mcastGrp1ScomAddr = getMulticastAddr(mcastGrp1ScomAddr, i_target.getMulticastGroup(),
                fapi2::MULTICAST_BITX, MCCORE_NONE);

            /*
             * This "magic" SCOM operation will perform a "grab bit 0" multicast
             * read from an address in the PCB slave that is guaranteed to be
             * readable (since it does not depend on a chiplet being powered/
             * enabled/clocked) and always have bit 0 set to '1'
             * (per definition).
             * The result of the operation will be a 64bit value that will
             * contain said bit 0, i.e. a '1' for all members of the multicast
             * group, and a '0' for all others.
             */

            // This function contains two scoms so not necessarily thread safe
            // Each individual scom is protected, but not the greater operation
            l_errl = deviceRead(l_hbTarg, static_cast<void *>(&l_buffer), l_size,
                DEVICE_SCOM_ADDRESS(mcastGrp1ScomAddr));

            if (l_errl)
            {
                FAPI_ERR("getMulticastChildren: Error from deviceRead");
                errlCommit(l_errl, SECURE_COMP_ID);
            }
            else
            {
                assert(l_size == sizeof(l_buffer), "size of buffer changed after deviceRead");
                getChildChiplets(l_children, l_hbTarg, i_child, false);
                for (auto& l_tar : l_children)
                {
                    // Get each pervasive parent
                    TARGETING::TargetHandleList l_parentList;
                    TARGETING::getParentPervasiveTargetsByState(l_parentList,
                            l_tar,
                            TARGETING::CLASS_NA,
                            TARGETING::TYPE_PERV,
                            TARGETING::UTIL_FILTER_ALL);

                    if (l_parentList.size() == 1)
                    {
                        TARGETING::Target* l_parentTarget = l_parentList[0];
                        const int l_unit = l_parentTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                        // Check if the chip_unit has an enabled bit from the deviceRead
                        if ((l_buffer >> (63 - l_unit)) & 1)
                        {
                            o_list.push_back(l_tar);
                        }
                    }
                }
            }
        }
        return o_list;
    }


} // End namespace fapi2

#endif // __FAPI2_PLAT_TARGET__
