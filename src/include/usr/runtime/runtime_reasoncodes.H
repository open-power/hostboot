/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/runtime_reasoncodes.H $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#ifndef __RUNTIME_REASONCODES_H
#define __RUNTIME_REASONCODES_H

#include <hbotcompid.H>

namespace RUNTIME
{
    enum RuntimeModuleId
    {
        MOD_RUNTIME_INVALID             = 0x00, /**< Zero is an invalid module id */
        MOD_RUNTIME_POP_SYS_ATTR        = 0x01, 
        MOD_RUNTIME_POP_NODE_ATTR       = 0x02,
    };

    enum RuntimeReasonCode
    {
        RC_ATTR_GET_FAIL            = RUNTIME_COMP_ID | 0x01,
    };
};

#endif
