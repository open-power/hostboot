/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaExtraSig.H $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

PRDR_ERROR_SIGNATURE(MaintUE,         0xffff0010, "", "Maintenance UE");

PRDR_ERROR_SIGNATURE(VcmVerified,     0xffff0020, "", "VCM: verified");
PRDR_ERROR_SIGNATURE(VcmFalseAlarm,   0xffff0021, "", "VCM: false alarm");
PRDR_ERROR_SIGNATURE(VcmBadSpare,     0xffff0022, "", "VCM: bad DRAM spare");
PRDR_ERROR_SIGNATURE(VcmMarksUnavail, 0xffff0023, "",
                     "VCM: No more marks available");

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



#endif // __prdfCenMbaExtraSig_H
