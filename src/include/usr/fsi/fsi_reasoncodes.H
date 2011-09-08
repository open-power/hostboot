//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/fsi/fsi_reasoncodes.H $
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
        MOD_FSIDD_DDREAD              = 0x05, /**< fsidd.C : ddRead */
        MOD_FSIDD_DDWRITE             = 0x06, /**< fsidd.C : ddWrite */
        MOD_FSIDD_INITPORT            = 0x07, /**< fsidd.C : FsiDD::initPort */
        MOD_FSIDD_POLLFORCOMPLETE     = 0x08, /**< fsidd.C : FsiDD::pollForComplete */
    };

    enum FSIReasonCode
    {
        RC_INVALID_LENGTH            = FSI_COMP_ID | 0x01, 
        RC_INVALID_ADDRESS           = FSI_COMP_ID | 0x02,
        RC_OPB_TIMEOUT               = FSI_COMP_ID | 0x03,
        RC_OPB_ERROR                 = FSI_COMP_ID | 0x04,
        RC_INVALID_TARGET            = FSI_COMP_ID | 0x05,
        RC_OPB_NO_READ_VALID         = FSI_COMP_ID | 0x06,
        RC_ERROR_ENABLING_SLAVE      = FSI_COMP_ID | 0x07,
    };
};

#endif
