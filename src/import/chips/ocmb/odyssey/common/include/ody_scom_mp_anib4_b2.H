/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_anib4_b2.H $ */
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

static const uint64_t DWC_DDRPHYA_ANIB4_BASE2_ACPOWERDOWNDYNEN_P2 = 0x802040820801303Full;

static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ACPOWERDOWNDYNEN_P2_ACTXPOWERDOWNDYNEN = 60;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ACPOWERDOWNDYNEN_P2_ACTXPOWERDOWNDYNEN_LEN = 4;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ACPOWERDOWNDYNEN_P2_ACRXPOWERDOWNDYNEN = 56;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ACPOWERDOWNDYNEN_P2_ACRXPOWERDOWNDYNEN_LEN = 4;


static const uint64_t DWC_DDRPHYA_ANIB4_BASE2_ATUDLY2NMODE_P2 = 0x802040840801303Full;

static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATUDLY2NMODE_P2_ATUDLY2NMODE_P2 = 56;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATUDLY2NMODE_P2_ATUDLY2NMODE_P2_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB4_BASE2_ATUDLY_P2 = 0x8020407F0801303Full;

static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATUDLY_P2_ATUDLY_P2 = 56;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATUDLY_P2_ATUDLY_P2_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB4_BASE2_ATXDLY2NMODE_P2 = 0x802040830801303Full;

static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXDLY2NMODE_P2_ATXDLY2NMODE_P2 = 56;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXDLY2NMODE_P2_ATXDLY2NMODE_P2_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB4_BASE2_ATXDLYSELECT_P2 = 0x802040850801303Full;

static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXDLYSELECT_P2_ATXDLYSELECT_P2 = 62;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXDLYSELECT_P2_ATXDLYSELECT_P2_LEN = 2;


static const uint64_t DWC_DDRPHYA_ANIB4_BASE2_ATXDLY_P2 = 0x802040800801303Full;

static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXDLY_P2_ATXDLY_P2 = 56;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXDLY_P2_ATXDLY_P2_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB4_BASE2_ATXSLEWRATE_P2 = 0x802040550801303Full;

static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXSLEWRATE_P2_CSRATXSRC = 56;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXSLEWRATE_P2_CSRATXSRC_LEN = 8;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXSLEWRATE_P2_ATXPREDRVMODE = 53;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXSLEWRATE_P2_ATXPREDRVMODE_LEN = 3;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXSLEWRATE_P2_ATXCHARGECANCEL = 49;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_ATXSLEWRATE_P2_ATXCHARGECANCEL_LEN = 4;


static const uint64_t DWC_DDRPHYA_ANIB4_BASE2_VREGCTRL1_P2 = 0x802040290801303Full;

static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_VREGCTRL1_P2_VSHCURRENTLOAD = 62;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_VREGCTRL1_P2_VSHCURRENTLOAD_LEN = 2;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_VREGCTRL1_P2_VSHDAC = 55;
static const uint32_t DWC_DDRPHYA_ANIB4_BASE2_VREGCTRL1_P2_VSHDAC_LEN = 7;



#ifndef __PPE_HCODE__
}
}
#endif

#ifndef SCOMT_OMIT_FIELD_ACCESSORS
    #include "ody_scom_mp_anib4_b2_fields.H"
#endif
