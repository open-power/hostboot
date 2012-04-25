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
#include <targeting/common/trace.H>

namespace ERRORLOG
{

//------------------------------------------------------------------------------
ErrlUserDetailsTarget::ErrlUserDetailsTarget(
    const TARGETING::Target * i_pTarget)
{
    // Set up ErrlUserDetails instance variables
    iv_CompId = HBERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = HBERRL_UDT_TARGET;

    if (i_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        uint8_t *pBuffer = reinterpret_cast<uint8_t *>(
                                reallocUsrBuf(sizeof(uint8_t)));
        // copy 0x1 to indicate MASTER
        *pBuffer = 1;
    }
    else
    {
        uint32_t bufSize = 0;
        uint8_t *pTargetString = i_pTarget->targetFFDC(bufSize);
        uint8_t *pBuffer = reinterpret_cast<uint8_t *>(reallocUsrBuf(bufSize));
        memcpy(pBuffer, pTargetString, bufSize);
        free (pTargetString);
    }
}

//------------------------------------------------------------------------------
ErrlUserDetailsTarget::~ErrlUserDetailsTarget()
{

}

}

