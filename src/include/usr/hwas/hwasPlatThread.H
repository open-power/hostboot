/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasPlatThread.H $                       */
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
#ifndef __HWAS_PLAT_THREAD_H
#define __HWAS_PLAT_THREAD_H

/**
* @file hwas/hwasPlatThread.H
*
* @brief Adapts platform neutral thread functions.
*/

//******************************************************************************
// Includes
//******************************************************************************

#define HWAS_MUTEX_TYPE \
mutable mutex_t

#define HWAS_MUTEX_INIT(_t) \
 mutex_init(_t)

#define HWAS_MUTEX_DESTROY(_t) \
 mutex_destroy(_t)

#define HWAS_MUTEX_LOCK(_t) \
 mutex_lock(_t)

#define HWAS_MUTEX_UNLOCK(_t) \
 mutex_unlock(_t)

#endif // __HWAS_PLAT_THREAD_H
