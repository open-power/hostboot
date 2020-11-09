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

//>> SET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]

//>> SET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]

//>> SET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.setBit<P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]

//>> CLEAR_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.clearBit<P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]

//>> GET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.extractToRight<P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]

//>> GET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]
static inline bool GET_P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.getBit<P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_L3_PFETSTAT_L3_VDD_PFETS_FINGER0_SENSE]

//>> SET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]

//>> SET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.insertFromRight<P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]

//>> SET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.setBit<P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]

//>> CLEAR_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return o_data.clearBit<P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]

//>> GET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.extractToRight<P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]

//>> GET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]
static inline bool GET_P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETSTAT));
#endif
    return i_data.getBit<P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_CPMS_L3_PFETSTAT_L3_VCS_PFETS_FINGER0_SENSE]

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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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
    FAPI_TRY(scomt::failOn(0xa, 0x20));
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

//>> SET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]

//>> SET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.insertFromRight<P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]

//>> SET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]
static inline fapi2::buffer<uint64_t>& SET_P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.setBit<P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]

//>> CLEAR_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return o_data.clearBit<P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]

//>> GET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]
static inline fapi2::buffer<uint64_t>& GET_P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.extractToRight<P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]

//>> GET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]
static inline bool GET_P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_ACTION0));
#endif
    return i_data.getBit<P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_EC_PC_FIR_CORE_ACTION0_UNUSED_13]

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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
