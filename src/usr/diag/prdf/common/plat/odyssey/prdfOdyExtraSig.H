/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/odyssey/prdfOdyExtraSig.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

#pragma once

#include <prdrSignatures.H>

/* Using signature that does not overlap with the processor RCS/PLL. */
PRDR_ERROR_SIGNATURE(PLL_UNLOCK, 0x00ed0007, "", "PLL unlock");

PRDR_ERROR_SIGNATURE(NceTceInvAddr, 0x00ef0000, "", "Mainline NCE/TCE on both ports. Invalid Address");
PRDR_ERROR_SIGNATURE(UeInvAddr, 0x00ef0001, "", "Mainline UE on both ports. Invalid Address");

PRDR_ERROR_SIGNATURE(SteerCe, 0x00ef0002, "", "Single Address Steer found Maint NCE/TCE");
PRDR_ERROR_SIGNATURE(SteerUe, 0x00ef0003, "", "Single Address Steer found Maint UE");
PRDR_ERROR_SIGNATURE(SteerMpe, 0x00ef0004, "", "Single Address Steer found Maint MPE");
PRDR_ERROR_SIGNATURE(SteerNone, 0x00ef0005, "", "Single Address Steer found no error");
