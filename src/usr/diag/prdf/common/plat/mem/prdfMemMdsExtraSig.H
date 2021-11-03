/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemMdsExtraSig.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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


#ifndef __prdfMemMdsExtraSig_H
#define __prdfMemMdsExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE(MdsInterfaceUe, 0xdddd0000, "", "MDS Interface UE");
PRDR_ERROR_SIGNATURE(MdsMaintMpe, 0xdddd0001, "", "MDS Maintenance MPE");
PRDR_ERROR_SIGNATURE(MdsMdiaVcmVer, 0xdddd0002, "", "MDS Memdiags VCM Verified");
PRDR_ERROR_SIGNATURE(MdsMdiaVcmFa, 0xdddd0003, "", "MDS Memdiags VCM False Alarm");
PRDR_ERROR_SIGNATURE(MdsDbe, 0xdddd0004, "", "MDS Double Bit Error");
PRDR_ERROR_SIGNATURE(MdsSbe, 0xdddd0005, "", "MDS Single Bit Error");
PRDR_ERROR_SIGNATURE(MdsPoison, 0xdddd0006, "", "MDS Poison Error");

#endif // __prdfMemMdsExtraSig_H
