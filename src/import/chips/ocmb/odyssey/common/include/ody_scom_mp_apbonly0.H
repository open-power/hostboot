/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_apbonly0.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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




static const uint64_t DWC_DDRPHYA_APBONLY0_DCTWRITEPROT = 0x800D00310801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DCTWRITEPROT_DCTWRITEPROT = 63;


static const uint64_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGCAPTURE0 = 0x800D00410801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGCAPTURE0_DFI0DEBUGCAPTURE0 = 52;
static const uint32_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGCAPTURE0_DFI0DEBUGCAPTURE0_LEN = 12;


static const uint64_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGCAPTURE1 = 0x800D00420801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGCAPTURE1_DFI0DEBUGCAPTURE1 = 54;
static const uint32_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGCAPTURE1_DFI0DEBUGCAPTURE1_LEN = 10;





static const uint64_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGPERFCTR = 0x800D00440801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGPERFCTR_DFI0DEBUGPERFCTR = 48;
static const uint32_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGPERFCTR_DFI0DEBUGPERFCTR_LEN = 16;


static const uint64_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGPERFCTREN = 0x800D00430801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFI0DEBUGPERFCTREN_DFI0DEBUGPERFCTREN = 63;


static const uint64_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGCAPTURE0 = 0x800D00490801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGCAPTURE0_DFI1DEBUGCAPTURE0 = 52;
static const uint32_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGCAPTURE0_DFI1DEBUGCAPTURE0_LEN = 12;


static const uint64_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGCAPTURE1 = 0x800D004A0801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGCAPTURE1_DFI1DEBUGCAPTURE1 = 54;
static const uint32_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGCAPTURE1_DFI1DEBUGCAPTURE1_LEN = 10;





static const uint64_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGPERFCTR = 0x800D004C0801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGPERFCTR_DFI1DEBUGPERFCTR = 48;
static const uint32_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGPERFCTR_DFI1DEBUGPERFCTR_LEN = 16;


static const uint64_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGPERFCTREN = 0x800D004B0801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFI1DEBUGPERFCTREN_DFI1DEBUGPERFCTREN = 63;


static const uint64_t DWC_DDRPHYA_APBONLY0_DFICFGRDDATAVALIDTICKS = 0x800D00370801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFICFGRDDATAVALIDTICKS_DFICFGRDDATAVALIDTICKSARC = 58;
static const uint32_t DWC_DDRPHYA_APBONLY0_DFICFGRDDATAVALIDTICKS_DFICFGRDDATAVALIDTICKSARC_LEN = 6;
static const uint32_t DWC_DDRPHYA_APBONLY0_DFICFGRDDATAVALIDTICKS_DFICFGRDDATAVALIDTICKSREG = 52;
static const uint32_t DWC_DDRPHYA_APBONLY0_DFICFGRDDATAVALIDTICKS_DFICFGRDDATAVALIDTICKSREG_LEN = 6;


static const uint64_t DWC_DDRPHYA_APBONLY0_DFIINITCOMPLETESHADOW = 0x800D00FA0801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_DFIINITCOMPLETESHADOW_DFIINITCOMPLETESHADOW = 63;


static const uint64_t DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL = 0x800D00000801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL_MICROCONTMUXSEL = 63;


static const uint64_t DWC_DDRPHYA_APBONLY0_MICRORESET = 0x800D00990801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_MICRORESET_STALLTOMICRO = 63;
static const uint32_t DWC_DDRPHYA_APBONLY0_MICRORESET_TESTWAKEUP = 62;
static const uint32_t DWC_DDRPHYA_APBONLY0_MICRORESET_RSVDMICRO = 61;
static const uint32_t DWC_DDRPHYA_APBONLY0_MICRORESET_RESETTOMICRO = 60;


static const uint64_t DWC_DDRPHYA_APBONLY0_MICRORESETPIEEN = 0x800D009A0801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_MICRORESETPIEEN_MICRORESETPIEEN = 63;


static const uint64_t DWC_DDRPHYA_APBONLY0_NEVERGATECSRCLOCK = 0x800D00350801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_NEVERGATECSRCLOCK_NEVERGATECSRCLOCK = 63;


static const uint64_t DWC_DDRPHYA_APBONLY0_SEQUENCEROVERRIDE = 0x800D00E70801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_SEQUENCEROVERRIDE_RFU_SEQUENCEROVERRIDE = 53;
static const uint32_t DWC_DDRPHYA_APBONLY0_SEQUENCEROVERRIDE_RFU_SEQUENCEROVERRIDE_LEN = 11;


static const uint64_t DWC_DDRPHYA_APBONLY0_UCTDATWRITEONLYSHADOW = 0x800D00340801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_UCTDATWRITEONLYSHADOW_UCTDATWRITEONLYSHADOW = 48;
static const uint32_t DWC_DDRPHYA_APBONLY0_UCTDATWRITEONLYSHADOW_UCTDATWRITEONLYSHADOW_LEN = 16;


static const uint64_t DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS = 0x800D00040801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS_UCTWRITEPROTSHADOW = 63;
static const uint32_t DWC_DDRPHYA_APBONLY0_UCTSHADOWREGS_UCTDATWRITEPROTSHADOW = 62;


static const uint64_t DWC_DDRPHYA_APBONLY0_UCTWRITEONLYSHADOW = 0x800D00320801303Full;

static const uint32_t DWC_DDRPHYA_APBONLY0_UCTWRITEONLYSHADOW_UCTWRITEONLYSHADOW = 48;
static const uint32_t DWC_DDRPHYA_APBONLY0_UCTWRITEONLYSHADOW_UCTWRITEONLYSHADOW_LEN = 16;



#ifndef __PPE_HCODE__
}
}
#endif

#ifndef SCOMT_OMIT_FIELD_ACCESSORS
    #include "ody_scom_mp_apbonly0_fields.H"
#endif
