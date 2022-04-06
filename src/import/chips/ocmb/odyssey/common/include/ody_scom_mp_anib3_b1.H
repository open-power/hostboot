/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_anib3_b1.H $ */
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

static const uint64_t DWC_DDRPHYA_ANIB3_BASE1_ACPOWERDOWNDYNEN_P1 = 0x801030820801303Full;

static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ACPOWERDOWNDYNEN_P1_ACTXPOWERDOWNDYNEN = 60;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ACPOWERDOWNDYNEN_P1_ACTXPOWERDOWNDYNEN_LEN = 4;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ACPOWERDOWNDYNEN_P1_ACRXPOWERDOWNDYNEN = 56;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ACPOWERDOWNDYNEN_P1_ACRXPOWERDOWNDYNEN_LEN = 4;


static const uint64_t DWC_DDRPHYA_ANIB3_BASE1_ATUDLY2NMODE_P1 = 0x801030840801303Full;

static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATUDLY2NMODE_P1_ATUDLY2NMODE_P1 = 56;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATUDLY2NMODE_P1_ATUDLY2NMODE_P1_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB3_BASE1_ATUDLY_P1 = 0x8010307F0801303Full;

static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATUDLY_P1_ATUDLY_P1 = 56;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATUDLY_P1_ATUDLY_P1_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB3_BASE1_ATXDLY2NMODE_P1 = 0x801030830801303Full;

static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXDLY2NMODE_P1_ATXDLY2NMODE_P1 = 56;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXDLY2NMODE_P1_ATXDLY2NMODE_P1_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB3_BASE1_ATXDLYSELECT_P1 = 0x801030850801303Full;

static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXDLYSELECT_P1_ATXDLYSELECT_P1 = 62;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXDLYSELECT_P1_ATXDLYSELECT_P1_LEN = 2;


static const uint64_t DWC_DDRPHYA_ANIB3_BASE1_ATXDLY_P1 = 0x801030800801303Full;

static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXDLY_P1_ATXDLY_P1 = 56;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXDLY_P1_ATXDLY_P1_LEN = 8;


static const uint64_t DWC_DDRPHYA_ANIB3_BASE1_ATXSLEWRATE_P1 = 0x801030550801303Full;

static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXSLEWRATE_P1_CSRATXSRC = 56;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXSLEWRATE_P1_CSRATXSRC_LEN = 8;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXSLEWRATE_P1_ATXPREDRVMODE = 53;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXSLEWRATE_P1_ATXPREDRVMODE_LEN = 3;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXSLEWRATE_P1_ATXCHARGECANCEL = 49;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_ATXSLEWRATE_P1_ATXCHARGECANCEL_LEN = 4;


static const uint64_t DWC_DDRPHYA_ANIB3_BASE1_VREGCTRL1_P1 = 0x801030290801303Full;

static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_VREGCTRL1_P1_VSHCURRENTLOAD = 62;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_VREGCTRL1_P1_VSHCURRENTLOAD_LEN = 2;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_VREGCTRL1_P1_VSHDAC = 55;
static const uint32_t DWC_DDRPHYA_ANIB3_BASE1_VREGCTRL1_P1_VSHDAC_LEN = 7;



#ifndef __PPE_HCODE__
}
}
#endif

#ifndef SCOMT_OMIT_FIELD_ACCESSORS
    #include "ody_scom_mp_anib3_b1_fields.H"
#endif
