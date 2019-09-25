/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00004.H $            */
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

#ifndef __C_REG00004_H_
#define __C_REG00004_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CCCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CCCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CCCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CCCR;
#endif
    return fapi2::getScom(i_target, CPMS_CCCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CCCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return fapi2::putScom(i_target, CPMS_CCCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_MODE,
           CPMS_CCCR_COUNT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_MODE,
           CPMS_CCCR_COUNT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_COUNT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_COUNT_MODE,
           CPMS_CCCR_COUNT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_TYPE,
           CPMS_CCCR_COUNT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_TYPE,
           CPMS_CCCR_COUNT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_COUNT_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_COUNT_TYPE,
           CPMS_CCCR_COUNT_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_TYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ENABLE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_ENABLE_SEL,
           CPMS_CCCR_COUNT_ENABLE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_ENABLE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ENABLE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_ENABLE_SEL,
           CPMS_CCCR_COUNT_ENABLE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_ENABLE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_COUNT_ENABLE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_COUNT_ENABLE_SEL,
           CPMS_CCCR_COUNT_ENABLE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_ENABLE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_INVERT_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_INVERT_COUNT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_INVERT_COUNT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.setBit<CPMS_CCCR_INVERT_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.clearBit<CPMS_CCCR_INVERT_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_INVERT_COUNT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CCCR_INVERT_COUNT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.getBit<CPMS_CCCR_INVERT_COUNT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_INVERT_COUNT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_ALWAYS_SAMPLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_COUNT_ALWAYS_SAMPLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.setBit<CPMS_CCCR_COUNT_ALWAYS_SAMPLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.clearBit<CPMS_CCCR_COUNT_ALWAYS_SAMPLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_COUNT_ALWAYS_SAMPLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_CCCR_COUNT_ALWAYS_SAMPLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.getBit<CPMS_CCCR_COUNT_ALWAYS_SAMPLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_COUNT_ALWAYS_SAMPLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_HI_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_HI_THRESHOLD,
           CPMS_CCCR_HI_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_HI_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_HI_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_HI_THRESHOLD,
           CPMS_CCCR_HI_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_HI_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_HI_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_HI_THRESHOLD,
           CPMS_CCCR_HI_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_HI_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_LO_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_LO_THRESHOLD,
           CPMS_CCCR_LO_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_LO_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_LO_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_LO_THRESHOLD,
           CPMS_CCCR_LO_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_LO_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_LO_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_LO_THRESHOLD,
           CPMS_CCCR_LO_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_LO_THRESHOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_SPARE,
           CPMS_CCCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_CCCR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return o_data.insertFromRight<CPMS_CCCR_SPARE,
           CPMS_CCCR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_CCCR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCCR));
#endif
    return i_data.extractToRight<CPMS_CCCR_SPARE,
           CPMS_CCCR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_CCCR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DPCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DPCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPCR;
#endif
    return fapi2::getScom(i_target, CPMS_DPCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DPCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return fapi2::putScom(i_target, CPMS_DPCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_PROXY_SCALE_FACTOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_PROXY_SCALE_FACTOR,
           CPMS_DPCR_PROXY_SCALE_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPCR_PROXY_SCALE_FACTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_PROXY_SCALE_FACTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_PROXY_SCALE_FACTOR,
           CPMS_DPCR_PROXY_SCALE_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPCR_PROXY_SCALE_FACTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPCR_PROXY_SCALE_FACTOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return i_data.extractToRight<CPMS_DPCR_PROXY_SCALE_FACTOR,
           CPMS_DPCR_PROXY_SCALE_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPCR_PROXY_SCALE_FACTOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_DDP_RECHARGE_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_DDP_RECHARGE_DELAY,
           CPMS_DPCR_DDP_RECHARGE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPCR_DDP_RECHARGE_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_DDP_RECHARGE_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_DDP_RECHARGE_DELAY,
           CPMS_DPCR_DDP_RECHARGE_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPCR_DDP_RECHARGE_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPCR_DDP_RECHARGE_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return i_data.extractToRight<CPMS_DPCR_DDP_RECHARGE_DELAY,
           CPMS_DPCR_DDP_RECHARGE_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPCR_DDP_RECHARGE_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_DDP_RECHARGE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_DDP_RECHARGE_VALUE,
           CPMS_DPCR_DDP_RECHARGE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPCR_DDP_RECHARGE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DPCR_DDP_RECHARGE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return o_data.insertFromRight<CPMS_DPCR_DDP_RECHARGE_VALUE,
           CPMS_DPCR_DDP_RECHARGE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPCR_DDP_RECHARGE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DPCR_DDP_RECHARGE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPCR));
#endif
    return i_data.extractToRight<CPMS_DPCR_DDP_RECHARGE_VALUE,
           CPMS_DPCR_DDP_RECHARGE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DPCR_DDP_RECHARGE_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_PSSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PSSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_PSSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PSSR;
#endif
    return fapi2::getScom(i_target, CPMS_PSSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_PSSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return fapi2::putScom(i_target, CPMS_PSSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_ACCUM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_ACCUM_ERROR,
           CPMS_PSSR_ACCUM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_ACCUM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_ACCUM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_ACCUM_ERROR,
           CPMS_PSSR_ACCUM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_ACCUM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_ACCUM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_ACCUM_ERROR,
           CPMS_PSSR_ACCUM_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_ACCUM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_PHASE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_PHASE0,
           CPMS_PSSR_AVG_FTX_PHASE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_AVG_FTX_PHASE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_PHASE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_PHASE0,
           CPMS_PSSR_AVG_FTX_PHASE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_AVG_FTX_PHASE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_AVG_FTX_PHASE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_AVG_FTX_PHASE0,
           CPMS_PSSR_AVG_FTX_PHASE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_AVG_FTX_PHASE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_PHASE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_PHASE1,
           CPMS_PSSR_AVG_FTX_PHASE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_AVG_FTX_PHASE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_PHASE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_PHASE1,
           CPMS_PSSR_AVG_FTX_PHASE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_AVG_FTX_PHASE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_AVG_FTX_PHASE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_AVG_FTX_PHASE1,
           CPMS_PSSR_AVG_FTX_PHASE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_AVG_FTX_PHASE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_TOTAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_TOTAL,
           CPMS_PSSR_AVG_FTX_TOTAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_AVG_FTX_TOTAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_AVG_FTX_TOTAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_AVG_FTX_TOTAL,
           CPMS_PSSR_AVG_FTX_TOTAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_AVG_FTX_TOTAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_AVG_FTX_TOTAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_AVG_FTX_TOTAL,
           CPMS_PSSR_AVG_FTX_TOTAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_AVG_FTX_TOTAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_PERIOD_NUMBER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_PERIOD_NUMBER,
           CPMS_PSSR_PITCH_PERIOD_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_PERIOD_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_PERIOD_NUMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_PERIOD_NUMBER,
           CPMS_PSSR_PITCH_PERIOD_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_PERIOD_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_PITCH_PERIOD_NUMBER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_PITCH_PERIOD_NUMBER,
           CPMS_PSSR_PITCH_PERIOD_NUMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_PERIOD_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_SUB_PERIOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_SUB_PERIOD,
           CPMS_PSSR_PITCH_SUB_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_SUB_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_SUB_PERIOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_SUB_PERIOD,
           CPMS_PSSR_PITCH_SUB_PERIOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_SUB_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_PITCH_SUB_PERIOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_PITCH_SUB_PERIOD,
           CPMS_PSSR_PITCH_SUB_PERIOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_SUB_PERIOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_PERIOD_TIMER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_PERIOD_TIMER,
           CPMS_PSSR_PITCH_PERIOD_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_PERIOD_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_PERIOD_TIMER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_PERIOD_TIMER,
           CPMS_PSSR_PITCH_PERIOD_TIMER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_PERIOD_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_PITCH_PERIOD_TIMER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_PITCH_PERIOD_TIMER,
           CPMS_PSSR_PITCH_PERIOD_TIMER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_PERIOD_TIMER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.insertFromRight<CPMS_PSSR_PITCH_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.setBit<CPMS_PSSR_PITCH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return o_data.clearBit<CPMS_PSSR_PITCH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.extractToRight<CPMS_PSSR_PITCH_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_PSSR_PITCH_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PSSR));
#endif
    return i_data.getBit<CPMS_PSSR_PITCH_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_PSSR_PITCH_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_RVCSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_RVCSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR;
#endif
    return fapi2::getScom(i_target, CPMS_RVCSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_RVCSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_RVCSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_RVCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_RVCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_RVCSR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_RVCSR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_RVCSR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_RVCSR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_RVCSR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_RVCSR_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_RVCSR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_RVCSR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_RVCSR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_RVID_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_RVID_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVID_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_RVCSR_RVID_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_RVID_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_RVID_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_RVID_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVID_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_RVCSR_RVID_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_RVID_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_OVERRIDE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_ACS_CALIBRATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_ACS_CALIBRATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_ACS_CALIBRATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_ACS_CALIBRATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_ACS_CALIBRATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_ACS_CALIBRATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_RVCSR_ACS_CALIBRATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_ACS_CALIBRATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_ACS_CALIBRATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVRM_TUNE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVRM_TUNE,
           CPMS_RVCSR_RVRM_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVRM_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVRM_TUNE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVRM_TUNE,
           CPMS_RVCSR_RVRM_TUNE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVRM_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVRM_TUNE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVRM_TUNE,
           CPMS_RVCSR_RVRM_TUNE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVRM_TUNE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_RVID_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_RVID_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVID_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_RVCSR_RVID_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_RVID_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_BYPASS_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_BYPASS_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_BYPASS_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_BYPASS_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_BYPASS_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_BYPASS_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_RVCSR_BYPASS_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_BYPASS_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_BYPASS_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_RVCSR_RVID_ENABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.setBit<CPMS_RVCSR_RVID_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return o_data.clearBit<CPMS_RVCSR_RVID_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_RVCSR_RVID_ENABLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_RVCSR_RVID_ENABLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_RVCSR, CPMS_RVCSR_WO_CLEAR, CPMS_RVCSR_WO_OR));
#endif
    return i_data.getBit<CPMS_RVCSR_RVID_ENABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_RVCSR_RVID_ENABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG11(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG11;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG11(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG11;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG11, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG11(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG11, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG11_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG11_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG11_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG11_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG11_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG11_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG11_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG11_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG11));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG11_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG11_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG7(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG7;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG7(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG7;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG7, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG7(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG7, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG7));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_VSU_HOLD_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_VSU_HOLD_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_VSU_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_VSU_HOLD_OUT;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_VSU_HOLD_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_VSU_HOLD_OUT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_VSU_HOLD_OUT));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_VSU_HOLD_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_RECOV_THOLD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RECOV_THOLD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_RECOV_THOLD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RECOV_THOLD;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_RECOV_THOLD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_RECOV_THOLD(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_THOLD));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_RECOV_THOLD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_THOLD));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT,
           EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_THOLD));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT,
           EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_THOLD));
#endif
    return i_data.extractToRight<EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT,
           EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_THOLD));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET,
           EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_THOLD));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET,
           EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_THOLD));
#endif
    return i_data.extractToRight<EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET,
           EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_IMA_EVENT_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_IMA_EVENT_MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_IMA_EVENT_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_IMA_EVENT_MASK;
#endif
    return fapi2::getScom(i_target, EC_PC_IMA_EVENT_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_IMA_EVENT_MASK(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return fapi2::putScom(i_target, EC_PC_IMA_EVENT_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_IC_TAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_IC_TAP,
           EC_PC_IMA_EVENT_MASK_IC_TAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_IC_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_IC_TAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_IC_TAP,
           EC_PC_IMA_EVENT_MASK_IC_TAP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_IC_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_IC_TAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_IC_TAP,
           EC_PC_IMA_EVENT_MASK_IC_TAP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_IC_TAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_DIS_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_DIS_WRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_DIS_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_DIS_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_DIS_WRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_IMA_EVENT_MASK_DIS_WRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_DIS_WRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_DIS_WRAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_FREEZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_FREEZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_FREEZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_IMA_EVENT_MASK_FREEZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_FREEZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_FREEZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EN_D_PRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EN_D_PRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_EN_D_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_EN_D_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_EN_D_PRE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_IMA_EVENT_MASK_EN_D_PRE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_EN_D_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_D_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EN_I_PRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EN_I_PRE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_EN_I_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_EN_I_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_EN_I_PRE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_IMA_EVENT_MASK_EN_I_PRE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_EN_I_PRE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EN_I_PRE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_ONE_EVENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_ONE_EVENT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.setBit<EC_PC_IMA_EVENT_MASK_ONE_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.clearBit<EC_PC_IMA_EVENT_MASK_ONE_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_ONE_EVENT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_IMA_EVENT_MASK_ONE_EVENT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.getBit<EC_PC_IMA_EVENT_MASK_ONE_EVENT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_ONE_EVENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EVENT_VTID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EVENT_VTID,
           EC_PC_IMA_EVENT_MASK_EVENT_VTID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_VTID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EVENT_VTID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EVENT_VTID,
           EC_PC_IMA_EVENT_MASK_EVENT_VTID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_VTID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_EVENT_VTID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_EVENT_VTID,
           EC_PC_IMA_EVENT_MASK_EVENT_VTID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_VTID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EVENT_SELECT,
           EC_PC_IMA_EVENT_MASK_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_EVENT_MASK_EVENT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return o_data.insertFromRight<EC_PC_IMA_EVENT_MASK_EVENT_SELECT,
           EC_PC_IMA_EVENT_MASK_EVENT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_EVENT_MASK_EVENT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_EVENT_MASK));
#endif
    return i_data.extractToRight<EC_PC_IMA_EVENT_MASK_EVENT_SELECT,
           EC_PC_IMA_EVENT_MASK_EVENT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_EVENT_MASK_EVENT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SCR5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SCR5(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR5;
#endif
    return fapi2::getScom(i_target, EC_PC_SCR5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SCR5(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SCR5));
#endif
    return fapi2::putScom(i_target, EC_PC_SCR5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TOD_SYNC011(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC011;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TOD_SYNC011(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC011;
#endif
    return fapi2::getScom(i_target, EC_PC_TOD_SYNC011, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TOD_SYNC011(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC011));
#endif
    return fapi2::putScom(i_target, EC_PC_TOD_SYNC011, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC011_TOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC011));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC011_TOD,
           EC_PC_TOD_SYNC011_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC011_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC011_TOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC011));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC011_TOD,
           EC_PC_TOD_SYNC011_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC011_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC011_TOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC011));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC011_TOD,
           EC_PC_TOD_SYNC011_TOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC011_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC011_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC011));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC011_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC011_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC011_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC011_CHIP_TOD_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC011));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC011_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC011_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC011_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC011_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC011));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC011_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC011_CHIP_TOD_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC011_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TOD_SYNC100(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC100;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TOD_SYNC100(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TOD_SYNC100;
#endif
    return fapi2::getScom(i_target, EC_PC_TOD_SYNC100, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TOD_SYNC100(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC100));
#endif
    return fapi2::putScom(i_target, EC_PC_TOD_SYNC100, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC100_TOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC100));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC100_TOD,
           EC_PC_TOD_SYNC100_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC100_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC100_TOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC100));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC100_TOD,
           EC_PC_TOD_SYNC100_TOD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC100_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC100_TOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC100));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC100_TOD,
           EC_PC_TOD_SYNC100_TOD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC100_TOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC100_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC100));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC100_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC100_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC100_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TOD_SYNC100_CHIP_TOD_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC100));
#endif
    return o_data.insertFromRight<EC_PC_TOD_SYNC100_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC100_CHIP_TOD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC100_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TOD_SYNC100_CHIP_TOD_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TOD_SYNC100));
#endif
    return i_data.extractToRight<EC_PC_TOD_SYNC100_CHIP_TOD_STATUS,
           EC_PC_TOD_SYNC100_CHIP_TOD_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TOD_SYNC100_CHIP_TOD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_ERR_RPT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_ERR_RPT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_ERR_RPT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_ERR_RPT1;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_ERR_RPT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_ERR_RPT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_ERR_RPT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_ERR_RPT1));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_MODE_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_MODE_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_MODE_REG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_MODE_REG0;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_MODE_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_MODE_REG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_MODE_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM,
           L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM,
           L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM,
           L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL,
           L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL,
           L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL,
           L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK,
           L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK,
           L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK,
           L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_SPARES1,
           L2_L2MISC_L2CERRS_MODE_REG0_SPARES1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_SPARES1,
           L2_L2MISC_L2CERRS_MODE_REG0_SPARES1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_SPARES1,
           L2_L2MISC_L2CERRS_MODE_REG0_SPARES1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_SPARES2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_SPARES2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_SPARES2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_SPARES2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_SPARES2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_SPARES2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_SPARES2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_SPARES3,
           L2_L2MISC_L2CERRS_MODE_REG0_SPARES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_SPARES3,
           L2_L2MISC_L2CERRS_MODE_REG0_SPARES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_SPARES3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_SPARES3,
           L2_L2MISC_L2CERRS_MODE_REG0_SPARES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_SPARES3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE,
           L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE,
           L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_MODE_REG0));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE,
           L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_TOPOTABLE2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_TOPOTABLE2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_TOPOTABLE2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_TOPOTABLE2;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_TOPOTABLE2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_TOPOTABLE2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_TOPOTABLE2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16,
           L2_L2MISC_L2CERRS_TOPOTABLE2_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16,
           L2_L2MISC_L2CERRS_TOPOTABLE2_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_16,
           L2_L2MISC_L2CERRS_TOPOTABLE2_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17,
           L2_L2MISC_L2CERRS_TOPOTABLE2_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17,
           L2_L2MISC_L2CERRS_TOPOTABLE2_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_17,
           L2_L2MISC_L2CERRS_TOPOTABLE2_17_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18,
           L2_L2MISC_L2CERRS_TOPOTABLE2_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18,
           L2_L2MISC_L2CERRS_TOPOTABLE2_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_18,
           L2_L2MISC_L2CERRS_TOPOTABLE2_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19,
           L2_L2MISC_L2CERRS_TOPOTABLE2_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19,
           L2_L2MISC_L2CERRS_TOPOTABLE2_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_19,
           L2_L2MISC_L2CERRS_TOPOTABLE2_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20,
           L2_L2MISC_L2CERRS_TOPOTABLE2_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20,
           L2_L2MISC_L2CERRS_TOPOTABLE2_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_20,
           L2_L2MISC_L2CERRS_TOPOTABLE2_20_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21,
           L2_L2MISC_L2CERRS_TOPOTABLE2_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21,
           L2_L2MISC_L2CERRS_TOPOTABLE2_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_21,
           L2_L2MISC_L2CERRS_TOPOTABLE2_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22,
           L2_L2MISC_L2CERRS_TOPOTABLE2_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22,
           L2_L2MISC_L2CERRS_TOPOTABLE2_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_22,
           L2_L2MISC_L2CERRS_TOPOTABLE2_22_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23,
           L2_L2MISC_L2CERRS_TOPOTABLE2_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_TOPOTABLE2_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23,
           L2_L2MISC_L2CERRS_TOPOTABLE2_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_TOPOTABLE2_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_TOPOTABLE2));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_TOPOTABLE2_23,
           L2_L2MISC_L2CERRS_TOPOTABLE2_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2_L2MISC_L2CERRS_TOPOTABLE2_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_3;
#endif
    return fapi2::getScom(i_target, L2TRA_TR1_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_3));
#endif
    return fapi2::putScom(i_target, L2TRA_TR1_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_3_C,
           L2TRA_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_3_C,
           L2TRA_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_3_C,
           L2TRA_TR1_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_3_D,
           L2TRA_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_3_D,
           L2TRA_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_3_D,
           L2TRA_TR1_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L2TRA_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23,
           L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_ERR_RPT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_ERR_RPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_ERR_RPT_REG;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_ERR_RPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_ERR_RPT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_ERR_RPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_ERR_RPT_REG));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0,
           NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0,
           NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_ACTION0_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0,
           NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_FIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1,
           NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1,
           NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1,
           NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SPWU_FSP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_FSP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SPWU_FSP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_FSP;
#endif
    return fapi2::getScom(i_target, QME_SPWU_FSP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SPWU_FSP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return fapi2::putScom(i_target, QME_SPWU_FSP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.insertFromRight<QME_SPWU_FSP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.insertFromRight<QME_SPWU_FSP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.setBit<QME_SPWU_FSP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.clearBit<QME_SPWU_FSP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return i_data.extractToRight<QME_SPWU_FSP_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SPWU_FSP_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return i_data.getBit<QME_SPWU_FSP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.insertFromRight<QME_SPWU_FSP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.insertFromRight<QME_SPWU_FSP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.setBit<QME_SPWU_FSP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return o_data.clearBit<QME_SPWU_FSP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return i_data.extractToRight<QME_SPWU_FSP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SPWU_FSP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_FSP));
#endif
    return i_data.getBit<QME_SPWU_FSP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_FSP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SPWU_HYP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_HYP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SPWU_HYP(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_HYP;
#endif
    return fapi2::getScom(i_target, QME_SPWU_HYP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SPWU_HYP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return fapi2::putScom(i_target, QME_SPWU_HYP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.insertFromRight<QME_SPWU_HYP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.insertFromRight<QME_SPWU_HYP_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.setBit<QME_SPWU_HYP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.clearBit<QME_SPWU_HYP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return i_data.extractToRight<QME_SPWU_HYP_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SPWU_HYP_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return i_data.getBit<QME_SPWU_HYP_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.insertFromRight<QME_SPWU_HYP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.insertFromRight<QME_SPWU_HYP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.setBit<QME_SPWU_HYP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return o_data.clearBit<QME_SPWU_HYP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return i_data.extractToRight<QME_SPWU_HYP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SPWU_HYP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_HYP));
#endif
    return i_data.getBit<QME_SPWU_HYP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_HYP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SPWU_OCC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_OCC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SPWU_OCC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_OCC;
#endif
    return fapi2::getScom(i_target, QME_SPWU_OCC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SPWU_OCC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return fapi2::putScom(i_target, QME_SPWU_OCC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.insertFromRight<QME_SPWU_OCC_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.insertFromRight<QME_SPWU_OCC_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.setBit<QME_SPWU_OCC_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.clearBit<QME_SPWU_OCC_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return i_data.extractToRight<QME_SPWU_OCC_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SPWU_OCC_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return i_data.getBit<QME_SPWU_OCC_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.insertFromRight<QME_SPWU_OCC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.insertFromRight<QME_SPWU_OCC_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.setBit<QME_SPWU_OCC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return o_data.clearBit<QME_SPWU_OCC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return i_data.extractToRight<QME_SPWU_OCC_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SPWU_OCC_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OCC));
#endif
    return i_data.getBit<QME_SPWU_OCC_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SPWU_OCC_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SSH_FSP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_FSP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SSH_FSP(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_FSP;
#endif
    return fapi2::getScom(i_target, QME_SSH_FSP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SSH_FSP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return fapi2::putScom(i_target, QME_SSH_FSP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_GATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.setBit<QME_SSH_FSP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.clearBit<QME_SSH_FSP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_STOP_GATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SSH_FSP_STOP_GATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.getBit<QME_SSH_FSP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.setBit<QME_SSH_FSP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.clearBit<QME_SSH_FSP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SSH_FSP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.getBit<QME_SSH_FSP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_STOP_TRANSITION,
           QME_SSH_FSP_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_STOP_TRANSITION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_STOP_TRANSITION,
           QME_SSH_FSP_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_STOP_TRANSITION,
           QME_SSH_FSP_STOP_TRANSITION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_REQ_STOP_LEVEL,
           QME_SSH_FSP_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_REQ_STOP_LEVEL,
           QME_SSH_FSP_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_REQ_STOP_LEVEL,
           QME_SSH_FSP_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_ACT_STOP_LEVEL,
           QME_SSH_FSP_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_ACT_STOP_LEVEL,
           QME_SSH_FSP_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_ACT_STOP_LEVEL,
           QME_SSH_FSP_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return o_data.insertFromRight<QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_FSP));
#endif
    return i_data.extractToRight<QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SSH_HYP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_HYP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SSH_HYP(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_HYP;
#endif
    return fapi2::getScom(i_target, QME_SSH_HYP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SSH_HYP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return fapi2::putScom(i_target, QME_SSH_HYP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_GATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.setBit<QME_SSH_HYP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.clearBit<QME_SSH_HYP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_STOP_GATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SSH_HYP_STOP_GATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.getBit<QME_SSH_HYP_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.setBit<QME_SSH_HYP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.clearBit<QME_SSH_HYP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SSH_HYP_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.getBit<QME_SSH_HYP_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_STOP_TRANSITION,
           QME_SSH_HYP_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_STOP_TRANSITION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_STOP_TRANSITION,
           QME_SSH_HYP_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_STOP_TRANSITION,
           QME_SSH_HYP_STOP_TRANSITION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_REQ_STOP_LEVEL,
           QME_SSH_HYP_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_REQ_STOP_LEVEL,
           QME_SSH_HYP_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_REQ_STOP_LEVEL,
           QME_SSH_HYP_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_ACT_STOP_LEVEL,
           QME_SSH_HYP_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_ACT_STOP_LEVEL,
           QME_SSH_HYP_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_ACT_STOP_LEVEL,
           QME_SSH_HYP_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return o_data.insertFromRight<QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_HYP));
#endif
    return i_data.extractToRight<QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SSH_OCC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_OCC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SSH_OCC(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_OCC;
#endif
    return fapi2::getScom(i_target, QME_SSH_OCC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SSH_OCC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return fapi2::putScom(i_target, QME_SSH_OCC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_GATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.setBit<QME_SSH_OCC_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.clearBit<QME_SSH_OCC_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_STOP_GATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SSH_OCC_STOP_GATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.getBit<QME_SSH_OCC_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.setBit<QME_SSH_OCC_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.clearBit<QME_SSH_OCC_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_QME_SSH_OCC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.getBit<QME_SSH_OCC_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_STOP_TRANSITION,
           QME_SSH_OCC_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_STOP_TRANSITION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_STOP_TRANSITION,
           QME_SSH_OCC_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_STOP_TRANSITION,
           QME_SSH_OCC_STOP_TRANSITION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_REQ_STOP_LEVEL,
           QME_SSH_OCC_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_REQ_STOP_LEVEL,
           QME_SSH_OCC_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_REQ_STOP_LEVEL,
           QME_SSH_OCC_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_ACT_STOP_LEVEL,
           QME_SSH_OCC_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_ACT_STOP_LEVEL,
           QME_SSH_OCC_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_ACT_STOP_LEVEL,
           QME_SSH_OCC_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return o_data.insertFromRight<QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OCC));
#endif
    return i_data.extractToRight<QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_PROTECT_ENABLE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = WRITE_PROTECT_ENABLE_REG;
#endif
    return fapi2::getScom(i_target, WRITE_PROTECT_ENABLE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_WRITE_PROTECT_ENABLE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return fapi2::putScom(i_target, WRITE_PROTECT_ENABLE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.setBit<WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.clearBit<WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.extractToRight<WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.getBit<WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.insertFromRight<WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.setBit<WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return o_data.clearBit<WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.extractToRight<WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(WRITE_PROTECT_ENABLE_REG));
#endif
    return i_data.getBit<WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
