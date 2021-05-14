/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemExtraSig.H $         */
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

#ifndef __prdfMemExtraSig_H
#define __prdfMemExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE(CmdComplete_ERROR, 0xeeee0000, "",
                     "ERROR: command complete analysis failed" );

PRDR_ERROR_SIGNATURE(StartVcmPhase1, 0xffff0000, "", "VCM: Starting phase 1");
PRDR_ERROR_SIGNATURE(StartVcmPhase2, 0xffff0001, "", "VCM: Starting phase 2");
PRDR_ERROR_SIGNATURE(StartDsdPhase1, 0xffff0002, "", "DSD: Starting phase 1");
PRDR_ERROR_SIGNATURE(StartDsdPhase2, 0xffff0003, "", "DSD: Starting phase 2");
PRDR_ERROR_SIGNATURE(StartTpsPhase1, 0xffff0004, "", "TPS: Starting phase 1");
PRDR_ERROR_SIGNATURE(StartTpsPhase2, 0xffff0005, "", "TPS: Starting phase 2");
PRDR_ERROR_SIGNATURE(EndTpsPhase2,   0xffff0006, "", "TPS: Phase 2 completed");
PRDR_ERROR_SIGNATURE(StartRrdPhase1, 0xffff0007, "", "RRD: Starting phase 1");

PRDR_ERROR_SIGNATURE(MaintUE,        0xffff0010, "", "Maintenance UE");
PRDR_ERROR_SIGNATURE(MaintIUE,       0xffff0011, "", "Maintenance IUE");
PRDR_ERROR_SIGNATURE(MaintMPE,       0xffff0012, "", "Maintenance MPE");
PRDR_ERROR_SIGNATURE(MaintHARD_CTE,  0xffff0013, "", "Maintenance HARD CTE");
PRDR_ERROR_SIGNATURE(MaintSOFT_CTE,  0xffff0014, "", "Maintenance SOFT CTE");
PRDR_ERROR_SIGNATURE(MaintINTER_CTE, 0xffff0015, "", "Maintenance INTER CTE");
PRDR_ERROR_SIGNATURE(MaintRETRY_CTE, 0xffff0016, "", "Maintenance RETRY CTE");

PRDR_ERROR_SIGNATURE(VcmVerified,     0xffff0020, "", "VCM: verified");
PRDR_ERROR_SIGNATURE(VcmFalseAlarm,   0xffff0021, "", "VCM: false alarm");
PRDR_ERROR_SIGNATURE(VcmFalseAlarmTH, 0xffff0022, "", "VCM: false alarm threshold");
PRDR_ERROR_SIGNATURE(VcmVerSameDram,  0xffff0023, "", "VCM: verified: previous PPR on same DRAM");
PRDR_ERROR_SIGNATURE(VcmVerDiffDram,  0xffff0024, "", "VCM: verified: previous PPR on different DRAM");
PRDR_ERROR_SIGNATURE(VcmVerFirstMce,  0xffff0025, "", "VCM: verified: first MCE");
PRDR_ERROR_SIGNATURE(VcmVerSecMce,    0xffff0026, "", "VCM: verified: second MCE");
PRDR_ERROR_SIGNATURE(VcmVerRowFail,   0xffff0027, "", "VCM: verified: common row fail");
PRDR_ERROR_SIGNATURE(VcmResume,       0xffff0028, "", "VCM: Resuming procedure");
PRDR_ERROR_SIGNATURE(AllDramRepairs,  0xffff002F, "", "all DRAM repairs used");

PRDR_ERROR_SIGNATURE(RdrInternalFail,  0xffff0040, "", "RDR: Internal failure");
PRDR_ERROR_SIGNATURE(RdrInvalidConfig, 0xffff0041, "", "RDR: Invalid config");
PRDR_ERROR_SIGNATURE(RdrScreenBadDqs,  0xffff0042, "",
                     "RDR: DRAM repairs disabled and VPD found");
PRDR_ERROR_SIGNATURE(RdrRepairsUsed,   0xffff0043, "",
                     "RDR: All repairs used");
PRDR_ERROR_SIGNATURE(RdrRepairUnavail, 0xffff0044, "",
                     "RDR: Repairs needed but unavailable");

PRDR_ERROR_SIGNATURE(MnfgIplHardCE,  0xffff0051, "", "MNFG IPL hard CE");
PRDR_ERROR_SIGNATURE(MnfgIplDramCTE, 0xffff0052, "", "MNFG IPL DRAM CTE");
PRDR_ERROR_SIGNATURE(MnfgIplRankCTE, 0xffff0053, "", "MNFG IPL rank CTE");
PRDR_ERROR_SIGNATURE(MnfgIplDsCTE,   0xffff0054, "", "MNFG IPL DIMM CTE");

PRDR_ERROR_SIGNATURE(TpsFalseAlarm,   0xffff0061, "", "TPS: false alarm");
PRDR_ERROR_SIGNATURE(TpsFalseAlarmTH, 0xffff0062, "", "TPS: false alarm threshold");
PRDR_ERROR_SIGNATURE(TpsSymbolMark,   0xffff0063, "", "TPS: symbol mark placed");
PRDR_ERROR_SIGNATURE(TpsChipMark,     0xffff0064, "", "TPS: chip mark placed");
PRDR_ERROR_SIGNATURE(TpsSymUeRisk,    0xaaaa0065, "", "TPS: placing symbol mark risks UE");
PRDR_ERROR_SIGNATURE(TpsChipUeRisk,   0xaaaa0066, "", "TPS: placing chip mark risks UE");
PRDR_ERROR_SIGNATURE(TpsPotentialUe,  0xaaaa0067, "", "TPS: potential UE");
PRDR_ERROR_SIGNATURE(TpsDramDisabled, 0xaaaa0068, "", "TPS: DRAM repairs disabled");

PRDR_ERROR_SIGNATURE(MnfgDramCte,   0xffff0070, "", "MNFG per DRAM CTE");
PRDR_ERROR_SIGNATURE(MnfgRankCte,   0xffff0071, "", "MNFG per rank CTE");
PRDR_ERROR_SIGNATURE(MnfgDimmCte,   0xffff0072, "", "MNFG per DIMM CTE");
PRDR_ERROR_SIGNATURE(MnfgTableFull, 0xffff0073, "", "MNFG CE table full");
PRDR_ERROR_SIGNATURE(MnfgEntryCte,  0xffff0074, "", "MNFG CE table entry CTE");

PRDR_ERROR_SIGNATURE(NvdimmPersRes, 0xffff0080, "", "NVDIMM Persistency Restored");

PRDR_ERROR_SIGNATURE(VoltRegFail,   0xffff0081, "", "NVDIMM Voltage Regulator Failed");
PRDR_ERROR_SIGNATURE(VddLost,       0xffff0082, "", "NVDIMM VDD Lost");
PRDR_ERROR_SIGNATURE(VppLost,       0xffff0083, "", "NVDIMM VPP Lost");
PRDR_ERROR_SIGNATURE(VttLost,       0xffff0084, "", "NVDIMM VTT Lost");
PRDR_ERROR_SIGNATURE(NotSelfRefr,   0xffff0085, "", "NVDIMM Dram Not Self Refresh");
PRDR_ERROR_SIGNATURE(CtrlHwErr,     0xffff0086, "", "NVDIMM Controller Hardware Error");
PRDR_ERROR_SIGNATURE(NvmCtrlErr,    0xffff0087, "", "NVDIMM NVM Controller Error");
PRDR_ERROR_SIGNATURE(NvmLifeErr,    0xffff0088, "", "NVDIMM Final NVM Lifetime Error");

PRDR_ERROR_SIGNATURE(InsuffEnergy,  0xffff0089, "", "NVDIMM Not enough energy for CSAVE");
PRDR_ERROR_SIGNATURE(InvFwErr,      0xffff008A, "", "NVDIMM Invalid Firmware Error");
PRDR_ERROR_SIGNATURE(CnfgDataErr,   0xffff008B, "", "NVDIMM Configuration Data Error");
PRDR_ERROR_SIGNATURE(NoEsPres,      0xffff008C, "", "NVDIMM No Energy Source Present");
PRDR_ERROR_SIGNATURE(EsPolNotSet,   0xffff008D, "", "NVDIMM Energy Source Policy Not Set");
PRDR_ERROR_SIGNATURE(EsHwFail,      0xffff008E, "", "NVDIMM Energy Source Hardware Fail");
PRDR_ERROR_SIGNATURE(EsHlthAssess,  0xffff008F, "", "NVDIMM Energy Source Health Assessment Error");

PRDR_ERROR_SIGNATURE(EsLifeErr,     0xffff0090, "", "NVDIMM Final Energy Source Lifetime Error");
PRDR_ERROR_SIGNATURE(EsTmpErrHigh,  0xffff0091, "", "NVDIMM Energy Source Temperature Error - High Temp Threshold");
PRDR_ERROR_SIGNATURE(EsTmpErrLow,   0xffff0092, "", "NVDIMM Energy Source Temperature Error - Low Temp Threshold");

PRDR_ERROR_SIGNATURE(NvmLifeWarn1,  0xffff0093, "", "NVDIMM First NVM Lifetime Warning");
PRDR_ERROR_SIGNATURE(NvmLifeWarn2,  0xffff0094, "", "NVDIMM Second NVM Lifetime Warning");
PRDR_ERROR_SIGNATURE(EsLifeWarn1,   0xffff0095, "", "NVDIMM First Energy Source Lifetime Warning");
PRDR_ERROR_SIGNATURE(EsLifeWarn2,   0xffff0096, "", "NVDIMM Second Energy Source Lifetime Warning");
PRDR_ERROR_SIGNATURE(EsTmpWarnHigh, 0xffff0097, "", "NVDIMM Energy Source Temperature Warning - High Temp Threshold");
PRDR_ERROR_SIGNATURE(EsTmpWarnLow,  0xffff0098, "", "NVDIMM Energy Source Temperature Warning - Low Temp Threshold");
PRDR_ERROR_SIGNATURE(BelowWarnTh,   0xffff0099, "", "NVDIMM Below Warning Threshold");
PRDR_ERROR_SIGNATURE(IntNvdimmErr,  0xffff009A, "", "NVDIMM Intermittent error");
PRDR_ERROR_SIGNATURE(NotifStatErr,  0xffff009B, "", "NVDIMM Set Event Notification Status Error");
PRDR_ERROR_SIGNATURE(FirEvntGone,   0xffff009C, "", "NVDIMM Event Triggering the FIR no longer present");
PRDR_ERROR_SIGNATURE(EsTmpWarnFa,   0xffff009D, "", "NVDIMM Energy Source Temperature Warning - False Alarm");
PRDR_ERROR_SIGNATURE(EsTmpErrFa,    0xffff009E, "", "NVDIMM Energy Source Temperature Error - False Alarm");

PRDR_ERROR_SIGNATURE(DsdResume, 0xbbbb0003, "", "DSD: Resuming procedure");

PRDR_ERROR_SIGNATURE(VcmBadSpare,     0xbbbb0022, "", "VCM: bad DRAM spare");

PRDR_ERROR_SIGNATURE(DsdDramSpared,   0xbbbb0030, "", "DSD: DRAM spared");
PRDR_ERROR_SIGNATURE(DsdBadSpare,     0xbbbb0031, "", "DSD: DRAM spare is bad");
PRDR_ERROR_SIGNATURE(RrdRowDeployed,  0xbbbb0032, "", "RRD: Spare row successfully deployed");
PRDR_ERROR_SIGNATURE(RrdBadRow,       0xbbbb0033, "", "RRD: Bad spare row");

PRDR_ERROR_SIGNATURE(CrcRootCause,    0xffff009F, "", "Root cause of CRC error found in PAU_PHY_FIR");

#endif // __prdfMemExtraSig_H

