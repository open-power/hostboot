//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/diag/mdia/mdiamevent.H $
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
#ifndef __MDIA_MDIAMEVENT_H
#define __MDIA_MDIAMEVENT_H

#include <diag/mdia/mdia.H>

/**
 * @file mdiamevent.H
 * @brief mdia maint command event
 */

namespace MDIA
{

/**
 * @brief MaintCommandEvent maint command event
 */
struct MaintCommandEvent
{
    /**
     * @brief type the type associated with the event
     */
    MaintCommandEventType type;

    /**
     * @brief target the target associated with the event
     */
    TARGETING::TargetHandle_t target;
};
}
#endif
