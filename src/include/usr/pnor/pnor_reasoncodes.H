/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/pnor_reasoncodes.H $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
        //RC_UNSUPORTED_HARDWARE Must have one unique use
        //   for Shutdown path  
        RC_UNSUPORTED_HARDWARE       = PNOR_COMP_ID | 0x0A,
        RC_MICRON_INCOMPLETE         = PNOR_COMP_ID | 0x0B,
        //RC_PARTITION_TABLE_INVALID Must have one unique use
        //   for Shutdown path  
        RC_PARTITION_TABLE_INVALID   = PNOR_COMP_ID | 0x0C,
        //RC_UNSUPPORTED_MODE can only be used in
        //   shutdown calls.
        RC_UNSUPPORTED_MODE          = PNOR_COMP_ID | 0x0D,
        //RC_UNSUPPORTED_SFCRANGE can only be used in
        //   shutdown calls.
        RC_UNSUPPORTED_SFCRANGE      = PNOR_COMP_ID | 0x0E,
    };
};

#endif
