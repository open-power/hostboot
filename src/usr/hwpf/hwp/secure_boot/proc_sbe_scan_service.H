/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/secure_boot/proc_sbe_scan_service.H $        */
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
// $Id: proc_sbe_scan_service.H,v 1.1 2015/05/14 22:23:55 jmcgill Exp $

/// Substep numbers for the proc_sbe_scan_service procedure

#ifndef __PROC_SBE_SCAN_SERVICE_H
#define __PROC_SBE_SCAN_SERVICE_H

#include "fapi_sbe_common.H"
#include "sbe_vital.H"

//NOTE: The following values must stay constant as HB looks for them
CONST_UINT8_T(SUBSTEP_PROC_ENTRY,                   ULL(0x0));
CONST_UINT8_T(SUBSTEP_SBE_READY,                    ULL(0x1));
CONST_UINT8_T(SUBSTEP_DECODE_REQ,                   ULL(0x2));
CONST_UINT8_T(SUBSTEP_SCAN_IP,                      ULL(0x3));
CONST_UINT8_T(SUBSTEP_SCAN_PRE_BRANCH,              ULL(0x4));
CONST_UINT8_T(SUBSTEP_SCAN_IN_BRANCH,               ULL(0x5));
CONST_UINT8_T(SUBSTEP_SCAN_DONE,                    ULL(0x6));
CONST_UINT8_T(SUBSTEP_SCAN_POST_BRANCH,             ULL(0x7));
CONST_UINT8_T(SUBSTEP_RESCAN_IP,                    ULL(0x8));
CONST_UINT8_T(SUBSTEP_RESCAN_CHECKWORD_ERR,         ULL(0xD));
CONST_UINT8_T(SUBSTEP_ARG_ERR,                      ULL(0xE));
CONST_UINT8_T(SUBSTEP_HALT_SUCCESS,                 ULL(0xF));

#endif  // __PROC_SBE_SCAN_SERVICE_H
