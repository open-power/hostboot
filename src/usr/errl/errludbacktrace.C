/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludbacktrace.C $                              */
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
/**
 *  @file errludbacktrace.C
 *
 *  @brief Implementation of ErrlUserDetailsBackTrace
 */
#include <errl/errludbacktrace.H>
#include <errl/errlreasoncodes.H>
#include <errl/backtrace.H>

namespace ERRORLOG
{

//------------------------------------------------------------------------------
ErrlUserDetailsBackTrace::ErrlUserDetailsBackTrace()
{
    // Collect the backtrace
    std::vector<uint64_t> l_bt;
    collectBacktrace(l_bt);

    if (l_bt.size())
    {
        uint32_t l_size = l_bt.size() * sizeof(uint64_t);
        uint8_t * l_pBuf = reallocUsrBuf(l_size);
        memcpy(l_pBuf, &l_bt[0], l_size);
    
        // Set up ErrlUserDetails instance variables
        iv_CompId = ERRL_COMP_ID;
        iv_Version = 1;
        iv_SubSection = ERRL_UDT_BACKTRACE;
    }
}

//------------------------------------------------------------------------------
ErrlUserDetailsBackTrace::~ErrlUserDetailsBackTrace()
{

}

}

