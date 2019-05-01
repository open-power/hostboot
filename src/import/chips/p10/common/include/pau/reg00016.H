/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00016.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
/* [+] International Business Machines Corp.                              */
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
#include "fapi2.H"

#ifndef __PAU_REG00016_H_
#define __PAU_REG00016_H_

namespace scomt
{
namespace pau
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTL0_MISC_PMU_CONTROL1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a23;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTL0_MISC_PMU_CONTROL1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a23;
#endif
    return fapi2::getScom(i_target, OTL0_MISC_PMU_CONTROL1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTL0_MISC_PMU_CONTROL1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return fapi2::putScom(i_target, OTL0_MISC_PMU_CONTROL1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C01_OPCODEA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C01_OPCODEA,
           OTL0_MISC_PMU_CONTROL1_C01_OPCODEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_OPCODEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C01_OPCODEA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C01_OPCODEA,
           OTL0_MISC_PMU_CONTROL1_C01_OPCODEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_OPCODEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_C01_OPCODEA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_C01_OPCODEA,
           OTL0_MISC_PMU_CONTROL1_C01_OPCODEA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_OPCODEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C01_OPCODEB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C01_OPCODEB,
           OTL0_MISC_PMU_CONTROL1_C01_OPCODEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_OPCODEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C01_OPCODEB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C01_OPCODEB,
           OTL0_MISC_PMU_CONTROL1_C01_OPCODEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_OPCODEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_C01_OPCODEB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_C01_OPCODEB,
           OTL0_MISC_PMU_CONTROL1_C01_OPCODEB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_OPCODEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C23_OPCODEA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C23_OPCODEA,
           OTL0_MISC_PMU_CONTROL1_C23_OPCODEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_OPCODEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C23_OPCODEA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C23_OPCODEA,
           OTL0_MISC_PMU_CONTROL1_C23_OPCODEA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_OPCODEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_C23_OPCODEA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_C23_OPCODEA,
           OTL0_MISC_PMU_CONTROL1_C23_OPCODEA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_OPCODEA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C23_OPCODEB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C23_OPCODEB,
           OTL0_MISC_PMU_CONTROL1_C23_OPCODEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_OPCODEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C23_OPCODEB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C23_OPCODEB,
           OTL0_MISC_PMU_CONTROL1_C23_OPCODEB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_OPCODEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_C23_OPCODEB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_C23_OPCODEB,
           OTL0_MISC_PMU_CONTROL1_C23_OPCODEB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_OPCODEB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C01_DLA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C01_DLA,
           OTL0_MISC_PMU_CONTROL1_C01_DLA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_DLA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C01_DLA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C01_DLA,
           OTL0_MISC_PMU_CONTROL1_C01_DLA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_DLA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_C01_DLA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_C01_DLA,
           OTL0_MISC_PMU_CONTROL1_C01_DLA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_DLA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C01_DLB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C01_DLB,
           OTL0_MISC_PMU_CONTROL1_C01_DLB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_DLB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C01_DLB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C01_DLB,
           OTL0_MISC_PMU_CONTROL1_C01_DLB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_DLB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_C01_DLB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_C01_DLB,
           OTL0_MISC_PMU_CONTROL1_C01_DLB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C01_DLB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C23_DLA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C23_DLA,
           OTL0_MISC_PMU_CONTROL1_C23_DLA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_DLA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C23_DLA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C23_DLA,
           OTL0_MISC_PMU_CONTROL1_C23_DLA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_DLA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_C23_DLA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_C23_DLA,
           OTL0_MISC_PMU_CONTROL1_C23_DLA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_DLA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C23_DLB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C23_DLB,
           OTL0_MISC_PMU_CONTROL1_C23_DLB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_DLB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_C23_DLB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_C23_DLB,
           OTL0_MISC_PMU_CONTROL1_C23_DLB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_DLB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_C23_DLB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_C23_DLB,
           OTL0_MISC_PMU_CONTROL1_C23_DLB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_C23_DLB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY,
           OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY,
           OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY,
           OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_OPCODE_LATENCY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_RESERVED1,
           OTL0_MISC_PMU_CONTROL1_RESERVED1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PMU_CONTROL1_RESERVED1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return o_data.insertFromRight<OTL0_MISC_PMU_CONTROL1_RESERVED1,
           OTL0_MISC_PMU_CONTROL1_RESERVED1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PMU_CONTROL1_RESERVED1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a23));
#endif
    return i_data.extractToRight<OTL0_MISC_PMU_CONTROL1_RESERVED1,
           OTL0_MISC_PMU_CONTROL1_RESERVED1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PMU_CONTROL1_RESERVED1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTL0_MISC_PSL_DAR_AN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a49;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTL0_MISC_PSL_DAR_AN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a49;
#endif
    return fapi2::getScom(i_target, OTL0_MISC_PSL_DAR_AN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTL0_MISC_PSL_DAR_AN(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010a49));
#endif
    return fapi2::putScom(i_target, OTL0_MISC_PSL_DAR_AN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PSL_DAR_AN_CO_EA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a49));
#endif
    return o_data.insertFromRight<OTL0_MISC_PSL_DAR_AN_CO_EA,
           OTL0_MISC_PSL_DAR_AN_CO_EA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PSL_DAR_AN_CO_EA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_PSL_DAR_AN_CO_EA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a49));
#endif
    return o_data.insertFromRight<OTL0_MISC_PSL_DAR_AN_CO_EA,
           OTL0_MISC_PSL_DAR_AN_CO_EA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PSL_DAR_AN_CO_EA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_PSL_DAR_AN_CO_EA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a49));
#endif
    return i_data.extractToRight<OTL0_MISC_PSL_DAR_AN_CO_EA,
           OTL0_MISC_PSL_DAR_AN_CO_EA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_PSL_DAR_AN_CO_EA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTL0_MISC_TX_DL_CREDIT_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a34;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTL0_MISC_TX_DL_CREDIT_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a34;
#endif
    return fapi2::getScom(i_target, OTL0_MISC_TX_DL_CREDIT_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTL0_MISC_TX_DL_CREDIT_STATUS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010a34));
#endif
    return fapi2::putScom(i_target, OTL0_MISC_TX_DL_CREDIT_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a34));
#endif
    return o_data.insertFromRight<OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT,
           OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a34));
#endif
    return o_data.insertFromRight<OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT,
           OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a34));
#endif
    return i_data.extractToRight<OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT,
           OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL0_MISC_TX_DL_CREDIT_STATUS_STATUS_DL_CREDIT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTL1_MISC_CONFIG_TLX_CREDITS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a5a;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTL1_MISC_CONFIG_TLX_CREDITS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a5a;
#endif
    return fapi2::getScom(i_target, OTL1_MISC_CONFIG_TLX_CREDITS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTL1_MISC_CONFIG_TLX_CREDITS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return fapi2::putScom(i_target, OTL1_MISC_CONFIG_TLX_CREDITS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC0_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC1_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC2_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_VC3_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_DCP0_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_SPARE,
           OTL1_MISC_CONFIG_TLX_CREDITS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_SPARE,
           OTL1_MISC_CONFIG_TLX_CREDITS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TLX_CREDITS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TLX_CREDITS_SPARE,
           OTL1_MISC_CONFIG_TLX_CREDITS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_DCP2_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a5a));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS,
           OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TLX_CREDITS_DCP3_CREDITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTL1_MISC_CONFIG_TX2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a68;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTL1_MISC_CONFIG_TX2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a68;
#endif
    return fapi2::getScom(i_target, OTL1_MISC_CONFIG_TX2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTL1_MISC_CONFIG_TX2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return fapi2::putScom(i_target, OTL1_MISC_CONFIG_TX2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_TX_SEND_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_TX_SEND_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_TX_SEND_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_TX_SEND_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_TX_SEND_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_TX_SEND_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_TX_SEND_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.setBit<OTL1_MISC_CONFIG_TX2_TX_SEND_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_TX_SEND_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_CONFIG_TX2_TX_SEND_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.clearBit<OTL1_MISC_CONFIG_TX2_TX_SEND_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_TX_SEND_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TX2_TX_SEND_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TX2_TX_SEND_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_TX_SEND_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_CONFIG_TX2_TX_SEND_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return i_data.getBit<OTL1_MISC_CONFIG_TX2_TX_SEND_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_TX_SEND_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_TX_SPARE4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_TX_SPARE4,
           OTL1_MISC_CONFIG_TX2_TX_SPARE4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_TX_SPARE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_TX_SPARE4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_TX_SPARE4,
           OTL1_MISC_CONFIG_TX2_TX_SPARE4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_TX_SPARE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TX2_TX_SPARE4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TX2_TX_SPARE4,
           OTL1_MISC_CONFIG_TX2_TX_SPARE4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_TX_SPARE4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC1_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC1_THRESH1,
           OTL1_MISC_CONFIG_TX2_VC1_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC1_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC1_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC1_THRESH1,
           OTL1_MISC_CONFIG_TX2_VC1_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC1_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TX2_VC1_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TX2_VC1_THRESH1,
           OTL1_MISC_CONFIG_TX2_VC1_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC1_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC2_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC2_THRESH1,
           OTL1_MISC_CONFIG_TX2_VC2_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC2_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC2_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC2_THRESH1,
           OTL1_MISC_CONFIG_TX2_VC2_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC2_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TX2_VC2_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TX2_VC2_THRESH1,
           OTL1_MISC_CONFIG_TX2_VC2_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC2_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC3_THRESH1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC3_THRESH1,
           OTL1_MISC_CONFIG_TX2_VC3_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC3_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC3_THRESH1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC3_THRESH1,
           OTL1_MISC_CONFIG_TX2_VC3_THRESH1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC3_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TX2_VC3_THRESH1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TX2_VC3_THRESH1,
           OTL1_MISC_CONFIG_TX2_VC3_THRESH1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC3_THRESH1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC1_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC1_THRESH2,
           OTL1_MISC_CONFIG_TX2_VC1_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC1_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC1_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC1_THRESH2,
           OTL1_MISC_CONFIG_TX2_VC1_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC1_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TX2_VC1_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TX2_VC1_THRESH2,
           OTL1_MISC_CONFIG_TX2_VC1_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC1_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC2_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC2_THRESH2,
           OTL1_MISC_CONFIG_TX2_VC2_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC2_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC2_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC2_THRESH2,
           OTL1_MISC_CONFIG_TX2_VC2_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC2_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TX2_VC2_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TX2_VC2_THRESH2,
           OTL1_MISC_CONFIG_TX2_VC2_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC2_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC3_THRESH2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC3_THRESH2,
           OTL1_MISC_CONFIG_TX2_VC3_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC3_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_CONFIG_TX2_VC3_THRESH2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return o_data.insertFromRight<OTL1_MISC_CONFIG_TX2_VC3_THRESH2,
           OTL1_MISC_CONFIG_TX2_VC3_THRESH2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC3_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_CONFIG_TX2_VC3_THRESH2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a68));
#endif
    return i_data.extractToRight<OTL1_MISC_CONFIG_TX2_VC3_THRESH2,
           OTL1_MISC_CONFIG_TX2_VC3_THRESH2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_CONFIG_TX2_VC3_THRESH2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OTL1_MISC_C_ERR_RPT_MASK0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a57;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OTL1_MISC_C_ERR_RPT_MASK0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a57;
#endif
    return fapi2::getScom(i_target, OTL1_MISC_C_ERR_RPT_MASK0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OTL1_MISC_C_ERR_RPT_MASK0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return fapi2::putScom(i_target, OTL1_MISC_C_ERR_RPT_MASK0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.insertFromRight<OTL1_MISC_C_ERR_RPT_MASK0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_OTL1_MISC_C_ERR_RPT_MASK0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.setBit<OTL1_MISC_C_ERR_RPT_MASK0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_OTL1_MISC_C_ERR_RPT_MASK0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return o_data.clearBit<OTL1_MISC_C_ERR_RPT_MASK0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_OTL1_MISC_C_ERR_RPT_MASK0_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.extractToRight<OTL1_MISC_C_ERR_RPT_MASK0_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_OTL1_MISC_C_ERR_RPT_MASK0_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a57));
#endif
    return i_data.getBit<OTL1_MISC_C_ERR_RPT_MASK0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access OTL1_MISC_C_ERR_RPT_MASK0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_XSLOP_VLOG_RGS_EEI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a95;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010a95;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_XSLOP_VLOG_RGS_EEI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_XSLOP_VLOG_RGS_EEI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_XSLOP_VLOG_RGS_EEI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return o_data.setBit<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return o_data.clearBit<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return i_data.getBit<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ECMD_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_ETYPE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return o_data.insertFromRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010a95));
#endif
    return i_data.extractToRight<XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL,
           XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_XSLOP_VLOG_RGS_EEI_RSPCODE_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_ARY_RD_ADDR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010aa1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_ARY_RD_ADDR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010aa1;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_ARY_RD_ADDR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_ARY_RD_ADDR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_ARY_RD_ADDR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_ARY_RD_ADDR_REG_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return i_data.extractToRight<XSL_MAIN_ARY_RD_ADDR_REG_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS,
           XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS,
           XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return i_data.extractToRight<XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS,
           XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_ENTRY_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return o_data.insertFromRight<XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa1));
#endif
    return i_data.extractToRight<XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT,
           XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_ARY_RD_ADDR_REG_DATA_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_DEBUG0_CONFIG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010aa3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_DEBUG0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010aa3;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_DEBUG0_CONFIG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_DEBUG0_CONFIG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010aa3));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_DEBUG0_CONFIG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa3));
#endif
    return o_data.insertFromRight<XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL,
           XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa3));
#endif
    return o_data.insertFromRight<XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL,
           XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aa3));
#endif
    return i_data.extractToRight<XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL,
           XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_DEBUG0_CONFIG_XSL_DEBUG0_CONFIG_DIAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_WRAP_ERR_MASK_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010aaa;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_WRAP_ERR_MASK_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010aaa;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_WRAP_ERR_MASK_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_WRAP_ERR_MASK_0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010aaa));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_WRAP_ERR_MASK_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aaa));
#endif
    return o_data.insertFromRight<XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL,
           XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aaa));
#endif
    return o_data.insertFromRight<XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL,
           XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010aaa));
#endif
    return i_data.extractToRight<XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL,
           XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_WRAP_ERR_MASK_0_XSL_WRAP_ERR_MASK_0_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_ATSD_HYP11(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010b1b;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_ATSD_HYP11(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010b1b;
#endif
    return fapi2::getScom(i_target, XTS_ATSD_HYP11, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_ATSD_HYP11(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return fapi2::putScom(i_target, XTS_ATSD_HYP11, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP11_MSRHV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_MSRHV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP11_MSRHV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return o_data.setBit<XTS_ATSD_HYP11_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return o_data.clearBit<XTS_ATSD_HYP11_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return i_data.extractToRight<XTS_ATSD_HYP11_MSRHV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_ATSD_HYP11_MSRHV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return i_data.getBit<XTS_ATSD_HYP11_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_LPARID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP11_LPARID,
           XTS_ATSD_HYP11_LPARID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP11_LPARID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP11_LPARID,
           XTS_ATSD_HYP11_LPARID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_ATSD_HYP11_LPARID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010b1b));
#endif
    return i_data.extractToRight<XTS_ATSD_HYP11_LPARID,
           XTS_ATSD_HYP11_LPARID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP11_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_REG_ATRMISS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010afa;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_REG_ATRMISS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = 0x10010afa;
#endif
    return fapi2::getScom(i_target, XTS_REG_ATRMISS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_REG_ATRMISS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return fapi2::putScom(i_target, XTS_REG_ATRMISS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_ADDR,
           XTS_REG_ATRMISS_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_ADDR,
           XTS_REG_ATRMISS_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_ADDR,
           XTS_REG_ATRMISS_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_OTHER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_OTHER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_OTHER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_OTHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_OTHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_OTHER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_OTHER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_OTHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_OTHER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_PREF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_PREF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_PREF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_PREF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_PREF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_PREF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_PREF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_PREF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_PREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_DMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_DMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_DMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_DMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_DMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_DMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_DMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_DMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_DMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_MAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_MAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_MAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_MAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_MAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_MAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_MAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_MAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_FLAG_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_FLAG_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_FLAG_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_FLAG_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_FLAG_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_FLAG_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_FLAG_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_RETIRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_RETIRE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_RETIRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_RETIRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_RETIRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_RETIRE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_RETIRE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_RETIRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_RETIRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_IRQENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_IRQENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_IRQENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_IRQENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_IRQENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_IRQENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_IRQENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_IRQENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_IRQENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_SECOND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_SECOND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_SECOND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_SECOND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_SECOND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_SECOND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_SECOND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_SECOND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_SECOND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_TRIGGERED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_TRIGGERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_TRIGGERED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_TRIGGERED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_TRIGGERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_TRIGGERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ENA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.insertFromRight<XTS_REG_ATRMISS_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.setBit<XTS_REG_ATRMISS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return o_data.clearBit<XTS_REG_ATRMISS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.extractToRight<XTS_REG_ATRMISS_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_ATRMISS_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(0x10010afa));
#endif
    return i_data.getBit<XTS_REG_ATRMISS_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ATRMISS_ENA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
