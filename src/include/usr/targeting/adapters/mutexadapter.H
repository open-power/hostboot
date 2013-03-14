/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/adapters/mutexadapter.H $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef __TARGETING_MUTEXADAPTER_H
#define __TARGETING_MUTEXADAPTER_H

/**
* @file mutexAdapter.H
*
* @brief Provides Hostboot specific TARGETING Mutex
*/

#include <sys/sync.h>

#define TARG_MUTEX_TYPE \
 mutex_t

#define TARG_MUTEX_INIT(_t) \
 mutex_init(&(_t))

#define TARG_MUTEX_DESTROY(_t) \
 mutex_destroy(&(_t))

#define TARG_MUTEX_LOCK(_t) \
 mutex_lock(&(_t))

#define TARG_MUTEX_UNLOCK(_t) \
 mutex_unlock(&(_t))

#endif
