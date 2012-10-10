/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/initservice/istepdispatcher/istepWorker.H $
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
#ifndef __ISTEPWORKER_H
#define __ISTEPWORKER_H
/**
 *  @file istepWorker.H
 *
 *  IStep Dispatcher Worker thread
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>

#include <initservice/initsvcstructs.H>


namespace   INITSERVICE
{

/**
* @brief This function is called to start the task.
*
* @param[in/out] io_args - This is a void pointer, but the code expects that
*       this will be the msg queue to communicate with the main thread.
*
* @return NULL
*/
void* startIStepWorkerThread ( void * io_args );

/**
* @brief This function is the main loop for the Istep dispatcher worker
*       thread.
*
* @param[in] i_msgQ - The message queue to talk to the main thread.
*
* @return any errlogs 
 */
void iStepWorkerThread ( void * i_msgQ );

/**
 * @brief This function will be used to query the istep master list and the
 *      other istep headers to know what functions/tasks need to be started
 *      for the Istep/Substep that we are in.
 *
 * @param[in] i_IStep - The Istep to run.
 *
 * @param[in] i_SubStep - The SubStep to run.
 *
 * @return TaskInfo - The task info for the task to start as a result of the
 *      requested Istep/Substep.
 */
const TaskInfo * findTaskInfo ( const uint32_t i_IStep,
                                const uint32_t i_SubStep );


} // namespace

#endif
