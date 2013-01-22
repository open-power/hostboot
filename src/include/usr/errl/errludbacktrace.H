/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludbacktrace.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

