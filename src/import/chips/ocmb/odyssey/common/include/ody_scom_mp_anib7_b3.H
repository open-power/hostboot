/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_anib7_b3.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
/* [+] International Business Machines Corp.                              */
/* [+] Synopsys, Inc.                                                     */
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
#pragma once
#include <stdint.h>

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mp
{
#endif

static const uint64_t DWC_DDRPHYA_ANIB7_BASE3_ACPOWERDOWNDYNEN_P3 = 0x803070820801303Full;

static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ACPOWERDOWNDYNEN_P3_ACTXPOWERDOWNDYNEN = 60;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ACPOWERDOWNDYNEN_P3_ACTXPOWERDOWNDYNEN_LEN = 4;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ACPOWERDOWNDYNEN_P3_ACRXPOWERDOWNDYNEN = 56;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ACPOWERDOWNDYNEN_P3_ACRXPOWERDOWNDYNEN_LEN = 4;


static const uint64_t DWC_DDRPHYA_ANIB7_BASE3_ATUDLY2NMODE_P3 = 0x803070840801303Full;

static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATUDLY2NMODE_P3_ATUDLY2NMODE_P3 = 56;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATUDLY2NMODE_P3_ATUDLY2NMODE_P3_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB7_BASE3_ATUDLY_P3 = 0x8030707F0801303Full;

static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATUDLY_P3_ATUDLY_P3 = 56;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATUDLY_P3_ATUDLY_P3_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB7_BASE3_ATXDLY2NMODE_P3 = 0x803070830801303Full;

static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXDLY2NMODE_P3_ATXDLY2NMODE_P3 = 56;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXDLY2NMODE_P3_ATXDLY2NMODE_P3_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB7_BASE3_ATXDLYSELECT_P3 = 0x803070850801303Full;

static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXDLYSELECT_P3_ATXDLYSELECT_P3 = 62;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXDLYSELECT_P3_ATXDLYSELECT_P3_LEN = 2;


static const uint64_t DWC_DDRPHYA_ANIB7_BASE3_ATXDLY_P3 = 0x803070800801303Full;

static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXDLY_P3_ATXDLY_P3 = 56;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXDLY_P3_ATXDLY_P3_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB7_BASE3_ATXSLEWRATE_P3 = 0x803070550801303Full;

static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXSLEWRATE_P3_CSRATXSRC = 56;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXSLEWRATE_P3_CSRATXSRC_LEN = 8;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXSLEWRATE_P3_ATXPREDRVMODE = 53;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXSLEWRATE_P3_ATXPREDRVMODE_LEN = 3;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXSLEWRATE_P3_ATXCHARGECANCEL = 49;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_ATXSLEWRATE_P3_ATXCHARGECANCEL_LEN = 4;


static const uint64_t DWC_DDRPHYA_ANIB7_BASE3_VREGCTRL1_P3 = 0x803070290801303Full;

static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_VREGCTRL1_P3_VSHCURRENTLOAD = 62;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_VREGCTRL1_P3_VSHCURRENTLOAD_LEN = 2;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_VREGCTRL1_P3_VSHDAC = 55;
static const uint32_t DWC_DDRPHYA_ANIB7_BASE3_VREGCTRL1_P3_VSHDAC_LEN = 7;



#ifndef __PPE_HCODE__
}
}
#endif

#ifndef SCOMT_OMIT_FIELD_ACCESSORS
    #include "ody_scom_mp_anib7_b3_fields.H"
#endif
