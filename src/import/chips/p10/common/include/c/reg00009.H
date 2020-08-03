/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00009.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_DDSR]
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
//<< PREP_[CPMS_DDSR]

//>> GET_[CPMS_DDSR]
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
//<< GET_[CPMS_DDSR]

//>> PUT_[CPMS_DDSR]
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
//<< PUT_[CPMS_DDSR]


//>> SET_[CPMS_DDSR_DDS_DATA]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DDS_DATA]

//>> SET_[CPMS_DDSR_DDS_DATA]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DDS_DATA]

//>> GET_[CPMS_DDSR_DDS_DATA]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_DDS_DATA]

//>> SET_[CPMS_DDSR_DDS_MIN]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DDS_MIN]

//>> SET_[CPMS_DDSR_DDS_MIN]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DDS_MIN]

//>> GET_[CPMS_DDSR_DDS_MIN]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_DDS_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_DDS_MIN]

//>> SET_[CPMS_DDSR_DDS_MAX]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DDS_MAX]

//>> SET_[CPMS_DDSR_DDS_MAX]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DDS_MAX]

//>> GET_[CPMS_DDSR_DDS_MAX]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_DDS_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_DDS_MAX]

//>> SET_[CPMS_DDSR_DPLL_ENCODED_DATA]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_DPLL_ENCODED_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DPLL_ENCODED_DATA]

//>> SET_[CPMS_DDSR_DPLL_ENCODED_DATA]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_DPLL_ENCODED_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DPLL_ENCODED_DATA]

//>> GET_[CPMS_DDSR_DPLL_ENCODED_DATA]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_DPLL_ENCODED_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_DPLL_ENCODED_DATA]

//>> SET_[CPMS_DDSR_DPLL_ENCODED_MIN]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_DPLL_ENCODED_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DPLL_ENCODED_MIN]

//>> SET_[CPMS_DDSR_DPLL_ENCODED_MIN]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_DPLL_ENCODED_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DPLL_ENCODED_MIN]

//>> GET_[CPMS_DDSR_DPLL_ENCODED_MIN]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_DPLL_ENCODED_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_DPLL_ENCODED_MIN]

//>> SET_[CPMS_DDSR_DPLL_ENCODED_MAX]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_DPLL_ENCODED_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DPLL_ENCODED_MAX]

//>> SET_[CPMS_DDSR_DPLL_ENCODED_MAX]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_DPLL_ENCODED_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_DPLL_ENCODED_MAX]

//>> GET_[CPMS_DDSR_DPLL_ENCODED_MAX]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_DPLL_ENCODED_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_DPLL_ENCODED_MAX]

//>> SET_[CPMS_DDSR_STOP_STATE_ACTIVE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_STOP_STATE_ACTIVE]

//>> SET_[CPMS_DDSR_STOP_STATE_ACTIVE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_STOP_STATE_ACTIVE]

//>> SET_[CPMS_DDSR_STOP_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.setBit<CPMS_DDSR_STOP_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_STOP_STATE_ACTIVE]

//>> CLEAR_[CPMS_DDSR_STOP_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.clearBit<CPMS_DDSR_STOP_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DDSR_STOP_STATE_ACTIVE]

//>> GET_[CPMS_DDSR_STOP_STATE_ACTIVE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_STOP_STATE_ACTIVE]

//>> GET_[CPMS_DDSR_STOP_STATE_ACTIVE]
static inline bool GET_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.getBit<CPMS_DDSR_STOP_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_STOP_STATE_ACTIVE]

//>> SET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> SET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> SET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.setBit<CPMS_DDSR_CORE_SAMPLE_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> CLEAR_[CPMS_DDSR_CORE_SAMPLE_DISABLED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.clearBit<CPMS_DDSR_CORE_SAMPLE_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> GET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> GET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]
static inline bool GET_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.getBit<CPMS_DDSR_CORE_SAMPLE_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> SET_[CPMS_DDSR_STOP_STATE_OCCURRED]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_DDSR_STOP_STATE_OCCURRED]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_DDSR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.setBit<CPMS_DDSR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_STOP_STATE_OCCURRED]

//>> CLEAR_[CPMS_DDSR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.clearBit<CPMS_DDSR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DDSR_STOP_STATE_OCCURRED]

//>> GET_[CPMS_DDSR_STOP_STATE_OCCURRED]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_STOP_STATE_OCCURRED]

//>> GET_[CPMS_DDSR_STOP_STATE_OCCURRED]
static inline bool GET_CPMS_DDSR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.getBit<CPMS_DDSR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DDSR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]

//>> SET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]

//>> SET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.setBit<CPMS_DDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]

//>> CLEAR_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return o_data.clearBit<CPMS_DDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]

//>> GET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]

//>> GET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]
static inline bool GET_CPMS_DDSR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DDSR));
#endif
    return i_data.getBit<CPMS_DDSR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DDSR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DDSR_SAMPLE_DISABLE_OCCURRED]

//>> PREP_[CPMS_FDIR]
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
//<< PREP_[CPMS_FDIR]

//>> GET_[CPMS_FDIR]
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
//<< GET_[CPMS_FDIR]

//>> PUT_[CPMS_FDIR]
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
//<< PUT_[CPMS_FDIR]

//>> PREP_[CPMS_FDIR_WO_CLEAR]
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
//<< PREP_[CPMS_FDIR_WO_CLEAR]

//>> GET_[CPMS_FDIR_WO_CLEAR]
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
//<< GET_[CPMS_FDIR_WO_CLEAR]

//>> PUT_[CPMS_FDIR_WO_CLEAR]
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
//<< PUT_[CPMS_FDIR_WO_CLEAR]

//>> PREP_[CPMS_FDIR_WO_OR]
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
//<< PREP_[CPMS_FDIR_WO_OR]

//>> GET_[CPMS_FDIR_WO_OR]
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
//<< GET_[CPMS_FDIR_WO_OR]

//>> PUT_[CPMS_FDIR_WO_OR]
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
//<< PUT_[CPMS_FDIR_WO_OR]


//>> SET_[CPMS_FDIR_INJECT_ENABLE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_INJECT_ENABLE]

//>> SET_[CPMS_FDIR_INJECT_ENABLE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_INJECT_ENABLE]

//>> SET_[CPMS_FDIR_INJECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_INJECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_INJECT_ENABLE]

//>> CLEAR_[CPMS_FDIR_INJECT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_INJECT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_INJECT_ENABLE]

//>> GET_[CPMS_FDIR_INJECT_ENABLE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_INJECT_ENABLE]

//>> GET_[CPMS_FDIR_INJECT_ENABLE]
static inline bool GET_CPMS_FDIR_INJECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_INJECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_INJECT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_INJECT_ENABLE]

//>> SET_[CPMS_FDIR_UARCH_HALT_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_UARCH_HALT_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_UARCH_HALT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_UARCH_HALT_INJECT]

//>> SET_[CPMS_FDIR_UARCH_HALT_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_UARCH_HALT_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_UARCH_HALT_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_UARCH_HALT_INJECT]

//>> SET_[CPMS_FDIR_UARCH_HALT_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_UARCH_HALT_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_UARCH_HALT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_UARCH_HALT_INJECT]

//>> CLEAR_[CPMS_FDIR_UARCH_HALT_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_UARCH_HALT_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_UARCH_HALT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_UARCH_HALT_INJECT]

//>> GET_[CPMS_FDIR_UARCH_HALT_INJECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_UARCH_HALT_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_UARCH_HALT_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_UARCH_HALT_INJECT]

//>> GET_[CPMS_FDIR_UARCH_HALT_INJECT]
static inline bool GET_CPMS_FDIR_UARCH_HALT_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_UARCH_HALT_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_UARCH_HALT_INJECT]

//>> SET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]

//>> SET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]

//>> SET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]

//>> CLEAR_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]

//>> GET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]

//>> GET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]
static inline bool GET_CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_UARCH_HALT_TOGGLE_INJECT]

//>> SET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]

//>> SET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]

//>> SET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_FETCH_THROTTLE10_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_FETCH_THROTTLE10_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]

//>> CLEAR_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_FETCH_THROTTLE10_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_FETCH_THROTTLE10_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]

//>> GET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]

//>> GET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]
static inline bool GET_CPMS_FDIR_FETCH_THROTTLE10_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_FETCH_THROTTLE10_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE10_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_FETCH_THROTTLE10_INJECT]

//>> SET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]

//>> SET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]

//>> SET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_FETCH_THROTTLE01_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_FETCH_THROTTLE01_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]

//>> CLEAR_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_FETCH_THROTTLE01_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_FETCH_THROTTLE01_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]

//>> GET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]

//>> GET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]
static inline bool GET_CPMS_FDIR_FETCH_THROTTLE01_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_FETCH_THROTTLE01_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_FETCH_THROTTLE01_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_FETCH_THROTTLE01_INJECT]

//>> SET_[CPMS_FDIR_ISSUE_NTC_INJECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_ISSUE_NTC_INJECT]

//>> SET_[CPMS_FDIR_ISSUE_NTC_INJECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_ISSUE_NTC_INJECT]

//>> SET_[CPMS_FDIR_ISSUE_NTC_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_ISSUE_NTC_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_ISSUE_NTC_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_ISSUE_NTC_INJECT]

//>> CLEAR_[CPMS_FDIR_ISSUE_NTC_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_ISSUE_NTC_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_ISSUE_NTC_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_ISSUE_NTC_INJECT]

//>> GET_[CPMS_FDIR_ISSUE_NTC_INJECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_ISSUE_NTC_INJECT]

//>> GET_[CPMS_FDIR_ISSUE_NTC_INJECT]
static inline bool GET_CPMS_FDIR_ISSUE_NTC_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_ISSUE_NTC_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_ISSUE_NTC_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_ISSUE_NTC_INJECT]

//>> SET_[CPMS_FDIR_PREFETCH_THROTTLE_INJECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_PREFETCH_THROTTLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_PREFETCH_THROTTLE_INJECT]

//>> SET_[CPMS_FDIR_PREFETCH_THROTTLE_INJECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_PREFETCH_THROTTLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_PREFETCH_THROTTLE_INJECT]

//>> GET_[CPMS_FDIR_PREFETCH_THROTTLE_INJECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_PREFETCH_THROTTLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_PREFETCH_THROTTLE_INJECT]

//>> SET_[CPMS_FDIR_SLOW_FETCH_INJECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_SLOW_FETCH_INJECT]

//>> SET_[CPMS_FDIR_SLOW_FETCH_INJECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_SLOW_FETCH_INJECT]

//>> SET_[CPMS_FDIR_SLOW_FETCH_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SLOW_FETCH_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_SLOW_FETCH_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_SLOW_FETCH_INJECT]

//>> CLEAR_[CPMS_FDIR_SLOW_FETCH_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_SLOW_FETCH_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_SLOW_FETCH_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_SLOW_FETCH_INJECT]

//>> GET_[CPMS_FDIR_SLOW_FETCH_INJECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_SLOW_FETCH_INJECT]

//>> GET_[CPMS_FDIR_SLOW_FETCH_INJECT]
static inline bool GET_CPMS_FDIR_SLOW_FETCH_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_SLOW_FETCH_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_SLOW_FETCH_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_SLOW_FETCH_INJECT]

//>> SET_[CPMS_FDIR_VECTOR_LIMIT_INJECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_VECTOR_LIMIT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_VECTOR_LIMIT_INJECT]

//>> SET_[CPMS_FDIR_VECTOR_LIMIT_INJECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_VECTOR_LIMIT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_VECTOR_LIMIT_INJECT]

//>> GET_[CPMS_FDIR_VECTOR_LIMIT_INJECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_VECTOR_LIMIT_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_VECTOR_LIMIT_INJECT]

//>> SET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]

//>> SET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]

//>> SET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_SLOW_COMPLETION_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_SLOW_COMPLETION_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]

//>> CLEAR_[CPMS_FDIR_SLOW_COMPLETION_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_SLOW_COMPLETION_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_SLOW_COMPLETION_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_SLOW_COMPLETION_INJECT]

//>> GET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]

//>> GET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]
static inline bool GET_CPMS_FDIR_SLOW_COMPLETION_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_SLOW_COMPLETION_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_SLOW_COMPLETION_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_SLOW_COMPLETION_INJECT]

//>> SET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_MMA_UARCH_ENABLE_INJECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_MMA_UARCH_ENABLE_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_MMA_UARCH_ENABLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]

//>> SET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_MMA_UARCH_ENABLE_INJECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_MMA_UARCH_ENABLE_INJECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_MMA_UARCH_ENABLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]

//>> SET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_MMA_UARCH_ENABLE_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_MMA_UARCH_ENABLE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_MMA_UARCH_ENABLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]

//>> CLEAR_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_MMA_UARCH_ENABLE_INJECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_MMA_UARCH_ENABLE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_MMA_UARCH_ENABLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]

//>> GET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_MMA_UARCH_ENABLE_INJECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_MMA_UARCH_ENABLE_INJECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_MMA_UARCH_ENABLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]

//>> GET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]
static inline bool GET_CPMS_FDIR_MMA_UARCH_ENABLE_INJECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_MMA_UARCH_ENABLE_INJECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_MMA_UARCH_ENABLE_INJECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_MMA_UARCH_ENABLE_INJECT]

//>> SET_[CPMS_FDIR_MMA_LIMIT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_MMA_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_MMA_LIMIT]

//>> SET_[CPMS_FDIR_MMA_LIMIT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_MMA_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_MMA_LIMIT]

//>> GET_[CPMS_FDIR_MMA_LIMIT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_MMA_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_MMA_LIMIT]

//>> SET_[CPMS_FDIR_TOGGLE_HALT_AMOUNT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_TOGGLE_HALT_AMOUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_TOGGLE_HALT_AMOUNT]

//>> SET_[CPMS_FDIR_TOGGLE_HALT_AMOUNT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_TOGGLE_HALT_AMOUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_TOGGLE_HALT_AMOUNT]

//>> GET_[CPMS_FDIR_TOGGLE_HALT_AMOUNT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_TOGGLE_HALT_AMOUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_TOGGLE_HALT_AMOUNT]

//>> SET_[CPMS_FDIR_IRRITATE_INJECT_RESPONSE]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_IRRITATE_INJECT_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_INJECT_RESPONSE]

//>> SET_[CPMS_FDIR_IRRITATE_INJECT_RESPONSE]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_IRRITATE_INJECT_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_INJECT_RESPONSE]

//>> GET_[CPMS_FDIR_IRRITATE_INJECT_RESPONSE]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_IRRITATE_INJECT_RESPONSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_IRRITATE_INJECT_RESPONSE]

//>> SET_[CPMS_FDIR_IRRITATE_LFSR_SELECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_IRRITATE_LFSR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_LFSR_SELECT]

//>> SET_[CPMS_FDIR_IRRITATE_LFSR_SELECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_IRRITATE_LFSR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_LFSR_SELECT]

//>> GET_[CPMS_FDIR_IRRITATE_LFSR_SELECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_IRRITATE_LFSR_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_IRRITATE_LFSR_SELECT]

//>> SET_[CPMS_FDIR_IRRITATE_SMALL_SELECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_IRRITATE_SMALL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_SMALL_SELECT]

//>> SET_[CPMS_FDIR_IRRITATE_SMALL_SELECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_IRRITATE_SMALL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_SMALL_SELECT]

//>> GET_[CPMS_FDIR_IRRITATE_SMALL_SELECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_IRRITATE_SMALL_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_IRRITATE_SMALL_SELECT]

//>> SET_[CPMS_FDIR_IRRITATE_LARGE_SELECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_IRRITATE_LARGE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_LARGE_SELECT]

//>> SET_[CPMS_FDIR_IRRITATE_LARGE_SELECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_IRRITATE_LARGE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_LARGE_SELECT]

//>> GET_[CPMS_FDIR_IRRITATE_LARGE_SELECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_IRRITATE_LARGE_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_IRRITATE_LARGE_SELECT]

//>> SET_[CPMS_FDIR_EXCLUDE_LSU_HALT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_EXCLUDE_LSU_HALT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_EXCLUDE_LSU_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_EXCLUDE_LSU_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_EXCLUDE_LSU_HALT]

//>> SET_[CPMS_FDIR_EXCLUDE_LSU_HALT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_EXCLUDE_LSU_HALT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_FDIR_EXCLUDE_LSU_HALT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_EXCLUDE_LSU_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_EXCLUDE_LSU_HALT]

//>> SET_[CPMS_FDIR_EXCLUDE_LSU_HALT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_EXCLUDE_LSU_HALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_EXCLUDE_LSU_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_EXCLUDE_LSU_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_EXCLUDE_LSU_HALT]

//>> CLEAR_[CPMS_FDIR_EXCLUDE_LSU_HALT]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_EXCLUDE_LSU_HALT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_EXCLUDE_LSU_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_EXCLUDE_LSU_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_EXCLUDE_LSU_HALT]

//>> GET_[CPMS_FDIR_EXCLUDE_LSU_HALT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDIR_EXCLUDE_LSU_HALT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.extractToRight<CPMS_FDIR_EXCLUDE_LSU_HALT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_EXCLUDE_LSU_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_EXCLUDE_LSU_HALT]

//>> GET_[CPMS_FDIR_EXCLUDE_LSU_HALT]
static inline bool GET_CPMS_FDIR_EXCLUDE_LSU_HALT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_EXCLUDE_LSU_HALT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_EXCLUDE_LSU_HALT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_EXCLUDE_LSU_HALT]

//>> SET_[CPMS_FDIR_IRRITATE_WEIGHT_SELECT]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_IRRITATE_WEIGHT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_WEIGHT_SELECT]

//>> SET_[CPMS_FDIR_IRRITATE_WEIGHT_SELECT]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_IRRITATE_WEIGHT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_IRRITATE_WEIGHT_SELECT]

//>> GET_[CPMS_FDIR_IRRITATE_WEIGHT_SELECT]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_IRRITATE_WEIGHT_SELECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_IRRITATE_WEIGHT_SELECT]

//>> SET_[CPMS_FDIR_INJECT_DPT_SUSPEND]
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
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_INJECT_DPT_SUSPEND]

//>> SET_[CPMS_FDIR_INJECT_DPT_SUSPEND]
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
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_INJECT_DPT_SUSPEND]

//>> SET_[CPMS_FDIR_INJECT_DPT_SUSPEND]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDIR_INJECT_DPT_SUSPEND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.setBit<CPMS_FDIR_INJECT_DPT_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDIR_INJECT_DPT_SUSPEND]

//>> CLEAR_[CPMS_FDIR_INJECT_DPT_SUSPEND]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDIR_INJECT_DPT_SUSPEND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return o_data.clearBit<CPMS_FDIR_INJECT_DPT_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDIR_INJECT_DPT_SUSPEND]

//>> GET_[CPMS_FDIR_INJECT_DPT_SUSPEND]
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
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_INJECT_DPT_SUSPEND]

//>> GET_[CPMS_FDIR_INJECT_DPT_SUSPEND]
static inline bool GET_CPMS_FDIR_INJECT_DPT_SUSPEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDIR, CPMS_FDIR_WO_CLEAR, CPMS_FDIR_WO_OR));
#endif
    return i_data.getBit<CPMS_FDIR_INJECT_DPT_SUSPEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDIR_INJECT_DPT_SUSPEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDIR_INJECT_DPT_SUSPEND]

//>> PREP_[EC_PC_TFX_SM]
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
//<< PREP_[EC_PC_TFX_SM]

//>> GET_[EC_PC_TFX_SM]
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
//<< GET_[EC_PC_TFX_SM]

//>> PUT_[EC_PC_TFX_SM]
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
//<< PUT_[EC_PC_TFX_SM]


//>> SET_[EC_PC_TFX_SM_INACTIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_INACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_INACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TFX_SM_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_INACTIVE]

//>> SET_[EC_PC_TFX_SM_INACTIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_INACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_INACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TFX_SM_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_INACTIVE]

//>> SET_[EC_PC_TFX_SM_INACTIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_INACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.setBit<EC_PC_TFX_SM_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TFX_SM_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_INACTIVE]

//>> CLEAR_[EC_PC_TFX_SM_INACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TFX_SM_INACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.clearBit<EC_PC_TFX_SM_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TFX_SM_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TFX_SM_INACTIVE]

//>> GET_[EC_PC_TFX_SM_INACTIVE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TFX_SM_INACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.extractToRight<EC_PC_TFX_SM_INACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TFX_SM_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_INACTIVE]

//>> GET_[EC_PC_TFX_SM_INACTIVE]
static inline bool GET_EC_PC_TFX_SM_INACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.getBit<EC_PC_TFX_SM_INACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TFX_SM_INACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_INACTIVE]

//>> SET_[EC_PC_TFX_SM_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TFX_SM_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_ACTIVE]

//>> SET_[EC_PC_TFX_SM_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TFX_SM_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_ACTIVE]

//>> SET_[EC_PC_TFX_SM_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.setBit<EC_PC_TFX_SM_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TFX_SM_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_ACTIVE]

//>> CLEAR_[EC_PC_TFX_SM_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TFX_SM_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.clearBit<EC_PC_TFX_SM_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TFX_SM_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TFX_SM_ACTIVE]

//>> GET_[EC_PC_TFX_SM_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TFX_SM_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.extractToRight<EC_PC_TFX_SM_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TFX_SM_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_ACTIVE]

//>> GET_[EC_PC_TFX_SM_ACTIVE]
static inline bool GET_EC_PC_TFX_SM_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.getBit<EC_PC_TFX_SM_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TFX_SM_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_ACTIVE]

//>> SET_[EC_PC_TFX_SM_LOAD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_LOAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_LOAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TFX_SM_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_LOAD]

//>> SET_[EC_PC_TFX_SM_LOAD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_LOAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TFX_SM_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_LOAD]

//>> SET_[EC_PC_TFX_SM_LOAD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_LOAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.setBit<EC_PC_TFX_SM_LOAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TFX_SM_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_LOAD]

//>> CLEAR_[EC_PC_TFX_SM_LOAD]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TFX_SM_LOAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.clearBit<EC_PC_TFX_SM_LOAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TFX_SM_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TFX_SM_LOAD]

//>> GET_[EC_PC_TFX_SM_LOAD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TFX_SM_LOAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.extractToRight<EC_PC_TFX_SM_LOAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TFX_SM_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_LOAD]

//>> GET_[EC_PC_TFX_SM_LOAD]
static inline bool GET_EC_PC_TFX_SM_LOAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.getBit<EC_PC_TFX_SM_LOAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TFX_SM_LOAD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_LOAD]

//>> SET_[EC_PC_TFX_SM_SEND]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_SEND(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_SEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TFX_SM_SEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_SEND]

//>> SET_[EC_PC_TFX_SM_SEND]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_SEND(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_SEND,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TFX_SM_SEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_SEND]

//>> SET_[EC_PC_TFX_SM_SEND]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_SEND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.setBit<EC_PC_TFX_SM_SEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TFX_SM_SEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_SEND]

//>> CLEAR_[EC_PC_TFX_SM_SEND]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TFX_SM_SEND(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.clearBit<EC_PC_TFX_SM_SEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TFX_SM_SEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TFX_SM_SEND]

//>> GET_[EC_PC_TFX_SM_SEND]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TFX_SM_SEND(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.extractToRight<EC_PC_TFX_SM_SEND,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TFX_SM_SEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_SEND]

//>> GET_[EC_PC_TFX_SM_SEND]
static inline bool GET_EC_PC_TFX_SM_SEND(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.getBit<EC_PC_TFX_SM_SEND>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TFX_SM_SEND chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_SEND]

//>> SET_[EC_PC_TFX_SM_RECEIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_RECEIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_RECEIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TFX_SM_RECEIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_RECEIVE]

//>> SET_[EC_PC_TFX_SM_RECEIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_RECEIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.insertFromRight<EC_PC_TFX_SM_RECEIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TFX_SM_RECEIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_RECEIVE]

//>> SET_[EC_PC_TFX_SM_RECEIVE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TFX_SM_RECEIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.setBit<EC_PC_TFX_SM_RECEIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TFX_SM_RECEIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TFX_SM_RECEIVE]

//>> CLEAR_[EC_PC_TFX_SM_RECEIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TFX_SM_RECEIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return o_data.clearBit<EC_PC_TFX_SM_RECEIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TFX_SM_RECEIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TFX_SM_RECEIVE]

//>> GET_[EC_PC_TFX_SM_RECEIVE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TFX_SM_RECEIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.extractToRight<EC_PC_TFX_SM_RECEIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TFX_SM_RECEIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_RECEIVE]

//>> GET_[EC_PC_TFX_SM_RECEIVE]
static inline bool GET_EC_PC_TFX_SM_RECEIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TFX_SM));
#endif
    return i_data.getBit<EC_PC_TFX_SM_RECEIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TFX_SM_RECEIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TFX_SM_RECEIVE]

//>> PREP_[L3_MISC_L3CERRS_BACKING_CTL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_BACKING_CTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_BACKING_CTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_BACKING_CTL_REG]

//>> GET_[L3_MISC_L3CERRS_BACKING_CTL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_BACKING_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_BACKING_CTL_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_BACKING_CTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_BACKING_CTL_REG]

//>> PUT_[L3_MISC_L3CERRS_BACKING_CTL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_BACKING_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_BACKING_CTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_BACKING_CTL_REG]


//>> SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]

//>> GET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]
static inline bool GET_L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG]

//>> SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG,
           L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG]

//>> SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG,
           L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG]

//>> GET_[L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_BACKING_CTL_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG,
           L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_BACKING_CTL_REG_BACKING_CNT_CFG]

//>> PREP_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS]
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
//<< PREP_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS]
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
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS]

//>> PUT_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS]
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
//<< PUT_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS]


//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]
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
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]
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
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]
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
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]
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
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]
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
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]
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
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED]
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
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED]
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
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED]
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
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM]
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
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM]
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
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM]
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
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT]
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
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT]
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
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT]
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
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT]

//>> PREP_[QME_CDBB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_CDBB(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    scomt::last_scom = QME_CDBB;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_CDBB]

//>> GET_[QME_CDBB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_CDBB(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    scomt::last_scom = QME_CDBB;
#endif
    return fapi2::getScom(i_target, QME_CDBB, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_CDBB]

//>> PUT_[QME_CDBB]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_CDBB(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_CDBB));
#endif
    return fapi2::putScom(i_target, QME_CDBB, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_CDBB]


//>> SET_[QME_CDBB_MESSAGE_NUMBER]
static inline fapi2::buffer<uint64_t>& SET_QME_CDBB_MESSAGE_NUMBER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_CDBB));
#endif
    return o_data.insertFromRight<QME_CDBB_MESSAGE_NUMBER,
           QME_CDBB_MESSAGE_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CDBB_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CDBB_MESSAGE_NUMBER]

//>> SET_[QME_CDBB_MESSAGE_NUMBER]
static inline fapi2::buffer<uint64_t>& SET_QME_CDBB_MESSAGE_NUMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_CDBB));
#endif
    return o_data.insertFromRight<QME_CDBB_MESSAGE_NUMBER,
           QME_CDBB_MESSAGE_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CDBB_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CDBB_MESSAGE_NUMBER]

//>> GET_[QME_CDBB_MESSAGE_NUMBER]
static inline fapi2::buffer<uint64_t>& GET_QME_CDBB_MESSAGE_NUMBER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_CDBB));
#endif
    return i_data.extractToRight<QME_CDBB_MESSAGE_NUMBER,
           QME_CDBB_MESSAGE_NUMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CDBB_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CDBB_MESSAGE_NUMBER]


//>> PREP_[NC_NCCHTM_NCCHTSC_HTM_LAST]
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
//<< PREP_[NC_NCCHTM_NCCHTSC_HTM_LAST]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_LAST]
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
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_LAST]

//>> PUT_[NC_NCCHTM_NCCHTSC_HTM_LAST]
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
//<< PUT_[NC_NCCHTM_NCCHTSC_HTM_LAST]


//>> SET_[NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS]
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
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS]
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
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS]
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
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
