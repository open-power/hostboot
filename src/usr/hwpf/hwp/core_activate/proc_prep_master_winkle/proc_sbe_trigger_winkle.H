/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle/proc_sbe_trigger_winkle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: proc_sbe_trigger_winkle.H,v 1.8 2013/10/18 17:23:48 jeshua Exp $

/// Substep numbers for the proc_sbe_trigger_winkle procedure

#ifndef __PROC_SBE_TRIGGER_WINKLE_H
#define __PROC_SBE_TRIGGER_WINKLE_H

#include "fapi_sbe_common.H"
#include "sbe_vital.H"

//NOTE: The following values must stay constant as HB looks for them
CONST_UINT8_T(SUBSTEP_PROC_ENTRY,                   ULL(0x0));
CONST_UINT8_T(SUBSTEP_SBE_READY,                    ULL(0x1));
CONST_UINT8_T(SUBSTEP_DEADMAN_START,                ULL(0x2));
CONST_UINT8_T(SUBSTEP_DEADMAN_WAITING_FOR_WINKLE,   ULL(0x3));
CONST_UINT8_T(SUBSTEP_DEADMAN_WAITING_FOR_WAKEUP,   ULL(0x4));
CONST_UINT8_T(SUBSTEP_DEADMAN_WAITING_FOR_HOSTBOOT, ULL(0x5));
CONST_UINT8_T(SUBSTEP_HOSTBOOT_ALIVE_AGAIN,         ULL(0x6));

#ifdef __ASSEMBLER__
// The location in the proc_sbe_trigger_winkle_control
// containing the mask of threads to start
//WARNING: if thread_start_vector_start is changed from 16,
//then the code needs to be updated to shift it to bit 16
.set THREAD_START_VECTOR_START, 16
.set THREAD_START_VECTOR_LENGTH, 8
#endif

#endif  // __PROC_SBE_TRIGGER_WINKLE_H
