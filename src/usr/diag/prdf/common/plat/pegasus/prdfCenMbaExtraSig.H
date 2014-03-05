/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaExtraSig.H $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __prdfCenMbaExtraSig_H
#define __prdfCenMbaExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE(MaintCmdComplete_ERROR, 0xeeee0000, "",
                     "ERROR: maint cmd complete analysis failed" );

PRDR_ERROR_SIGNATURE(StartVcmPhase1,  0xffff0000, "", "Starting VCM phase 1");
PRDR_ERROR_SIGNATURE(StartVcmPhase2,  0xffff0001, "", "Starting VCM phase 2");
PRDR_ERROR_SIGNATURE(StartDsdPhase1,  0xffff0002, "", "Starting DSD phase 1");
PRDR_ERROR_SIGNATURE(StartDsdPhase2,  0xffff0003, "", "Starting DSD phase 2");
PRDR_ERROR_SIGNATURE(StartTpsPhase1,  0xffff0004, "", "Starting TPS phase 1");
PRDR_ERROR_SIGNATURE(StartTpsPhase2,  0xffff0005, "", "Starting TPS phase 2");
PRDR_ERROR_SIGNATURE(EndTpsPhase2,    0xffff0006, "", "TPS Phase 2 completed");

PRDR_ERROR_SIGNATURE(MaintUE,        0xffff0010, "", "Maintenance UE");
PRDR_ERROR_SIGNATURE(MaintMPE,       0xffff0011, "", "Maintenance MPE");
PRDR_ERROR_SIGNATURE(MaintHARD_CTE,  0xffff0012, "", "Maintenance HARD CTE");
PRDR_ERROR_SIGNATURE(MaintSOFT_CTE,  0xffff0013, "", "Maintenance SOFT CTE");
PRDR_ERROR_SIGNATURE(MaintINTER_CTE, 0xffff0014, "", "Maintenance INTER CTE");
PRDR_ERROR_SIGNATURE(MaintRETRY_CTE, 0xffff0015, "", "Maintenance RETRY CTE");
PRDR_ERROR_SIGNATURE(MaintNCE_CTE,   0xffff0016, "", "Maint SOFT/INTER CTE");

PRDR_ERROR_SIGNATURE(VcmVerified,     0xffff0020, "", "VCM: verified");
PRDR_ERROR_SIGNATURE(VcmFalseAlarm,   0xffff0021, "", "VCM: false alarm");
PRDR_ERROR_SIGNATURE(VcmBadSpare,     0xffff0022, "", "VCM: bad DRAM spare");
PRDR_ERROR_SIGNATURE(VcmCmAndSpare,   0xffff0023, "",
                     "VCM: Both spare and chip mark used");
PRDR_ERROR_SIGNATURE(VcmCmAndSm,      0xffff0024, "",
                     "VCM: Both symbol and chip mark used");
PRDR_ERROR_SIGNATURE(VcmFalseAlarmExceeded, 0xffff0025, "",
                     "VCM: false alarm threshold exceeded");

PRDR_ERROR_SIGNATURE(DsdDramSpared,   0xffff0030, "", "DSD: DRAM spared");
PRDR_ERROR_SIGNATURE(DsdBadSpare,     0xffff0031, "", "DSD: DRAM spare is bad");

PRDR_ERROR_SIGNATURE(RdrInternalFail,  0xffff0040, "", "RDR: Internal failure");
PRDR_ERROR_SIGNATURE(RdrInvalidConfig, 0xffff0041, "", "RDR: Invalid config");
PRDR_ERROR_SIGNATURE(RdrScreenBadDqs,  0xffff0042, "",
                     "RDR: DRAM repairs disabled and VPD found");
PRDR_ERROR_SIGNATURE(RdrRepairsUsed,   0xffff0043, "",
                     "RDR: Both spare and chip mark used");
PRDR_ERROR_SIGNATURE(RdrRepairUnavail, 0xffff0044, "",
                     "RDR: Repairs needed but unavailable");

PRDR_ERROR_SIGNATURE(MnfgIplFail,    0xffff0050, "",
                     "MNFG IPL Internal failure");
PRDR_ERROR_SIGNATURE(MnfgIplHardCE,  0xffff0051, "", "MNFG IPL hard CE");
PRDR_ERROR_SIGNATURE(MnfgIplDramCTE, 0xffff0052, "", "MNFG IPL DRAM CTE");
PRDR_ERROR_SIGNATURE(MnfgIplRankCTE, 0xffff0053, "", "MNFG IPL half-rank CTE");
PRDR_ERROR_SIGNATURE(MnfgIplDsCTE,   0xffff0054, "", "MNFG IPL DIMM CTE");

PRDR_ERROR_SIGNATURE(TpsFalseAlarm,         0xffff0061, "", "TPS: false alarm");
PRDR_ERROR_SIGNATURE(TpsFalseAlarmExceeded, 0xffff0062, "",
                     "TPS: false alarm threshold exceeded");
PRDR_ERROR_SIGNATURE(TpsSymbolMark, 0xffff0063, "", "TPS: symbol mark placed");
PRDR_ERROR_SIGNATURE(TpsChipMark,   0xffff0064, "", "TPS: chip mark placed");
PRDR_ERROR_SIGNATURE(TpsMarksUnavail, 0xffff0065, "",
                     "TPS: No more marks available");
PRDR_ERROR_SIGNATURE(TpsCmAndSpare, 0xffff0066, "",
                     "TPS: Both spare and chip mark used");

#endif // __prdfCenMbaExtraSig_H
