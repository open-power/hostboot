//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/pnor/pnor_reasoncodes.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __PNOR_REASONCODES_H
#define __PNOR_REASONCODES_H

#include <hbotcompid.H>

namespace PNOR
{
    enum PNORModuleId
    {
        MOD_PNORRP_WAITFORMESSAGE      = 0x01, /**< pnorrp.C : PnorRP::waitForMessage */
        MOD_PNORRP_COMPUTEDEVICEADDR   = 0x02, /**< pnorrp.C : PnorRP::computeDeviceAddr */
        MOD_PNORRP_GETSECTIONINFO      = 0x03, /**< pnorrp.C : PnorRP::getSectionInfo */
        MOD_PNORRP_COMPUTESECTION      = 0x04, /**< pnorrp.C : PnorRP::computeSection */
        MOD_PNORRP_INITDAEMON          = 0x05, /**< pnorrp.C : PnorRP::initDaemon */
        MOD_PNORRP_READTOC             = 0x06, /**< pnorrp.C : PnorRP::readTOC */
        MOD_PNORRP_READFROMDEVICE      = 0x07, /**< pnorrp.C : PnorRP::readFromDevice */
        MOD_PNORRP_WRITETODEVICE       = 0x08, /**< pnorrp.C : PnorRP::writeToDevice */

        MOD_PNORDD_VERIFYADDRESSRANGE  = 0x11  /**< pnordd.C : PnorDD::verifyAddressRange */
    };

    enum PNORReasonCode
    {
        RC_INVALID_MESSAGE_TYPE      = PNOR_COMP_ID | 0x01, 
        RC_INVALID_ADDRESS           = PNOR_COMP_ID | 0x02,
        RC_INVALID_SECTION           = PNOR_COMP_ID | 0x03,
        RC_EXTERNAL_ERROR            = PNOR_COMP_ID | 0x04,
        RC_STARTUP_FAIL              = PNOR_COMP_ID | 0x05,
        RC_INVALID_ASYNC_MESSAGE     = PNOR_COMP_ID | 0x06,
    };
};

#endif
