/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pau/reg00013.H $          */
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

#ifndef __PAU_REG00013_H_
#define __PAU_REG00013_H_

namespace scomt
{
namespace pau
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSL_MAIN_WRAP_ERR_MASK_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_WRAP_ERR_MASK_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSL_MAIN_WRAP_ERR_MASK_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSL_MAIN_WRAP_ERR_MASK_1;
#endif
    return fapi2::getScom(i_target, XSL_MAIN_WRAP_ERR_MASK_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSL_MAIN_WRAP_ERR_MASK_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSL_MAIN_WRAP_ERR_MASK_1));
#endif
    return fapi2::putScom(i_target, XSL_MAIN_WRAP_ERR_MASK_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_WRAP_ERR_MASK_1));
#endif
    return o_data.insertFromRight<XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL,
           XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_WRAP_ERR_MASK_1));
#endif
    return o_data.insertFromRight<XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL,
           XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSL_MAIN_WRAP_ERR_MASK_1));
#endif
    return i_data.extractToRight<XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL,
           XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XSL_MAIN_WRAP_ERR_MASK_1_XSL_WRAP_ERR_MASK_1_DIAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_ATSD_HYP10(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_ATSD_HYP10;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_ATSD_HYP10(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_ATSD_HYP10;
#endif
    return fapi2::getScom(i_target, XTS_ATSD_HYP10, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_ATSD_HYP10(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return fapi2::putScom(i_target, XTS_ATSD_HYP10, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP10_MSRHV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP10_MSRHV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP10_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP10_MSRHV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP10_MSRHV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP10_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP10_MSRHV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return o_data.setBit<XTS_ATSD_HYP10_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP10_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_XTS_ATSD_HYP10_MSRHV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return o_data.clearBit<XTS_ATSD_HYP10_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP10_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_ATSD_HYP10_MSRHV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return i_data.extractToRight<XTS_ATSD_HYP10_MSRHV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP10_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_XTS_ATSD_HYP10_MSRHV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return i_data.getBit<XTS_ATSD_HYP10_MSRHV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP10_MSRHV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP10_LPARID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP10_LPARID,
           XTS_ATSD_HYP10_LPARID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP10_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_ATSD_HYP10_LPARID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return o_data.insertFromRight<XTS_ATSD_HYP10_LPARID,
           XTS_ATSD_HYP10_LPARID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP10_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_ATSD_HYP10_LPARID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_ATSD_HYP10));
#endif
    return i_data.extractToRight<XTS_ATSD_HYP10_LPARID,
           XTS_ATSD_HYP10_LPARID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_ATSD_HYP10_LPARID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XTS_REG_ERR_FIRST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_ERR_FIRST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XTS_REG_ERR_FIRST(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XTS_REG_ERR_FIRST;
#endif
    return fapi2::getScom(i_target, XTS_REG_ERR_FIRST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XTS_REG_ERR_FIRST(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_FIRST));
#endif
    return fapi2::putScom(i_target, XTS_REG_ERR_FIRST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_FIRST_ERR_FIRST_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_FIRST));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_FIRST_ERR_FIRST_BITS,
           XTS_REG_ERR_FIRST_ERR_FIRST_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ERR_FIRST_ERR_FIRST_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_XTS_REG_ERR_FIRST_ERR_FIRST_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_FIRST));
#endif
    return o_data.insertFromRight<XTS_REG_ERR_FIRST_ERR_FIRST_BITS,
           XTS_REG_ERR_FIRST_ERR_FIRST_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ERR_FIRST_ERR_FIRST_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_XTS_REG_ERR_FIRST_ERR_FIRST_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XTS_REG_ERR_FIRST));
#endif
    return i_data.extractToRight<XTS_REG_ERR_FIRST_ERR_FIRST_BITS,
           XTS_REG_ERR_FIRST_ERR_FIRST_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access XTS_REG_ERR_FIRST_ERR_FIRST_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
