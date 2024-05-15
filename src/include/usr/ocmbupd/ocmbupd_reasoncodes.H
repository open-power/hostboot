/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ocmbupd/ocmbupd_reasoncodes.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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

#ifndef __OCMBUPD_REASONCODES_H
#define __OCMBUPD_REASONCODES_H

#include <hbotcompid.H>

namespace OCMBUPD
{

    enum OcmbUpdModuleId
    {
        MOD_OCMB_FW_VALIDATE_IMAGE     = 0x01,
        MOD_PARSE_TAGGED_DATA_TRIPLET  = 0x02,
        MOD_SET_FW_VERSION_INFO        = 0x03,
        MOD_WRITE_EXPLORER_FW_VERSION  = 0x04,
        MOD_IS_MDS_DDIMM               = 0x05,
        MOD_ODY_UPD_FSM                = 0x06
    };

    enum OcmbUpdReasonCode
    {
        INVALID_PARMS                             = OCMBUPD_COMP_ID | 0x01,
        INVALID_EYE_CATCHER                       = OCMBUPD_COMP_ID | 0x02,
        INVALID_HEADER_VERSION                    = OCMBUPD_COMP_ID | 0x03,
        INVALID_HEADER_SIZE                       = OCMBUPD_COMP_ID | 0x04,
        MISSING_SHA512_HASH                       = OCMBUPD_COMP_ID | 0x05,
        INVALID_DATA_TRIPLET_SIZE                 = OCMBUPD_COMP_ID | 0x06,
        INVALID_HASH_TRIPLET_SIZE                 = OCMBUPD_COMP_ID | 0x07,
        INVALID_TAG_ID                            = OCMBUPD_COMP_ID | 0x08,
        MISSING_FW_VERSION                        = OCMBUPD_COMP_ID | 0x09,
        UNSUPPORTED_NUMBER_OF_DIMMS               = OCMBUPD_COMP_ID | 0x0a, // Deprecated
        DEVICE_READ_FAIL                          = OCMBUPD_COMP_ID | 0x0b,
        EXPLORER_FW_IMAGE_MISSING                 = OCMBUPD_COMP_ID | 0x0c,
        OCMB_INVALID_EXT_HEADER_VERSION           = OCMBUPD_COMP_ID | 0x0d,
        FW_IMAGE_MISSING                          = OCMBUPD_COMP_ID | 0x0e,
        ODY_UPD_DECONFIGURE_OCMB                  = OCMBUPD_COMP_ID | 0x0f,
        ODY_UPD_INTERNAL_ERROR                    = OCMBUPD_COMP_ID | 0x10,
        ODY_UPD_BAD_FIRMWARE                      = OCMBUPD_COMP_ID | 0x11,
        ODY_UPD_FIRMWARE_UPDATED                  = OCMBUPD_COMP_ID | 0x12,
        ODY_UPD_UNKNOWN_STATE                     = OCMBUPD_COMP_ID | 0x13,
        ODY_UPD_DELAYED_DECONFIGURE_OCMB          = OCMBUPD_COMP_ID | 0x14,
    };

}; // namespace OCMBUPD

//*****************************************************
// SRC Graveyard
// Contains error log descriptions for SRCs that were
// removed from the code but we need to still provide
// backward compatible parser logic for.

/*@
* @moduleid        OCMBUPD::MOD_WRITE_EXPLORER_FW_VERSION
* @reasoncode      OCMBUPD::UNSUPPORTED_NUMBER_OF_DIMMS
* @userdata1       HUID of OCMB target whose DDIMM is being searched for
* @userdata2       Number of DDIMMs found
* @devdesc         Unsupported number of DDIMMs found tied to one OCMB in targeting layout.
* @custdesc        Error occurred during system boot.
*/


#endif
