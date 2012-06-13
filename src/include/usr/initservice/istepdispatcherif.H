/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/initservice/istepdispatcherif.H $
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
#ifndef __INITSERVICE_ISTEPDISPATCHERIF_H
#define __INITSERVICE_ISTEPDISPATCHERIF_H

#include    <sys/msg.h>

namespace INITSERVICE
{

/**
* @brief This function returns the MBOX Message Queue used by the istep
*      dispatcher.
*
* @param[out] o_msgQ - The message queue.
*
* @return NONE.
*/
void getIstepMsgQ ( msg_q_t & o_msgQ );

/**
 * @brief This function returns the current MBOX Message used by the istep
 *      dispatcher.
 *
 * @param[out] o_msg - The message.
 *
 * @return NONE.
 */
void getIstepMsg ( msg_t* & o_msg );

}

#endif
