/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludtarget.H $                         */
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
#ifndef ERRL_UDTARGET_H
#define ERRL_UDTARGET_H

/**
 *  @file errludTarget.H
 *
 *  Defines the ErrlUserDetailsTarget class that adds target FFDC to an
 *  error log as user detail data
 */

#include <errl/errluserdetails.H>

// Forward reference
namespace TARGETING
{
    class Target;
}

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsTarget
 *
 * Adds Target FFDC to an error log as user detail data
*/
class ErrlUserDetailsTarget : public ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *  
     *  Captures the supplied Target's FFDC data internally
     *  
     *  @param i_pTarget Pointer to Target to capture as user detail data
     */
    ErrlUserDetailsTarget(const TARGETING::Target * i_pTarget);

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsTarget();

private:
    // Disabled
    ErrlUserDetailsTarget(const ErrlUserDetailsTarget &);
    ErrlUserDetailsTarget & operator=(const ErrlUserDetailsTarget &);
};

}

#endif

