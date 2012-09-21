/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/sbe_vital.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: sbe_vital.H,v 1.1 2012/09/10 20:51:30 jeshua Exp $

/// Bit locations and lengths of the fields in the SBE vital register

#ifndef __SBE_VITAL_H
#define __SBE_VITAL_H

#include "fapi_sbe_common.H"

CONST_UINT8_T(HALT_CODE_BIT_POSITION,       ULL(12));
CONST_UINT8_T(HALT_CODE_BIT_LENGTH,         ULL(4));
CONST_UINT8_T(ISTEP_NUM_BIT_POSITION,       ULL(16));
CONST_UINT8_T(ISTEP_NUM_BIT_LENGTH,         ULL(12));
CONST_UINT8_T(SUBSTEP_NUM_BIT_POSITION,     ULL(28));
CONST_UINT8_T(SUBSTEP_NUM_BIT_LENGTH,       ULL(4));


#endif  // __SBE_VITAL_H
