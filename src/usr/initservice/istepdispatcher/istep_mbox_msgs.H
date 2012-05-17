//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/istepdispatcher/istep_mbox_msgs.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __INITSERVICE_ISTEP_MBOX_MSGS_H
#define __INITSERVICE_ISTEP_MBOX_MSGS_H

/**
 * @file istep_mbox_msgs.H
 *
 * @brief   Mailbox types used by IStepDisp to communicate with FSP/SP
 *
 */

#include    "splesscommon.H"

namespace   INITSERVICE
{

enum
{
    // TODO - I'm not changing this file, but I would really like to put the
    // SYNC_POINT_REACHED message here.  Since its related to Isteps and
    // syncing Hostboot and Fsp.  But to do that, this needs to be in the
    // src/include/usr side of things.
    //
    // Plus, I think its weird that this file uses definitions from
    // splesscommon.H.  It should be the other way around.  Define them here
    // and use them from splesscommon.  Issue 42491 has been opened to
    // discuss this further.
    //
    // I am going to define my own message in the code that I'm writing until
    // we get something figured out.
    SINGLE_STEP_TYPE        =   MBOX::FIRST_SECURE_MSG |
                                    SPLESS::SPLESS_SINGLE_ISTEP_CMD,
    CLEAR_TRACE_TYPE        =   MBOX::FIRST_SECURE_MSG |
                                    SPLESS::SPLESS_CLEAR_TRACE_CMD,
    SHUTDOWN_TYPE           =   MBOX::FIRST_SECURE_MSG |
                                    SPLESS::SPLESS_SHUTDOWN_CMD,
    BREAKPOINT_TYPE        =   MBOX::FIRST_UNSECURE_MSG |
                                    SPLESS::SPLESS_AT_BREAK_POINT
};

}   // namespace

#endif
