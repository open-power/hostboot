/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/adapters/erroradapter.H $           */
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

#ifndef __TARGETING_ERRORADAPTER_H
#define __TARGETING_ERRORADAPTER_H

/**
 *  @file targeting/adapters/erroradapter.H
 *
 *  @brief Adapts platform neutral error log requests to the platform
 */

//******************************************************************************
// Includes
//******************************************************************************

// Include the platform specific errlentry.H file and pick up the platform 
// specific errlHndlt_t typedef. This is enough for common code to use pass 
// errlHndl_t pointers around and check for NULL
#include <errl/errlentry.H>

namespace COMMON
{

namespace ERRORLOG
{
    /**
     *  @brief Import the ::ERRORLOG namespace into the ::COMMON:ERRORLOG
     *      namespace.  This allows all the common targeting code to use the 
     *      same namespacing yet directly invoke platform specific error log 
     *      support.  Since nothing else is declared in the namespace, there is 
     *      no danger of a namespace collision.
     */
    using namespace ::ERRORLOG;

} // End namespace COMMON

} // End namespace ERRORLOG

#endif // __TARGETING_ERRORADAPTER_H
