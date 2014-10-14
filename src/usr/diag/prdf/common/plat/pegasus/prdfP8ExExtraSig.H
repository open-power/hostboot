/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8ExExtraSig.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

#ifndef __prdfP8ExExtraSig_H
#define __prdfP8ExExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE( P8EX_L2CE_LD_ISSUED, 0x0fff0000, "L2FIR[0]",
                      "L2 Cache Read CE, Line Delete Issued");
PRDR_ERROR_SIGNATURE( P8EX_L2CE_LD_FAILURE, 0x0fff0001, "L2FIR[0]",
                      "L2 Cache Read CE, Line Delete Failed");
PRDR_ERROR_SIGNATURE( P8EX_L2_ARRAY_REPAIR_COMPLETE, 0x0fff0002, "L2FIR[0]",
                      "L2 Array Repair Complete");
PRDR_ERROR_SIGNATURE( P8EX_L2_ARRAY_REPAIR_FAILURE, 0x0fff0003, "L2FIR[0]",
                      "L2 Array Repair Failure");
PRDR_ERROR_SIGNATURE( P8EX_L2_ARRAY_REPAIR_OUT_OF, 0x0fff0004, "L2FIR[0]",
                      "No L2 Array Repairs Left");
PRDR_ERROR_SIGNATURE( P8EX_L2_ARRAY_REPAIR_HW_OUT_OF, 0x0fff000a, "L2FIR[0]",
                      "No L2 Array Repairs Left in HW");

PRDR_ERROR_SIGNATURE( P8EX_L3CE_LD_ISSUED, 0x0fff0005, "L3FIR[4]",
                      "L3 Cache Read CE, Line Delete Issued");
PRDR_ERROR_SIGNATURE( P8EX_L3CE_LD_FAILURE, 0x0fff0006, "L3FIR[4]",
                      "L3 Cache Read CE, Line Delete Failed");
PRDR_ERROR_SIGNATURE( P8EX_L3_ARRAY_REPAIR_COMPLETE, 0x0fff0007, "L3FIR[4]",
                      "L3 Array Repair Complete");
PRDR_ERROR_SIGNATURE( P8EX_L3_ARRAY_REPAIR_FAILURE, 0x0fff0008, "L3FIR[4]",
                      "L3 Array Repair Failure");
PRDR_ERROR_SIGNATURE( P8EX_L3_ARRAY_REPAIR_OUT_OF, 0x0fff0009, "L3FIR[4]",
                      "No L3 Array Repairs Left");
PRDR_ERROR_SIGNATURE( P8EX_L3_ARRAY_REPAIR_HW_OUT_OF, 0x0fff000b, "L3FIR[4]",
                      "No L3 Array Repairs Left in HW");

#endif // __prdfP8ExExtraSig_H
