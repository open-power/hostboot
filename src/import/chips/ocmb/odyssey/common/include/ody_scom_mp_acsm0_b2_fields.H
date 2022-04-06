/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_acsm0_b2_fields.H $ */
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

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL0_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL0_P2_t : public ScomRegister<0x802400F00801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL0_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL0_P2_t, RFU_ACSMCTRL0_P2, 48, 16); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL5_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL5_P2_t : public ScomRegister<0x802400F50801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL5_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL5_P2_t, RFU_ACSMCTRL5_P2, 50, 14); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL6_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL6_P2_t : public ScomRegister<0x802400F60801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL6_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMCTRL6_P2_t, RFU_ACSMCTRL6_P2, 53, 11); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X0_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X0_P2_t : public ScomRegister<0x802400800801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X0_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X0_P2_t, ACSMPLAYBACK0X0_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X1_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X1_P2_t : public ScomRegister<0x802400820801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X1_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X1_P2_t, ACSMPLAYBACK0X1_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X2_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X2_P2_t : public ScomRegister<0x802400840801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X2_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X2_P2_t, ACSMPLAYBACK0X2_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X3_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X3_P2_t : public ScomRegister<0x802400860801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X3_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X3_P2_t, ACSMPLAYBACK0X3_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X4_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X4_P2_t : public ScomRegister<0x802400880801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X4_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X4_P2_t, ACSMPLAYBACK0X4_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X5_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X5_P2_t : public ScomRegister<0x8024008A0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X5_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X5_P2_t, ACSMPLAYBACK0X5_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X6_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X6_P2_t : public ScomRegister<0x8024008C0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X6_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X6_P2_t, ACSMPLAYBACK0X6_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X7_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X7_P2_t : public ScomRegister<0x8024008E0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X7_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK0X7_P2_t, ACSMPLAYBACK0X7_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X0_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X0_P2_t : public ScomRegister<0x802400810801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X0_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X0_P2_t, ACSMPLAYBACK1X0_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X1_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X1_P2_t : public ScomRegister<0x802400830801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X1_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X1_P2_t, ACSMPLAYBACK1X1_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X2_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X2_P2_t : public ScomRegister<0x802400850801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X2_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X2_P2_t, ACSMPLAYBACK1X2_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X3_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X3_P2_t : public ScomRegister<0x802400870801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X3_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X3_P2_t, ACSMPLAYBACK1X3_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X4_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X4_P2_t : public ScomRegister<0x802400890801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X4_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X4_P2_t, ACSMPLAYBACK1X4_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X5_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X5_P2_t : public ScomRegister<0x8024008B0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X5_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X5_P2_t, ACSMPLAYBACK1X5_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X6_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X6_P2_t : public ScomRegister<0x8024008D0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X6_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X6_P2_t, ACSMPLAYBACK1X6_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X7_P2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X7_P2_t : public ScomRegister<0x8024008F0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X7_P2_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE2_ACSMPLAYBACK1X7_P2_t, ACSMPLAYBACK1X7_P2, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE
