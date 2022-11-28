/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/multicast_defs.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
#ifndef __FAPI2_COMMON_MULTICAST_DEFS__
#define __FAPI2_COMMON_MULTICAST_DEFS__

namespace fapi2
{
enum MulticastType : uint32_t
{
    // Code points picked according to PCB spec
    MULTICAST_OR      = 0,
    MULTICAST_AND     = 1,
    MULTICAST_BITX    = 2,
    MULTICAST_COMPARE = 4,
};

/**
 * @brief Abstract multicast group definitions
 *
 * These are abstract multicast groups that a procedure may want to talk to.
 * They are being mapped to hardware MC group IDs by the platform layer.
 * Due to the limited amount of hardware MC groups, the availability of
 * certain abstract groups will be dependent on system state, for example
 * the currently executing istep.
 *
 * The actual multicast group enumerations will be defined in a project specific header.
 */
enum MulticastGroup : uint32_t;

    /**
     * @brief Single FAPI->HW multicast group mapping
     *
     * This is used to provide a mapping of an abstract MulticastGroup to a hardware dependent
     * value. The calling HWP and platform layer must have the same understanding of the HW
     * value (e.g. PCB multicast group ID), FAPI2 is only the conduit and imposes no restriction
     * on hwValue.
     */
    struct MulticastGroupMapping
{
    MulticastGroup abstractGroup;
    uint32_t       hwValue;
};

/**
 * @brief Bit mask for selecting cores out of an EQ.
 */
enum MulticastCoreSelect : uint32_t
{
    MCCORE_0   = 0x8,
    MCCORE_1   = 0x4,
    MCCORE_2   = 0x2,
    MCCORE_3   = 0x1,
    MCCORE_ALL = 0xF,
};

inline MulticastCoreSelect operator|(const MulticastCoreSelect a, const MulticastCoreSelect b)
{
    return static_cast<MulticastCoreSelect>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
}

}

#endif
