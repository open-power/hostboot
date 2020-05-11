/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00000.H $            */
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

#ifndef __C_REG00000_H_
#define __C_REG00000_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_L3_PFETCNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_L3_PFETCNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_L3_PFETCNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_L3_PFETCNTL]

//>> GET_[CPMS_L3_PFETCNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_L3_PFETCNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_L3_PFETCNTL;
#endif
    return fapi2::getScom(i_target, CPMS_L3_PFETCNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL]

//>> PUT_[CPMS_L3_PFETCNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_L3_PFETCNTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_L3_PFETCNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_L3_PFETCNTL]

//>> PREP_[CPMS_L3_PFETCNTL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_L3_PFETCNTL_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_L3_PFETCNTL_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_L3_PFETCNTL_WO_CLEAR]

//>> GET_[CPMS_L3_PFETCNTL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_L3_PFETCNTL_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_L3_PFETCNTL_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_L3_PFETCNTL_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_WO_CLEAR]

//>> PUT_[CPMS_L3_PFETCNTL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_L3_PFETCNTL_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_L3_PFETCNTL_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_L3_PFETCNTL_WO_CLEAR]

//>> PREP_[CPMS_L3_PFETCNTL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_L3_PFETCNTL_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_L3_PFETCNTL_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_L3_PFETCNTL_WO_OR]

//>> GET_[CPMS_L3_PFETCNTL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_L3_PFETCNTL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_L3_PFETCNTL_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_L3_PFETCNTL_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_WO_OR]

//>> PUT_[CPMS_L3_PFETCNTL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_L3_PFETCNTL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_L3_PFETCNTL_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_L3_PFETCNTL_WO_OR]


//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE]

//>> GET_[CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE,
           CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE,
           CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE]

//>> GET_[CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE,
           CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> CLEAR_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline bool GET_CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> CLEAR_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline bool GET_CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> CLEAR_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline bool GET_CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> CLEAR_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline bool GET_CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE]

//>> GET_[CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE]

//>> GET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE,
           CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE,
           CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE]

//>> GET_[CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE,
           CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE,
           CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE,
           CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE]

//>> GET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE,
           CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PG_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PG_STATE,
           CPMS_L3_PFETCNTL_VDD_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PG_STATE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PG_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PG_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PG_STATE,
           CPMS_L3_PFETCNTL_VDD_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PG_STATE]

//>> GET_[CPMS_L3_PFETCNTL_VDD_PG_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VDD_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VDD_PG_STATE,
           CPMS_L3_PFETCNTL_VDD_PG_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VDD_PG_STATE]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PG_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PG_SEL,
           CPMS_L3_PFETCNTL_VDD_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PG_SEL]

//>> SET_[CPMS_L3_PFETCNTL_VDD_PG_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VDD_PG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VDD_PG_SEL,
           CPMS_L3_PFETCNTL_VDD_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VDD_PG_SEL]

//>> GET_[CPMS_L3_PFETCNTL_VDD_PG_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VDD_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VDD_PG_SEL,
           CPMS_L3_PFETCNTL_VDD_PG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VDD_PG_SEL]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PG_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PG_STATE,
           CPMS_L3_PFETCNTL_VCS_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PG_STATE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PG_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PG_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PG_STATE,
           CPMS_L3_PFETCNTL_VCS_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PG_STATE]

//>> GET_[CPMS_L3_PFETCNTL_VCS_PG_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VCS_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VCS_PG_STATE,
           CPMS_L3_PFETCNTL_VCS_PG_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VCS_PG_STATE]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PG_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PG_SEL,
           CPMS_L3_PFETCNTL_VCS_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PG_SEL]

//>> SET_[CPMS_L3_PFETCNTL_VCS_PG_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_VCS_PG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_VCS_PG_SEL,
           CPMS_L3_PFETCNTL_VCS_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_VCS_PG_SEL]

//>> GET_[CPMS_L3_PFETCNTL_VCS_PG_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_VCS_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_VCS_PG_SEL,
           CPMS_L3_PFETCNTL_VCS_PG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_VCS_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_VCS_PG_SEL]

//>> SET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_SRAM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_L3_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]

//>> SET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_SRAM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_L3_PFETCNTL_SRAM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_L3_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]

//>> SET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_L3_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_L3_PFETCNTL_SRAM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_L3_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]

//>> CLEAR_[CPMS_L3_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_L3_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_L3_PFETCNTL_SRAM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_L3_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_L3_PFETCNTL_SRAM_ENABLE]

//>> GET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_L3_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_L3_PFETCNTL_SRAM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_L3_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]

//>> GET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]
static inline bool GET_CPMS_L3_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_L3_PFETCNTL, CPMS_L3_PFETCNTL_WO_CLEAR, CPMS_L3_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_L3_PFETCNTL_SRAM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_L3_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_L3_PFETCNTL_SRAM_ENABLE]

//>> PREP_[L3_MISC_L3CERRS_PM_PURGE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_PM_PURGE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PM_PURGE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_PM_PURGE_REG]

//>> GET_[L3_MISC_L3CERRS_PM_PURGE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_PM_PURGE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_PM_PURGE_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_PM_PURGE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_PURGE_REG]

//>> PUT_[L3_MISC_L3CERRS_PM_PURGE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_PM_PURGE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_PM_PURGE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_PM_PURGE_REG]


//>> SET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_PURGE_REG_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_PURGE_REG_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]

//>> SET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_PURGE_REG_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_PURGE_REG_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]

//>> SET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_PURGE_REG_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PM_PURGE_REG_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]

//>> CLEAR_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PM_PURGE_REG_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PM_PURGE_REG_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]

//>> GET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PM_PURGE_REG_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PM_PURGE_REG_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]

//>> GET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]
static inline bool GET_L3_MISC_L3CERRS_PM_PURGE_REG_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PM_PURGE_REG_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_PURGE_REG_REQ]

//>> SET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]

//>> SET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]

//>> SET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]

//>> CLEAR_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]

//>> GET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]

//>> GET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]
static inline bool GET_L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR]

//>> SET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_PURGE_REG_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_PURGE_REG_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]

//>> SET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_PURGE_REG_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_PM_PURGE_REG_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]

//>> SET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_PM_PURGE_REG_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_PM_PURGE_REG_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]

//>> CLEAR_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_PM_PURGE_REG_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_PM_PURGE_REG_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]

//>> GET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_PM_PURGE_REG_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_PM_PURGE_REG_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]

//>> GET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]
static inline bool GET_L3_MISC_L3CERRS_PM_PURGE_REG_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_PM_PURGE_REG));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_PM_PURGE_REG_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_PM_PURGE_REG_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_PM_PURGE_REG_ABORT]

//>> PREP_[QME_SPWU_OTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SPWU_OTR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_OTR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SPWU_OTR]

//>> GET_[QME_SPWU_OTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SPWU_OTR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SPWU_OTR;
#endif
    return fapi2::getScom(i_target, QME_SPWU_OTR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SPWU_OTR]

//>> PUT_[QME_SPWU_OTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SPWU_OTR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return fapi2::putScom(i_target, QME_SPWU_OTR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SPWU_OTR]


//>> SET_[QME_SPWU_OTR_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OTR_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return o_data.insertFromRight<QME_SPWU_OTR_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SPWU_OTR_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OTR_REQ]

//>> SET_[QME_SPWU_OTR_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OTR_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return o_data.insertFromRight<QME_SPWU_OTR_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SPWU_OTR_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OTR_REQ]

//>> SET_[QME_SPWU_OTR_REQ]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OTR_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return o_data.setBit<QME_SPWU_OTR_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SPWU_OTR_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OTR_REQ]

//>> CLEAR_[QME_SPWU_OTR_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_OTR_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return o_data.clearBit<QME_SPWU_OTR_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SPWU_OTR_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SPWU_OTR_REQ]

//>> GET_[QME_SPWU_OTR_REQ]
static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_OTR_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return i_data.extractToRight<QME_SPWU_OTR_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SPWU_OTR_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_OTR_REQ]

//>> GET_[QME_SPWU_OTR_REQ]
static inline bool GET_QME_SPWU_OTR_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return i_data.getBit<QME_SPWU_OTR_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SPWU_OTR_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_OTR_REQ]

//>> SET_[QME_SPWU_OTR_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OTR_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return o_data.insertFromRight<QME_SPWU_OTR_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SPWU_OTR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OTR_DONE]

//>> SET_[QME_SPWU_OTR_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OTR_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return o_data.insertFromRight<QME_SPWU_OTR_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SPWU_OTR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OTR_DONE]

//>> SET_[QME_SPWU_OTR_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SPWU_OTR_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return o_data.setBit<QME_SPWU_OTR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SPWU_OTR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SPWU_OTR_DONE]

//>> CLEAR_[QME_SPWU_OTR_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SPWU_OTR_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return o_data.clearBit<QME_SPWU_OTR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SPWU_OTR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SPWU_OTR_DONE]

//>> GET_[QME_SPWU_OTR_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SPWU_OTR_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return i_data.extractToRight<QME_SPWU_OTR_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SPWU_OTR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_OTR_DONE]

//>> GET_[QME_SPWU_OTR_DONE]
static inline bool GET_QME_SPWU_OTR_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SPWU_OTR));
#endif
    return i_data.getBit<QME_SPWU_OTR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SPWU_OTR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SPWU_OTR_DONE]

//>> PREP_[QME_SSH_OTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SSH_OTR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_OTR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SSH_OTR]

//>> GET_[QME_SSH_OTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SSH_OTR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_OTR;
#endif
    return fapi2::getScom(i_target, QME_SSH_OTR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SSH_OTR]

//>> PUT_[QME_SSH_OTR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SSH_OTR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return fapi2::putScom(i_target, QME_SSH_OTR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SSH_OTR]


//>> SET_[QME_SSH_OTR_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_GATED]

//>> SET_[QME_SSH_OTR_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_GATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_GATED]

//>> SET_[QME_SSH_OTR_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.setBit<QME_SSH_OTR_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_OTR_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_GATED]

//>> CLEAR_[QME_SSH_OTR_STOP_GATED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OTR_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.clearBit<QME_SSH_OTR_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_OTR_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_OTR_STOP_GATED]

//>> GET_[QME_SSH_OTR_STOP_GATED]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_STOP_GATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_STOP_GATED]

//>> GET_[QME_SSH_OTR_STOP_GATED]
static inline bool GET_QME_SSH_OTR_STOP_GATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.getBit<QME_SSH_OTR_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_OTR_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_STOP_GATED]

//>> SET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.setBit<QME_SSH_OTR_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]

//>> CLEAR_[QME_SSH_OTR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OTR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.clearBit<QME_SSH_OTR_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_OTR_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]
static inline bool GET_QME_SSH_OTR_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.getBit<QME_SSH_OTR_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_OTR_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_STOP_TRANSITION,
           QME_SSH_OTR_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_TRANSITION]

//>> SET_[QME_SSH_OTR_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_TRANSITION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_STOP_TRANSITION,
           QME_SSH_OTR_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_TRANSITION]

//>> GET_[QME_SSH_OTR_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_STOP_TRANSITION,
           QME_SSH_OTR_STOP_TRANSITION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_STOP_TRANSITION]

//>> SET_[QME_SSH_OTR_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_REQ_STOP_LEVEL,
           QME_SSH_OTR_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_OTR_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_REQ_STOP_LEVEL,
           QME_SSH_OTR_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_REQ_STOP_LEVEL]

//>> GET_[QME_SSH_OTR_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_REQ_STOP_LEVEL,
           QME_SSH_OTR_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_OTR_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_ACT_STOP_LEVEL,
           QME_SSH_OTR_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_OTR_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_ACT_STOP_LEVEL,
           QME_SSH_OTR_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_ACT_STOP_LEVEL]

//>> GET_[QME_SSH_OTR_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_ACT_STOP_LEVEL,
           QME_SSH_OTR_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL]

//>> GET_[QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL,
           QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL]

//>> GET_[QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL,
           QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_SPECIAL_WKUP_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_SPECIAL_WKUP_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]

//>> SET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_SPECIAL_WKUP_OCCURRED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_SPECIAL_WKUP_OCCURRED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]

//>> SET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_SPECIAL_WKUP_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.setBit<QME_SSH_OTR_SPECIAL_WKUP_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]

//>> CLEAR_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OTR_SPECIAL_WKUP_OCCURRED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.clearBit<QME_SSH_OTR_SPECIAL_WKUP_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]

//>> GET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_SPECIAL_WKUP_OCCURRED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_SPECIAL_WKUP_OCCURRED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]

//>> GET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]
static inline bool GET_QME_SSH_OTR_SPECIAL_WKUP_OCCURRED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.getBit<QME_SSH_OTR_SPECIAL_WKUP_OCCURRED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_OCCURRED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_SPECIAL_WKUP_OCCURRED]

//>> SET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_SPECIAL_WKUP_ENTERED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_SPECIAL_WKUP_ENTERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]

//>> SET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_SPECIAL_WKUP_ENTERED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_SPECIAL_WKUP_ENTERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]

//>> SET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_SPECIAL_WKUP_ENTERED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.setBit<QME_SSH_OTR_SPECIAL_WKUP_ENTERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]

//>> CLEAR_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OTR_SPECIAL_WKUP_ENTERED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.clearBit<QME_SSH_OTR_SPECIAL_WKUP_ENTERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]

//>> GET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_SPECIAL_WKUP_ENTERED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_SPECIAL_WKUP_ENTERED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]

//>> GET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]
static inline bool GET_QME_SSH_OTR_SPECIAL_WKUP_ENTERED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.getBit<QME_SSH_OTR_SPECIAL_WKUP_ENTERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_OTR_SPECIAL_WKUP_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_SPECIAL_WKUP_ENTERED]

//>> SET_[QME_SSH_OTR_STOP_STATE_EXITED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_STATE_EXITED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_STOP_STATE_EXITED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_EXITED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_STATE_EXITED]

//>> SET_[QME_SSH_OTR_STOP_STATE_EXITED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_STATE_EXITED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_STOP_STATE_EXITED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_EXITED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_STATE_EXITED]

//>> SET_[QME_SSH_OTR_STOP_STATE_EXITED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_STATE_EXITED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.setBit<QME_SSH_OTR_STOP_STATE_EXITED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_EXITED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_STATE_EXITED]

//>> CLEAR_[QME_SSH_OTR_STOP_STATE_EXITED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OTR_STOP_STATE_EXITED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.clearBit<QME_SSH_OTR_STOP_STATE_EXITED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_EXITED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_OTR_STOP_STATE_EXITED]

//>> GET_[QME_SSH_OTR_STOP_STATE_EXITED]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_STOP_STATE_EXITED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_STOP_STATE_EXITED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_EXITED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_STOP_STATE_EXITED]

//>> GET_[QME_SSH_OTR_STOP_STATE_EXITED]
static inline bool GET_QME_SSH_OTR_STOP_STATE_EXITED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.getBit<QME_SSH_OTR_STOP_STATE_EXITED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_EXITED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_STOP_STATE_EXITED]

//>> SET_[QME_SSH_OTR_STOP_STATE_ENTERED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_STATE_ENTERED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_STOP_STATE_ENTERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_STATE_ENTERED]

//>> SET_[QME_SSH_OTR_STOP_STATE_ENTERED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_STATE_ENTERED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_STOP_STATE_ENTERED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_STATE_ENTERED]

//>> SET_[QME_SSH_OTR_STOP_STATE_ENTERED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_STOP_STATE_ENTERED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.setBit<QME_SSH_OTR_STOP_STATE_ENTERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_STOP_STATE_ENTERED]

//>> CLEAR_[QME_SSH_OTR_STOP_STATE_ENTERED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_OTR_STOP_STATE_ENTERED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.clearBit<QME_SSH_OTR_STOP_STATE_ENTERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_OTR_STOP_STATE_ENTERED]

//>> GET_[QME_SSH_OTR_STOP_STATE_ENTERED]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_STOP_STATE_ENTERED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_STOP_STATE_ENTERED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_STOP_STATE_ENTERED]

//>> GET_[QME_SSH_OTR_STOP_STATE_ENTERED]
static inline bool GET_QME_SSH_OTR_STOP_STATE_ENTERED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.getBit<QME_SSH_OTR_STOP_STATE_ENTERED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_OTR_STOP_STATE_ENTERED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_STOP_STATE_ENTERED]

//>> SET_[QME_SSH_OTR_DEEPEST_STOP_ENTRY]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_DEEPEST_STOP_ENTRY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_DEEPEST_STOP_ENTRY,
           QME_SSH_OTR_DEEPEST_STOP_ENTRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_OTR_DEEPEST_STOP_ENTRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_DEEPEST_STOP_ENTRY]

//>> SET_[QME_SSH_OTR_DEEPEST_STOP_ENTRY]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_OTR_DEEPEST_STOP_ENTRY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return o_data.insertFromRight<QME_SSH_OTR_DEEPEST_STOP_ENTRY,
           QME_SSH_OTR_DEEPEST_STOP_ENTRY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_OTR_DEEPEST_STOP_ENTRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_OTR_DEEPEST_STOP_ENTRY]

//>> GET_[QME_SSH_OTR_DEEPEST_STOP_ENTRY]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_OTR_DEEPEST_STOP_ENTRY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_OTR));
#endif
    return i_data.extractToRight<QME_SSH_OTR_DEEPEST_STOP_ENTRY,
           QME_SSH_OTR_DEEPEST_STOP_ENTRY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_OTR_DEEPEST_STOP_ENTRY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_OTR_DEEPEST_STOP_ENTRY]

//>> PREP_[QME_SSH_SRC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SSH_SRC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_SRC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SSH_SRC]

//>> GET_[QME_SSH_SRC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SSH_SRC(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SSH_SRC;
#endif
    return fapi2::getScom(i_target, QME_SSH_SRC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SSH_SRC]

//>> PUT_[QME_SSH_SRC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SSH_SRC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return fapi2::putScom(i_target, QME_SSH_SRC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SSH_SRC]


//>> SET_[QME_SSH_SRC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_STOP_GATED]

//>> SET_[QME_SSH_SRC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_STOP_GATED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_STOP_GATED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_STOP_GATED]

//>> SET_[QME_SSH_SRC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.setBit<QME_SSH_SRC_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_SRC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_STOP_GATED]

//>> CLEAR_[QME_SSH_SRC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_SRC_STOP_GATED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.clearBit<QME_SSH_SRC_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_SRC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_SRC_STOP_GATED]

//>> GET_[QME_SSH_SRC_STOP_GATED]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_STOP_GATED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_STOP_GATED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_STOP_GATED]

//>> GET_[QME_SSH_SRC_STOP_GATED]
static inline bool GET_QME_SSH_SRC_STOP_GATED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.getBit<QME_SSH_SRC_STOP_GATED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_SRC_STOP_GATED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_STOP_GATED]

//>> SET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPECIAL_WKUP_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPECIAL_WKUP_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.setBit<QME_SSH_SRC_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_SRC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]

//>> CLEAR_[QME_SSH_SRC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_SRC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.clearBit<QME_SSH_SRC_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_SRC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_SRC_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SPECIAL_WKUP_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]

//>> GET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]
static inline bool GET_QME_SSH_SRC_SPECIAL_WKUP_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.getBit<QME_SSH_SRC_SPECIAL_WKUP_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_SRC_SPECIAL_WKUP_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SPECIAL_WKUP_DONE]

//>> SET_[QME_SSH_SRC_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_STOP_TRANSITION,
           QME_SSH_SRC_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_STOP_TRANSITION]

//>> SET_[QME_SSH_SRC_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_STOP_TRANSITION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_STOP_TRANSITION,
           QME_SSH_SRC_STOP_TRANSITION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_STOP_TRANSITION]

//>> GET_[QME_SSH_SRC_STOP_TRANSITION]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_STOP_TRANSITION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_STOP_TRANSITION,
           QME_SSH_SRC_STOP_TRANSITION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_STOP_TRANSITION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_STOP_TRANSITION]

//>> SET_[QME_SSH_SRC_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_REQ_STOP_LEVEL,
           QME_SSH_SRC_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_SRC_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_REQ_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_REQ_STOP_LEVEL,
           QME_SSH_SRC_REQ_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_REQ_STOP_LEVEL]

//>> GET_[QME_SSH_SRC_REQ_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_REQ_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_REQ_STOP_LEVEL,
           QME_SSH_SRC_REQ_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_REQ_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_REQ_STOP_LEVEL]

//>> SET_[QME_SSH_SRC_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_ACT_STOP_LEVEL,
           QME_SSH_SRC_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_SRC_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_ACT_STOP_LEVEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_ACT_STOP_LEVEL,
           QME_SSH_SRC_ACT_STOP_LEVEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_ACT_STOP_LEVEL]

//>> GET_[QME_SSH_SRC_ACT_STOP_LEVEL]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_ACT_STOP_LEVEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_ACT_STOP_LEVEL,
           QME_SSH_SRC_ACT_STOP_LEVEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_ACT_STOP_LEVEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_ACT_STOP_LEVEL]

//>> SET_[QME_SSH_SRC_REQ_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_REQ_WRITE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_REQ_WRITE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_REQ_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_REQ_WRITE_ENABLE]

//>> SET_[QME_SSH_SRC_REQ_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_REQ_WRITE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_REQ_WRITE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_REQ_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_REQ_WRITE_ENABLE]

//>> SET_[QME_SSH_SRC_REQ_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_REQ_WRITE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.setBit<QME_SSH_SRC_REQ_WRITE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_SRC_REQ_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_REQ_WRITE_ENABLE]

//>> CLEAR_[QME_SSH_SRC_REQ_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_SRC_REQ_WRITE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.clearBit<QME_SSH_SRC_REQ_WRITE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_SRC_REQ_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_SRC_REQ_WRITE_ENABLE]

//>> GET_[QME_SSH_SRC_REQ_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_REQ_WRITE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_REQ_WRITE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_REQ_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_REQ_WRITE_ENABLE]

//>> GET_[QME_SSH_SRC_REQ_WRITE_ENABLE]
static inline bool GET_QME_SSH_SRC_REQ_WRITE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.getBit<QME_SSH_SRC_REQ_WRITE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_SRC_REQ_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_REQ_WRITE_ENABLE]

//>> SET_[QME_SSH_SRC_ACT_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_ACT_WRITE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_ACT_WRITE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_ACT_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_ACT_WRITE_ENABLE]

//>> SET_[QME_SSH_SRC_ACT_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_ACT_WRITE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_ACT_WRITE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_ACT_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_ACT_WRITE_ENABLE]

//>> SET_[QME_SSH_SRC_ACT_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_ACT_WRITE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.setBit<QME_SSH_SRC_ACT_WRITE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_SRC_ACT_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_ACT_WRITE_ENABLE]

//>> CLEAR_[QME_SSH_SRC_ACT_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_SRC_ACT_WRITE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.clearBit<QME_SSH_SRC_ACT_WRITE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_SRC_ACT_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_SRC_ACT_WRITE_ENABLE]

//>> GET_[QME_SSH_SRC_ACT_WRITE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_ACT_WRITE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_ACT_WRITE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_ACT_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_ACT_WRITE_ENABLE]

//>> GET_[QME_SSH_SRC_ACT_WRITE_ENABLE]
static inline bool GET_QME_SSH_SRC_ACT_WRITE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.getBit<QME_SSH_SRC_ACT_WRITE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_SRC_ACT_WRITE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_ACT_WRITE_ENABLE]

//>> SET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SELF_SAVE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SELF_SAVE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SELF_SAVE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]

//>> SET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SELF_SAVE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SELF_SAVE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SELF_SAVE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]

//>> SET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SELF_SAVE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.setBit<QME_SSH_SRC_SELF_SAVE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_SRC_SELF_SAVE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]

//>> CLEAR_[QME_SSH_SRC_SELF_SAVE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_SRC_SELF_SAVE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.clearBit<QME_SSH_SRC_SELF_SAVE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_SRC_SELF_SAVE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_SRC_SELF_SAVE_ACTIVE]

//>> GET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SELF_SAVE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SELF_SAVE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SELF_SAVE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]

//>> GET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]
static inline bool GET_QME_SSH_SRC_SELF_SAVE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.getBit<QME_SSH_SRC_SELF_SAVE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_SRC_SELF_SAVE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SELF_SAVE_ACTIVE]

//>> SET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SELF_RESTORE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SELF_RESTORE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SELF_RESTORE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]

//>> SET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SELF_RESTORE_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SELF_RESTORE_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SELF_RESTORE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]

//>> SET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SELF_RESTORE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.setBit<QME_SSH_SRC_SELF_RESTORE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_SRC_SELF_RESTORE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]

//>> CLEAR_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_SRC_SELF_RESTORE_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.clearBit<QME_SSH_SRC_SELF_RESTORE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_SRC_SELF_RESTORE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]

//>> GET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SELF_RESTORE_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SELF_RESTORE_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SELF_RESTORE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]

//>> GET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]
static inline bool GET_QME_SSH_SRC_SELF_RESTORE_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.getBit<QME_SSH_SRC_SELF_RESTORE_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_SRC_SELF_RESTORE_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SELF_RESTORE_ACTIVE]

//>> SET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SAMPLED_STOP_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> SET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SAMPLED_STOP_ACTIVE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> SET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.setBit<QME_SSH_SRC_SAMPLED_STOP_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> CLEAR_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.clearBit<QME_SSH_SRC_SAMPLED_STOP_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> GET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SAMPLED_STOP_ACTIVE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> GET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]
static inline bool GET_QME_SSH_SRC_SAMPLED_STOP_ACTIVE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.getBit<QME_SSH_SRC_SAMPLED_STOP_ACTIVE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access QME_SSH_SRC_SAMPLED_STOP_ACTIVE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SAMPLED_STOP_ACTIVE]

//>> SET_[QME_SSH_SRC_SAMPLED_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SAMPLED_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SAMPLED_STOP_STATE,
           QME_SSH_SRC_SAMPLED_STOP_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SAMPLED_STOP_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SAMPLED_STOP_STATE]

//>> SET_[QME_SSH_SRC_SAMPLED_STOP_STATE]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SAMPLED_STOP_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SAMPLED_STOP_STATE,
           QME_SSH_SRC_SAMPLED_STOP_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SAMPLED_STOP_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SAMPLED_STOP_STATE]

//>> GET_[QME_SSH_SRC_SAMPLED_STOP_STATE]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SAMPLED_STOP_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SAMPLED_STOP_STATE,
           QME_SSH_SRC_SAMPLED_STOP_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SAMPLED_STOP_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SAMPLED_STOP_STATE]

//>> SET_[QME_SSH_SRC_SPECIAL_WKUP_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPECIAL_WKUP_PRESENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPECIAL_WKUP_PRESENT,
           QME_SSH_SRC_SPECIAL_WKUP_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SPECIAL_WKUP_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPECIAL_WKUP_PRESENT]

//>> SET_[QME_SSH_SRC_SPECIAL_WKUP_PRESENT]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPECIAL_WKUP_PRESENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPECIAL_WKUP_PRESENT,
           QME_SSH_SRC_SPECIAL_WKUP_PRESENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SPECIAL_WKUP_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPECIAL_WKUP_PRESENT]

//>> GET_[QME_SSH_SRC_SPECIAL_WKUP_PRESENT]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SPECIAL_WKUP_PRESENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SPECIAL_WKUP_PRESENT,
           QME_SSH_SRC_SPECIAL_WKUP_PRESENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SPECIAL_WKUP_PRESENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SPECIAL_WKUP_PRESENT]

//>> SET_[QME_SSH_SRC_SPC_WKUP_RECENT_SET]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPC_WKUP_RECENT_SET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPC_WKUP_RECENT_SET,
           QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPC_WKUP_RECENT_SET]

//>> SET_[QME_SSH_SRC_SPC_WKUP_RECENT_SET]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPC_WKUP_RECENT_SET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPC_WKUP_RECENT_SET,
           QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPC_WKUP_RECENT_SET]

//>> GET_[QME_SSH_SRC_SPC_WKUP_RECENT_SET]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SPC_WKUP_RECENT_SET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SPC_WKUP_RECENT_SET,
           QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SPC_WKUP_RECENT_SET]

//>> SET_[QME_SSH_SRC_SPC_WKUP_RECENT_CLR]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPC_WKUP_RECENT_CLR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPC_WKUP_RECENT_CLR,
           QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_CLR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPC_WKUP_RECENT_CLR]

//>> SET_[QME_SSH_SRC_SPC_WKUP_RECENT_CLR]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPC_WKUP_RECENT_CLR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPC_WKUP_RECENT_CLR,
           QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_CLR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPC_WKUP_RECENT_CLR]

//>> GET_[QME_SSH_SRC_SPC_WKUP_RECENT_CLR]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SPC_WKUP_RECENT_CLR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SPC_WKUP_RECENT_CLR,
           QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_CLR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SPC_WKUP_RECENT_CLR]

//>> SET_[QME_SSH_SRC_SPC_WKUP_RECENT_ACT]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPC_WKUP_RECENT_ACT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPC_WKUP_RECENT_ACT,
           QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_ACT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPC_WKUP_RECENT_ACT]

//>> SET_[QME_SSH_SRC_SPC_WKUP_RECENT_ACT]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPC_WKUP_RECENT_ACT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPC_WKUP_RECENT_ACT,
           QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_ACT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPC_WKUP_RECENT_ACT]

//>> GET_[QME_SSH_SRC_SPC_WKUP_RECENT_ACT]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SPC_WKUP_RECENT_ACT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SPC_WKUP_RECENT_ACT,
           QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_ACT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SPC_WKUP_RECENT_ACT]

//>> SET_[QME_SSH_SRC_SPC_WKUP_RECENT_DRP]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPC_WKUP_RECENT_DRP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPC_WKUP_RECENT_DRP,
           QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_DRP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPC_WKUP_RECENT_DRP]

//>> SET_[QME_SSH_SRC_SPC_WKUP_RECENT_DRP]
static inline fapi2::buffer<uint64_t>& SET_QME_SSH_SRC_SPC_WKUP_RECENT_DRP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return o_data.insertFromRight<QME_SSH_SRC_SPC_WKUP_RECENT_DRP,
           QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_DRP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SSH_SRC_SPC_WKUP_RECENT_DRP]

//>> GET_[QME_SSH_SRC_SPC_WKUP_RECENT_DRP]
static inline fapi2::buffer<uint64_t>& GET_QME_SSH_SRC_SPC_WKUP_RECENT_DRP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SSH_SRC));
#endif
    return i_data.extractToRight<QME_SSH_SRC_SPC_WKUP_RECENT_DRP,
           QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_SSH_SRC_SPC_WKUP_RECENT_DRP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SSH_SRC_SPC_WKUP_RECENT_DRP]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
