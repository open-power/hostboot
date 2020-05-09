/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00011.H $            */
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

#ifndef __C_REG00011_H_
#define __C_REG00011_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_DHDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DHDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DHDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DHDR]

//>> GET_[CPMS_DHDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DHDR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DHDR;
#endif
    return fapi2::getScom(i_target, CPMS_DHDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DHDR]

//>> PUT_[CPMS_DHDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DHDR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return fapi2::putScom(i_target, CPMS_DHDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DHDR]


//>> SET_[CPMS_DHDR_FTC_EVENT_HISTORY0]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_FTC_EVENT_HISTORY0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_FTC_EVENT_HISTORY0,
           CPMS_DHDR_FTC_EVENT_HISTORY0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_FTC_EVENT_HISTORY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_FTC_EVENT_HISTORY0]

//>> SET_[CPMS_DHDR_FTC_EVENT_HISTORY0]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_FTC_EVENT_HISTORY0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_FTC_EVENT_HISTORY0,
           CPMS_DHDR_FTC_EVENT_HISTORY0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_FTC_EVENT_HISTORY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_FTC_EVENT_HISTORY0]

//>> GET_[CPMS_DHDR_FTC_EVENT_HISTORY0]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_FTC_EVENT_HISTORY0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_FTC_EVENT_HISTORY0,
           CPMS_DHDR_FTC_EVENT_HISTORY0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_FTC_EVENT_HISTORY0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_FTC_EVENT_HISTORY0]

//>> SET_[CPMS_DHDR_FTC_EVENT_HISTORY1]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_FTC_EVENT_HISTORY1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_FTC_EVENT_HISTORY1,
           CPMS_DHDR_FTC_EVENT_HISTORY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_FTC_EVENT_HISTORY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_FTC_EVENT_HISTORY1]

//>> SET_[CPMS_DHDR_FTC_EVENT_HISTORY1]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_FTC_EVENT_HISTORY1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_FTC_EVENT_HISTORY1,
           CPMS_DHDR_FTC_EVENT_HISTORY1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_FTC_EVENT_HISTORY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_FTC_EVENT_HISTORY1]

//>> GET_[CPMS_DHDR_FTC_EVENT_HISTORY1]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_FTC_EVENT_HISTORY1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_FTC_EVENT_HISTORY1,
           CPMS_DHDR_FTC_EVENT_HISTORY1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_FTC_EVENT_HISTORY1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_FTC_EVENT_HISTORY1]

//>> SET_[CPMS_DHDR_FTC_EVENT_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_FTC_EVENT_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_FTC_EVENT_DATA,
           CPMS_DHDR_FTC_EVENT_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_FTC_EVENT_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_FTC_EVENT_DATA]

//>> SET_[CPMS_DHDR_FTC_EVENT_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_FTC_EVENT_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_FTC_EVENT_DATA,
           CPMS_DHDR_FTC_EVENT_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_FTC_EVENT_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_FTC_EVENT_DATA]

//>> GET_[CPMS_DHDR_FTC_EVENT_DATA]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_FTC_EVENT_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_FTC_EVENT_DATA,
           CPMS_DHDR_FTC_EVENT_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_FTC_EVENT_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_FTC_EVENT_DATA]

//>> SET_[CPMS_DHDR_FTC_RAW_EVENT_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_FTC_RAW_EVENT_HISTORY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_FTC_RAW_EVENT_HISTORY,
           CPMS_DHDR_FTC_RAW_EVENT_HISTORY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_FTC_RAW_EVENT_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_FTC_RAW_EVENT_HISTORY]

//>> SET_[CPMS_DHDR_FTC_RAW_EVENT_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_FTC_RAW_EVENT_HISTORY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_FTC_RAW_EVENT_HISTORY,
           CPMS_DHDR_FTC_RAW_EVENT_HISTORY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_FTC_RAW_EVENT_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_FTC_RAW_EVENT_HISTORY]

//>> GET_[CPMS_DHDR_FTC_RAW_EVENT_HISTORY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_FTC_RAW_EVENT_HISTORY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_FTC_RAW_EVENT_HISTORY,
           CPMS_DHDR_FTC_RAW_EVENT_HISTORY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_FTC_RAW_EVENT_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_FTC_RAW_EVENT_HISTORY]

//>> SET_[CPMS_DHDR_ADJ_WARN_EVENT_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_ADJ_WARN_EVENT_HISTORY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_ADJ_WARN_EVENT_HISTORY,
           CPMS_DHDR_ADJ_WARN_EVENT_HISTORY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_ADJ_WARN_EVENT_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_ADJ_WARN_EVENT_HISTORY]

//>> SET_[CPMS_DHDR_ADJ_WARN_EVENT_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_ADJ_WARN_EVENT_HISTORY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_ADJ_WARN_EVENT_HISTORY,
           CPMS_DHDR_ADJ_WARN_EVENT_HISTORY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_ADJ_WARN_EVENT_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_ADJ_WARN_EVENT_HISTORY]

//>> GET_[CPMS_DHDR_ADJ_WARN_EVENT_HISTORY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_ADJ_WARN_EVENT_HISTORY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_ADJ_WARN_EVENT_HISTORY,
           CPMS_DHDR_ADJ_WARN_EVENT_HISTORY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_ADJ_WARN_EVENT_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_ADJ_WARN_EVENT_HISTORY]

//>> SET_[CPMS_DHDR_ADJ_WARN_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_ADJ_WARN_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_ADJ_WARN_ACTIVE,
           CPMS_DHDR_ADJ_WARN_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_ADJ_WARN_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_ADJ_WARN_ACTIVE]

//>> SET_[CPMS_DHDR_ADJ_WARN_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_ADJ_WARN_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_ADJ_WARN_ACTIVE,
           CPMS_DHDR_ADJ_WARN_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_ADJ_WARN_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_ADJ_WARN_ACTIVE]

//>> GET_[CPMS_DHDR_ADJ_WARN_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_ADJ_WARN_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_ADJ_WARN_ACTIVE,
           CPMS_DHDR_ADJ_WARN_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_ADJ_WARN_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_ADJ_WARN_ACTIVE]

//>> SET_[CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA,
           CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA]

//>> SET_[CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA,
           CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA]

//>> GET_[CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA,
           CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA]

//>> SET_[CPMS_DHDR_CPMS_DDSR_DDS_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_DDS_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_CPMS_DDSR_DDS_DATA,
           CPMS_DHDR_CPMS_DDSR_DDS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_DDS_DATA]

//>> SET_[CPMS_DHDR_CPMS_DDSR_DDS_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_DDS_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_CPMS_DDSR_DDS_DATA,
           CPMS_DHDR_CPMS_DDSR_DDS_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_DDS_DATA]

//>> GET_[CPMS_DHDR_CPMS_DDSR_DDS_DATA]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_CPMS_DDSR_DDS_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_CPMS_DDSR_DDS_DATA,
           CPMS_DHDR_CPMS_DDSR_DDS_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_DDS_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_CPMS_DDSR_DDS_DATA]

//>> SET_[CPMS_DHDR_DPLL_ENCODED_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_DPLL_ENCODED_MIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_DPLL_ENCODED_MIN,
           CPMS_DHDR_DPLL_ENCODED_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_DPLL_ENCODED_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_DPLL_ENCODED_MIN]

//>> SET_[CPMS_DHDR_DPLL_ENCODED_MIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_DPLL_ENCODED_MIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_DPLL_ENCODED_MIN,
           CPMS_DHDR_DPLL_ENCODED_MIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_DPLL_ENCODED_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_DPLL_ENCODED_MIN]

//>> GET_[CPMS_DHDR_DPLL_ENCODED_MIN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_DPLL_ENCODED_MIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_DPLL_ENCODED_MIN,
           CPMS_DHDR_DPLL_ENCODED_MIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_DPLL_ENCODED_MIN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_DPLL_ENCODED_MIN]

//>> SET_[CPMS_DHDR_MIN_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_MIN_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_MIN_DATA,
           CPMS_DHDR_MIN_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_MIN_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_MIN_DATA]

//>> SET_[CPMS_DHDR_MIN_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_MIN_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_MIN_DATA,
           CPMS_DHDR_MIN_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_MIN_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_MIN_DATA]

//>> GET_[CPMS_DHDR_MIN_DATA]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_MIN_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_MIN_DATA,
           CPMS_DHDR_MIN_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_MIN_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_MIN_DATA]

//>> SET_[CPMS_DHDR_DPLL_ENCODED_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_DPLL_ENCODED_MAX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_DPLL_ENCODED_MAX,
           CPMS_DHDR_DPLL_ENCODED_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_DPLL_ENCODED_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_DPLL_ENCODED_MAX]

//>> SET_[CPMS_DHDR_DPLL_ENCODED_MAX]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_DPLL_ENCODED_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_DPLL_ENCODED_MAX,
           CPMS_DHDR_DPLL_ENCODED_MAX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_DPLL_ENCODED_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_DPLL_ENCODED_MAX]

//>> GET_[CPMS_DHDR_DPLL_ENCODED_MAX]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_DPLL_ENCODED_MAX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_DPLL_ENCODED_MAX,
           CPMS_DHDR_DPLL_ENCODED_MAX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_DPLL_ENCODED_MAX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_DPLL_ENCODED_MAX]

//>> SET_[CPMS_DHDR_MAX_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_MAX_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_MAX_DATA,
           CPMS_DHDR_MAX_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_MAX_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_MAX_DATA]

//>> SET_[CPMS_DHDR_MAX_DATA]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_MAX_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_MAX_DATA,
           CPMS_DHDR_MAX_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_MAX_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_MAX_DATA]

//>> GET_[CPMS_DHDR_MAX_DATA]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_MAX_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_MAX_DATA,
           CPMS_DHDR_MAX_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_MAX_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_MAX_DATA]

//>> SET_[CPMS_DHDR_DDP_EVENT_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_DDP_EVENT_HISTORY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_DDP_EVENT_HISTORY,
           CPMS_DHDR_DDP_EVENT_HISTORY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_DDP_EVENT_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_DDP_EVENT_HISTORY]

//>> SET_[CPMS_DHDR_DDP_EVENT_HISTORY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_DDP_EVENT_HISTORY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_DDP_EVENT_HISTORY,
           CPMS_DHDR_DDP_EVENT_HISTORY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_DDP_EVENT_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_DDP_EVENT_HISTORY]

//>> GET_[CPMS_DHDR_DDP_EVENT_HISTORY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_DDP_EVENT_HISTORY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_DDP_EVENT_HISTORY,
           CPMS_DHDR_DDP_EVENT_HISTORY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_DDP_EVENT_HISTORY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_DDP_EVENT_HISTORY]

//>> SET_[CPMS_DHDR_DDP_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_DDP_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_DDP_ACTIVE,
           CPMS_DHDR_DDP_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_DDP_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_DDP_ACTIVE]

//>> SET_[CPMS_DHDR_DDP_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_DDP_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_DDP_ACTIVE,
           CPMS_DHDR_DDP_ACTIVE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_DDP_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_DDP_ACTIVE]

//>> GET_[CPMS_DHDR_DDP_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_DDP_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_DDP_ACTIVE,
           CPMS_DHDR_DDP_ACTIVE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_DDP_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_DDP_ACTIVE]

//>> SET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]

//>> SET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]

//>> SET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.setBit<CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]

//>> CLEAR_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.clearBit<CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]

//>> GET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]

//>> GET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]
static inline bool GET_CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.getBit<CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE]

//>> SET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> SET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> SET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.setBit<CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> CLEAR_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.clearBit<CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> GET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> GET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]
static inline bool GET_CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.getBit<CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED]

//>> SET_[CPMS_DHDR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_DHDR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_STOP_STATE_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_STOP_STATE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_DHDR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.setBit<CPMS_DHDR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DHDR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_STOP_STATE_OCCURRED]

//>> CLEAR_[CPMS_DHDR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHDR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.clearBit<CPMS_DHDR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DHDR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DHDR_STOP_STATE_OCCURRED]

//>> GET_[CPMS_DHDR_STOP_STATE_OCCURRED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_STOP_STATE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_STOP_STATE_OCCURRED]

//>> GET_[CPMS_DHDR_STOP_STATE_OCCURRED]
static inline bool GET_CPMS_DHDR_STOP_STATE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.getBit<CPMS_DHDR_STOP_STATE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DHDR_STOP_STATE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_STOP_STATE_OCCURRED]

//>> SET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_SAMPLE_DISABLE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DHDR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]

//>> SET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_SAMPLE_DISABLE_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.insertFromRight<CPMS_DHDR_SAMPLE_DISABLE_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DHDR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]

//>> SET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DHDR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.setBit<CPMS_DHDR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DHDR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]

//>> CLEAR_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DHDR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return o_data.clearBit<CPMS_DHDR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DHDR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]

//>> GET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DHDR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.extractToRight<CPMS_DHDR_SAMPLE_DISABLE_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DHDR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]

//>> GET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]
static inline bool GET_CPMS_DHDR_SAMPLE_DISABLE_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DHDR));
#endif
    return i_data.getBit<CPMS_DHDR_SAMPLE_DISABLE_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DHDR_SAMPLE_DISABLE_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DHDR_SAMPLE_DISABLE_OCCURRED]

//>> PREP_[CPMS_L3_PFETSTAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_L3_PFETSTAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_L3_PFETSTAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_L3_PFETSTAT]

//>> GET_[CPMS_L3_PFETSTAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_L3_PFETSTAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_L3_PFETSTAT;
#endif
    return fapi2::getScom(i_target, CPMS_L3_PFETSTAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT]

//>> PUT_[CPMS_L3_PFETSTAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_L3_PFETSTAT(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return fapi2::putScom(i_target, CPMS_L3_PFETSTAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_L3_PFETSTAT]


//>> SET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.setBit<CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> CLEAR_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.clearBit<CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]
static inline bool GET_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.getBit<CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.setBit<CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> CLEAR_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.clearBit<CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]
static inline bool GET_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.getBit<CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.setBit<CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> CLEAR_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.clearBit<CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> GET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]
static inline bool GET_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.getBit<CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.setBit<CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> CLEAR_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.clearBit<CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> GET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]
static inline bool GET_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.getBit<CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE]

//>> SET_[CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL,
           CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL]

//>> SET_[CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL,
           CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL]

//>> GET_[CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL,
           CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL]

//>> SET_[CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL,
           CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL]

//>> SET_[CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL,
           CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL]

//>> GET_[CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL,
           CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL]

//>> SET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]

//>> SET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]

//>> SET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.setBit<CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]

//>> CLEAR_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.clearBit<CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]

//>> GET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.extractToRight<CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]

//>> GET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]
static inline bool GET_CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.getBit<CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL]

//>> PREP_[CPMS_WPMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_WPMR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPMR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_WPMR]

//>> GET_[CPMS_WPMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_WPMR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPMR;
#endif
    return fapi2::getScom(i_target, CPMS_WPMR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_WPMR]

//>> PUT_[CPMS_WPMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_WPMR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_WPMR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_WPMR]

//>> PREP_[CPMS_WPMR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_WPMR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPMR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_WPMR_SCOM2]

//>> GET_[CPMS_WPMR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_WPMR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPMR_SCOM2;
#endif
    return fapi2::getScom(i_target, CPMS_WPMR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_WPMR_SCOM2]

//>> PUT_[CPMS_WPMR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_WPMR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_WPMR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_WPMR_SCOM2]

//>> PREP_[CPMS_WPMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_WPMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPMR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_WPMR_WO_CLEAR]

//>> GET_[CPMS_WPMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_WPMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_WPMR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_WPMR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_WPMR_WO_CLEAR]

//>> PUT_[CPMS_WPMR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_WPMR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_WPMR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_WPMR_WO_CLEAR]


//>> SET_[CPMS_WPMR_PITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_PITCH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_PITCH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPMR_PITCH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_PITCH_ENABLE]

//>> SET_[CPMS_WPMR_PITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_PITCH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_PITCH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPMR_PITCH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_PITCH_ENABLE]

//>> SET_[CPMS_WPMR_PITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_PITCH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_WPMR_PITCH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPMR_PITCH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_PITCH_ENABLE]

//>> CLEAR_[CPMS_WPMR_PITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPMR_PITCH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_WPMR_PITCH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPMR_PITCH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPMR_PITCH_ENABLE]

//>> GET_[CPMS_WPMR_PITCH_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPMR_PITCH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_WPMR_PITCH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPMR_PITCH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_PITCH_ENABLE]

//>> GET_[CPMS_WPMR_PITCH_ENABLE]
static inline bool GET_CPMS_WPMR_PITCH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_WPMR_PITCH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPMR_PITCH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_PITCH_ENABLE]

//>> SET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]

//>> SET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]

//>> SET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]

//>> CLEAR_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]

//>> GET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]

//>> GET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]
static inline bool GET_CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE]

//>> SET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]

//>> SET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]

//>> SET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]

//>> CLEAR_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]

//>> GET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]

//>> GET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]
static inline bool GET_CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE]

//>> SET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_PITCH_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_PITCH_INTERRUPT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPMR_PITCH_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]

//>> SET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_PITCH_INTERRUPT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_PITCH_INTERRUPT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPMR_PITCH_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]

//>> SET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_PITCH_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_WPMR_PITCH_INTERRUPT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPMR_PITCH_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]

//>> CLEAR_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPMR_PITCH_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_WPMR_PITCH_INTERRUPT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPMR_PITCH_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]

//>> GET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPMR_PITCH_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_WPMR_PITCH_INTERRUPT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPMR_PITCH_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]

//>> GET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]
static inline bool GET_CPMS_WPMR_PITCH_INTERRUPT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_WPMR_PITCH_INTERRUPT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPMR_PITCH_INTERRUPT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_PITCH_INTERRUPT_ENABLE]

//>> SET_[CPMS_WPMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_SPARE,
           CPMS_WPMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_SPARE]

//>> SET_[CPMS_WPMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_SPARE,
           CPMS_WPMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_SPARE]

//>> GET_[CPMS_WPMR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_WPMR_SPARE,
           CPMS_WPMR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_SPARE]

//>> SET_[CPMS_WPMR_PITCH_PERIOD_TIME]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_PITCH_PERIOD_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_PITCH_PERIOD_TIME,
           CPMS_WPMR_PITCH_PERIOD_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPMR_PITCH_PERIOD_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_PITCH_PERIOD_TIME]

//>> SET_[CPMS_WPMR_PITCH_PERIOD_TIME]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_PITCH_PERIOD_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_PITCH_PERIOD_TIME,
           CPMS_WPMR_PITCH_PERIOD_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPMR_PITCH_PERIOD_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_PITCH_PERIOD_TIME]

//>> GET_[CPMS_WPMR_PITCH_PERIOD_TIME]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPMR_PITCH_PERIOD_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_WPMR_PITCH_PERIOD_TIME,
           CPMS_WPMR_PITCH_PERIOD_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPMR_PITCH_PERIOD_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_PITCH_PERIOD_TIME]

//>> SET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_RESET_ACTIVITY_PROXY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]

//>> SET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ACTIVITY_PROXY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_RESET_ACTIVITY_PROXY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]

//>> SET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_WPMR_RESET_ACTIVITY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]

//>> CLEAR_[CPMS_WPMR_RESET_ACTIVITY_PROXY]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPMR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_WPMR_RESET_ACTIVITY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPMR_RESET_ACTIVITY_PROXY]

//>> GET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPMR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_WPMR_RESET_ACTIVITY_PROXY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]

//>> GET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]
static inline bool GET_CPMS_WPMR_RESET_ACTIVITY_PROXY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_WPMR_RESET_ACTIVITY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPMR_RESET_ACTIVITY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_RESET_ACTIVITY_PROXY]

//>> SET_[CPMS_WPMR_RESET_ENERGY_PROXY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_RESET_ENERGY_PROXY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ENERGY_PROXY]

//>> SET_[CPMS_WPMR_RESET_ENERGY_PROXY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ENERGY_PROXY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_WPMR_RESET_ENERGY_PROXY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ENERGY_PROXY]

//>> SET_[CPMS_WPMR_RESET_ENERGY_PROXY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_WPMR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_WPMR_RESET_ENERGY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_WPMR_RESET_ENERGY_PROXY]

//>> CLEAR_[CPMS_WPMR_RESET_ENERGY_PROXY]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_WPMR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_WPMR_RESET_ENERGY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_WPMR_RESET_ENERGY_PROXY]

//>> GET_[CPMS_WPMR_RESET_ENERGY_PROXY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_WPMR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_WPMR_RESET_ENERGY_PROXY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_RESET_ENERGY_PROXY]

//>> GET_[CPMS_WPMR_RESET_ENERGY_PROXY]
static inline bool GET_CPMS_WPMR_RESET_ENERGY_PROXY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_WPMR, CPMS_WPMR_SCOM2, CPMS_WPMR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_WPMR_RESET_ENERGY_PROXY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_WPMR_RESET_ENERGY_PROXY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_WPMR_RESET_ENERGY_PROXY]

//>> PREP_[EC_LS_LSU_HOLD_OUT_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_LS_LSU_HOLD_OUT_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_LS_LSU_HOLD_OUT_REG2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_LS_LSU_HOLD_OUT_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_LS_LSU_HOLD_OUT_REG2;
#endif
    return fapi2::getScom(i_target, EC_LS_LSU_HOLD_OUT_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2]

//>> PUT_[EC_LS_LSU_HOLD_OUT_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_LS_LSU_HOLD_OUT_REG2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return fapi2::putScom(i_target, EC_LS_LSU_HOLD_OUT_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_LS_LSU_HOLD_OUT_REG2]


//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_0_SETP_PERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET0]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET1]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET2]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET3]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET4]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET5]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET6]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.insertFromRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]

//>> SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& SET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.setBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]

//>> CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return o_data.clearBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]
static inline fapi2::buffer<uint64_t>& GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.extractToRight<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]

//>> GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]
static inline bool GET_EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_LS_LSU_HOLD_OUT_REG2));
#endif
    return i_data.getBit<EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_LS_LSU_HOLD_OUT_REG2_1_SETP_PERR_HOLD_OUT_SET7]

//>> PREP_[EC_PC_COMMON_SPR_SPATTN_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_SPATTN_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SPATTN_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_SPATTN_RW]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_SPATTN_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SPATTN_RW;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_SPATTN_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_RW]

//>> PUT_[EC_PC_COMMON_SPR_SPATTN_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_SPATTN_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_SPATTN_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_SPATTN_RW]

//>> PREP_[EC_PC_COMMON_SPR_SPATTN_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_SPATTN_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SPATTN_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_SPATTN_WO_AND]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_SPATTN_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SPATTN_WO_AND;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_SPATTN_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_WO_AND]

//>> PUT_[EC_PC_COMMON_SPR_SPATTN_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_SPATTN_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_SPATTN_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_SPATTN_WO_AND]

//>> PREP_[EC_PC_COMMON_SPR_SPATTN_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_COMMON_SPR_SPATTN_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SPATTN_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_COMMON_SPR_SPATTN_WO_OR]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_COMMON_SPR_SPATTN_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_COMMON_SPR_SPATTN_WO_OR;
#endif
    return fapi2::getScom(i_target, EC_PC_COMMON_SPR_SPATTN_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_WO_OR]

//>> PUT_[EC_PC_COMMON_SPR_SPATTN_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_COMMON_SPR_SPATTN_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return fapi2::putScom(i_target, EC_PC_COMMON_SPR_SPATTN_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_COMMON_SPR_SPATTN_WO_OR]


//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_0_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_0_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_0_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_1_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_1_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_1_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_2_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_2_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_2_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_3_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_3_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_3_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_4_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_4_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_4_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_5_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_5_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_5_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_6_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_6_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_6_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_7_SPR_INSTR_STOP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_7_ATTN_COMPLETE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CHECKSTOP_RECOVERY_HANDSHAKE]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.insertFromRight<EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]

//>> SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.setBit<EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]

//>> CLEAR_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return o_data.clearBit<EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.extractToRight<EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]

//>> GET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]
static inline bool GET_EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_COMMON_SPR_SPATTN_RW, EC_PC_COMMON_SPR_SPATTN_WO_AND, EC_PC_COMMON_SPR_SPATTN_WO_OR));
#endif
    return i_data.getBit<EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_COMMON_SPR_SPATTN_7_CORE_CODE_TO_SP]

//>> PREP_[EC_PC_FIR_CORE_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_ACTION0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_ACTION0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_FIR_CORE_ACTION0]

//>> GET_[EC_PC_FIR_CORE_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_ACTION0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_ACTION0;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_ACTION0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0]

//>> PUT_[EC_PC_FIR_CORE_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_ACTION0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_ACTION0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_FIR_CORE_ACTION0]


//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_6]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_10]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_20]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_27]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_39]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_40]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_42]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_44]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_48]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_49]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_50]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_51]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_UNUSED_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]

//>> SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_UNUSED_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_UNUSED_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_UNUSED_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_UNUSED_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_UNUSED_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_UNUSED_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]

//>> GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_UNUSED_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_UNUSED_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_UNUSED_54]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_ACTION0_PC_PHYP_XSTOP_ERROR]

//>> PREP_[EC_PC_PMU_SPRCOR_SCOMC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PMU_SPRCOR_SCOMC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_SCOMC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_PMU_SPRCOR_SCOMC]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PMU_SPRCOR_SCOMC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_SCOMC;
#endif
    return fapi2::getScom(i_target, EC_PC_PMU_SPRCOR_SCOMC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC]

//>> PUT_[EC_PC_PMU_SPRCOR_SCOMC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PMU_SPRCOR_SCOMC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return fapi2::putScom(i_target, EC_PC_PMU_SPRCOR_SCOMC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_PMU_SPRCOR_SCOMC]


//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_PMC1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_PMC1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_PMC1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_PMC1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_PMC1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_PMC1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_PMC1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC1]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_PMC2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_PMC2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_PMC2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_PMC2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_PMC2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_PMC2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_PMC2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC2]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_PMC3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_PMC3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_PMC3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_PMC3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_PMC3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_PMC3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_PMC3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC3]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_PMC4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_PMC4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_PMC4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_PMC4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_PMC4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_PMC4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_PMC4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC4]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_PMC5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_PMC5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_PMC5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_PMC5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_PMC5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_PMC5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_PMC5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC5]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_PMC6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_PMC6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_PMC6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_PMC6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_PMC6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_PMC6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_PMC6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_PMC6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_PMC6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_PMC6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_PMC6]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCRC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCRC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCRC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_MMCRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_MMCRC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_MMCRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_MMCRC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_MMCRC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_MMCRC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_MMCRC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRC]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_MMCR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_MMCR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_MMCR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR0]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_MMCR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_MMCR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_MMCR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR1]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_MMCR2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_MMCR2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_MMCR2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR2]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_MMCR3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_MMCR3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_MMCR3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_MMCR3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_MMCR3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCR3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCR3]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCRA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCRA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCRA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_MMCRA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_MMCRA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_MMCRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_MMCRA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_MMCRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_MMCRA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_MMCRA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_MMCRA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_MMCRA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_MMCRA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_MMCRA]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_SIER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_SIER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_SIER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_SIER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_SIER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_SIER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_SIER]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_SIER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_SIER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_SIER]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_SIER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_SIER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_SIER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_SIER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_SIER]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_SIERA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_SIERA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_SIERA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_SIERA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_SIERA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_SIERA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_SIERA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_SIERA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_SIERA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_SIERA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_SIERA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_SIERA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_SIERA]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_SIERB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_SIERB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_SIERB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_SIERB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_SIERB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_SCOMC_SIERB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]

//>> CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_SCOMC_SIERB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_SCOMC_SIERB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_SIERB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_SIERB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]
static inline bool GET_EC_PC_PMU_SPRCOR_SCOMC_SIERB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_SCOMC_SIERB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_SIERB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_SIERB]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID,
           EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID]

//>> SET_[EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID,
           EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID]

//>> GET_[EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_SCOMC));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID,
           EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_SCOMC_THREAD_ID]

//>> PREP_[EC_PC_SCR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SCR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_SCR0]

//>> GET_[EC_PC_SCR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SCR0(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SCR0;
#endif
    return fapi2::getScom(i_target, EC_PC_SCR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_SCR0]

//>> PUT_[EC_PC_SCR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SCR0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SCR0));
#endif
    return fapi2::putScom(i_target, EC_PC_SCR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_SCR0]


//>> PREP_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_SPURR_FREQ_DETECT_CYC_CNT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SPURR_FREQ_DETECT_CYC_CNT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT]

//>> GET_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_SPURR_FREQ_DETECT_CYC_CNT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_SPURR_FREQ_DETECT_CYC_CNT;
#endif
    return fapi2::getScom(i_target, EC_PC_SPURR_FREQ_DETECT_CYC_CNT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT]

//>> PUT_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_SPURR_FREQ_DETECT_CYC_CNT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_DETECT_CYC_CNT));
#endif
    return fapi2::putScom(i_target, EC_PC_SPURR_FREQ_DETECT_CYC_CNT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT]


//>> SET_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_DETECT_CYC_CNT));
#endif
    return o_data.insertFromRight<EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT,
           EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT]

//>> SET_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_DETECT_CYC_CNT));
#endif
    return o_data.insertFromRight<EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT,
           EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT]

//>> GET_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_SPURR_FREQ_DETECT_CYC_CNT));
#endif
    return i_data.extractToRight<EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT,
           EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT]

//>> PREP_[EC_PC_TRACE1_TR_TR0_CONFIG_9]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE1_TR_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_CONFIG_9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE1_TR_TR0_CONFIG_9]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE1_TR_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE1_TR_TR0_CONFIG_9;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE1_TR_TR0_CONFIG_9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9]

//>> PUT_[EC_PC_TRACE1_TR_TR0_CONFIG_9]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE1_TR_TR0_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE1_TR_TR0_CONFIG_9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE1_TR_TR0_CONFIG_9]


//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DISABLE_COMPRESSION]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHA_MUXSEL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHB_MUXSEL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHC_MUXSEL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCHD_MUXSEL]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_OR_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_AND_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_OR_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_AND_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_NOT_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_NOT_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE,
           EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_MATCH_NOT_MODE]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_MASK]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_ERROR_CMP_PATTERN]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG0_ERR_CMP]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_TRIG1_ERR_CMP]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.insertFromRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]

//>> SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.setBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]

//>> CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return o_data.clearBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.extractToRight<EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]

//>> GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]
static inline bool GET_EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE1_TR_TR0_CONFIG_9));
#endif
    return i_data.getBit<EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE1_TR_TR0_CONFIG_9_SPARE_LT]

//>> PREP_[EC_PC_TRACE2_TR_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE2_TR_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE2_TR_TR0_CONFIG_2]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE2_TR_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_CONFIG_2;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE2_TR_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_2]

//>> PUT_[EC_PC_TRACE2_TR_TR0_CONFIG_2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE2_TR_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_2));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE2_TR_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE2_TR_TR0_CONFIG_2]


//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_2_A,
           EC_PC_TRACE2_TR_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_A]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_2_A,
           EC_PC_TRACE2_TR_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_A]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_A]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_CONFIG_2_A,
           EC_PC_TRACE2_TR_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_A]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_2_B,
           EC_PC_TRACE2_TR_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_B]

//>> SET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_CONFIG_2_B,
           EC_PC_TRACE2_TR_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_B]

//>> GET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_B]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_CONFIG_2_B,
           EC_PC_TRACE2_TR_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_CONFIG_2_B]

//>> PREP_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_SD_SDP_SDCR_UNIT_HOLD_OUT3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_SD_SDP_SDCR_UNIT_HOLD_OUT3;
#endif
    return fapi2::getScom(i_target, EC_SD_SDP_SDCR_UNIT_HOLD_OUT3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3]

//>> PUT_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return fapi2::putScom(i_target, EC_SD_SDP_SDCR_UNIT_HOLD_OUT3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3]


//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDP_WAT_T3_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_0]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_1]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_2]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_3]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_RCOV_HOLD_OUT_4]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_0]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_1]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_2]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_3]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_4]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDE_XSTOP_HOLD_OUT_5]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_SDD_STFTAG_HANG_HOLD_OUT]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED13]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED14]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.insertFromRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]

//>> SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]
static inline fapi2::buffer<uint64_t>& SET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.setBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]

//>> CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return o_data.clearBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]
static inline fapi2::buffer<uint64_t>& GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.extractToRight<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]

//>> GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]
static inline bool GET_EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_SD_SDP_SDCR_UNIT_HOLD_OUT3));
#endif
    return i_data.getBit<EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_SD_SDP_SDCR_UNIT_HOLD_OUT3_UNUSED15]

//>> PREP_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG]

//>> GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG]

//>> PUT_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG]


//>> SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]

//>> SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]

//>> SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]

//>> CLEAR_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]

//>> GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]

//>> GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]
static inline bool GET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG]

//>> SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]

//>> SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]

//>> SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]

//>> CLEAR_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]

//>> GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]

//>> GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]
static inline bool GET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE]

//>> SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE,
           L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE]

//>> SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE,
           L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE]

//>> GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE,
           L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE]

//>> PREP_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_RD_EPSILON_CFG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG]

//>> GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_RD_EPSILON_CFG_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_RD_EPSILON_CFG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG]

//>> PUT_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_RD_EPSILON_CFG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG]


//>> SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL,
           L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL]

//>> SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL,
           L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL]

//>> GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL,
           L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL]

//>> SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL,
           L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL]

//>> SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL,
           L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL]

//>> GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL,
           L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL]

//>> SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL,
           L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL]

//>> SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL,
           L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL]

//>> GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL,
           L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL]

//>> SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]

//>> SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]

//>> GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]

//>> GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]
static inline bool GET_L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_RD_EPSILON_CFG_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG]

//>> PREP_[NC_NCCHTM_NCCHTSC_HTM_MEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_HTM_MEM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_MEM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCCHTM_NCCHTSC_HTM_MEM]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_HTM_MEM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_HTM_MEM;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_HTM_MEM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM]

//>> PUT_[NC_NCCHTM_NCCHTSC_HTM_MEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_HTM_MEM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_HTM_MEM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCCHTM_NCCHTSC_HTM_MEM]


//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.setBit<NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]

//>> CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.clearBit<NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]
static inline bool GET_NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.getBit<NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_BASE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_BASE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_BASE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_BASE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_BASE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_BASE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_BASE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MEM_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MEM_BASE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_BASE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE]

//>> SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE]
static inline fapi2::buffer<uint64_t>& SET_NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return o_data.insertFromRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE]

//>> GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE]
static inline fapi2::buffer<uint64_t>& GET_NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_HTM_MEM));
#endif
    return i_data.extractToRight<NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE,
           NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE]

//>> PREP_[NC_NCCHTM_NCCHTSC_MEM_OP_CTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCCHTM_NCCHTSC_MEM_OP_CTR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_MEM_OP_CTR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCCHTM_NCCHTSC_MEM_OP_CTR]

//>> GET_[NC_NCCHTM_NCCHTSC_MEM_OP_CTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCCHTM_NCCHTSC_MEM_OP_CTR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCCHTM_NCCHTSC_MEM_OP_CTR;
#endif
    return fapi2::getScom(i_target, NC_NCCHTM_NCCHTSC_MEM_OP_CTR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCCHTM_NCCHTSC_MEM_OP_CTR]

//>> PUT_[NC_NCCHTM_NCCHTSC_MEM_OP_CTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCCHTM_NCCHTSC_MEM_OP_CTR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCCHTM_NCCHTSC_MEM_OP_CTR));
#endif
    return fapi2::putScom(i_target, NC_NCCHTM_NCCHTSC_MEM_OP_CTR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCCHTM_NCCHTSC_MEM_OP_CTR]


//>> PREP_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1;
#endif
    return fapi2::getScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1]

//>> PUT_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return fapi2::putScom(i_target, NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1]


//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.setBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]

//>> CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]
static inline fapi2::buffer<uint64_t>& CLEAR_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.clearBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]
static inline bool GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.getBit<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15]

//>> SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15]
static inline fapi2::buffer<uint64_t>& SET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return o_data.insertFromRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15]

//>> GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15]
static inline fapi2::buffer<uint64_t>& GET_NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1));
#endif
    return i_data.extractToRight<NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15,
           NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15]

//>> PREP_[QME_PSCRS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PSCRS1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PSCRS1]

//>> GET_[QME_PSCRS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PSCRS1(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PSCRS1;
#endif
    return fapi2::getScom(i_target, QME_PSCRS1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PSCRS1]

//>> PUT_[QME_PSCRS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PSCRS1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return fapi2::putScom(i_target, QME_PSCRS1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PSCRS1]


//>> SET_[QME_PSCRS1_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_DPDES_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_DPDES_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_DPDES_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS1_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_DPDES_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_DPDES_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_DPDES_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_DPDES_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_DPDES_EXIT_ENABLE]
static inline bool GET_QME_PSCRS1_DPDES_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_DPDES_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_DPDES_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_DPDES_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_SD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_SD]

//>> SET_[QME_PSCRS1_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_SD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_SD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_SD]

//>> SET_[QME_PSCRS1_SD]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_SD]

//>> CLEAR_[QME_PSCRS1_SD]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_SD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_SD]

//>> GET_[QME_PSCRS1_SD]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_SD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_SD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_SD]

//>> GET_[QME_PSCRS1_SD]
static inline bool GET_QME_PSCRS1_SD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_SD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_SD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_SD]

//>> SET_[QME_PSCRS1_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_ESL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_ESL]

//>> SET_[QME_PSCRS1_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_ESL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_ESL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_ESL]

//>> SET_[QME_PSCRS1_ESL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_ESL]

//>> CLEAR_[QME_PSCRS1_ESL]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_ESL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_ESL]

//>> GET_[QME_PSCRS1_ESL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_ESL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_ESL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_ESL]

//>> GET_[QME_PSCRS1_ESL]
static inline bool GET_QME_PSCRS1_ESL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_ESL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_ESL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_ESL]

//>> SET_[QME_PSCRS1_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_EC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_EC]

//>> SET_[QME_PSCRS1_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_EC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_EC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_EC]

//>> SET_[QME_PSCRS1_EC]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_EC]

//>> CLEAR_[QME_PSCRS1_EC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_EC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_EC]

//>> GET_[QME_PSCRS1_EC]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_EC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_EC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_EC]

//>> GET_[QME_PSCRS1_EC]
static inline bool GET_QME_PSCRS1_EC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_EC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_EC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_EC]

//>> SET_[QME_PSCRS1_PSLL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_PSLL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_PSLL,
           QME_PSCRS1_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_PSLL]

//>> SET_[QME_PSCRS1_PSLL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_PSLL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_PSLL,
           QME_PSCRS1_PSLL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_PSLL]

//>> GET_[QME_PSCRS1_PSLL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_PSLL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_PSLL,
           QME_PSCRS1_PSLL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_PSLL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_PSLL]

//>> SET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_HYP_VIRT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_HYP_VIRT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_HYP_VIRT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]
static inline bool GET_QME_PSCRS1_HYP_VIRT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_HYP_VIRT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_HYP_VIRT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_HYP_VIRT_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_UV_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_UV_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS1_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_UV_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_UV_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]
static inline bool GET_QME_PSCRS1_UV_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_UV_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_UV_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_UV_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_HYP_DB_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_HYP_DB_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_HYP_DB_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]
static inline bool GET_QME_PSCRS1_HYP_DB_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_HYP_DB_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_HYP_DB_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_HYP_DB_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_EXT_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_EXT_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_EXT_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS1_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_EXT_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_EXT_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_EXT_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_EXT_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_EXT_EXIT_ENABLE]
static inline bool GET_QME_PSCRS1_EXT_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_EXT_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_EXT_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_EXT_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_DEC_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_DEC_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_DEC_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS1_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_DEC_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_DEC_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_DEC_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_DEC_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_DEC_EXIT_ENABLE]
static inline bool GET_QME_PSCRS1_DEC_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_DEC_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_DEC_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_DEC_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_HMI_EXIT_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_HMI_EXIT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.setBit<QME_PSCRS1_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_PSCRS1_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_HMI_EXIT_ENABLE]

//>> CLEAR_[QME_PSCRS1_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_PSCRS1_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.clearBit<QME_PSCRS1_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_PSCRS1_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_PSCRS1_HMI_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_HMI_EXIT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_HMI_EXIT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_HMI_EXIT_ENABLE]

//>> GET_[QME_PSCRS1_HMI_EXIT_ENABLE]
static inline bool GET_QME_PSCRS1_HMI_EXIT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.getBit<QME_PSCRS1_HMI_EXIT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_PSCRS1_HMI_EXIT_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_HMI_EXIT_ENABLE]

//>> SET_[QME_PSCRS1_TR]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_TR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_TR,
           QME_PSCRS1_TR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_TR]

//>> SET_[QME_PSCRS1_TR]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_TR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_TR,
           QME_PSCRS1_TR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_TR]

//>> GET_[QME_PSCRS1_TR]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_TR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_TR,
           QME_PSCRS1_TR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_TR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_TR]

//>> SET_[QME_PSCRS1_MTL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_MTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_MTL,
           QME_PSCRS1_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_MTL]

//>> SET_[QME_PSCRS1_MTL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_MTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_MTL,
           QME_PSCRS1_MTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_MTL]

//>> GET_[QME_PSCRS1_MTL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_MTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_MTL,
           QME_PSCRS1_MTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_MTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_MTL]

//>> SET_[QME_PSCRS1_RL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_RL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_RL,
           QME_PSCRS1_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_RL]

//>> SET_[QME_PSCRS1_RL]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_RL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_RL,
           QME_PSCRS1_RL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_RL]

//>> GET_[QME_PSCRS1_RL]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_RL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_RL,
           QME_PSCRS1_RL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_RL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_RL]

//>> SET_[QME_PSCRS1_PLS]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_PLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_PLS,
           QME_PSCRS1_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_PSCRS1_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_PLS]

//>> SET_[QME_PSCRS1_PLS]
static inline fapi2::buffer<uint64_t>& SET_QME_PSCRS1_PLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return o_data.insertFromRight<QME_PSCRS1_PLS,
           QME_PSCRS1_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_PSCRS1_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PSCRS1_PLS]

//>> GET_[QME_PSCRS1_PLS]
static inline fapi2::buffer<uint64_t>& GET_QME_PSCRS1_PLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PSCRS1));
#endif
    return i_data.extractToRight<QME_PSCRS1_PLS,
           QME_PSCRS1_PLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_PSCRS1_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PSCRS1_PLS]

//>> PREP_[RING_FENCE_MASK_LATCH_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RING_FENCE_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RING_FENCE_MASK_LATCH_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RING_FENCE_MASK_LATCH_REG]

//>> GET_[RING_FENCE_MASK_LATCH_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RING_FENCE_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RING_FENCE_MASK_LATCH_REG;
#endif
    return fapi2::getScom(i_target, RING_FENCE_MASK_LATCH_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RING_FENCE_MASK_LATCH_REG]

//>> PUT_[RING_FENCE_MASK_LATCH_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RING_FENCE_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RING_FENCE_MASK_LATCH_REG));
#endif
    return fapi2::putScom(i_target, RING_FENCE_MASK_LATCH_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RING_FENCE_MASK_LATCH_REG]


//>> SET_[RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK]
static inline fapi2::buffer<uint64_t>& SET_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RING_FENCE_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK]

//>> SET_[RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK]
static inline fapi2::buffer<uint64_t>& SET_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RING_FENCE_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK]

//>> GET_[RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK]
static inline fapi2::buffer<uint64_t>& GET_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RING_FENCE_MASK_LATCH_REG));
#endif
    return i_data.extractToRight<RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
