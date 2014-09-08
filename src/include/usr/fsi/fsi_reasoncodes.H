/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fsi/fsi_reasoncodes.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
#ifndef __FSI_REASONCODES_H
#define __FSI_REASONCODES_H

#include <hbotcompid.H>

namespace FSI
{
    enum FSIModuleId
    {
        MOD_FSIDD_INVALID             = 0x00, /**< Zero is an invalid module id */
        MOD_FSIDD_WRITE               = 0x01, /**< fsidd.C : FsiDD::write */
        MOD_FSIDD_READ                = 0x02, /**< fsidd.C : FsiDD::read */
        MOD_FSIDD_VERIFYADDRESSRANGE  = 0x03, /**< fsidd.C : FsiDD::verifyAddressRange */
        MOD_FSIDD_HANDLEOPBERRORS     = 0x04, /**< fsidd.C : FsiDD::handleOpbErrors */
        MOD_FSIDD_DDOP                = 0x05, /**< fsidd.C : ddOp */
        MOD_FSIDD_POLLFORCOMPLETE     = 0x06, /**< fsidd.C : FsiDD::pollForComplete */
        MOD_FSIDD_INITPORT            = 0x07, /**< fsidd.C : FsiDD::initPort */
        MOD_FSIDD_GENFULLFSIADDR      = 0x09, /**< fsidd.C : FsiDD::genFullFsiAddr */
        MOD_FSIDD_CHECKFORERRORS      = 0x0A, /**< fsidd.C : FsiDD::checkForErrors */
        MOD_FSIDD_VERIFYPRESENT       = 0x0B, /**< fsidd.C : FsiDD::verifyPresent */
        MOD_FSIDD_INITIALIZEHARDWARE  = 0x0C, /**< fsidd.C : FsiDD::initializeHardware */

        MOD_FSIPRES_PROCPRESENCEDETECT  = 0x20, /**< fsipres.C : procPresenceDetect */
        MOD_FSIPRES_MEMBPRESENCEDETECT  = 0x21, /**< fsipres.C : membPresenceDetect */
    };

    enum FSIReasonCode
    {
        RC_BAD_REASONCODE            = FSI_COMP_ID | 0x00,
        RC_INVALID_LENGTH            = FSI_COMP_ID | 0x01,
        RC_INVALID_ADDRESS           = FSI_COMP_ID | 0x02,
        RC_OPB_TIMEOUT               = FSI_COMP_ID | 0x03,
        RC_OPB_ERROR                 = FSI_COMP_ID | 0x04,
        RC_INVALID_TARGET            = FSI_COMP_ID | 0x05,
        RC_OPB_NO_READ_VALID         = FSI_COMP_ID | 0x06,
        RC_ERROR_ENABLING_SLAVE      = FSI_COMP_ID | 0x07,
        RC_INVALID_OPERATION         = FSI_COMP_ID | 0x08,
        RC_NULL_TARGET               = FSI_COMP_ID | 0x09,
        RC_MASTER_TARGET             = FSI_COMP_ID | 0x0A,
        RC_FSI_NOT_SUPPORTED         = FSI_COMP_ID | 0x0B,
        RC_INVALID_FSI_PATH_1        = FSI_COMP_ID | 0x0C,
        RC_INVALID_FSI_PATH_2        = FSI_COMP_ID | 0x0D,
        RC_TARGET_NEVER_DETECTED     = FSI_COMP_ID | 0x0E,
        RC_FSI_MVPD_MISMATCH         = FSI_COMP_ID | 0x0F,
        RC_FSI_CVPD_MISMATCH         = FSI_COMP_ID | 0x10,
        RC_ERROR_IN_MAEB             = FSI_COMP_ID | 0x11,
        RC_BAD_ATTRIBUTES            = FSI_COMP_ID | 0x12,
    };

    enum UserDetailsTypes
    {
        FSI_UDT_NO_FORMAT       = 0x0,
        FSI_UDT_PRESENCE        = 0x1,
        FSI_UDT_OPERATION       = 0x2,
    };
};

#endif
