/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_mc/mss_draminit_mc.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// $Id: mss_draminit_mc.H,v 1.5 2012/07/17 13:22:39 bellows Exp $
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|   Date:  | Author:  | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.5    | 07/16/12 | bellows  | added in Id tag
//  1.4    | 03/07/12 | jdsloat  | changed target to centaur
//  1.3    | 02/17/12 | jdsloat  | Added the other &
//  1.1    | 02/02/12 | jdsloat  | Added & and description of target type
//  1.0    | 12/08/11 | dcadiga  | First draft.

#ifndef mss_draminit_mc_H_
#define mss_draminit_mc_H_
#include <fapi.H>

typedef fapi::ReturnCode (*mss_draminit_mc_FP_t)(const fapi::Target& target);

extern "C"
{

/**
 * @brief Draminit MC procedure. Enable MC functions and set IML complete within centaur
 *
 * @param[in]  i_target  Reference to centaur target
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_draminit_mc(const fapi::Target& target);

} // extern "C"

#endif // mss_draminit_mc_H_
