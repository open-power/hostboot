/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10ProcExtraSig.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

#ifndef __prdfP10ProcExtraSig_H
#define __prdfP10ProcExtraSig_H

#include <prdrSignatures.H>

/* PLL extra signatures */
PRDR_ERROR_SIGNATURE(RCS_PLL_ERROR,   0x00ed0000, "", "clock error detected");
PRDR_ERROR_SIGNATURE(PLL_UNLOCK_0,    0x00ed0001, "", "PLL unlock on clk0");
PRDR_ERROR_SIGNATURE(PLL_UNLOCK_1,    0x00ed0002, "", "PLL unlock on clk1");
PRDR_ERROR_SIGNATURE(RCS_OSC_ERROR_0, 0x00ed0003, "", "RCS OSC error on clk0");
PRDR_ERROR_SIGNATURE(RCS_OSC_ERROR_1, 0x00ed0004, "", "RCS OSC error on clk1");
PRDR_ERROR_SIGNATURE(RCS_UNLOCKDET_0, 0x00ed0005, "", "RCS unlock det on clk0");
PRDR_ERROR_SIGNATURE(RCS_UNLOCKDET_1, 0x00ed0006, "", "RCS unlock det on clk1");

#endif // __prdfP10ProcExtraSig_H
