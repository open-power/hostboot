/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/targplatutil.C $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

/**
 *  @file targeting/targplatutil.C
 *
 *  @brief Provides implementation for general platform specific utilities
 *      to support core functions
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdlib.h>

// TARG
#include <targeting/targplatutil.H>
#include <targeting/common/predicates/predicates.H>
#include <errl/errlmanager.H>

namespace TARGETING
{

namespace UTIL
{

#define TARG_NAMESPACE "TARGETING::UTIL"
#define TARG_CLASS ""

//******************************************************************************
// createTracingError
//******************************************************************************

void createTracingError(
    const uint8_t     i_modId,
    const uint16_t    i_reasonCode,
    const uint32_t    i_userData1,
    const uint32_t    i_userData2,
    const uint32_t    i_userData3,
    const uint32_t    i_userData4,
          errlHndl_t& io_pError)
{
#ifndef __HOSTBOOT_RUNTIME // TODO: RTC 87716
    errlHndl_t pNewError = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                   i_modId,
                                   i_reasonCode,
                                   static_cast<uint64_t>(i_userData1) << 32
                                       | (i_userData2 & (0xFFFFFFFF)),
                                   static_cast<uint64_t>(i_userData3) << 32
                                       | (i_userData4 & (0xFFFFFFFF)));
    if(io_pError != NULL)
    {
        // Tie logs together; existing log primary, new log as secondary
        pNewError->plid(io_pError->plid());
        errlCommit(pNewError,TARG_COMP_ID);
    }
    else
    {
        io_pError = pNewError;
        pNewError = NULL;
    }
#endif

    return;
}

void getMasterNodeTarget(Target*& o_masterNodeTarget)
{
    Target* masterNodeTarget = NULL;
    PredicateCTM nodeFilter(CLASS_ENC, TYPE_NODE);
    TargetRangeFilter localBlueprintNodes(
                targetService().begin(),
                targetService().end(),
                &nodeFilter);
    if(localBlueprintNodes)
    {
        masterNodeTarget = *localBlueprintNodes;
    }

    o_masterNodeTarget = masterNodeTarget;
}

#undef TARG_NAMESPACE
#undef TARG_CLASS

} // End namespace TARGETING::UTIL

} // End namespace TARGETING

