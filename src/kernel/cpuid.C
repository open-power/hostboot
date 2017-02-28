/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/cpuid.C $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2017                        */
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
#include <arch/pvrformat.H>

namespace CpuID
{
    ProcessorCoreType getCpuType()
    {
        PVR_t l_pvr( getPVR() );

        switch(l_pvr.chipFamily)
        {
            case PVR_t::P8_MURANO:
                return CORE_POWER8_MURANO;

            case PVR_t::P8_NAPLES:
                return CORE_POWER8_NAPLES;

            case PVR_t::P8_VENICE:
                return CORE_POWER8_VENICE;

            case PVR_t::P9_ALL:
            {
                // Nimbus DD1.0 has a different PVR format
                if( (l_pvr.word & PVR_t::CHIP_DD_MASK) == PVR_t::IS_NIMBUS_DD1)
                {
                    return CORE_POWER9_NIMBUS;
                }

                switch(l_pvr.chipType)
                {
                    case PVR_t::NIMBUS_CHIP:
                        return CORE_POWER9_NIMBUS;

                    case PVR_t::CUMULUS_CHIP:
                        return CORE_POWER9_CUMULUS;

                    default:
                        return CORE_UNKNOWN;
                }
            }

            default:
                return CORE_UNKNOWN;
        }
    }

    uint8_t getCpuDD()
    {
        PVR_t l_pvr( getPVR() );
        return l_pvr.getDDLevel();
    }
};


