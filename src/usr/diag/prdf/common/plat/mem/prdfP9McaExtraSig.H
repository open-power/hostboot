/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfP9McaExtraSig.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#ifndef __prdfP9McaExtraSig_H
#define __prdfP9McaExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE(StartVcmPhase1, 0xffff0000, "", "VCM: Starting phase 1");
PRDR_ERROR_SIGNATURE(StartVcmPhase2, 0xffff0001, "", "VCM: Starting phase 2");
PRDR_ERROR_SIGNATURE(StartDsdPhase1, 0xffff0002, "", "DSD: Starting phase 1");
PRDR_ERROR_SIGNATURE(StartDsdPhase2, 0xffff0003, "", "DSD: Starting phase 2");
PRDR_ERROR_SIGNATURE(StartTpsPhase1, 0xffff0004, "", "TPS: Starting phase 1");
PRDR_ERROR_SIGNATURE(StartTpsPhase2, 0xffff0005, "", "TPS: Starting phase 2");
PRDR_ERROR_SIGNATURE(EndTpsPhase2,   0xffff0006, "", "TPS: Phase 2 completed");

PRDR_ERROR_SIGNATURE(MaintUE,        0xffff0010, "", "Maintenance UE");
PRDR_ERROR_SIGNATURE(MaintIUE,       0xffff0011, "", "Maintenance IUE");
PRDR_ERROR_SIGNATURE(MaintMPE,       0xffff0012, "", "Maintenance MPE");
PRDR_ERROR_SIGNATURE(MaintHARD_CTE,  0xffff0013, "", "Maintenance HARD CTE");
PRDR_ERROR_SIGNATURE(MaintSOFT_CTE,  0xffff0014, "", "Maintenance SOFT CTE");
PRDR_ERROR_SIGNATURE(MaintINTER_CTE, 0xffff0015, "", "Maintenance INTER CTE");
PRDR_ERROR_SIGNATURE(MaintRETRY_CTE, 0xffff0016, "", "Maintenance RETRY CTE");

PRDR_ERROR_SIGNATURE(VcmVerified,    0xffff0020, "", "VCM: verified");
PRDR_ERROR_SIGNATURE(VcmFalseAlarm,  0xffff0021, "", "VCM: false alarm");

PRDR_ERROR_SIGNATURE(MnfgIplHardCE,  0xffff0051, "", "MNFG IPL hard CE");
PRDR_ERROR_SIGNATURE(MnfgIplDramCTE, 0xffff0052, "", "MNFG IPL DRAM CTE");
PRDR_ERROR_SIGNATURE(MnfgIplRankCTE, 0xffff0053, "", "MNFG IPL rank CTE");
PRDR_ERROR_SIGNATURE(MnfgIplDsCTE,   0xffff0054, "", "MNFG IPL DIMM CTE");

PRDR_ERROR_SIGNATURE(MnfgDramCte,   0xffff0070, "", "MNFG per DRAM CTE");
PRDR_ERROR_SIGNATURE(MnfgRankCte,   0xffff0071, "", "MNFG per rank CTE");
PRDR_ERROR_SIGNATURE(MnfgDimmCte,   0xffff0072, "", "MNFG per DIMM CTE");
PRDR_ERROR_SIGNATURE(MnfgTableFull, 0xffff0073, "", "MNFG CE table full");
PRDR_ERROR_SIGNATURE(MnfgEntryCte,  0xffff0074, "", "MNFG CE table entry CTE");

#endif // __prdfP9McaExtraSig_H

