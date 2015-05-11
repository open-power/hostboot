/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/cpuid.C $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
/** @file cpuid.C
 *  Implementation of the cpuid functions.
 */

#include <kernel/cpuid.H>

namespace CpuID
{
    ProcessorCoreType getCpuType()
    {
        uint64_t l_pvr = getPVR();

        // Layout of the PVR is (32-bit):
        //     2 nibbles reserved.
        //     2 nibbles chip type.
        //     1 nibble technology.
        //     1 nibble major DD.
        //     1 nibble reserved.
        //     1 nibble minor DD.

        switch(l_pvr & 0xFFFF0000)
        {
            case 0x004B0000:
                return CORE_POWER8_MURANO;

            case 0x004C0000:
                return CORE_POWER8_NAPLES;

            case 0x004D0000:
                return CORE_POWER8_VENICE;

            case 0x004E0000:
                return CORE_POWER9_NIMBUS;

            case 0x004F0000:
                return CORE_POWER9_CUMULUS;

            default:
                return CORE_UNKNOWN;
        }
    }

    uint8_t getCpuDD()
    {
        uint64_t l_pvr = getPVR();
        return ((l_pvr & 0x0F00) >> 4) | (l_pvr & 0x000F);
    }
};


