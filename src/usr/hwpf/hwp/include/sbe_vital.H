/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/include/sbe_vital.H $                        */
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
