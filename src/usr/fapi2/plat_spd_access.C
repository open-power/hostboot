/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_spd_access.C $                             */
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
#include <spd.H>
#include <vpd/spdenums.H>
#include <hwas/common/hwasCallout.H>
#include <plat_utils.H>

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

    errlHndl_t l_errl  = nullptr;
    fapi2::ReturnCode  l_rc;
    TARGETING::Target* l_pTarget = nullptr;

    do
    {
        l_errl = fapi2::platAttrSvc::getTargetingTarget(i_pTarget,
                                                        l_pTarget,
                                                        TARGETING::TYPE_DIMM);
        if (l_errl)
        {
            FAPI_ERR("getSPD: Error from getTargetingTarget for TYPE_DIMM");
            break;
        }

        // If the caller passed a nullptr for blob then
        // return size of the SPD
        if ( o_blob == nullptr )
        {
            // Get the DRAM generation from SPD
            uint8_t l_memGen = 0x0;
            size_t l_memSize = sizeof(l_memGen);

            l_errl = deviceRead(l_pTarget,
                                static_cast<void *>(&l_memGen),
                                l_memSize,
                                DEVICE_SPD_ADDRESS(SPD::BASIC_MEMORY_TYPE));

            if ( l_errl )
            {
                FAPI_ERR("getSPD: Error from deviceRead for BASIC_MEMORY_TYPE")
                break;
            }

            switch(l_memGen)
            {
                case SPD::MEM_DDR3:
                    o_size = SPD::DDR3_SPD_SIZE;
                    break;

                case SPD::MEM_DDR4:
                {
                    uint8_t l_memModule = 0x0;

                    l_errl = deviceRead(l_pTarget,
                                        static_cast<void *>(&l_memModule),
                                        l_memSize,
                                        DEVICE_SPD_ADDRESS(SPD::MODULE_TYPE));

                    if( l_errl )
                    {
                        FAPI_ERR("getSPD: Error on deviceRead for MODULE_TYPE");
                        break;
                    }

                    if( l_memModule == SPD::MOD_TYPE_DDIMM )
                    {
                        // currently getSPD only supports the ENTIRE_SPD
                        // keyword. In the DDIMM case this include the EFD
                        // data so be sure to reflect that in the size we return.
                        o_size = SPD::OCMB_SPD_EFD_COMBINED_SIZE;
                    }
                    else
                    {
                        o_size = SPD::DDR4_SPD_SIZE;
                    }
                }// case MEM_DDR4
                break;

                default:
                {
                    FAPI_ERR("getSPD: Unsupported DIMM DDR Generation");

                    /*@
                     * @errortype
                     * @moduleid     MOD_FAPI2_SPD_ACCESS
                     * @reasoncode   RC_INVALID_SPD_DRAM_GEN
                     * @userdata1    DDR generation
                     * @userdata2    HUID of input target
                     * @devdesc      Bad SPD or unsupported DIMM
                     * @custdesc     Unsupported DIMM generation
                     */
                    l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            MOD_FAPI2_SPD_ACCESS,
                            RC_INVALID_SPD_DRAM_GEN,
                            TARGETING::get_huid(l_pTarget),
                            l_memGen );

                    l_errl->addHwCallout( l_pTarget,
                                          HWAS::SRCI_PRIORITY_HIGH,
                                          HWAS::DELAYED_DECONFIG,
                                          HWAS::GARD_NULL );
                }
                break;

            }// switch

            FAPI_DBG("getSPD: Returning the size of the SPD :%d ", o_size);

        }// endif
        else
        {
            // Return the entire SPD blob
            l_errl = deviceRead(l_pTarget,
                                o_blob,
                                o_size,
                                DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD));
        }// end else

        break;

    } while(0);

    if ( l_errl )
    {
        FAPI_ERR("getSPD: Error getting SPD data for HUID=0x%.8X Size %d",
                TARGETING::get_huid(l_pTarget),o_size);

        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_errl);
    }

    FAPI_DBG("getSPD: SPD data for HUID=0x%.8X Size %d Blob %d",
            TARGETING::get_huid(l_pTarget),o_size,o_blob);

    FAPI_DBG(EXIT_MRK "getSPD");
    return l_rc;
}

} // End fapi2 namespace
