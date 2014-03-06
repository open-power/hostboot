/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/targreasoncodes.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __TARGETING_COMMON_TARGREASONCODES_H
#define __TARGETING_COMMON_TARGREASONCODES_H

/**
 *  @file targeting/common/targetreasoncodes.H
 *
 *  @brief Provides reason codes for various targeting errors
 */

#include <targeting/adapters/types.H>

namespace TARGETING
{

enum TargetingModuleId
{
    TARG_MOD_TEST           = 0x01,
    TARG_MOD_ATTRRP         = 0x02,
    TARG_MOD_ATTR_SYNC      = 0x03,
    TARG_RT_GET_RT_TARGET   = 0x04,
    TARG_RT_GET_HB_TARGET   = 0x05,
};

enum TargetingReasonCode
{
    TARG_RC_TEST_TARGET_FFDC             = TARG_COMP_ID | 0x01,
    TARG_RC_BAD_EYECATCH                 = TARG_COMP_ID | 0x02,
    TARG_RC_MM_BLOCK_FAIL                = TARG_COMP_ID | 0x03,
    TARG_RC_MM_PERM_FAIL                 = TARG_COMP_ID | 0x04,
    TARG_RC_ATTR_MSG_FAIL                = TARG_COMP_ID | 0x05,
    TARG_RC_UNHANDLED_ATTR_SEC_TYPE      = TARG_COMP_ID | 0x06,
    TARG_RC_ATTR_SYNC_TO_FSP_FAIL        = TARG_COMP_ID | 0x07,
    TARG_RC_ATTR_SYNC_REQUEST_TO_HB_FAIL = TARG_COMP_ID | 0x08,
    TARG_RC_ATTR_SYNC_TO_HB_FAIL         = TARG_COMP_ID | 0x09,
    TARG_RT_UNIT_TARGET_NOT_FOUND        = TARG_COMP_ID | 0x0a,
    TARG_RT_NO_PROC_TARGET               = TARG_COMP_ID | 0x0b,
    TARG_RT_TARGET_TYPE_NOT_SUPPORTED    = TARG_COMP_ID | 0x0c,
};

}; // End TARGETING namespace

#endif // __TARGETING_COMMON_TARGREASONCODES_H
