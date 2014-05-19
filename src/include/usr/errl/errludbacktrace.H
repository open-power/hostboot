/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludbacktrace.H $                      */
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
#ifndef ERRL_UDBACKTRACE_H
#define ERRL_UDBACKTRACE_H

/**
 *  @file errludbacktrace.H
 *
 *  Defines the ErrlUserDetailsBackTrace class that adds backtrace FFDC to an
 *  error log as user detail data
 */

#include <errl/errluserdetails.H>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsBackTrace
 *
 * Adds backtrace FFDC to an error log as user detail data
 */
class ErrlUserDetailsBackTrace : public ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *  
     *  Captures the backtrace internally
     */
    ErrlUserDetailsBackTrace();

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsBackTrace();

private:
    // Disabled
    ErrlUserDetailsBackTrace(const ErrlUserDetailsBackTrace &);
    ErrlUserDetailsBackTrace & operator=(const ErrlUserDetailsBackTrace &);
};

}

#endif

