/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/intr/intr_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef INTR_REASONCODES_H
#define INTR_REASONCODES_H

#include <hbotcompid.H>

namespace INTR
{
    enum IntrModuleID
    {
        MOD_INVALID                  = 0x00, /**< Invalid Module ID */
        MOD_INTR_ENABLE              = 0x01, /**< intrrp.C : INTR::enableExternalInterrupts */
        MOD_INTR_DISABLE             = 0x02, /**< intrrp.C : INTR::disableExternalInterrupts */
        MOD_INTR_REGISTER            = 0x03, /**< intrrp.C : INTR::registerMsgQ */
        MOD_INTRRP_CHECKADDRESS      = 0x04, /**< intrrp.C : IntrRp::checkAddress */
        MOD_INTRRP_REGISTERINTERRUPT = 0x05, /**< intrrp.C : IntrRp::registerInterrupt */
        MOD_INTR_ENABLE_PSI_INTR     = 0x06, /**< intrrp.C : INTR::enablePsiIntr */
        MOD_INTR_INIT_XIVR           = 0x07, /**< intrrp.C : INTR::initXIVR */
        MOD_INTR_INIT_MPIPLAREA      = 0x08, /**< intrrp.C : IntrRp::initailizeMpiplSyncArea() */
        MOD_INTR_SYNC_NODES          = 0x09, /**< intrrp.C : IntrRp::syncNodes() */
        MOD_INTR_SYNC_ADDNODE        = 0x0A, /**< intrrp.C : IntrRp::addHbNodeToMpiplSyncArea */
        MOD_INTR_ADDHBNODE           = 0x0B, /**< intrrp.C : INTR::addHbNode */
        MOD_INTR_EXTRACTNODEINFO     = 0x0C, /**< intrrp.C : INTR::extractHbNodeInfo */
    };

    enum IntrReasonCode
    {
        RC_ALREADY_REGISTERED         = INTR_COMP_ID | 0x01,
        RC_REGISTRY_NOT_READY         = INTR_COMP_ID | 0x02,
        RC_RP_NOT_INITIALIZED         = INTR_COMP_ID | 0x03,
        RC_BAD_VIRTUAL_IO_ADDRESS     = INTR_COMP_ID | 0x04,
        RC_BAD_ISN                    = INTR_COMP_ID | 0x05,
        //termination_rc
        RC_PERSISTENT_INTERRUPTS      = INTR_COMP_ID | 0x06,
        RC_CANNOT_MAP_MEMORY          = INTR_COMP_ID | 0x07,
    };
};

#endif
