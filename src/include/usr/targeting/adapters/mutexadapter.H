/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/adapters/mutexadapter.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
