/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/istep_mbox_msgs.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __INITSERVICE_ISTEP_MBOX_MSGS_H
#define __INITSERVICE_ISTEP_MBOX_MSGS_H

#include <mbox/mbox_queues.H>

/**
 * @file istep_mbox_msgs.H
 *
 * @brief   Mailbox types used by IStepDisp to communicate with FSP/SP
 *
 */
namespace   INITSERVICE
{

const uint32_t SPLESS_MSG   = 0x000F0000;
const uint32_t ISTEP_MSG_SUCCESS     = 0x00F00000;
const uint32_t ISTEP_INVALID_MESSAGE = 0x00F00000;

// ------------------------------------------------------------------
// HwSvr Msg Type RC values
enum
{
    HWSVR_MSG_SUCCESS            = 0x00,
    HWSVR_INVALID_MESSAGE        = 0x01,
    HWSVR_MSG_ERROR              = 0x02,
};

// ------------------------------------------------------------------
// HwSvr Msg Type Enums
enum
{
    // Secure
    HWSVR_ISTEP_MSG_TYPE        = 0x00,
    // Unsecure
    HWSVR_BREAKPOINT            = 0x00,
    HWSVR_SYNC_POINT            = 0x10,
    HWSVR_IPL_PROGRESS_CODE     = 0x11,
    HWSVR_DO_IOVALID_PROCESSING = 0xC1,
    HWSVR_COALESCE_HOST         = 0xC2,
    HWSVR_DO_SHUTDOWN           = 0x12
};

// ------------------------------------------------------------------
// Msgs that IstepDispatcher can accept
enum
{
    // --------------------------------------------------------------
    // General Messages from all sources
    // --------------------------------------------------------------
    ISTEP_MSG_TYPE          = MBOX::FIRST_SECURE_MSG |
                                HWSVR_ISTEP_MSG_TYPE,
    SYNC_POINT_REACHED      = MBOX::FIRST_UNSECURE_MSG |
                                HWSVR_SYNC_POINT,
    BREAKPOINT              = MBOX::FIRST_UNSECURE_MSG |
                                HWSVR_BREAKPOINT,
    PROCESS_IOVALID_REQUEST = MBOX::FIRST_UNSECURE_MSG |
                              HWSVR_DO_IOVALID_PROCESSING,
    IPL_PROGRESS_CODE       = MBOX::FIRST_UNSECURE_MSG |
                                HWSVR_IPL_PROGRESS_CODE,
    SHUTDOWN                = MBOX::FIRST_UNSECURE_MSG |
                                HWSVR_DO_SHUTDOWN,
    COALESCE_HOST           = MBOX::FIRST_UNSECURE_MSG |
                                HWSVR_COALESCE_HOST,

};

}   // namespace

#endif
