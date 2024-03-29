/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_mastr_b1_fields.H $ */
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
#include "scomt_regs.H"

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_ACCLKDLLCONTROL_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_ACCLKDLLCONTROL_P1_t : public ScomRegister<0x801200EA0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_ACCLKDLLCONTROL_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_ACCLKDLLCONTROL_P1_t, ACLCDLUPDINTERVAL, 52, 12); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_ACCLKDLLCONTROL_P1_t, ACLCDLSTEPINTERVAL, 50, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_ARDPTRINITVAL_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_ARDPTRINITVAL_P1_t : public ScomRegister<0x8012002E0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_ARDPTRINITVAL_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_ARDPTRINITVAL_P1_t, ARDPTRINITVAL_P1, 60, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_CALUCLKINFO_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_CALUCLKINFO_P1_t : public ScomRegister<0x801200080801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_CALUCLKINFO_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_CALUCLKINFO_P1_t, CALUCLKTICKSPER1US, 53, 11); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RDCSPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RDCSPULSE_P1_t : public ScomRegister<0x801201240801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RDCSPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RDCSPULSE_P1_t, D5ACSM0RDCSDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RDCSPULSE_P1_t, D5ACSM0RDCSDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RDCSPULSE_P1_t, D5ACSM0RDCSWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RPTCNTOVERRIDE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RPTCNTOVERRIDE_P1_t : public ScomRegister<0x801201520801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RPTCNTOVERRIDE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RPTCNTOVERRIDE_P1_t, D5ACSM0RPTCNTOVERRIDE_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXENPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXENPULSE_P1_t : public ScomRegister<0x801201200801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXENPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXENPULSE_P1_t, D5ACSM0RXENDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXENPULSE_P1_t, D5ACSM0RXENDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXENPULSE_P1_t, D5ACSM0RXENWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXVALPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXVALPULSE_P1_t : public ScomRegister<0x801201210801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXVALPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXVALPULSE_P1_t, D5ACSM0RXVALDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXVALPULSE_P1_t, D5ACSM0RXVALDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0RXVALPULSE_P1_t, D5ACSM0RXVALWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0SNOOPPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0SNOOPPULSE_P1_t : public ScomRegister<0x801201250801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0SNOOPPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0SNOOPPULSE_P1_t, D5ACSM0SNOOPDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0SNOOPPULSE_P1_t, D5ACSM0SNOOPDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0SNOOPPULSE_P1_t, D5ACSM0SNOOPWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0STARTADDR_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0STARTADDR_P1_t : public ScomRegister<0x8012012B0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0STARTADDR_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0STARTADDR_P1_t, D5ACSM0STARTADDR_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0STOPADDR_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0STOPADDR_P1_t : public ScomRegister<0x8012012C0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0STOPADDR_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0STOPADDR_P1_t, D5ACSM0STOPADDR_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0TXENPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0TXENPULSE_P1_t : public ScomRegister<0x801201220801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0TXENPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0TXENPULSE_P1_t, D5ACSM0TXENDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0TXENPULSE_P1_t, D5ACSM0TXENDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0TXENPULSE_P1_t, D5ACSM0TXENWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0WRCSPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0WRCSPULSE_P1_t : public ScomRegister<0x801201230801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0WRCSPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0WRCSPULSE_P1_t, D5ACSM0WRCSDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0WRCSPULSE_P1_t, D5ACSM0WRCSDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM0WRCSPULSE_P1_t, D5ACSM0WRCSWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RDCSPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RDCSPULSE_P1_t : public ScomRegister<0x801201440801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RDCSPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RDCSPULSE_P1_t, D5ACSM1RDCSDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RDCSPULSE_P1_t, D5ACSM1RDCSDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RDCSPULSE_P1_t, D5ACSM1RDCSWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RPTCNTOVERRIDE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RPTCNTOVERRIDE_P1_t : public ScomRegister<0x801201530801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RPTCNTOVERRIDE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RPTCNTOVERRIDE_P1_t, D5ACSM1RPTCNTOVERRIDE_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXENPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXENPULSE_P1_t : public ScomRegister<0x801201400801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXENPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXENPULSE_P1_t, D5ACSM1RXENDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXENPULSE_P1_t, D5ACSM1RXENDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXENPULSE_P1_t, D5ACSM1RXENWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXVALPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXVALPULSE_P1_t : public ScomRegister<0x801201410801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXVALPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXVALPULSE_P1_t, D5ACSM1RXVALDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXVALPULSE_P1_t, D5ACSM1RXVALDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1RXVALPULSE_P1_t, D5ACSM1RXVALWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1SNOOPPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1SNOOPPULSE_P1_t : public ScomRegister<0x801201450801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1SNOOPPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1SNOOPPULSE_P1_t, D5ACSM1SNOOPDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1SNOOPPULSE_P1_t, D5ACSM1SNOOPDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1SNOOPPULSE_P1_t, D5ACSM1SNOOPWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1STARTADDR_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1STARTADDR_P1_t : public ScomRegister<0x8012014B0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1STARTADDR_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1STARTADDR_P1_t, D5ACSM1STARTADDR_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1STOPADDR_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1STOPADDR_P1_t : public ScomRegister<0x8012014C0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1STOPADDR_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1STOPADDR_P1_t, D5ACSM1STOPADDR_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1TXENPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1TXENPULSE_P1_t : public ScomRegister<0x801201420801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1TXENPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1TXENPULSE_P1_t, D5ACSM1TXENDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1TXENPULSE_P1_t, D5ACSM1TXENDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1TXENPULSE_P1_t, D5ACSM1TXENWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1WRCSPULSE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1WRCSPULSE_P1_t : public ScomRegister<0x801201430801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1WRCSPULSE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1WRCSPULSE_P1_t, D5ACSM1WRCSDELAY, 58, 6); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1WRCSPULSE_P1_t, D5ACSM1WRCSDELAYRESERVED, 56, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5ACSM1WRCSPULSE_P1_t, D5ACSM1WRCSWIDTH, 50, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_D5RDIMMSDRMODE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_D5RDIMMSDRMODE_P1_t : public ScomRegister<0x8012001F0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_D5RDIMMSDRMODE_P1_t); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_D5RDIMMSDRMODE_P1_t, D5RDIMMSDRMODE_P1, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DFIFREQRATIO_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DFIFREQRATIO_P1_t : public ScomRegister<0x801200FA0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DFIFREQRATIO_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DFIFREQRATIO_P1_t, DFIFREQRATIO_P1, 62, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DFIRDDATACSDESTMAP_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DFIRDDATACSDESTMAP_P1_t : public ScomRegister<0x801200B00801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DFIRDDATACSDESTMAP_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DFIRDDATACSDESTMAP_P1_t, DFIRDDESTM0, 62, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DFIRDDATACSDESTMAP_P1_t, DFIRDDESTM1, 60, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DFIRDDATACSDESTMAP_P1_t, DFIRDDESTM2, 58, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DFIRDDATACSDESTMAP_P1_t, DFIRDDESTM3, 56, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DFIWRDATACSDESTMAP_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DFIWRDATACSDESTMAP_P1_t : public ScomRegister<0x801200B40801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DFIWRDATACSDESTMAP_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DFIWRDATACSDESTMAP_P1_t, DFIWRDESTM0, 62, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DFIWRDATACSDESTMAP_P1_t, DFIWRDESTM1, 60, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DFIWRDATACSDESTMAP_P1_t, DFIWRDESTM2, 58, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DFIWRDATACSDESTMAP_P1_t, DFIWRDESTM3, 56, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DLLGAINCTL_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DLLGAINCTL_P1_t : public ScomRegister<0x8012007C0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DLLGAINCTL_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DLLGAINCTL_P1_t, DLLGAINIV, 60, 4); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DLLGAINCTL_P1_t, DLLGAINTV, 56, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DLLLOCKPARAM_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DLLLOCKPARAM_P1_t : public ScomRegister<0x8012007D0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DLLLOCKPARAM_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DLLLOCKPARAM_P1_t, RFU_DLLLOCKPARAM_P1, 54, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DLLTRAINPARAM_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DLLTRAINPARAM_P1_t : public ScomRegister<0x801200710801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DLLTRAINPARAM_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DLLTRAINPARAM_P1_t, EXTENDPHDTIME, 62, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DMIPINPRESENT_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DMIPINPRESENT_P1_t : public ScomRegister<0x8012002D0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DMIPINPRESENT_P1_t); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DMIPINPRESENT_P1_t, RDDBIENABLED, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DMPREAMBLEPATTERN_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DMPREAMBLEPATTERN_P1_t : public ScomRegister<0x801200FE0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DMPREAMBLEPATTERN_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DMPREAMBLEPATTERN_P1_t, TXDMPREAMBLEPATTERN, 60, 4); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DMPREAMBLEPATTERN_P1_t, ENTXDMPREAMBLEPATTERN, 56, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU0_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU0_P1_t : public ScomRegister<0x801200FC0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU0_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU0_P1_t, TXDQPREAMBLEPATTERNU0, 60, 4); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU0_P1_t, ENTXDQPREAMBLEPATTERNU0, 56, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU1_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU1_P1_t : public ScomRegister<0x801200FD0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU1_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU1_P1_t, TXDQPREAMBLEPATTERNU1, 60, 4); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQPREAMBLEPATTERNU1_P1_t, ENTXDQPREAMBLEPATTERNU1, 56, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DQSPOSTAMBLEPATTERN_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DQSPOSTAMBLEPATTERN_P1_t : public ScomRegister<0x801200A20801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DQSPOSTAMBLEPATTERN_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPOSTAMBLEPATTERN_P1_t, TXDQSPOSTAMBLEPATTERN, 60, 4); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPOSTAMBLEPATTERN_P1_t, ENTXDQSPOSTAMBLEPATTERN, 56, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t : public ScomRegister<0x801200240801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, TWOTCKRXDQSPRE, 63); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, TWOTCKTXDQSPRE, 62); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, POSITIONDFEINIT, 59, 3); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, DISDLYADJPOSDI, 58); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, WDQSEXTENSION, 57); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, DDR5RXPREAMBLEEN, 56); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, DDR5RXPREAMBLE, 53, 3); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, DDR5RXPOSTAMBLE, 52); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, POSITIONTXPHASEUPDATE, 50, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLECONTROL_P1_t, POSITIONRXPHASEUPDATE, 48, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLEPATTERN_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLEPATTERN_P1_t : public ScomRegister<0x801200A10801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLEPATTERN_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLEPATTERN_P1_t, TXDQSPREAMBLEPATTERN, 56, 8); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_DQSPREAMBLEPATTERN_P1_t, ENTXDQSPREAMBLEPATTERN, 48, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_HWTMRL_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_HWTMRL_P1_t : public ScomRegister<0x801200200801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_HWTMRL_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_HWTMRL_P1_t, HWTMRL_P1, 59, 5); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_LCDLCHARACTERIZATION_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_LCDLCHARACTERIZATION_P1_t : public ScomRegister<0x801200860801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_LCDLCHARACTERIZATION_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_LCDLCHARACTERIZATION_P1_t, RFU_LCDLCHARACTERIZATION_P1, 58, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_LCDLDBGCNTL3_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_LCDLDBGCNTL3_P1_t : public ScomRegister<0x801200EB0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_LCDLDBGCNTL3_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_LCDLDBGCNTL3_P1_t, STICKYUNLOCKTHRESHOLD, 61, 3); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL1_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL1_P1_t : public ScomRegister<0x801200C70801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL1_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL1_P1_t, PLLCPINTCTRL, 59, 5); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL1_P1_t, PLLCPPROPCTRL, 55, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL2_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL2_P1_t : public ScomRegister<0x801200C50801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL2_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL2_P1_t, PLLFREQSEL, 59, 5); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL4_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL4_P1_t : public ScomRegister<0x801200CC0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL4_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL4_P1_t, PLLCPINTGSCTRL, 59, 5); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PLLCTRL4_P1_t, PLLCPPROPGSCTRL, 55, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_PLLTESTMODE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_PLLTESTMODE_P1_t : public ScomRegister<0x801200CA0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_PLLTESTMODE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PLLTESTMODE_P1_t, PLLTESTMODE_P1, 48, 16); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP2_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP2_P1_t : public ScomRegister<0x801200110801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP2_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP2_P1_t, RFU_PPTTRAINSETUP2_P1, 61, 3); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP_P1_t : public ScomRegister<0x801200100801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP_P1_t, PHYMSTRTRAININTERVAL, 60, 4); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP_P1_t, PHYMSTRMAXREQTOACK, 57, 3); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PPTTRAINSETUP_P1_t, PHYMSTRCTRLMODE, 56); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_PTRINITTRACKINGMODECNTRL_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_PTRINITTRACKINGMODECNTRL_P1_t : public ScomRegister<0x801200510801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_PTRINITTRACKINGMODECNTRL_P1_t); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PTRINITTRACKINGMODECNTRL_P1_t, DISPTRINITCLRTXTRACKING, 63); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_PTRINITTRACKINGMODECNTRL_P1_t, DISPTRINITCLRRXTRACKING, 62); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_RXDQSTRKLIMIT_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_RXDQSTRKLIMIT_P1_t : public ScomRegister<0x801200280801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_RXDQSTRKLIMIT_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_RXDQSTRKLIMIT_P1_t, RXENDLYTRKLIMITLOW, 61, 3); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_RXDQSTRKLIMIT_P1_t, RXENDLYTRKLIMITHIGH, 58, 3); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY0_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY0_P1_t : public ScomRegister<0x8012000B0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY0_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY0_P1_t, SEQ0BDLY0_P1, 48, 16); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY1_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY1_P1_t : public ScomRegister<0x8012000C0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY1_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY1_P1_t, SEQ0BDLY1_P1, 48, 16); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY2_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY2_P1_t : public ScomRegister<0x8012000D0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY2_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY2_P1_t, SEQ0BDLY2_P1, 48, 16); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY3_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY3_P1_t : public ScomRegister<0x8012000E0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY3_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_SEQ0BDLY3_P1_t, SEQ0BDLY3_P1, 48, 16); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t : public ScomRegister<0x801200410801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t, ENDFITDQS2DQTRACKINGTG0, 63); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t, ENDFITDQS2DQTRACKINGTG1, 62); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t, ENDFITDQS2DQTRACKINGTG2, 61); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t, ENDFITDQS2DQTRACKINGTG3, 60); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t, ENRXDQSTRACKING, 59); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t, TDQS2DQTRACKINGLIMIT, 56, 3); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t, DQSOSCRUNTIMESEL, 52, 4); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRACKINGMODECNTRL_P1_t, RXDQSTRACKINGTHRESHOLD, 49, 3); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_TRISTATEMODECA_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_TRISTATEMODECA_P1_t : public ScomRegister<0x801200190801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_TRISTATEMODECA_P1_t); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRISTATEMODECA_P1_t, DISDYNADRTRI, 63); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRISTATEMODECA_P1_t, DDR2TMODE, 62); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_TRISTATEMODECA_P1_t, CKDISVAL, 60, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_VREFINGLOBAL_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_VREFINGLOBAL_P1_t : public ScomRegister<0x801200B20801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_VREFINGLOBAL_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_VREFINGLOBAL_P1_t, GLOBALVREFINSEL, 61, 3); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_VREFINGLOBAL_P1_t, GLOBALVREFINDAC, 54, 7); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_VREFINGLOBAL_P1_t, GLOBALVREFINTRIM, 50, 4); \
            _SCOMT_BOOL_FIELD(DWC_DDRPHYA_MASTER0_BASE1_VREFINGLOBAL_P1_t, GLOBALVREFINMODE, 49); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_MASTER0_BASE1_VREGCTRL1_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_MASTER0_BASE1_VREGCTRL1_P1_t : public ScomRegister<0x801200290801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_MASTER0_BASE1_VREGCTRL1_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_VREGCTRL1_P1_t, VSHCURRENTLOAD, 62, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_MASTER0_BASE1_VREGCTRL1_P1_t, VSHDAC, 55, 7); \
    }; _SCOMT_CLOSE_NAMESPACE
