/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_anib5_b1_fields.H $ */
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

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB5_BASE1_ACPOWERDOWNDYNEN_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB5_BASE1_ACPOWERDOWNDYNEN_P1_t : public ScomRegister<0x801050820801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB5_BASE1_ACPOWERDOWNDYNEN_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ACPOWERDOWNDYNEN_P1_t, ACTXPOWERDOWNDYNEN, 60, 4); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ACPOWERDOWNDYNEN_P1_t, ACRXPOWERDOWNDYNEN, 56, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB5_BASE1_ATUDLY2NMODE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB5_BASE1_ATUDLY2NMODE_P1_t : public ScomRegister<0x801050840801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB5_BASE1_ATUDLY2NMODE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ATUDLY2NMODE_P1_t, ATUDLY2NMODE_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB5_BASE1_ATUDLY_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB5_BASE1_ATUDLY_P1_t : public ScomRegister<0x8010507F0801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB5_BASE1_ATUDLY_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ATUDLY_P1_t, ATUDLY_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB5_BASE1_ATXDLY2NMODE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB5_BASE1_ATXDLY2NMODE_P1_t : public ScomRegister<0x801050830801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB5_BASE1_ATXDLY2NMODE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ATXDLY2NMODE_P1_t, ATXDLY2NMODE_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB5_BASE1_ATXDLYSELECT_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB5_BASE1_ATXDLYSELECT_P1_t : public ScomRegister<0x801050850801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB5_BASE1_ATXDLYSELECT_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ATXDLYSELECT_P1_t, ATXDLYSELECT_P1, 62, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB5_BASE1_ATXDLY_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB5_BASE1_ATXDLY_P1_t : public ScomRegister<0x801050800801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB5_BASE1_ATXDLY_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ATXDLY_P1_t, ATXDLY_P1, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB5_BASE1_ATXSLEWRATE_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB5_BASE1_ATXSLEWRATE_P1_t : public ScomRegister<0x801050550801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB5_BASE1_ATXSLEWRATE_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ATXSLEWRATE_P1_t, CSRATXSRC, 56, 8); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ATXSLEWRATE_P1_t, ATXPREDRVMODE, 53, 3); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_ATXSLEWRATE_P1_t, ATXCHARGECANCEL, 49, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_DWC_DDRPHYA_ANIB5_BASE1_VREGCTRL1_P1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class DWC_DDRPHYA_ANIB5_BASE1_VREGCTRL1_P1_t : public ScomRegister<0x801050290801303F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(DWC_DDRPHYA_ANIB5_BASE1_VREGCTRL1_P1_t); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_VREGCTRL1_P1_t, VSHCURRENTLOAD, 62, 2); \
            _SCOMT_INT_FIELD(DWC_DDRPHYA_ANIB5_BASE1_VREGCTRL1_P1_t, VSHDAC, 55, 7); \
    }; _SCOMT_CLOSE_NAMESPACE
