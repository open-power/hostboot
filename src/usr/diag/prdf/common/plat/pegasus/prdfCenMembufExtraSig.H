/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMembufExtraSig.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

#ifndef __prdfCenMembufExtraSig_H
#define __prdfCenMembufExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE(MnfgDramCte,    0x44440000, "", "MNFG per DRAM CTE");
PRDR_ERROR_SIGNATURE(MnfgHrCte,      0x44440001, "", "MNFG per half-rank CTE");
PRDR_ERROR_SIGNATURE(MnfgDimmCte,    0x44440002, "", "MNFG per DIMM CTE");
PRDR_ERROR_SIGNATURE(MnfgTableFull,  0x44440003, "", "MNFG CE table full");
PRDR_ERROR_SIGNATURE(MnfgEntryCte,   0x44440004, "", "MNFG CE table entry CTE");

PRDR_ERROR_SIGNATURE(MbsFir_30_DD1Signature, 0x44440008, "MBSFIR[30]",
                                   "DD1: MBS_FIR_REG_INTERNAL_SCOM_ERROR_COPY");

#endif // __prdfCenMembufExtraSig_H
