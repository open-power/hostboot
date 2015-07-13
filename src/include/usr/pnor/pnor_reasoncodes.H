/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/pnor_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] Google Inc.                                                        */
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
        // pnorrp.C
        MOD_PNORRP_WAITFORMESSAGE       = 0x01, /**< PnorRP::waitForMessage */
        MOD_PNORRP_COMPUTEDEVICEADDR    = 0x02, /**< PnorRP::computeDeviceAddr */
        MOD_PNORRP_GETSECTIONINFO       = 0x03, /**< PnorRP::getSectionInfo */
        MOD_PNORRP_COMPUTESECTION       = 0x04, /**< PnorRP::computeSection */
        MOD_PNORRP_INITDAEMON           = 0x05, /**< PnorRP::initDaemon */
        MOD_PNORRP_READTOC              = 0x06, /**< PnorRP::readTOC */
        MOD_PNORRP_READFROMDEVICE       = 0x07, /**< PnorRP::readFromDevice */
        MOD_PNORRP_WRITETODEVICE        = 0x08, /**< PnorRP::writeToDevice */
        MOD_PNORRP_DIDSTARTUPFAIL       = 0x09, /**< didStartupFail(rc) */
        MOD_PNORRP_FLUSH                = 0x0A, /**< mm_remove_pages */
        MOD_PNORRP_FIXECC               = 0x0B, /**< PnorRP::fixECC */
        MOD_PNORRP_FINDTOC              = 0x0C, /**< PnorRP::findTOC */
        MOD_PNORRP_GETSIDEINFO          = 0x0D, /**< PnorRP::getSideInfo */
        MOD_PNORRP_SETSIDEINFO          = 0x0E, /**< PnorRP::setSideInfo */

        // pnorvalid.C
        MOD_PNORVALID_MAIN              = 0x0E, /**< validateAltMaster */
        MOD_PNORVALID_MAGIC             = 0x0F, /**< validateAltMaster */

        // pnordd.C
        MOD_PNORDD_VERIFYADDRESSRANGE   = 0x11, /**< PnorDD::verifyAddressRange */
        MOD_PNORDD_READFLASH            = 0x12, /**< PnorDD::readFlash */
        MOD_PNORDD_WRITEFLASH           = 0x13, /**< PnorDD::writeFlash */
        MOD_PNORDD_SFCINIT              = 0x14, /**< PnorDD::sfcInit */
        MOD_PNORDD_ERASEFLASH           = 0x15, /**< PnorDD::eraseFlash */
        MOD_PNORDD_CHECKFORERRORS       = 0x16, /**< PnorDD::checkForErrors */

        // sfc_ibm.C
        MOD_SFCIBM_VERIFYADDRESSRANGE   = 0x40, /**< SfcIBM::verifyAddressRange */
        MOD_SFCIBM_READFLASH            = 0x41, /**< SfcIBM::readFlash */
        MOD_SFCIBM_WRITEFLASH           = 0x42, /**< SfcIBM::writeFlash */
        MOD_SFCIBM_POLLOPCOMPLETE       = 0x43, /**< SfcIBM::pollSfcOpComplete */
        MOD_SFCIBM_SFCINIT              = 0x44, /**< SfcIBM::sfcInit */
        MOD_SFCIBM_ERASEFLASH           = 0x45, /**< SfcIBM::eraseFlash */
        MOD_SFCIBM_CHECKFORERRORS       = 0x46, /**< SfcIBM::checkForErrors */
        MOD_SFCIBM_HWRESET              = 0x47, /**< SfcIBM::hwReset */

        // sfc_fake.C
        MOD_SFCFAKE_VERIFYADDRESSRANGE  = 0x60, /**< SfcFake::verifyAddressRange */
        MOD_SFCFAKE_READFLASH           = 0x61, /**< SfcFake::readFlash */
        MOD_SFCFAKE_WRITEFLASH          = 0x62, /**< SfcFake::writeFlash */
        MOD_SFCFAKE_ERASEFLASH          = 0x63, /**< SfcFake::eraseFlash */
        MOD_SFCFAKE_SENDSPICMD          = 0x64, /**< SfcFake::sendSpiCmd */

        // sfc_ast2400.C
        MOD_SFCAST2400_ENABLEWRITEMODE  = 0x80, /**< SfcAST2400::verifyAddressRange */
        MOD_SFCAST2400_READFLASH        = 0x81, /**< SfcAST2400::readFlash */
        MOD_SFCAST2400_WRITEFLASH       = 0x82, /**< SfcAST2400::writeFlash */
        MOD_SFCAST2400_POLLOPCOMPLETE   = 0x83, /**< SfcAST2400::pollSfcOpComplete */
        MOD_SFCAST2400_ERASEFLASH       = 0x84, /**< SfcAST2400::eraseFlash */

        // nor_micron.C
        MOD_NORMICRON_MICRONFLAGSTATUS  = 0xA0, /**< micronFlagStatus */

        //rt_pnor.C
        MOD_RTPNOR_GETSECTIONINFO       = 0xB0, /**< RtPnor::getSectionInfo*/
        MOD_RTPNOR_FLUSH                = 0xB1, /**< RtPnor::flush */
        MOD_RTPNOR_READFROMDEVICE       = 0xB2, /**< RtPnor::readFromDevice */
        MOD_RTPNOR_WRITETODEVICE        = 0xB3, /**< RtPnor::writeToDevice */

        //pnor_common.C
        MOD_PNORCOMMON_PARSETOC        = 0xC0, /**< PNOR::parseTOC */
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
        RC_SFC_ERROR                 = PNOR_COMP_ID | 0x12,
        //termination_rc
        RC_PNOR_INIT_FAILURE         = PNOR_COMP_ID | 0x13,
        RC_CANNOT_ENABLE_WRITES      = PNOR_COMP_ID | 0x14,
        RC_SFC_TIMEOUT               = PNOR_COMP_ID | 0x15,
        RC_PNOR_READ_FAILED          = PNOR_COMP_ID | 0x16,
        RC_PNOR_WRITE_FAILED         = PNOR_COMP_ID | 0x17,
        RC_CORRUPTED_TOCS            = PNOR_COMP_ID | 0x18,
        RC_BAD_TOC_HEADER            = PNOR_COMP_ID | 0x19,
        RC_SECTION_SIZE_IS_BIG       = PNOR_COMP_ID | 0x1A,
        RC_RTPNOR_INVALID_SECTION    = PNOR_COMP_ID | 0x1B,
        RC_UNCORRECTABLE_ECC         = PNOR_COMP_ID | 0x1C,
        RC_SECTION_SIZE_IS_ZERO      = PNOR_COMP_ID | 0x1D,
        RC_MM_REMOVE_PAGES_FAILED    = PNOR_COMP_ID | 0x1E,
        RC_PNOR_READ_NOT_SUPPORTED   = PNOR_COMP_ID | 0x1F,
        RC_PNOR_WRITE_NOT_SUPPORTED  = PNOR_COMP_ID | 0x20,
        RC_NON_ECC_PROTECTED_SECTION = PNOR_COMP_ID | 0x21,
        RC_WRITABLE_PERM_FAIL        = PNOR_COMP_ID | 0x22,
        RC_WRITE_TRACKED_PERM_FAIL   = PNOR_COMP_ID | 0x23,
        //termination_rc
        RC_PARTITION_TABLE_NOT_FOUND = PNOR_COMP_ID | 0x24,
        //termination_rc
        RC_PARTITION_TABLE_CORRUPTED = PNOR_COMP_ID | 0x25,
        //termination_rc
        RC_FINDTOC_FAILED            = PNOR_COMP_ID | 0x26,
        RC_INVALID_PNOR_SIDE         = PNOR_COMP_ID | 0x27,
        //termination_rc
        RC_INVALID_WORKING_TOC       = PNOR_COMP_ID | 0x28,
        RC_INVALID_TOC               = PNOR_COMP_ID | 0x29,
        RC_WRONG_SIZE_FROM_READ      = PNOR_COMP_ID | 0x2A,

        //@fixme-RTC:131607-Temporary value to allow HWSV compile
        //termination_rc
        RC_PNOR_CORRUPTION           = PNOR_COMP_ID | 0x99,
    };

    enum UserDetailsTypes
    {
        PNOR_UDT_NO_FORMAT           = 0x0,
        PNOR_UDT_PNORDD_PARAMETERS   = 0x1,
    };
};

#endif
