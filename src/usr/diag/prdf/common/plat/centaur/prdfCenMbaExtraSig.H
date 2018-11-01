/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/centaur/prdfCenMbaExtraSig.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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

#ifndef __prdfCenMbaExtraSig_H
#define __prdfCenMbaExtraSig_H

#include <prdrSignatures.H>
#include <prdfMemExtraSig.H>

PRDR_ERROR_SIGNATURE(CmdComplete_ERROR, 0xeeee0000, "",
                     "ERROR: command complete analysis failed" );

PRDR_ERROR_SIGNATURE(VcmResume, 0xbbbb0000, "", "VCM: Resuming procedure");
PRDR_ERROR_SIGNATURE(TpsResume, 0xbbbb0001, "", "TPS: Resuming procedure");
PRDR_ERROR_SIGNATURE(DsdResume, 0xbbbb0003, "", "DSD: Resuming procedure");

PRDR_ERROR_SIGNATURE(MaintNCE_CTE,   0xbbbb0016, "", "Maint SOFT/INTER CTE");

PRDR_ERROR_SIGNATURE(VcmBadSpare,     0xbbbb0022, "", "VCM: bad DRAM spare");
PRDR_ERROR_SIGNATURE(VcmCmAndSpare,   0xbbbb0023, "",
                     "VCM: Both spare and chip mark used");
PRDR_ERROR_SIGNATURE(VcmCmAndSm,      0xbbbb0024, "",
                     "VCM: Both symbol and chip mark used");

PRDR_ERROR_SIGNATURE(DsdDramSpared,   0xbbbb0030, "", "DSD: DRAM spared");
PRDR_ERROR_SIGNATURE(DsdBadSpare,     0xbbbb0031, "", "DSD: DRAM spare is bad");

PRDR_ERROR_SIGNATURE(MnfgIplFail,    0xbbbb0050, "",
                     "MNFG IPL Internal failure");

PRDR_ERROR_SIGNATURE(TpsMarksUnavail, 0xbbbb0065, "",
                     "TPS: No more marks available");
PRDR_ERROR_SIGNATURE(TpsCmAndSpare, 0xbbbb0066, "",
                     "TPS: Both spare and chip mark used");

#endif // __prdfCenMbaExtraSig_H



