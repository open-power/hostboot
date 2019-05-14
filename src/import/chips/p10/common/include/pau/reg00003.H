/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00003.H $          */
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

#ifndef __PAU_REG00003_H_
#define __PAU_REG00003_H_

namespace scomt
{
namespace pau
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_REG_CONFIG3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_CONFIG3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_REG_CONFIG3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_CONFIG3;
#endif
    return fapi2::getScom(i_target, XTS_REG_CONFIG3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_REG_CONFIG3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return fapi2::putScom(i_target, XTS_REG_CONFIG3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_CAP_RESERVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_CAP_RESERVE,
           XTS_REG_CONFIG3_CAP_RESERVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_CAP_RESERVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_CAP_RESERVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_CAP_RESERVE,
           XTS_REG_CONFIG3_CAP_RESERVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_CAP_RESERVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG3_CAP_RESERVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG3_CAP_RESERVE,
           XTS_REG_CONFIG3_CAP_RESERVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_CAP_RESERVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_ATSD_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_ATSD_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_ATSD_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_ATSD_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_ATSD_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_ATSD_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_ATSD_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.setBit<XTS_REG_CONFIG3_ATSD_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_ATSD_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG3_ATSD_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.clearBit<XTS_REG_CONFIG3_ATSD_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_ATSD_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG3_ATSD_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG3_ATSD_ALIGN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_ATSD_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_CONFIG3_ATSD_ALIGN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return i_data.getBit<XTS_REG_CONFIG3_ATSD_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_ATSD_ALIGN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_MMIOSD_OCAPI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_MMIOSD_OCAPI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_MMIOSD_OCAPI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_MMIOSD_OCAPI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_MMIOSD_OCAPI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_MMIOSD_OCAPI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_MMIOSD_OCAPI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.setBit<XTS_REG_CONFIG3_MMIOSD_OCAPI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_MMIOSD_OCAPI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG3_MMIOSD_OCAPI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.clearBit<XTS_REG_CONFIG3_MMIOSD_OCAPI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_MMIOSD_OCAPI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG3_MMIOSD_OCAPI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG3_MMIOSD_OCAPI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_MMIOSD_OCAPI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_CONFIG3_MMIOSD_OCAPI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return i_data.getBit<XTS_REG_CONFIG3_MMIOSD_OCAPI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_MMIOSD_OCAPI chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.setBit<XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.clearBit<XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return i_data.getBit<XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_TLBIE_OVERLAP_OP2_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_NVLINK_16CHIP_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_NVLINK_16CHIP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_NVLINK_16CHIP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_NVLINK_16CHIP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.insertFromRight<XTS_REG_CONFIG3_NVLINK_16CHIP_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_NVLINK_16CHIP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_CONFIG3_NVLINK_16CHIP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.setBit<XTS_REG_CONFIG3_NVLINK_16CHIP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_NVLINK_16CHIP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_REG_CONFIG3_NVLINK_16CHIP_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return o_data.clearBit<XTS_REG_CONFIG3_NVLINK_16CHIP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_NVLINK_16CHIP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_CONFIG3_NVLINK_16CHIP_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return i_data.extractToRight<XTS_REG_CONFIG3_NVLINK_16CHIP_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_NVLINK_16CHIP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_REG_CONFIG3_NVLINK_16CHIP_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_CONFIG3));
#endif
    return i_data.getBit<XTS_REG_CONFIG3_NVLINK_16CHIP_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_CONFIG3_NVLINK_16CHIP_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
