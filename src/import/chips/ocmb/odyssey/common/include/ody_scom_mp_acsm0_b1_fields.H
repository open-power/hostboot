/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_acsm0_b1_fields.H $ */
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

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL0_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL0_P1_t : public ScomRegister<0x801400F00801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL0_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL0_P1_t, RFU_ACSMCTRL0_P1, 48, 16); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL5_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL5_P1_t : public ScomRegister<0x801400F50801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL5_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL5_P1_t, RFU_ACSMCTRL5_P1, 50, 14); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL6_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL6_P1_t : public ScomRegister<0x801400F60801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL6_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMCTRL6_P1_t, RFU_ACSMCTRL6_P1, 53, 11); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X0_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X0_P1_t : public ScomRegister<0x801400800801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X0_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X0_P1_t, ACSMPLAYBACK0X0_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X1_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X1_P1_t : public ScomRegister<0x801400820801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X1_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X1_P1_t, ACSMPLAYBACK0X1_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X2_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X2_P1_t : public ScomRegister<0x801400840801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X2_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X2_P1_t, ACSMPLAYBACK0X2_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X3_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X3_P1_t : public ScomRegister<0x801400860801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X3_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X3_P1_t, ACSMPLAYBACK0X3_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X4_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X4_P1_t : public ScomRegister<0x801400880801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X4_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X4_P1_t, ACSMPLAYBACK0X4_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X5_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X5_P1_t : public ScomRegister<0x8014008A0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X5_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X5_P1_t, ACSMPLAYBACK0X5_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X6_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X6_P1_t : public ScomRegister<0x8014008C0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X6_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X6_P1_t, ACSMPLAYBACK0X6_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X7_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X7_P1_t : public ScomRegister<0x8014008E0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X7_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK0X7_P1_t, ACSMPLAYBACK0X7_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X0_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X0_P1_t : public ScomRegister<0x801400810801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X0_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X0_P1_t, ACSMPLAYBACK1X0_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X1_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X1_P1_t : public ScomRegister<0x801400830801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X1_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X1_P1_t, ACSMPLAYBACK1X1_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X2_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X2_P1_t : public ScomRegister<0x801400850801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X2_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X2_P1_t, ACSMPLAYBACK1X2_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X3_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X3_P1_t : public ScomRegister<0x801400870801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X3_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X3_P1_t, ACSMPLAYBACK1X3_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X4_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X4_P1_t : public ScomRegister<0x801400890801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X4_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X4_P1_t, ACSMPLAYBACK1X4_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X5_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X5_P1_t : public ScomRegister<0x8014008B0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X5_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X5_P1_t, ACSMPLAYBACK1X5_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X6_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X6_P1_t : public ScomRegister<0x8014008D0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X6_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X6_P1_t, ACSMPLAYBACK1X6_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X7_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X7_P1_t : public ScomRegister<0x8014008F0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X7_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE1_ACSMPLAYBACK1X7_P1_t, ACSMPLAYBACK1X7_P1, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE
