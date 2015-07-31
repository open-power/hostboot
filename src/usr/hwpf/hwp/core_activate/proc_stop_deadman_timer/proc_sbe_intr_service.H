/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_stop_deadman_timer/proc_sbe_intr_service.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
// $Id: proc_sbe_intr_service.H,v 1.2 2015/07/27 00:28:05 jmcgill Exp $

/// Substep numbers for the proc_sbe_intr_service procedure

#ifndef __PROC_SBE_INTR_SERVICE_H
#define __PROC_SBE_INTR_SERVICE_H

#include "fapi_sbe_common.H"
#include "sbe_vital.H"

//NOTE: The following values must stay constant as HB looks for them
CONST_UINT8_T(PROC_SBE_INTR_SERVICE_SUBSTEP_SBE_READY,                    ULL(0x1));
CONST_UINT8_T(PROC_SBE_INTR_SERVICE_SUBSTEP_HALT_SUCCESS,                 ULL(0xF));

#endif  // __PROC_SBE_INTR_SERVICE_H
