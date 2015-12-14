/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/target_states.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2012,2015                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file target_states.H
 * @brief common state for fapi2 targets
 */

#ifndef __FAPI2_TARGET_STATES__
#define __FAPI2_TARGET_STATES__

namespace fapi2
{
///
/// @brief Enumeration of target state values (bitmask values)
///
enum TargetState
{
    TARGET_STATE_PRESENT    = 0x00000001,
    TARGET_STATE_FUNCTIONAL = 0x00000002,
};
}

#endif
