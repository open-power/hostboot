/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8McsExtraSig.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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

#ifndef __prdfP8McsExtraSig_H
#define __prdfP8McsExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE(MciFir_48_DD1Signature, 0x55550000, "MCIFIR[48]",
                                            "DD1: MCIFIRQ_INTERNAL_SCOM_ERROR");
PRDR_ERROR_SIGNATURE(MciFir_49_DD1Signature, 0x55550001, "MCIFIR[49]",
                                      "DD1: MCIFIRQ_INTERNAL_SCOM_ERROR_CLONE");

#endif // __prdfP8McsExtraSig_H
