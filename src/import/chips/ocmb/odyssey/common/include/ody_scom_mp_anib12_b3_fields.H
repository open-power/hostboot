/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_anib12_b3_fields.H $ */
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

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB12_BASE3_ACPOWERDOWNDYNEN_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB12_BASE3_ACPOWERDOWNDYNEN_P3_t : public ScomRegister<0x8030C0820801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB12_BASE3_ACPOWERDOWNDYNEN_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ACPOWERDOWNDYNEN_P3_t, ACTXPOWERDOWNDYNEN, 60, 4); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ACPOWERDOWNDYNEN_P3_t, ACRXPOWERDOWNDYNEN, 56, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB12_BASE3_ATUDLY2NMODE_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB12_BASE3_ATUDLY2NMODE_P3_t : public ScomRegister<0x8030C0840801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB12_BASE3_ATUDLY2NMODE_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ATUDLY2NMODE_P3_t, ATUDLY2NMODE_P3, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB12_BASE3_ATUDLY_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB12_BASE3_ATUDLY_P3_t : public ScomRegister<0x8030C07F0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB12_BASE3_ATUDLY_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ATUDLY_P3_t, ATUDLY_P3, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB12_BASE3_ATXDLY2NMODE_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB12_BASE3_ATXDLY2NMODE_P3_t : public ScomRegister<0x8030C0830801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB12_BASE3_ATXDLY2NMODE_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ATXDLY2NMODE_P3_t, ATXDLY2NMODE_P3, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB12_BASE3_ATXDLYSELECT_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB12_BASE3_ATXDLYSELECT_P3_t : public ScomRegister<0x8030C0850801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB12_BASE3_ATXDLYSELECT_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ATXDLYSELECT_P3_t, ATXDLYSELECT_P3, 62, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB12_BASE3_ATXDLY_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB12_BASE3_ATXDLY_P3_t : public ScomRegister<0x8030C0800801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB12_BASE3_ATXDLY_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ATXDLY_P3_t, ATXDLY_P3, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB12_BASE3_ATXSLEWRATE_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB12_BASE3_ATXSLEWRATE_P3_t : public ScomRegister<0x8030C0550801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB12_BASE3_ATXSLEWRATE_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ATXSLEWRATE_P3_t, CSRATXSRC, 56, 8); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ATXSLEWRATE_P3_t, ATXPREDRVMODE, 53, 3); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_ATXSLEWRATE_P3_t, ATXCHARGECANCEL, 49, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB12_BASE3_VREGCTRL1_P3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB12_BASE3_VREGCTRL1_P3_t : public ScomRegister<0x8030C0290801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB12_BASE3_VREGCTRL1_P3_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_VREGCTRL1_P3_t, VSHCURRENTLOAD, 62, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB12_BASE3_VREGCTRL1_P3_t, VSHDAC, 55, 7); \
    }; _SCOMT_CLOSE_NAMESPACE
