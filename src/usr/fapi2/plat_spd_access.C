/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_spd_access.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file plat_attribute_service.C
///
/// @brief Implements the specialized platform functions that access
/// attributes for FAPI2
///

#include <attribute_service.H>
#include <target_types.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <fapi2_spd_access.H>

namespace fapi2
{

//******************************************************************************
// Function : getSPD()
// Return a blob of SPD data from a DIMM
//******************************************************************************
fapi2::ReturnCode getSPD(
                        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_pTarget,
                        uint8_t *  o_blob,
                        size_t& o_size)
{
    FAPI_DBG(ENTER_MRK "getSPD");

    const uint8_t   MEM_DDR3 = 0xB;
    const uint8_t   MEM_DDR4 = 0xC;
    const uint32_t  DDR3_KEYWORD_SIZE = 256;
    const uint32_t  DDR4_KEYWORD_SIZE = 512;

    errlHndl_t l_errl  = NULL;
    fapi2::ReturnCode  l_rc;
    TARGETING::Target* l_pTarget = NULL;

    do
    {
        l_errl = fapi2::platAttrSvc::getTargetingTarget(i_pTarget,
                                                        l_pTarget,
                                                        TARGETING::TYPE_DIMM);
        if (l_errl)
        {
            FAPI_ERR("getSPD: Error from getTargetingTarget");
            break;
        }

        // If the caller passed a nullptr for blob then
        // return size of the SPD
        if ( o_blob == NULL )
        {
            // Get the DDR device type from SPD
            uint8_t l_memType = 0x0;
            size_t  l_memSize = sizeof(l_memType);

            l_errl = deviceRead(l_pTarget,
                    (void *)&l_memType,
                    l_memSize,
                    DEVICE_SPD_ADDRESS(SPD::BASIC_MEMORY_TYPE));

            if ( !l_errl )
            {
                if ( l_memType == MEM_DDR3 )
                {
                    o_size = DDR3_KEYWORD_SIZE;
                }
                else if ( l_memType == MEM_DDR4 )
                {
                    o_size = DDR4_KEYWORD_SIZE;
                }
                else
                {
                    FAPI_ERR("getSPD: Invalid DIMM DDR Type");
                    break;
                }

                FAPI_DBG("getSPD: Returning the size of the SPD :%d ", o_size);
            }
        }
        else
        {
            l_errl = deviceRead(l_pTarget,
                    o_blob,
                    o_size,
                    DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD));
        }

        break;

    } while(0);

    if ( l_errl )
    {
        FAPI_ERR("getSPD: Error getting SPD data for HUID=0x%.8X Size %d",
                TARGETING::get_huid(l_pTarget),o_size);

        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }

    FAPI_DBG("getSPD: SPD data for HUID=0x%.8X Size %d Blob %d",
            TARGETING::get_huid(l_pTarget),o_size,o_blob);

    FAPI_DBG(EXIT_MRK "getSPD");
    return l_rc;
}

} // End fapi2 namespace
