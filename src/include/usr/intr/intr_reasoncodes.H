//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/intr/intr_reasoncodes.H $
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
#ifndef INTR_REASONCODES_H
#define INTR_REASONCODES_H

#include <hbotcompid.H>

namespace INTR
{
    enum IntrModuleID
    {
        UNDEFINED_MODULE_ERRL_ID        = 0,
        INTR_MODULE_ID,
    };

    enum IntrReasonCode
    {
        INTR_ALREADY_REGISTERED         = INTR_COMP_ID | 0x01,
        INTR_REGISTRY_NOT_READY         = INTR_COMP_ID | 0x02,
        INTR_RP_NOT_INITIALIZED         = INTR_COMP_ID | 0x03,
        INTR_BAD_VIRTUAL_IO_ADDRESS     = INTR_COMP_ID | 0x04,
    };
};

#endif
