/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/runtime_reasoncodes.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
        MOD_HDATSERVICE_GETHOSTDATASECTION  = 0x07, /**< hdatservice.C */
        MOD_HDATSERVICE_VERIFY_HDAT_ADDRESS  = 0x08, /**< hdatservice.C */
        MOD_TCE_CREATE                  = 0x09,   /**< tce.C */
        MOD_TCE_INIT_HDW                = 0x0A,   /**< tce.C */
        MOD_TCE_ALLOCATE                = 0x0B,   /**< tce.C */
        MOD_TCE_DEALLOCATE              = 0x0C,   /**< tce.C */
        MOD_TCE_INIT                    = 0x0D,   /**< tce.C */
        MOD_TCE_MAP                     = 0x0E,   /**< tce.C */
        MOD_HDATSERVICE_FINDSPIRA       = 0x0F, /** hdatservice.C */
        MOD_HDATSERVICE_UPDATE_SECTION_ACTUAL = 0x10, /**< hdatservice.C */
        MOD_HDATSERVICE_MAPREGION       = 0x11, /**< hdatservice.C */

        // customize_attrs_for_payload.C
        MOD_CUST_COMP_NON_PHYP_RT_TARGET = 0x12,
        MOD_CUST_CONF_HBRT_HYP_IDS       = 0x13,
    };

    enum RuntimeReasonCode
    {
        RC_DO_NOT_USE_THIS          = RUNTIME_COMP_ID | 0x00,
        RC_ATTR_GET_FAIL            = RUNTIME_COMP_ID | 0x01,
        RC_BAD_HDAT_HEADER          = RUNTIME_COMP_ID | 0x02,
        RC_BAD_HDAT_TUPLE           = RUNTIME_COMP_ID | 0x03,
        RC_INVALID_STANDALONE       = RUNTIME_COMP_ID | 0x04,
        RC_CANNOT_MAP_MEMORY        = RUNTIME_COMP_ID | 0x05,
        //RC_XXX                    = RUNTIME_COMP_ID | 0x06,
        RC_CANNOT_MAP_MEMORY2       = RUNTIME_COMP_ID | 0x07,
        RC_INVALID_PAYLOAD_KIND     = RUNTIME_COMP_ID | 0x08,
        RC_NO_HSVC_NODE_DATA_FOUND  = RUNTIME_COMP_ID | 0x09,
        RC_BAD_NACA                 = RUNTIME_COMP_ID | 0x0A,
        RC_INVALID_ADDRESS          = RUNTIME_COMP_ID | 0x0B,
        RC_INVALID_SECTION          = RUNTIME_COMP_ID | 0x0C,
        RC_CANNOT_MAP_MEMORY3       = RUNTIME_COMP_ID | 0x0D,
        RC_TCE_INVALID_SIZE         = RUNTIME_COMP_ID | 0x0E,
        RC_TCE_ADDR_NOT_ALIGNED     = RUNTIME_COMP_ID | 0x0F,
        RC_TCE_INIT_NOT_RUN         = RUNTIME_COMP_ID | 0x10,
        RC_TCE_DEV_MAP_FAIL         = RUNTIME_COMP_ID | 0x11,
        RC_TCE_DEV_UNMAP_FAIL       = RUNTIME_COMP_ID | 0x12,
        RC_TCE_NO_ACTIVE_PSI        = RUNTIME_COMP_ID | 0x13,
        RC_TCE_NOT_ENOUGH_FREE_ENTRIES = RUNTIME_COMP_ID | 0x14,
        RC_TCE_ENTRY_NOT_CONTIGUOUS   = RUNTIME_COMP_ID | 0x15,
        RC_NO_SPIRA                 = RUNTIME_COMP_ID | 0x16,
        RC_CANNOT_MAP_HDAT          = RUNTIME_COMP_ID | 0x17,
        RC_NOT_ENOUGH_SPACE         = RUNTIME_COMP_ID | 0x18,
        RT_UNIT_TARGET_NOT_FOUND    = RUNTIME_COMP_ID | 0x19,
        RT_TARGET_TYPE_NOT_SUPPORTED = RUNTIME_COMP_ID | 0x1A,
        RT_NO_PROC_TARGET            = RUNTIME_COMP_ID | 0x1B
    };

    enum UserDetailsTypes
    {
        RUNTIME_UDT_NO_FORMAT       = 0x0,
        RUNTIME_UDT_NACA            = 0x1,
        RUNTIME_UDT_SPIRA           = 0x2,
        RUNTIME_UDT_TUPLE           = 0x3,
    };
};

#endif
