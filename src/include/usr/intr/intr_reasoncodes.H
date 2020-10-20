/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/intr/intr_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#ifndef INTR_REASONCODES_H
#define INTR_REASONCODES_H

#include <hbotcompid.H>

#define INTR_TRACE_NAME INTR_COMP_NAME


namespace INTR
{
    enum IntrModuleID
    {
        MOD_INVALID                    = 0x00, /**< Invalid Module ID */
        MOD_INTR_ENABLE                = 0x01, /**< intrrp.C : INTR::enableExternalInterrupts */
        MOD_INTR_DISABLE               = 0x02, /**< intrrp.C : INTR::disableExternalInterrupts */
        MOD_INTR_REGISTER              = 0x03, /**< intrrp.C : INTR::registerMsgQ */
        MOD_INTRRP_REGISTERINTERRUPT   = 0x05, /**< intrrp.C : IntrRp::registerInterrupt */
        MOD_INTR_ENABLE_PSI_INTR       = 0x06, /**< intrrp.C : INTR::enablePsiIntr */
        MOD_INTR_INIT_XIVR             = 0x07, /**< intrrp.C : INTR::initXIVR */
        MOD_INTR_INIT_MPIPLAREA        = 0x08, /**< intrrp.C : IntrRp::initailizeMpiplSyncArea() */
        MOD_INTR_SYNC_NODES            = 0x09, /**< intrrp.C : IntrRp::syncNodes() */
        MOD_INTR_SYNC_ADDNODE          = 0x0A, /**< intrrp.C : IntrRp::addHbNodeToMpiplSyncArea */
        MOD_INTR_ADDHBNODE             = 0x0B, /**< intrrp.C : INTR::addHbNode */
        MOD_INTR_EXTRACTNODEINFO       = 0x0C, /**< intrrp.C : INTR::extractHbNodeInfo */
        MOD_INTRRP_SENDEOI             = 0x0D, /**< intrrp.C : INTR::sendEOI */
        MOD_INTRRP_MASKINTERRUPT       = 0x0E, /**< intrrp.C : INTR::maskInterruptSource */
        MOD_INTRRP_UNMASKINTERRUPT     = 0x0F, /**< intrrp.C : INTR::unmaskInterruptSource */
        MOD_INTRRP_HNDLPSUINTERRUPT    = 0x10, /**< intrrp.C : INTR::handlePsuInterrupt */
        MOD_INTRRP_RESETINTUNIT        = 0x11, /**< intrrp.C : IntrRp::resetIntUnit */
        MOD_INTRRP_XIVE_SENDEOI        = 0x12,
        MOD_INTRRP_IPC                 = 0x13,
        MOD_INTR_DUMP                  = 0x14, /**< intrrp.C : INTR::printInterruptInfo */
        MOD_INTRRP_UNREGISTERINTERRUPT = 0x15, /**< intrrp.C : IntrRp::unregisterInterrupt */
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
        RC_PSIHB_ESB_EOI_FAIL         = INTR_COMP_ID | 0x08,
        RC_XIVE_ESB_WRONG_STATE       = INTR_COMP_ID | 0x09,
        RC_PSU_DOORBELL_TIMEOUT       = INTR_COMP_ID | 0x0A,
        RC_XIVE_PBUS_QUIESCE_TIMEOUT  = INTR_COMP_ID | 0x0B,
        RC_MESSAGE_SEND_ERROR         = INTR_COMP_ID | 0x0C,
        RC_IPC_DATA_INVALID           = INTR_COMP_ID | 0x0D,
        RC_SOURCE_NOT_REGISTERED      = INTR_COMP_ID | 0x0E,
        RC_NODE_SYNC_TIMEOUT          = INTR_COMP_ID | 0x0F,
        RC_PROC_IS_NULLPTR            = INTR_COMP_ID | 0x10,
    };
};

#endif
