/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_drtub0.H $ */
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

static const uint64_t DWC_DDRPHYA_DRTUB0_APBARCECCCTRL = 0x800C008C0801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_APBARCECCCTRL_APBARCECCCLRERR = 63;
static const uint32_t DWC_DDRPHYA_DRTUB0_APBARCECCCTRL_APBARCECCMSKERR = 62;


static const uint64_t DWC_DDRPHYA_DRTUB0_APBARCECCDBERR = 0x800C008D0801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_APBARCECCDBERR_APBARCECCICCMDBERR = 63;
static const uint32_t DWC_DDRPHYA_DRTUB0_APBARCECCDBERR_APBARCECCDCCMDBERR = 62;


static const uint64_t DWC_DDRPHYA_DRTUB0_APBMODE16BITOVERRIDE = 0x800C008A0801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_APBMODE16BITOVERRIDE_APBMODE16BITOVERRIDE = 63;


static const uint64_t DWC_DDRPHYA_DRTUB0_APBMODE32BIT = 0x800C008B0801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_APBMODE32BIT_APBMODE32BIT = 63;


static const uint64_t DWC_DDRPHYA_DRTUB0_ARCDCCMSBERRCTR = 0x800C00840801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_ARCDCCMSBERRCTR_ARCDCCMSBERRCTR = 48;
static const uint32_t DWC_DDRPHYA_DRTUB0_ARCDCCMSBERRCTR_ARCDCCMSBERRCTR_LEN = 16;


static const uint64_t DWC_DDRPHYA_DRTUB0_ARCECCINDICATIONS = 0x800C00820801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_ARCECCINDICATIONS_ARCICCMDBERROR = 63;
static const uint32_t DWC_DDRPHYA_DRTUB0_ARCECCINDICATIONS_ARCICCMADRERROR = 62;
static const uint32_t DWC_DDRPHYA_DRTUB0_ARCECCINDICATIONS_ARCDCCMDBERROR = 61;
static const uint32_t DWC_DDRPHYA_DRTUB0_ARCECCINDICATIONS_ARCDCCMADRERROR = 60;
static const uint32_t DWC_DDRPHYA_DRTUB0_ARCECCINDICATIONS_ARCEXCEPTIONERROR = 59;


static const uint64_t DWC_DDRPHYA_DRTUB0_ARCICCMSBERRCTR = 0x800C00830801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_ARCICCMSBERRCTR_ARCICCMSBERRCTR = 48;
static const uint32_t DWC_DDRPHYA_DRTUB0_ARCICCMSBERRCTR_ARCICCMSBERRCTR_LEN = 16;


static const uint64_t DWC_DDRPHYA_DRTUB0_ARCPMUECCCTL = 0x800C00860801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_ARCPMUECCCTL_ARCPMUECCCTL = 58;
static const uint32_t DWC_DDRPHYA_DRTUB0_ARCPMUECCCTL_ARCPMUECCCTL_LEN = 6;


static const uint64_t DWC_DDRPHYA_DRTUB0_ARCSBCTRENABLES = 0x800C00850801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_ARCSBCTRENABLES_ARCICCMSBCTREN = 63;
static const uint32_t DWC_DDRPHYA_DRTUB0_ARCSBCTRENABLES_ARCDCCMSBCTREN = 62;


static const uint64_t DWC_DDRPHYA_DRTUB0_CLRWAKEUPSTICKY = 0x800C00950801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_CLRWAKEUPSTICKY_CLRWAKEUPSTICKY = 60;
static const uint32_t DWC_DDRPHYA_DRTUB0_CLRWAKEUPSTICKY_CLRWAKEUPSTICKY_LEN = 4;


static const uint64_t DWC_DDRPHYA_DRTUB0_CURPSTATE0B = 0x800C00810801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_CURPSTATE0B_CURPSTATE0B = 60;
static const uint32_t DWC_DDRPHYA_DRTUB0_CURPSTATE0B_CURPSTATE0B_LEN = 4;


static const uint64_t DWC_DDRPHYA_DRTUB0_CUSTPHYREV = 0x800C00EC0801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_CUSTPHYREV_CUSTPHYREV = 58;
static const uint32_t DWC_DDRPHYA_DRTUB0_CUSTPHYREV_CUSTPHYREV_LEN = 6;


static const uint64_t DWC_DDRPHYA_DRTUB0_CUSTPUBREV = 0x800C00ED0801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_CUSTPUBREV_CUSTPUBREV = 58;
static const uint32_t DWC_DDRPHYA_DRTUB0_CUSTPUBREV_CUSTPUBREV_LEN = 6;


static const uint64_t DWC_DDRPHYA_DRTUB0_DCCMCLEARRUNNING = 0x800C00890801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_DCCMCLEARRUNNING_DCCMCLEARRUNNING = 63;


static const uint64_t DWC_DDRPHYA_DRTUB0_DCTSHADOWREGS = 0x800C00040801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_DCTSHADOWREGS_RFU_DCTSHADOWREGS = 63;


static const uint64_t DWC_DDRPHYA_DRTUB0_DCTWRITEONLYSHADOW = 0x800C00300801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_DCTWRITEONLYSHADOW_DCTWRITEONLYSHADOW = 48;
static const uint32_t DWC_DDRPHYA_DRTUB0_DCTWRITEONLYSHADOW_DCTWRITEONLYSHADOW_LEN = 16;


static const uint64_t DWC_DDRPHYA_DRTUB0_MICRORESETPIE = 0x800C007E0801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_MICRORESETPIE_STALLTOMICROPIE = 63;
static const uint32_t DWC_DDRPHYA_DRTUB0_MICRORESETPIE_MICRORESETPIERESERVED = 61;
static const uint32_t DWC_DDRPHYA_DRTUB0_MICRORESETPIE_MICRORESETPIERESERVED_LEN = 2;
static const uint32_t DWC_DDRPHYA_DRTUB0_MICRORESETPIE_RESETTOMICROPIE = 60;


static const uint64_t DWC_DDRPHYA_DRTUB0_PUBREV = 0x800C00EE0801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_PUBREV_PUBMNR = 60;
static const uint32_t DWC_DDRPHYA_DRTUB0_PUBREV_PUBMNR_LEN = 4;
static const uint32_t DWC_DDRPHYA_DRTUB0_PUBREV_PUBMDR = 56;
static const uint32_t DWC_DDRPHYA_DRTUB0_PUBREV_PUBMDR_LEN = 4;
static const uint32_t DWC_DDRPHYA_DRTUB0_PUBREV_PUBMJR = 48;
static const uint32_t DWC_DDRPHYA_DRTUB0_PUBREV_PUBMJR_LEN = 8;


static const uint64_t DWC_DDRPHYA_DRTUB0_PUBVAR = 0x800C00EF0801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_PUBVAR_PUBVAR = 48;
static const uint32_t DWC_DDRPHYA_DRTUB0_PUBVAR_PUBVAR_LEN = 16;


static const uint64_t DWC_DDRPHYA_DRTUB0_STARTDCCMCLEAR = 0x800C00880801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_STARTDCCMCLEAR_STARTDCCMCLEAR = 63;


static const uint64_t DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES = 0x800C00800801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES_UCCLKEN = 63;
static const uint32_t DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES_HCLKEN = 62;
static const uint32_t DWC_DDRPHYA_DRTUB0_UCCLKHCLKENABLES_UCCLKFULL = 61;


static const uint64_t DWC_DDRPHYA_DRTUB0_UCTDATWRITEONLY = 0x800C00340801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_UCTDATWRITEONLY_UCTDATWRITEONLY = 48;
static const uint32_t DWC_DDRPHYA_DRTUB0_UCTDATWRITEONLY_UCTDATWRITEONLY_LEN = 16;


static const uint64_t DWC_DDRPHYA_DRTUB0_UCTDATWRITEPROT = 0x800C00350801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_UCTDATWRITEPROT_UCTDATWRITEPROT = 63;


static const uint64_t DWC_DDRPHYA_DRTUB0_UCTLERR = 0x800C00360801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_UCTLERR_UCTLERR = 63;


static const uint64_t DWC_DDRPHYA_DRTUB0_UCTWRITEONLY = 0x800C00320801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_UCTWRITEONLY_UCTWRITEONLY = 48;
static const uint32_t DWC_DDRPHYA_DRTUB0_UCTWRITEONLY_UCTWRITEONLY_LEN = 16;


static const uint64_t DWC_DDRPHYA_DRTUB0_UCTWRITEPROT = 0x800C00330801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_UCTWRITEPROT_UCTWRITEPROT = 63;


static const uint64_t DWC_DDRPHYA_DRTUB0_WAKEUPMASK = 0x800C00960801303Full;

static const uint32_t DWC_DDRPHYA_DRTUB0_WAKEUPMASK_WAKEUPMASK = 60;
static const uint32_t DWC_DDRPHYA_DRTUB0_WAKEUPMASK_WAKEUPMASK_LEN = 4;



#ifndef __PPE_HCODE__
}
}
#endif

#ifndef SCOMT_OMIT_FIELD_ACCESSORS
    #include "ody_scom_mp_drtub0_fields.H"
#endif
