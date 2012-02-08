//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/initservice/initsvcbreakpoint.H $
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
#if !defined(INITSVCBREAKPOINT_H)
#define INITSVCBREAKPOINT_H

#include <stdint.h>

namespace       INITSERVICE
{
    /**
     * Signal that a break point has been hit during an istep
     * @param[in] i_info,   tag provided by fapi break point
     * @returns nothing
     * @note Blocks until an outside cmd to resume has been received 
     */
    void iStepBreakPoint( uint32_t i_info );
};
#endif
