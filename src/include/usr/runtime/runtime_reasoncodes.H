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
        MOD_RUNTIME_INVALID             = 0x00, /**< Invalid module id */
        MOD_RUNTIME_POP_SYS_ATTR        = 0x01, /**< populate_attributes.C */
        MOD_RUNTIME_POP_NODE_ATTR       = 0x02, /**< populate_attributes.C */
        MOD_HDATSERVICE_CHECK_HEADER    = 0x03, /**< hdatservice.C */
        MOD_HDATSERVICE_CHECK_TUPLE     = 0x04, /**< hdatservice.C */
        MOD_HDATSERVICE_LOAD_HOST_DATA  = 0x05, /**< hdatservice.C */
        MOD_HDATSERVICE_GET_STANDALONE_SECTION  = 0x06, /**< hdatservice.C */
        MOD_HDATSERVICE_GET_HOST_DATA_SECTION  = 0x07, /**< hdatservice.C */
        MOD_HDATSERVICE_VERIFY_HDAT_ADDRESS  = 0x08, /**< hdatservice.C */
    };

    enum RuntimeReasonCode
    {
        RC_ATTR_GET_FAIL            = RUNTIME_COMP_ID | 0x01,
        RC_BAD_HDAT_HEADER          = RUNTIME_COMP_ID | 0x02,
        RC_BAD_HDAT_TUPLE           = RUNTIME_COMP_ID | 0x03,
        RC_INVALID_STANDALONE       = RUNTIME_COMP_ID | 0x04,
        RC_CANNOT_MAP_MEMORY        = RUNTIME_COMP_ID | 0x05,
        RC_WRONG_PAYLOAD_ATTRS      = RUNTIME_COMP_ID | 0x06,
        RC_CANNOT_MAP_MEMORY2       = RUNTIME_COMP_ID | 0x07,
        RC_INVALID_PAYLOAD_KIND     = RUNTIME_COMP_ID | 0x08,
        RC_NO_HSVC_NODE_DATA_FOUND  = RUNTIME_COMP_ID | 0x09,
        RC_BAD_NACA                 = RUNTIME_COMP_ID | 0x0A,
        RC_INVALID_ADDRESS          = RUNTIME_COMP_ID | 0x0B,
        RC_INVALID_SECTION          = RUNTIME_COMP_ID | 0x0C,
    };
};

#endif
