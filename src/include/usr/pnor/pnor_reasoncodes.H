/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/pnor_reasoncodes.H $                     */
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
#ifndef __PNOR_REASONCODES_H
#define __PNOR_REASONCODES_H

#include <hbotcompid.H>

namespace PNOR
{
    enum PNORModuleId
    {
        MOD_PNORRP_WAITFORMESSAGE       = 0x01, /**< pnorrp.C : PnorRP::waitForMessage */
        MOD_PNORRP_COMPUTEDEVICEADDR    = 0x02, /**< pnorrp.C : PnorRP::computeDeviceAddr */
        MOD_PNORRP_GETSECTIONINFO       = 0x03, /**< pnorrp.C : PnorRP::getSectionInfo */
        MOD_PNORRP_COMPUTESECTION       = 0x04, /**< pnorrp.C : PnorRP::computeSection */
        MOD_PNORRP_INITDAEMON           = 0x05, /**< pnorrp.C : PnorRP::initDaemon */
        MOD_PNORRP_READTOC              = 0x06, /**< pnorrp.C : PnorRP::readTOC */
        MOD_PNORRP_READFROMDEVICE       = 0x07, /**< pnorrp.C : PnorRP::readFromDevice */
        MOD_PNORRP_WRITETODEVICE        = 0x08, /**< pnorrp.C : PnorRP::writeToDevice */
        MOD_PNORRP_DIDSTARTUPFAIL       = 0x1C,  /** didStartupFail(rc) */

        MOD_PNORDD_VERIFYADDRESSRANGE   = 0x11, /**< pnordd.C : PnorDD::verifyAddressRange */
        MOD_PNORDD_READFLASH            = 0x12, /**< pnordd.C : PnorDD::readFlash */
        MOD_PNORDD_WRITEFLASH           = 0x13, /**< pnordd.C : PnorDD::writeFlash */
        MOD_PNORDD_POLLSFCOPCOMPLETE    = 0x14, /**< pnordd.C : PnorDD::pollSfcOpComplete */
        MOD_PNORDD_SFCINIT              = 0x15, /**< pnordd.C : PnorDD::sfcInit */
        MOD_PNORDD_READREGSPI           = 0x16, /**< pnordd.C : PnorDD::readRegSPI */
        MOD_PNORDD_WRITEREGSPI          = 0x17, /**< pnordd.C : PnorDD::writeRegSPI */
        MOD_PNORDD_READLPC              = 0x18, /**< pnordd.C : PnorDD::readLPC */
        MOD_PNORDD_WRITELPC             = 0x19, /**< pnordd.C : PnorDD::writeLPC */
        MOD_PNORDD_ERASEFLASH           = 0x1A, /**< pnordd.C : PnorDD::eraseFlash */
        MOD_PNORDD_MICRONFLAGSTATUS     = 0x1B, /**< pnordd.C : PnorDD::micronFlagStatus */
        MOD_PNORDD_CHECKFORSFCERRORS    = 0x1D, /**< pnordd.C : PnorDD::checkForErrors */
        MOD_PNORDD_CHECKFOROPBERRORS    = 0x1E, /**< pnordd.C : PnorDD::checkForErrors */
        MOD_PNORDD_HANDLEECCBERROR      = 0x1F, /**< pnordd.C : PnorDD::handleEccbError */
        MOD_PNORDD_RESETPNOR            = 0x20, /**< pnordd.C : PnorDD::resetPnor */
        MOD_PNORVALID_MAIN              = 0x21, /**< pnorvalid.C : Main Function */
        MOD_PNORVALID_MAGIC             = 0x22, /**< pnorvalid.C : Magic Function */

    };

    enum PNORReasonCode
    {
        RC_INVALID_MESSAGE_TYPE      = PNOR_COMP_ID | 0x01,
        RC_INVALID_ADDRESS           = PNOR_COMP_ID | 0x02,
        RC_INVALID_SECTION           = PNOR_COMP_ID | 0x03,
        RC_EXTERNAL_ERROR            = PNOR_COMP_ID | 0x04,
        RC_STARTUP_FAIL              = PNOR_COMP_ID | 0x05,
        RC_INVALID_ASYNC_MESSAGE     = PNOR_COMP_ID | 0x06,
        RC_UNSUPPORTED_OPERATION     = PNOR_COMP_ID | 0x07,
        RC_LPC_ERROR                 = PNOR_COMP_ID | 0x08,
        RC_BAD_STARTUP_RC            = PNOR_COMP_ID | 0x09,
        //termination_rc
        RC_UNSUPPORTED_HARDWARE      = PNOR_COMP_ID | 0x0A,
        RC_MICRON_INCOMPLETE         = PNOR_COMP_ID | 0x0B,
        //termination_rc
        RC_PARTITION_TABLE_INVALID   = PNOR_COMP_ID | 0x0C,
        //termination_rc
        RC_UNSUPPORTED_MODE          = PNOR_COMP_ID | 0x0D,
        //termination_rc
        RC_UNSUPPORTED_SFCRANGE      = PNOR_COMP_ID | 0x0E,
        //termination_rc
        RC_ECC_UE                    = PNOR_COMP_ID | 0x0F,
        RC_ERROR_IN_STATUS_REG       = PNOR_COMP_ID | 0x10,
        //termination_rc
        RC_REINITIALIZE_SFC          = PNOR_COMP_ID | 0x11,
    };

    enum UserDetailsTypes
    {
        PNOR_UDT_NO_FORMAT           = 0x0,
        PNOR_UDT_PNORDD_PARAMETERS  = 0x1,
    };
};

#endif
