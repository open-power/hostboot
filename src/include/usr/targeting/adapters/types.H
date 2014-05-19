/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/adapters/types.H $                  */
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

#ifndef __TARGETING_TYPES_H
#define __TARGETING_TYPES_H

/**
 *  @file targeting/adapters/types.H
 *
 *  @brief Platform specific type translation support
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <hbotcompid.H>

#ifndef PARSER

#include <sys/sync.h>
#include <util/singleton.H>
#include <vmmconst.h>

/**
 *  @brief Adapt common singleton declaration to specific platform
 *
 *  @param[in] __T__
 *      Type of singleton, fully namespaced
 *
 *  @param[in] __NAME__
 *      Symbol name for singleton
 */
#define TARG_DECLARE_SINGLETON(__T__,__NAME__) \
    typedef Singleton<__T__> __NAME__;

/**
 *  @brief Adapt common singleton "getter" to the specific platform
 *
 *  @param[in] __TYPE__
 *      Typedef for singleton, as created above
 *
 *  @return Singleton reference for the given singleton
 */
#define TARG_GET_SINGLETON(__TYPE__) \
    __TYPE__::instance()

#endif // PARSER
#endif // __TARGETING_TYPES_H
