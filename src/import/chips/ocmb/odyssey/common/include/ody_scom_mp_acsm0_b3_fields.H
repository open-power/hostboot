/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_acsm0_b3_fields.H $ */
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

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL0_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL0_P3_t : public ScomRegister<0x803400F00801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL0_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL0_P3_t, RFU_ACSMCTRL0_P3, 48, 16); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL5_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL5_P3_t : public ScomRegister<0x803400F50801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL5_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL5_P3_t, RFU_ACSMCTRL5_P3, 50, 14); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL6_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL6_P3_t : public ScomRegister<0x803400F60801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL6_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMCTRL6_P3_t, RFU_ACSMCTRL6_P3, 53, 11); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X0_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X0_P3_t : public ScomRegister<0x803400800801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X0_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X0_P3_t, ACSMPLAYBACK0X0_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X1_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X1_P3_t : public ScomRegister<0x803400820801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X1_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X1_P3_t, ACSMPLAYBACK0X1_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X2_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X2_P3_t : public ScomRegister<0x803400840801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X2_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X2_P3_t, ACSMPLAYBACK0X2_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X3_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X3_P3_t : public ScomRegister<0x803400860801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X3_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X3_P3_t, ACSMPLAYBACK0X3_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X4_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X4_P3_t : public ScomRegister<0x803400880801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X4_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X4_P3_t, ACSMPLAYBACK0X4_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X5_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X5_P3_t : public ScomRegister<0x8034008A0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X5_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X5_P3_t, ACSMPLAYBACK0X5_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X6_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X6_P3_t : public ScomRegister<0x8034008C0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X6_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X6_P3_t, ACSMPLAYBACK0X6_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X7_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X7_P3_t : public ScomRegister<0x8034008E0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X7_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK0X7_P3_t, ACSMPLAYBACK0X7_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X0_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X0_P3_t : public ScomRegister<0x803400810801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X0_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X0_P3_t, ACSMPLAYBACK1X0_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X1_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X1_P3_t : public ScomRegister<0x803400830801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X1_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X1_P3_t, ACSMPLAYBACK1X1_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X2_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X2_P3_t : public ScomRegister<0x803400850801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X2_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X2_P3_t, ACSMPLAYBACK1X2_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X3_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X3_P3_t : public ScomRegister<0x803400870801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X3_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X3_P3_t, ACSMPLAYBACK1X3_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X4_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X4_P3_t : public ScomRegister<0x803400890801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X4_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X4_P3_t, ACSMPLAYBACK1X4_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X5_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X5_P3_t : public ScomRegister<0x8034008B0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X5_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X5_P3_t, ACSMPLAYBACK1X5_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X6_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X6_P3_t : public ScomRegister<0x8034008D0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X6_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X6_P3_t, ACSMPLAYBACK1X6_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X7_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X7_P3_t : public ScomRegister<0x8034008F0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X7_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ACSM0_BASE3_ACSMPLAYBACK1X7_P3_t, ACSMPLAYBACK1X7_P3, 52, 12); \
    }; _SCOMT_CLOSE_NAMESPACE
