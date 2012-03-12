//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errludbacktrace.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file errludbacktrace.C
 *
 *  @brief Implementation of ErrlUserDetailsBackTrace
 */
#include <errl/errludbacktrace.H>
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
        iv_CompId = HBERRL_COMP_ID;
        iv_Version = 1;
        iv_SubSection = HBERRL_UDT_BACKTRACE;
    }
}

//------------------------------------------------------------------------------
ErrlUserDetailsBackTrace::~ErrlUserDetailsBackTrace()
{

}

}

