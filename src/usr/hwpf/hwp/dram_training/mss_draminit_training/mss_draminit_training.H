//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_training/mss_draminit_training.H $
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
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|   Date:  | Author:  | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.1    | 02/20/12 | divyakum | Added target description
//  1.0    | 11/14/11 | divyakum | First draft.

#ifndef mss_draminit_training_H_
#define mss_draminit_training_H_
#include <fapi.H>

typedef fapi::ReturnCode (*mss_draminit_training_FP_t)(const fapi::Target target);

extern "C"
{

/**
 * @brief Draminit Training procedure. Calibrating DRAMs
 *
 * @param[in]  target  Reference to centaur.mba target
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_draminit_training(const fapi::Target target);

} // extern "C"

#endif // mss_draminit_training_H_
