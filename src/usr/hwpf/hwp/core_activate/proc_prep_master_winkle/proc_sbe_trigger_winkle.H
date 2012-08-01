/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle/proc_sbe_trigger_winkle.H $
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
// $Id: proc_sbe_trigger_winkle.H,v 1.3 2012/05/11 21:16:15 jeshua Exp $

/// Istep number encoding for all SEEPROM and PNOR procedures.  Used to update
/// the SBEVITAL register to record procedure progress

#ifndef __PROC_SBE_TRIGGER_WINKLE_H
#define __PROC_SBE_TRIGGER_WINKLE_H

#include "fapi_sbe_common.H"

CONST_UINT8_T(substep_proc_entry,           ULL(0x0));
CONST_UINT8_T(substep_sbe_ready,            ULL(0x1));
CONST_UINT8_T(substep_deadman_start,        ULL(0x2));
CONST_UINT8_T(substep_deadman_waiting_for_winlke, ULL(0x3));
CONST_UINT8_T(substep_deadman_waiting_for_wakeup, ULL(0x4));
CONST_UINT8_T(substep_hostboot_alive_again, ULL(0x5));

CONST_UINT8_T(istep_num_bit_position,       ULL(16));
CONST_UINT8_T(istep_num_bit_length,         ULL(12));
CONST_UINT8_T(substep_num_bit_position,     ULL(28));
CONST_UINT8_T(substep_num_bit_length,       ULL(4));

#endif  // __PROC_SBE_TRIGGER_WINKLE_H
