/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/prdfGlobal.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2014              */
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

#ifndef PRDF_GLOBAL_HB_H
#define PRDF_GLOBAL_HB_H

/**
 * @file  prdfGlobal.H
 * @brief PRD global code specific to hostboot.
 *
 * This file contains the Processor Runtime Diagnostics global variable
 * and type declarations specific to hostboot.
 */

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/
#include <prdfGlobal_common.H>
#include <util/singleton.H>
#include <sys/sync.h> // for mutex support

/*--------------------------------------------------------------------*/
/*  Singleton macros common to both FSP and Hostboot                  */
/*--------------------------------------------------------------------*/
/**
 *  @brief common singleton declaration to specific platform
 *
 *  @param[in] __T__
 *      Type of singleton, fully namespaced
 *
 *  @param[in] __NAME__
 *      Symbol name for singleton
 */

/**
 *  @brief common singleton "getter" to the specific platform
 *
 *  @param[in] __TYPE__
 *      Typedef for singleton, as created above
 *
 *  @return Singleton reference for the given singleton
 */

#define PRDF_DECLARE_SINGLETON(__T__,__NAME__) \
    typedef Singleton<__T__> __NAME__


#define PRDF_GET_SINGLETON(__TYPE__) \
    __TYPE__::instance()

// end Singleton macros

/**
 * @brief Interface to deconfig target at Runtime (Not valid in Hostboot)
 */
// FIXME:RTC: 65609 will address this issue.
// need to implement in Hostboot
#define PRDF_RUNTIME_DECONFIG( i_pTarget, i_errl, i_dmp ) \
  SUCCESS

/**
 * @brief   defined dump content to get through hostboot compilation.
 *          hwTableContent is a FSP specific enum originally defined in dump.
 */
typedef uint32_t hwTableContent;

/**
 * @brief   defined dump content type to get through hostboot compilation.
 *          CONTENT_HW is a FSP specific enum val originally defined in dump.
 */
const uint32_t CONTENT_HW = 0x40000000;

/**
 * @brief   This class provides general purpose mutual
 *          exclusion (mutex) class for locking static or
 *          member data to ensure thread safety.
 */
class prdfMutex
{
public:

    /**
     * Constructor
     */
    prdfMutex();

    /**
     * Destructor
     */
    ~prdfMutex();

    /**
     * Lock this mutex
     */
    void lock();

    /**
     * Unlock this mutex
     */
    void unlock();

private:
    mutex_t ivMutex;

    // No copies or assignments allowed
    prdfMutex(prdfMutex& r);
    prdfMutex& operator=(prdfMutex& r);
};

inline prdfMutex::prdfMutex()
{
    mutex_init(&ivMutex);
}

inline prdfMutex::~prdfMutex()
{
    mutex_destroy(&ivMutex);
}

inline void prdfMutex::lock()
{
    mutex_lock( &ivMutex );
}

inline void prdfMutex::unlock()
{
    mutex_unlock( &ivMutex );
}

/**
 * @brief   This class provides interfaces to
 *          acquire a scope mutex
 */
class prdfScopeMutex
{
public:
    /**
     * Constructor (locks the specified mutex)
     *
     * @param i_mutex the mutex to be locked
     *        for the scope of this function
     */
    prdfScopeMutex(prdfMutex& i_mutex);

    /**
     * Destructor
     */
    ~prdfScopeMutex();

private:
    prdfMutex* ivMutex;

    // No copies or assignments allowed
    prdfScopeMutex(prdfScopeMutex& r);
    prdfScopeMutex& operator=(prdfScopeMutex& r);
};

inline prdfScopeMutex::prdfScopeMutex(prdfMutex& i_mutex)
: ivMutex(&i_mutex)
{
    ivMutex->lock();
}

inline prdfScopeMutex::~prdfScopeMutex()
{
    ivMutex->unlock();
}

extern prdfMutex g_prdMutex;

/**
 * @brief macro to acquire global scope mutex
 */
#define PRDF_SYSTEM_SCOPELOCK         \
    prdfScopeMutex dataLock(g_prdMutex);

#endif // PRDF_GLOBAL_HB_H
