/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_vpd_access.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
/**
 *  @file plat_vpd_access.C
 *
 *  @brief Implements the GetVpd function
 */

#include <stdint.h>
#include <fapi2.H>
#include <vpd_access_defs.H>
#include <vpd_access.H>
#include <ddimm_get_efd.H>
#include <attribute_service.H>
#include <errl/errlmanager.H>
#include <fapi2_spd_access.H>

 #include <spd.H>
 #include <ocmb_spd.H>


//The following can be uncommented for unit testing
// #undef FAPI_DBG
// #define FAPI_DBG(args...) FAPI_INF(args)

namespace fapi2
{

fapi2::ReturnCode platGetVPD(
   const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbFapi2Target,
         VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>&       io_vpdInfo,
         uint8_t* const o_blob)
{
    FAPI_DBG("platGetVPD<OCMB>(%s): enter",
             getFapiName(i_ocmbFapi2Target));

    fapi2::ReturnCode l_rc{fapi2::FAPI2_RC_SUCCESS};

    errlHndl_t l_errl = nullptr;

    uint8_t* l_spdBuffer = nullptr;

    do
    {
        // Get targeting OCMB target
        TARGETING::Target * l_ocmbTarget = nullptr;
        l_errl = fapi2::platAttrSvc::getTargetingTarget(i_ocmbFapi2Target,
                                                        l_ocmbTarget,
                                                        TARGETING::TYPE_OCMB_CHIP);
        if (l_errl)
        {
            FAPI_ERR("platGetVPD<OCMB>: Error from getTargetingTarget");
            break; //return with error
        }

        FAPI_DBG("platGetVPD<OCMB> : HUID = 0x%08X", TARGETING::get_huid(l_ocmbTarget));

        // Retrieve the EFD data or the EFD data size if o_blob is NULL
        if (fapi2::EFD == io_vpdInfo.iv_vpd_type)
        {

            // Read the Basic Memory Type
            uint8_t l_memType(SPD::MEM_TYPE_INVALID);
            l_errl = OCMB_SPD::getMemType(l_memType, l_ocmbTarget, EEPROM::AUTOSELECT);

            if (l_errl || !SPD::isValidOcmbDimmType(l_memType))
            {
                FAPI_ERR("platGetVPD<OCMB>: Error from getMemType() for HUID = 0x%08X, l_memType = 0x%2X",
                         TARGETING::get_huid(l_ocmbTarget), l_memType);

                if (!l_errl)
                {
                    /*@
                    * @errortype
                    * @moduleid          fapi2::MOD_FAPI2_PLAT_GET_VPD_OCMB
                    * @reasoncode        fapi2::RC_UNKNOWN_OCMB_CHIP_TYPE
                    * @userdata1         Mem type of OCMB
                    * @userdata2         HUID of OCMB target
                    * @devdesc           Invalid or unsupported MemVpdData requested.
                    * @custdesc          Firmware Error
                    */
                    l_errl = new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         fapi2::MOD_FAPI2_PLAT_GET_VPD_OCMB,
                                         fapi2::RC_UNKNOWN_OCMB_CHIP_TYPE,
                                         l_memType,
                                         TARGETING::get_huid(l_ocmbTarget),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                }
                break;
            }

            SPD::modSpecTypes_t l_modType = SPD::NA;
            l_errl = SPD::getModType(l_modType, l_ocmbTarget, l_memType);

            if (l_errl)
            {
                FAPI_ERR("platGetVPD<OCMB>: Error from getModType() for HUID = 0x%08X, l_modType = 0x%02X",
                         TARGETING::get_huid(l_ocmbTarget), l_modType);
                break;
            }

            // For standard OCMBs, need a 2KB buffer
            // 1st KB is SPD info, 2nd KB is EFD info.
            // For Planar OCMBs, need a 4KB buffer
            // 1st 512B is SPD info, and remaining 3.5KB is EFD info
            size_t l_spdBufferSize = (l_modType == SPD::PLANAR) ?
                                     SPD::PLANAR_OCMB_SPD_EFD_COMBINED_SIZE :
                                     SPD::OCMB_SPD_EFD_COMBINED_SIZE;

            // Allocate buffer to hold SPD and init to 0
            l_spdBuffer = new uint8_t[l_spdBufferSize];
            memset(l_spdBuffer, 0, l_spdBufferSize);

            // Get the SPD buffer
            l_errl = deviceRead(l_ocmbTarget,
                                l_spdBuffer,
                                l_spdBufferSize,
                                DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD));

            // If unable to retrieve the SPD buffer then can't
            // extract the EFD data, so return error.
            if (l_errl)
            {
                FAPI_ERR("platGetVPD<OCMB>: Error from trying to read ENTIRE SPD from 0x%08X",
                         TARGETING::get_huid(l_ocmbTarget));
                break;
            }

            // Retrieve the EFD data from the given SPD buffer.  If o_blob is
            // nullptr then size will be returned in io_vpdInfo.iv_size
            FAPI_EXEC_HWP( l_rc,
                           ddimm_get_efd,
                           i_ocmbFapi2Target,
                           io_vpdInfo,
                           o_blob,
                           l_spdBuffer,
                           l_spdBufferSize );
            if (l_rc)
            {
                FAPI_ERR("platGetVPD<OCMB>: Error returned from ddimm_get_efd called on target 0x%08X",
                         TARGETING::get_huid(l_ocmbTarget));
            }
        }
        // Retrieve the data or the data size if o_blob is nullptr
        else if (fapi2::BUFFER == io_vpdInfo.iv_vpd_type)
        {
            // while fapi2::BUFFER only needs the first 448 bytes of SPD,
            // it's ok to return a bit more with ENTIRE_SPD_WITHOUT_EFD as
            // long as all key bytes are returned such as module specific
            // information and CRC bytes
            l_errl = deviceRead(l_ocmbTarget,
                                o_blob,
                                io_vpdInfo.iv_size,
                                DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD_WITHOUT_EFD));

            if (l_errl)
            {
                FAPI_ERR("platGetVPD<OCMB>: Error from trying to read ENTIRE_SPD_WITHOUT_EFD data from 0x%08X",
                         TARGETING::get_huid(l_ocmbTarget));
                break;
            }

        }  // end if (fapi2::BUFFER == io_vpdInfo.iv_vpd_type)
        else
        {
            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_PLAT_GET_VPD_OCMB
            * @reasoncode        fapi2::RC_INVALID_TYPE
            * @userdata1         vpd_type attempted
            * @userdata2         HUID of OCMB target
            * @devdesc           Invalid or unsupported MemVpdData requested.
            * @custdesc          Firmware Error
            */
            l_errl = new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 fapi2::MOD_FAPI2_PLAT_GET_VPD_OCMB,
                                 fapi2::RC_INVALID_TYPE,
                                 io_vpdInfo.iv_vpd_type,
                                 TARGETING::get_huid(l_ocmbTarget),
                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        }
    } while (0);

    // Caller is not interested in the SPD buffer, so delete it.
    if (l_spdBuffer)
    {
        delete []l_spdBuffer;
        l_spdBuffer = nullptr;
    }

    if ( l_errl )
    {
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_errl);
    }

    FAPI_DBG("platGetVPD<OCMB>: exiting with %s",
             ( (l_rc == fapi2::FAPI2_RC_SUCCESS) ?
               "no errors" : "errors" ));

    return l_rc;
}

} // namespace
