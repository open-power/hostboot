/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10CoreExtraSig.H $     */
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
#ifndef __prdfP10CoreExtraSig_H
#define __prdfP10CoreExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE( P10CORE_L2CE_LD_ISSUED, 0x0fff0000, "EQ_L2_FIR[0]",
                      "L2 Cache Read CE, Line Delete Issued");
PRDR_ERROR_SIGNATURE( P10CORE_L2CE_LD_FAILURE, 0x0fff0001, "EQ_L2_FIR[0]",
                      "L2 Cache Read CE, Line Delete Failed");
PRDR_ERROR_SIGNATURE( P10CORE_L3CE_LD_ISSUED, 0x0fff0005, "EQ_L3_FIR[4]",
                      "L3 Cache Read CE, Line Delete Issued");
PRDR_ERROR_SIGNATURE( P10CORE_L3CE_LD_FAILURE, 0x0fff0006, "EQ_L3_FIR[4]",
                      "L3 Cache Read CE, Line Delete Failed");
PRDR_ERROR_SIGNATURE( P10CORE_L3CE_MBF_FAIL, 0x0fff0007, "EQ_L3_FIR[4]",
                      "L3 Cache Read CE, Multi-bitline failure");
#endif // __prdfP10CoreExtraSig_H

