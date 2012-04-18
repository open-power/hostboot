//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errludtarget.C $
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
 *  @file errludtarget.C
 *
 *  @brief Implementation of ErrlUserDetailsTarget
 */
#include <errl/errludtarget.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>

namespace ERRORLOG
{

//------------------------------------------------------------------------------
ErrlUserDetailsTarget::ErrlUserDetailsTarget(
    const TARGETING::Target * i_pTarget)
: iv_pTarget(i_pTarget)
{

}

//------------------------------------------------------------------------------
ErrlUserDetailsTarget::~ErrlUserDetailsTarget()
{

}

//------------------------------------------------------------------------------
void ErrlUserDetailsTarget::addToLog(errlHndl_t i_errl)
{
    if (i_errl != NULL)
    {
        if (iv_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            const char *l_bufPtr = "MASTER_PROCESSOR_CHIP_TARGET_SENTINEL";
            i_errl->addFFDC(HBERRL_COMP_ID,
                            l_bufPtr, strlen(l_bufPtr)+1,
                            1, HBERRL_UDT_TARGET);
        }
        else
        {
            uint32_t l_bufSize = 0;
            char * l_bufPtr = NULL;

            l_bufPtr = iv_pTarget->targetFFDC( l_bufSize );
            if (l_bufPtr)
            {
                i_errl->addFFDC(HBERRL_COMP_ID,
                                l_bufPtr, l_bufSize,
                                1, HBERRL_UDT_TARGET);
                free (l_bufPtr);
            }
        }
    }
}

}

