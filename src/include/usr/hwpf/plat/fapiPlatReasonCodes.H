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
        MOD_RC_TO_ERRL                             = 0x01,
        MOD_FAPI_GET_CHILD_CHIPLETS                = 0x02,
        MOD_FAPI_GET_PARENT_CHIP                   = 0x03,
        MOD_PLAT_ATTR_SVC_CREATE_ATTR_ACCESS_ERROR = 0x04,
        MOD_HANDLE_ECMD_BUF_RC                     = 0x05,
        MOD_VERIFY_CFAM_ACCESS_TARGET              = 0x06,
    };

    enum hwpfReasonCode
    {
        RC_HWP_ERROR                  = HWPF_COMP_ID | 0x01,
        RC_FAPI_ERROR                 = HWPF_COMP_ID | 0x02,
        RC_INVALID_REQUEST            = HWPF_COMP_ID | 0x03,
        RC_UNSUPPORTED_REQUEST        = HWPF_COMP_ID | 0x04,
        RC_NO_SINGLE_PARENT           = HWPF_COMP_ID | 0x05,
        RC_FAILED_TO_ACCESS_ATTRIBUTE = HWPF_COMP_ID | 0x06,
        RC_ECMD_OPERATION_FAILURE     = HWPF_COMP_ID | 0x07,
        RC_CFAM_ACCESS_ON_PROC_ERR    = HWPF_COMP_ID | 0x08,
    };
};

#endif
