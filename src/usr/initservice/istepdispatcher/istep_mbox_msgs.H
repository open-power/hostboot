/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/initservice/istepdispatcher/istep_mbox_msgs.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
const uint32_t ISTEP_WORKER_MSG = 0x00F00000;

// ------------------------------------------------------------------
// HwSvr Msg Type Enums
enum
{
    HWSVR_BREAKPOINT            = 0x00,
    HWSVR_SYNC_POINT            = 0x10,
};

// ------------------------------------------------------------------
// Worker Thread Msg Type Enums
enum
{
    WORKER_MORE_WORK_NEEDED     = 0x00,
    WORKER_BREAKPOINT           = 0x01,
};

// ------------------------------------------------------------------
// SPLess Msg Type Enums
enum
{
    // Randomly picked 0xAA since SPLess mode looks at this to know whether it
    // got a shutdown.  originall was 0x0, and shutdown every time.
    // TODO - need to check if the simics script needs to know this value.
    // Opened Issue 45042 to have this as well as hb-istep support of shutdown
    // removed.
    SPLESS_SHUTDOWN_CMD         = 0xAA,
};

// ------------------------------------------------------------------
// Msgs that IstepDispatcher can accept
enum
{
    // --------------------------------------------------------------
    // General Messages from all sources
    // --------------------------------------------------------------
    SYNC_POINT_REACHED      = MBOX::FIRST_UNSECURE_MSG |
                                HWSVR_SYNC_POINT,
    BREAKPOINT              = MBOX::FIRST_UNSECURE_MSG |
                                HWSVR_BREAKPOINT,

    // --------------------------------------------------------------
    // Worker Thread Messages
    // --------------------------------------------------------------
    MORE_WORK_NEEDED        = MBOX::FIRST_SECURE_MSG |
                                ISTEP_WORKER_MSG |
                                WORKER_MORE_WORK_NEEDED,
    BREAKPOINT_WORKER       = MBOX::FIRST_SECURE_MSG |
                                ISTEP_WORKER_MSG |
                                WORKER_BREAKPOINT,

    // --------------------------------------------------------------
    // SPLess Messages
    // --------------------------------------------------------------
    SHUTDOWN_SPLESS         = MBOX::FIRST_SECURE_MSG |
                                SPLESS_MSG |
                                SPLESS_SHUTDOWN_CMD,

};

}   // namespace

#endif
