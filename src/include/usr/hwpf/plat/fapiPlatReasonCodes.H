//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/plat/fapiPlatReasonCodes.H $
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
#ifndef FAPIPLATREASONCODES_H_
#define FAPIPLATREASONCODES_H_

#include <hbotcompid.H>

namespace fapi
{
    enum hwpfModuleId
    {
        MOD_RC_TO_ERRL  = 0x01,
    };

    enum hwpfReasonCode
    {
        RC_HWP_ERROR  = HWPF_COMP_ID | 0x01,
        RC_FAPI_ERROR = HWPF_COMP_ID | 0x02,
    };
};

#endif
