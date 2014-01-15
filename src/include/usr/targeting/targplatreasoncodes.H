/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/targplatreasoncodes.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#ifndef TARGPLATREASONCODES_H
#define TARGPLATREASONCODES_H

/**
 *  @file targeting/targplatreasoncodes.H
 *
 *  @brief Provides reason codes for various platform specific targeting errors
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <targeting/adapters/types.H>

//******************************************************************************
// Constants
//******************************************************************************

namespace TARGETING
{

/**
 *  @brief Platform specific targeting module IDs
 *
 *  @note Must always start @ 0x80, since common module IDs occupy 0x00 -> 0x7F
 *     range
 */
enum PlatTargetingModuleId
{
    TARG_MOD_QUERY_MASTER_PROC_CHIP               = 0x80,
    TARG_MOD_SET_MASTER_NODE                      = 0x81,
    TARG_MOD_ATTRRP_RT                            = 0x82,
};

/**
 *  @brief Platform specific targeting reason codes
 *
 *  @note Must always start @ 0x80, since common reasons codes occupy
 *      0x00 -> 0x7F range
 */
enum PlatTargetingReasonCode
{
    TARG_RC_INVALID_NODE        = TARG_COMP_ID | 0x80,
    TARG_RC_TARGET_NOT_FOUND    = TARG_COMP_ID | 0x81,
};

} // End TARGETING namespace

#endif // TARGPLATREASONCODES_H

