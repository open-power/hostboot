/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00009.H $            */
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

#ifndef __C_REG00009_H_
#define __C_REG00009_H_

namespace scomt
{
namespace c
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DDSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DDSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DDSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DDSR;
#endif
    return fapi2::getScom(i_target, CPMS_DDSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DDSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return fapi2::putScom(i_target, CPMS_DDSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DDS_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DDS_DATA,
           CPMS_DDSR_DDS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DDS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DDS_DATA,
           CPMS_DDSR_DDS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_DDS_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_DDS_DATA,
           CPMS_DDSR_DDS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DDS_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DDS_MIN,
           CPMS_DDSR_DDS_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DDS_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DDS_MIN,
           CPMS_DDSR_DDS_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_DDS_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_DDS_MIN,
           CPMS_DDSR_DDS_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DDS_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DDS_MAX,
           CPMS_DDSR_DDS_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DDS_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DDS_MAX,
           CPMS_DDSR_DDS_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_DDS_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_DDS_MAX,
           CPMS_DDSR_DDS_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DPLL_ENCODED_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DPLL_ENCODED_DATA,
           CPMS_DDSR_DPLL_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DPLL_ENCODED_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DPLL_ENCODED_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DPLL_ENCODED_DATA,
           CPMS_DDSR_DPLL_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DPLL_ENCODED_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_DPLL_ENCODED_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_DPLL_ENCODED_DATA,
           CPMS_DDSR_DPLL_ENCODED_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DPLL_ENCODED_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DPLL_ENCODED_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DPLL_ENCODED_MIN,
           CPMS_DDSR_DPLL_ENCODED_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DPLL_ENCODED_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DPLL_ENCODED_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DPLL_ENCODED_MIN,
           CPMS_DDSR_DPLL_ENCODED_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DPLL_ENCODED_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_DPLL_ENCODED_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_DPLL_ENCODED_MIN,
           CPMS_DDSR_DPLL_ENCODED_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DPLL_ENCODED_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DPLL_ENCODED_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DPLL_ENCODED_MAX,
           CPMS_DDSR_DPLL_ENCODED_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DPLL_ENCODED_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_DPLL_ENCODED_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_DPLL_ENCODED_MAX,
           CPMS_DDSR_DPLL_ENCODED_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DPLL_ENCODED_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_DPLL_ENCODED_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_DPLL_ENCODED_MAX,
           CPMS_DDSR_DPLL_ENCODED_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_DPLL_ENCODED_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_STOP_STATE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_STOP_STATE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_STOP_STATE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.setBit<CPMS_DDSR_STOP_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.clearBit<CPMS_DDSR_STOP_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_STOP_STATE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.getBit<CPMS_DDSR_STOP_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_CORE_SAMPLE_DISABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_CORE_SAMPLE_DISABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_CORE_SAMPLE_DISABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.setBit<CPMS_DDSR_CORE_SAMPLE_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.clearBit<CPMS_DDSR_CORE_SAMPLE_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_CORE_SAMPLE_DISABLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.getBit<CPMS_DDSR_CORE_SAMPLE_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_STOP_STATE_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.setBit<CPMS_DDSR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.clearBit<CPMS_DDSR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_STOP_STATE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.getBit<CPMS_DDSR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_SAMPLE_DISABLE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_SAMPLE_DISABLE_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.insertFromRight<CPMS_DDSR_SAMPLE_DISABLE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.setBit<CPMS_DDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.clearBit<CPMS_DDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_DDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.extractToRight<CPMS_DDSR_SAMPLE_DISABLE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_DDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.getBit<CPMS_DDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FDIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDIR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FDIR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDIR;
#endif
    return fapi2::getScom(i_target, CPMS_FDIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FDIR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FDIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FDIR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDIR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FDIR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDIR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_FDIR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FDIR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FDIR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FDIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FDIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDIR_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_FDIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FDIR_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_FDIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_INJECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_INJECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_INJECT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_INJECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_INJECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_INJECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_INJECT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_INJECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_INJECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_HALT_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_HALT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_HALT_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_HALT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_HALT_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_HALT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_HALT_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_HALT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_HALT_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_HALT_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_HALT_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_HALT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_HALT_TOGGLE_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_HALT_TOGGLE_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_HALT_TOGGLE_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_HALT_TOGGLE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_HALT_TOGGLE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_HALT_TOGGLE_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_HALT_TOGGLE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_FETCH_THROTTLE01_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_FETCH_THROTTLE01_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_FETCH_THROTTLE01_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_FETCH_THROTTLE01_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_FETCH_THROTTLE01_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_FETCH_THROTTLE01_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_FETCH_THROTTLE01_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_FETCH_THROTTLE01_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_FETCH_THROTTLE01_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_FETCH_THROTTLE01_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_FETCH_THROTTLE01_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_FETCH_THROTTLE01_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_FETCH_THROTTLE10_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_FETCH_THROTTLE10_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_FETCH_THROTTLE10_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_FETCH_THROTTLE10_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_FETCH_THROTTLE10_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_FETCH_THROTTLE10_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_FETCH_THROTTLE10_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_FETCH_THROTTLE10_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_FETCH_THROTTLE10_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_FETCH_THROTTLE10_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_FETCH_THROTTLE10_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_FETCH_THROTTLE10_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_ISSUE_NTC_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_ISSUE_NTC_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_ISSUE_NTC_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_ISSUE_NTC_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_ISSUE_NTC_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_ISSUE_NTC_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_ISSUE_NTC_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_ISSUE_NTC_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_ISSUE_NTC_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_ISSUE_NTC_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_ISSUE_NTC_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_ISSUE_NTC_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_PREFETCH_THROTTLE_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_PREFETCH_THROTTLE_INJECT,
           CPMS_FDIR_PREFETCH_THROTTLE_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_PREFETCH_THROTTLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_PREFETCH_THROTTLE_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_PREFETCH_THROTTLE_INJECT,
           CPMS_FDIR_PREFETCH_THROTTLE_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_PREFETCH_THROTTLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_PREFETCH_THROTTLE_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_PREFETCH_THROTTLE_INJECT,
           CPMS_FDIR_PREFETCH_THROTTLE_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_PREFETCH_THROTTLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SLOW_FETCH_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_SLOW_FETCH_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SLOW_FETCH_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_SLOW_FETCH_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SLOW_FETCH_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_SLOW_FETCH_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_SLOW_FETCH_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_SLOW_FETCH_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_SLOW_FETCH_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_SLOW_FETCH_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_SLOW_FETCH_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_SLOW_FETCH_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_VECTOR_LIMIT_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_VECTOR_LIMIT_INJECT,
           CPMS_FDIR_VECTOR_LIMIT_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_VECTOR_LIMIT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_VECTOR_LIMIT_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_VECTOR_LIMIT_INJECT,
           CPMS_FDIR_VECTOR_LIMIT_INJECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_VECTOR_LIMIT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_VECTOR_LIMIT_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_VECTOR_LIMIT_INJECT,
           CPMS_FDIR_VECTOR_LIMIT_INJECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_VECTOR_LIMIT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SLOW_COMPLETION_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_SLOW_COMPLETION_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SLOW_COMPLETION_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_SLOW_COMPLETION_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SLOW_COMPLETION_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_SLOW_COMPLETION_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_SLOW_COMPLETION_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_SLOW_COMPLETION_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_SLOW_COMPLETION_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_SLOW_COMPLETION_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_SLOW_COMPLETION_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_SLOW_COMPLETION_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_MMA_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_MMA_LIMIT,
           CPMS_FDIR_MMA_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_MMA_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_MMA_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_MMA_LIMIT,
           CPMS_FDIR_MMA_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_MMA_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_MMA_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_MMA_LIMIT,
           CPMS_FDIR_MMA_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_MMA_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_TOGGLE_HALT_AMOUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_TOGGLE_HALT_AMOUNT,
           CPMS_FDIR_TOGGLE_HALT_AMOUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_TOGGLE_HALT_AMOUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_TOGGLE_HALT_AMOUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_TOGGLE_HALT_AMOUNT,
           CPMS_FDIR_TOGGLE_HALT_AMOUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_TOGGLE_HALT_AMOUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_TOGGLE_HALT_AMOUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_TOGGLE_HALT_AMOUNT,
           CPMS_FDIR_TOGGLE_HALT_AMOUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_TOGGLE_HALT_AMOUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_INJECT_RESPONSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_INJECT_RESPONSE,
           CPMS_FDIR_IRRITATE_INJECT_RESPONSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_INJECT_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_INJECT_RESPONSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_INJECT_RESPONSE,
           CPMS_FDIR_IRRITATE_INJECT_RESPONSE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_INJECT_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_IRRITATE_INJECT_RESPONSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_IRRITATE_INJECT_RESPONSE,
           CPMS_FDIR_IRRITATE_INJECT_RESPONSE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_INJECT_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_LFSR_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_LFSR_SELECT,
           CPMS_FDIR_IRRITATE_LFSR_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_LFSR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_LFSR_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_LFSR_SELECT,
           CPMS_FDIR_IRRITATE_LFSR_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_LFSR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_IRRITATE_LFSR_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_IRRITATE_LFSR_SELECT,
           CPMS_FDIR_IRRITATE_LFSR_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_LFSR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_SMALL_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_SMALL_SELECT,
           CPMS_FDIR_IRRITATE_SMALL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_SMALL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_SMALL_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_SMALL_SELECT,
           CPMS_FDIR_IRRITATE_SMALL_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_SMALL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_IRRITATE_SMALL_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_IRRITATE_SMALL_SELECT,
           CPMS_FDIR_IRRITATE_SMALL_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_SMALL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_LARGE_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_LARGE_SELECT,
           CPMS_FDIR_IRRITATE_LARGE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_LARGE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_LARGE_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_LARGE_SELECT,
           CPMS_FDIR_IRRITATE_LARGE_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_LARGE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_IRRITATE_LARGE_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_IRRITATE_LARGE_SELECT,
           CPMS_FDIR_IRRITATE_LARGE_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_LARGE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_IRRITATE_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_IRRITATE_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_IRRITATE_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_IRRITATE_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_IRRITATE_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_IRRITATE_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_IRRITATE_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_WEIGHT_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_WEIGHT_SELECT,
           CPMS_FDIR_IRRITATE_WEIGHT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_WEIGHT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_IRRITATE_WEIGHT_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_IRRITATE_WEIGHT_SELECT,
           CPMS_FDIR_IRRITATE_WEIGHT_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_WEIGHT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_IRRITATE_WEIGHT_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_IRRITATE_WEIGHT_SELECT,
           CPMS_FDIR_IRRITATE_WEIGHT_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_IRRITATE_WEIGHT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_INJECT_DPT_SUSPEND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_INJECT_DPT_SUSPEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_INJECT_DPT_SUSPEND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_INJECT_DPT_SUSPEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_INJECT_DPT_SUSPEND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_INJECT_DPT_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_INJECT_DPT_SUSPEND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_INJECT_DPT_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_INJECT_DPT_SUSPEND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_INJECT_DPT_SUSPEND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_CPMS_FDIR_INJECT_DPT_SUSPEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_INJECT_DPT_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_CTRL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_CTRL;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_CTRL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_0_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_0_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_0_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_0_RUN_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_0_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_0_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_0_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_CTRL_0_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_0_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_CTRL_0_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_CTRL_0_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_0_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_CTRL_0_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_CTRL_0_RUN_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_0_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_CTRL_0_RUN_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_CTRL_0_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_0_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_1_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_1_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_1_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_1_RUN_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_1_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_1_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_1_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_CTRL_1_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_1_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_CTRL_1_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_CTRL_1_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_1_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_CTRL_1_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_CTRL_1_RUN_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_1_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_CTRL_1_RUN_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_CTRL_1_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_1_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_2_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_2_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_2_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_2_RUN_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_2_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_2_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_2_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_CTRL_2_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_2_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_CTRL_2_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_CTRL_2_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_2_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_CTRL_2_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_CTRL_2_RUN_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_2_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_CTRL_2_RUN_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_CTRL_2_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_2_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_3_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_3_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_3_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_3_RUN_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_3_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_3_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_3_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_CTRL_3_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_3_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_CTRL_3_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_CTRL_3_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_3_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_CTRL_3_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_CTRL_3_RUN_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_3_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_CTRL_3_RUN_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_CTRL_3_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_3_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_4_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_4_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_4_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_4_RUN_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_4_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_4_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_4_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_CTRL_4_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_4_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_CTRL_4_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_CTRL_4_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_4_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_CTRL_4_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_CTRL_4_RUN_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_4_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_CTRL_4_RUN_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_CTRL_4_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_4_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_5_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_5_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_5_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_5_RUN_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_5_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_5_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_5_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_CTRL_5_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_5_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_CTRL_5_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_CTRL_5_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_5_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_CTRL_5_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_CTRL_5_RUN_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_5_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_CTRL_5_RUN_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_CTRL_5_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_5_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_6_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_6_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_6_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_6_RUN_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_6_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_6_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_6_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_CTRL_6_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_6_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_CTRL_6_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_CTRL_6_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_6_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_CTRL_6_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_CTRL_6_RUN_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_6_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_CTRL_6_RUN_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_CTRL_6_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_6_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_7_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_7_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_7_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_7_RUN_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_CTRL_7_RUN_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_7_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_CTRL_7_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_CTRL_7_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_7_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_CTRL_7_RUN_Q(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_CTRL_7_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_7_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_CTRL_7_RUN_Q(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_CTRL_7_RUN_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_7_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_COMMON_SPR_CTRL_7_RUN_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_CTRL));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_CTRL_7_RUN_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_COMMON_SPR_CTRL_7_RUN_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_IMA_TRACE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_IMA_TRACE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_IMA_TRACE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_IMA_TRACE;
#endif
    return fapi2::getScom(i_target, EC_PC_IMA_TRACE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_IMA_TRACE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return fapi2::putScom(i_target, EC_PC_IMA_TRACE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_SAMPSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_SAMPSEL,
           EC_PC_IMA_TRACE_SAMPSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_SAMPSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_SAMPSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_SAMPSEL,
           EC_PC_IMA_TRACE_SAMPSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_SAMPSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_TRACE_SAMPSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return i_data.extractToRight<EC_PC_IMA_TRACE_SAMPSEL,
           EC_PC_IMA_TRACE_SAMPSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_SAMPSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_CPMC_LOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_CPMC_LOAD,
           EC_PC_IMA_TRACE_CPMC_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_CPMC_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_CPMC_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_CPMC_LOAD,
           EC_PC_IMA_TRACE_CPMC_LOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_CPMC_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_TRACE_CPMC_LOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return i_data.extractToRight<EC_PC_IMA_TRACE_CPMC_LOAD,
           EC_PC_IMA_TRACE_CPMC_LOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_CPMC_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_CPMC1SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_CPMC1SEL,
           EC_PC_IMA_TRACE_CPMC1SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_CPMC1SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_CPMC1SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_CPMC1SEL,
           EC_PC_IMA_TRACE_CPMC1SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_CPMC1SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_TRACE_CPMC1SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return i_data.extractToRight<EC_PC_IMA_TRACE_CPMC1SEL,
           EC_PC_IMA_TRACE_CPMC1SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_CPMC1SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_CPMC2SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_CPMC2SEL,
           EC_PC_IMA_TRACE_CPMC2SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_CPMC2SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_CPMC2SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_CPMC2SEL,
           EC_PC_IMA_TRACE_CPMC2SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_CPMC2SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_TRACE_CPMC2SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return i_data.extractToRight<EC_PC_IMA_TRACE_CPMC2SEL,
           EC_PC_IMA_TRACE_CPMC2SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_CPMC2SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_BUFFERSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_BUFFERSIZE,
           EC_PC_IMA_TRACE_BUFFERSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_BUFFERSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_IMA_TRACE_BUFFERSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return o_data.insertFromRight<EC_PC_IMA_TRACE_BUFFERSIZE,
           EC_PC_IMA_TRACE_BUFFERSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_BUFFERSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_IMA_TRACE_BUFFERSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_IMA_TRACE));
#endif
    return i_data.extractToRight<EC_PC_IMA_TRACE_BUFFERSIZE,
           EC_PC_IMA_TRACE_BUFFERSIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_IMA_TRACE_BUFFERSIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TFX_SM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TFX_SM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TFX_SM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TFX_SM;
#endif
    return fapi2::getScom(i_target, EC_PC_TFX_SM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TFX_SM(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return fapi2::putScom(i_target, EC_PC_TFX_SM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_HANG_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_THRCTL_TCTLCOM_HANG_CONTROL;
#endif
    return fapi2::getScom(i_target, EC_PC_THRCTL_TCTLCOM_HANG_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return fapi2::putScom(i_target, EC_PC_THRCTL_TCTLCOM_HANG_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.setBit<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.clearBit<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return i_data.getBit<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return o_data.insertFromRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_THRCTL_TCTLCOM_HANG_CONTROL));
#endif
    return i_data.extractToRight<EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK,
           EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE1_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR0_CONFIG_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE1_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR0_CONFIG_1;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE1_TR0_CONFIG_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE1_TR0_CONFIG_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_1));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE1_TR0_CONFIG_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_1));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR0_CONFIG_1));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87,
           EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_WR_EPSILON_CFG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_WR_EPSILON_CFG_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_WR_EPSILON_CFG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_WR_EPSILON_CFG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE,
           L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_WR_EPSILON_CFG_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_PHYP_PURGE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PHYP_PURGE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_PHYP_PURGE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PHYP_PURGE_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_PHYP_PURGE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_PHYP_PURGE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_PHYP_PURGE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE,
           L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE,
           L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE,
           L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER,
           L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER,
           L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER,
           L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR,
           L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR,
           L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PHYP_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR,
           L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED,
           NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED,
           NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED,
           NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM,
           NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM,
           NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM,
           NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT,
           NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT,
           NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT,
           NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_HTM_LAST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_LAST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_HTM_LAST(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_LAST;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_HTM_LAST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_HTM_LAST(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_LAST));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_HTM_LAST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_LAST));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS,
           NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_LAST));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS,
           NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_LAST));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS,
           NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_CDBB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CDBB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_CDBB(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CDBB;
#endif
    return fapi2::getScom(i_target, QME_CDBB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_CDBB(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_CDBB));
#endif
    return fapi2::putScom(i_target, QME_CDBB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_QME_CDBB_QME_CDBB_MESSAGE_NUMBER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CDBB));
#endif
    return o_data.insertFromRight<QME_CDBB_QME_CDBB_MESSAGE_NUMBER,
           QME_CDBB_QME_CDBB_MESSAGE_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_CDBB_QME_CDBB_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_QME_CDBB_QME_CDBB_MESSAGE_NUMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CDBB));
#endif
    return o_data.insertFromRight<QME_CDBB_QME_CDBB_MESSAGE_NUMBER,
           QME_CDBB_QME_CDBB_MESSAGE_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_CDBB_QME_CDBB_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_QME_CDBB_QME_CDBB_MESSAGE_NUMBER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CDBB));
#endif
    return i_data.extractToRight<QME_CDBB_QME_CDBB_MESSAGE_NUMBER,
           QME_CDBB_QME_CDBB_MESSAGE_NUMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access QME_CDBB_QME_CDBB_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
