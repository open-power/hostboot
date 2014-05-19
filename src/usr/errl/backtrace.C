/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/backtrace.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
/**
 *  @file backtrace.C
 *
 *  @brief Provide backtrace support to the errorlog classes.
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <trace/interface.H>
#include <errl/backtrace.H>
#include <vector>

#include <kernel/console.H>

namespace ERRORLOG
{

// ------------------------------------------------------------------
// collectBacktrace
// ------------------------------------------------------------------
void collectBacktrace ( std::vector<uint64_t> & o_addrVector )
{
    o_addrVector.clear();

    uint64_t* frame = static_cast<uint64_t*>(framePointer());
    bool first = true;
    while (frame != NULL)
    {
        if ((0 != *frame) && (!first))
        {
            o_addrVector.push_back( frame[2] );
        }

        frame = reinterpret_cast<uint64_t*>(*frame);
        first = false;
    }
} // End collectBacktrace


} // End ERRORLOG namespace

