/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00003.H $            */
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

#ifndef __C_REG00003_H_
#define __C_REG00003_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_CCDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CCDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CCDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_CCDR]

//>> GET_[CPMS_CCDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CCDR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CCDR;
#endif
    return fapi2::getScom(i_target, CPMS_CCDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_CCDR]

//>> PUT_[CPMS_CCDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CCDR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return fapi2::putScom(i_target, CPMS_CCDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_CCDR]


//>> SET_[CPMS_CCDR_CHAR_COUNTA_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTA_SCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTA_SCALE,
           CPMS_CCDR_CHAR_COUNTA_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTA_SCALE]

//>> SET_[CPMS_CCDR_CHAR_COUNTA_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTA_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTA_SCALE,
           CPMS_CCDR_CHAR_COUNTA_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTA_SCALE]

//>> GET_[CPMS_CCDR_CHAR_COUNTA_SCALE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_CHAR_COUNTA_SCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_CHAR_COUNTA_SCALE,
           CPMS_CCDR_CHAR_COUNTA_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTA_SCALE]

//>> SET_[CPMS_CCDR_CHAR_COUNTA_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTA_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTA_VALUE,
           CPMS_CCDR_CHAR_COUNTA_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTA_VALUE]

//>> SET_[CPMS_CCDR_CHAR_COUNTA_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTA_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTA_VALUE,
           CPMS_CCDR_CHAR_COUNTA_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTA_VALUE]

//>> GET_[CPMS_CCDR_CHAR_COUNTA_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_CHAR_COUNTA_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_CHAR_COUNTA_VALUE,
           CPMS_CCDR_CHAR_COUNTA_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTA_VALUE]

//>> SET_[CPMS_CCDR_CHAR_COUNTB_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTB_SCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTB_SCALE,
           CPMS_CCDR_CHAR_COUNTB_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTB_SCALE]

//>> SET_[CPMS_CCDR_CHAR_COUNTB_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTB_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTB_SCALE,
           CPMS_CCDR_CHAR_COUNTB_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTB_SCALE]

//>> GET_[CPMS_CCDR_CHAR_COUNTB_SCALE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_CHAR_COUNTB_SCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_CHAR_COUNTB_SCALE,
           CPMS_CCDR_CHAR_COUNTB_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTB_SCALE]

//>> SET_[CPMS_CCDR_CHAR_COUNTB_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTB_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTB_VALUE,
           CPMS_CCDR_CHAR_COUNTB_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTB_VALUE]

//>> SET_[CPMS_CCDR_CHAR_COUNTB_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTB_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTB_VALUE,
           CPMS_CCDR_CHAR_COUNTB_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTB_VALUE]

//>> GET_[CPMS_CCDR_CHAR_COUNTB_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_CHAR_COUNTB_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_CHAR_COUNTB_VALUE,
           CPMS_CCDR_CHAR_COUNTB_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTB_VALUE]

//>> SET_[CPMS_CCDR_CHAR_COUNTC_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTC_SCALE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTC_SCALE,
           CPMS_CCDR_CHAR_COUNTC_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTC_SCALE]

//>> SET_[CPMS_CCDR_CHAR_COUNTC_SCALE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTC_SCALE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTC_SCALE,
           CPMS_CCDR_CHAR_COUNTC_SCALE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTC_SCALE]

//>> GET_[CPMS_CCDR_CHAR_COUNTC_SCALE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_CHAR_COUNTC_SCALE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_CHAR_COUNTC_SCALE,
           CPMS_CCDR_CHAR_COUNTC_SCALE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_SCALE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTC_SCALE]

//>> SET_[CPMS_CCDR_CHAR_COUNTC_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTC_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTC_VALUE,
           CPMS_CCDR_CHAR_COUNTC_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTC_VALUE]

//>> SET_[CPMS_CCDR_CHAR_COUNTC_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTC_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTC_VALUE,
           CPMS_CCDR_CHAR_COUNTC_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTC_VALUE]

//>> GET_[CPMS_CCDR_CHAR_COUNTC_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_CHAR_COUNTC_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_CHAR_COUNTC_VALUE,
           CPMS_CCDR_CHAR_COUNTC_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTC_VALUE]

//>> SET_[CPMS_CCDR_CHAR_COUNTA_MOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTA_MOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTA_MOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTA_MOD]

//>> SET_[CPMS_CCDR_CHAR_COUNTA_MOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTA_MOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTA_MOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTA_MOD]

//>> SET_[CPMS_CCDR_CHAR_COUNTA_MOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTA_MOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.setBit<CPMS_CCDR_CHAR_COUNTA_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTA_MOD]

//>> CLEAR_[CPMS_CCDR_CHAR_COUNTA_MOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CCDR_CHAR_COUNTA_MOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.clearBit<CPMS_CCDR_CHAR_COUNTA_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CCDR_CHAR_COUNTA_MOD]

//>> GET_[CPMS_CCDR_CHAR_COUNTA_MOD]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_CHAR_COUNTA_MOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_CHAR_COUNTA_MOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTA_MOD]

//>> GET_[CPMS_CCDR_CHAR_COUNTA_MOD]
static inline bool GET_CPMS_CCDR_CHAR_COUNTA_MOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.getBit<CPMS_CCDR_CHAR_COUNTA_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTA_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTA_MOD]

//>> SET_[CPMS_CCDR_CHAR_COUNTB_MOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTB_MOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTB_MOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTB_MOD]

//>> SET_[CPMS_CCDR_CHAR_COUNTB_MOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTB_MOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTB_MOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTB_MOD]

//>> SET_[CPMS_CCDR_CHAR_COUNTB_MOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTB_MOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.setBit<CPMS_CCDR_CHAR_COUNTB_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTB_MOD]

//>> CLEAR_[CPMS_CCDR_CHAR_COUNTB_MOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CCDR_CHAR_COUNTB_MOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.clearBit<CPMS_CCDR_CHAR_COUNTB_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CCDR_CHAR_COUNTB_MOD]

//>> GET_[CPMS_CCDR_CHAR_COUNTB_MOD]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_CHAR_COUNTB_MOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_CHAR_COUNTB_MOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTB_MOD]

//>> GET_[CPMS_CCDR_CHAR_COUNTB_MOD]
static inline bool GET_CPMS_CCDR_CHAR_COUNTB_MOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.getBit<CPMS_CCDR_CHAR_COUNTB_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTB_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTB_MOD]

//>> SET_[CPMS_CCDR_CHAR_COUNTC_MOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTC_MOD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTC_MOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTC_MOD]

//>> SET_[CPMS_CCDR_CHAR_COUNTC_MOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTC_MOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_CHAR_COUNTC_MOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTC_MOD]

//>> SET_[CPMS_CCDR_CHAR_COUNTC_MOD]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_CHAR_COUNTC_MOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.setBit<CPMS_CCDR_CHAR_COUNTC_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_CHAR_COUNTC_MOD]

//>> CLEAR_[CPMS_CCDR_CHAR_COUNTC_MOD]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CCDR_CHAR_COUNTC_MOD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.clearBit<CPMS_CCDR_CHAR_COUNTC_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CCDR_CHAR_COUNTC_MOD]

//>> GET_[CPMS_CCDR_CHAR_COUNTC_MOD]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_CHAR_COUNTC_MOD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_CHAR_COUNTC_MOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTC_MOD]

//>> GET_[CPMS_CCDR_CHAR_COUNTC_MOD]
static inline bool GET_CPMS_CCDR_CHAR_COUNTC_MOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.getBit<CPMS_CCDR_CHAR_COUNTC_MOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CCDR_CHAR_COUNTC_MOD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_CHAR_COUNTC_MOD]

//>> SET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_SAMPLE_DISABLE_INDICATOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_SAMPLE_DISABLE_INDICATOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CCDR_SAMPLE_DISABLE_INDICATOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]

//>> SET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_SAMPLE_DISABLE_INDICATOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.insertFromRight<CPMS_CCDR_SAMPLE_DISABLE_INDICATOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CCDR_SAMPLE_DISABLE_INDICATOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]

//>> SET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CCDR_SAMPLE_DISABLE_INDICATOR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.setBit<CPMS_CCDR_SAMPLE_DISABLE_INDICATOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CCDR_SAMPLE_DISABLE_INDICATOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]

//>> CLEAR_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CCDR_SAMPLE_DISABLE_INDICATOR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return o_data.clearBit<CPMS_CCDR_SAMPLE_DISABLE_INDICATOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CCDR_SAMPLE_DISABLE_INDICATOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]

//>> GET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CCDR_SAMPLE_DISABLE_INDICATOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.extractToRight<CPMS_CCDR_SAMPLE_DISABLE_INDICATOR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CCDR_SAMPLE_DISABLE_INDICATOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]

//>> GET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]
static inline bool GET_CPMS_CCDR_SAMPLE_DISABLE_INDICATOR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CCDR));
#endif
    return i_data.getBit<CPMS_CCDR_SAMPLE_DISABLE_INDICATOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CCDR_SAMPLE_DISABLE_INDICATOR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CCDR_SAMPLE_DISABLE_INDICATOR]

//>> PREP_[CPMS_CL2_PFETCNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CL2_PFETCNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CL2_PFETCNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_CL2_PFETCNTL]

//>> GET_[CPMS_CL2_PFETCNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CL2_PFETCNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CL2_PFETCNTL;
#endif
    return fapi2::getScom(i_target, CPMS_CL2_PFETCNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL]

//>> PUT_[CPMS_CL2_PFETCNTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CL2_PFETCNTL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_CL2_PFETCNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_CL2_PFETCNTL]

//>> PREP_[CPMS_CL2_PFETCNTL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CL2_PFETCNTL_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CL2_PFETCNTL_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_CL2_PFETCNTL_WO_CLEAR]

//>> GET_[CPMS_CL2_PFETCNTL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CL2_PFETCNTL_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CL2_PFETCNTL_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_CL2_PFETCNTL_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_WO_CLEAR]

//>> PUT_[CPMS_CL2_PFETCNTL_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CL2_PFETCNTL_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_CL2_PFETCNTL_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_CL2_PFETCNTL_WO_CLEAR]

//>> PREP_[CPMS_CL2_PFETCNTL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_CL2_PFETCNTL_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CL2_PFETCNTL_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_CL2_PFETCNTL_WO_OR]

//>> GET_[CPMS_CL2_PFETCNTL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_CL2_PFETCNTL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_CL2_PFETCNTL_WO_OR;
#endif
    return fapi2::getScom(i_target, CPMS_CL2_PFETCNTL_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_WO_OR]

//>> PUT_[CPMS_CL2_PFETCNTL_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_CL2_PFETCNTL_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return fapi2::putScom(i_target, CPMS_CL2_PFETCNTL_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_CL2_PFETCNTL_WO_OR]


//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE]

//>> GET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> CLEAR_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]
static inline bool GET_CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> CLEAR_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]
static inline bool GET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> CLEAR_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> GET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]
static inline bool GET_CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> CLEAR_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> GET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]
static inline bool GET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> CLEAR_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]
static inline bool GET_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE]

//>> GET_[CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE]

//>> GET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE,
           CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PG_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PG_STATE,
           CPMS_CL2_PFETCNTL_VDD_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PG_STATE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PG_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PG_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PG_STATE,
           CPMS_CL2_PFETCNTL_VDD_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PG_STATE]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PG_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PG_STATE,
           CPMS_CL2_PFETCNTL_VDD_PG_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PG_STATE]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PG_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PG_SEL,
           CPMS_CL2_PFETCNTL_VDD_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PG_SEL]

//>> SET_[CPMS_CL2_PFETCNTL_VDD_PG_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VDD_PG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VDD_PG_SEL,
           CPMS_CL2_PFETCNTL_VDD_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VDD_PG_SEL]

//>> GET_[CPMS_CL2_PFETCNTL_VDD_PG_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VDD_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VDD_PG_SEL,
           CPMS_CL2_PFETCNTL_VDD_PG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VDD_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VDD_PG_SEL]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PG_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PG_STATE,
           CPMS_CL2_PFETCNTL_VCS_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PG_STATE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PG_STATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PG_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PG_STATE,
           CPMS_CL2_PFETCNTL_VCS_PG_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PG_STATE]

//>> GET_[CPMS_CL2_PFETCNTL_VCS_PG_STATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PG_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PG_STATE,
           CPMS_CL2_PFETCNTL_VCS_PG_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VCS_PG_STATE]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PG_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PG_SEL,
           CPMS_CL2_PFETCNTL_VCS_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PG_SEL]

//>> SET_[CPMS_CL2_PFETCNTL_VCS_PG_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_VCS_PG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_VCS_PG_SEL,
           CPMS_CL2_PFETCNTL_VCS_PG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_VCS_PG_SEL]

//>> GET_[CPMS_CL2_PFETCNTL_VCS_PG_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_VCS_PG_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_VCS_PG_SEL,
           CPMS_CL2_PFETCNTL_VCS_PG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_VCS_PG_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_VCS_PG_SEL]

//>> SET_[CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL,
           CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL]

//>> SET_[CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL,
           CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL]

//>> GET_[CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL,
           CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL]

//>> SET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_ACS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_ACS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_ACS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]

//>> SET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_ACS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_ACS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_ACS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]

//>> SET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_ACS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_ACS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CL2_PFETCNTL_ACS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]

//>> CLEAR_[CPMS_CL2_PFETCNTL_ACS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_ACS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_ACS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CL2_PFETCNTL_ACS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CL2_PFETCNTL_ACS_ENABLE]

//>> GET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_ACS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_ACS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_ACS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]

//>> GET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]
static inline bool GET_CPMS_CL2_PFETCNTL_ACS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_ACS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CL2_PFETCNTL_ACS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_ACS_ENABLE]

//>> SET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_SRAM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]

//>> SET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.insertFromRight<CPMS_CL2_PFETCNTL_SRAM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]

//>> SET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.setBit<CPMS_CL2_PFETCNTL_SRAM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]

//>> CLEAR_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return o_data.clearBit<CPMS_CL2_PFETCNTL_SRAM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]

//>> GET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.extractToRight<CPMS_CL2_PFETCNTL_SRAM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]

//>> GET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]
static inline bool GET_CPMS_CL2_PFETCNTL_SRAM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_CL2_PFETCNTL, CPMS_CL2_PFETCNTL_WO_CLEAR, CPMS_CL2_PFETCNTL_WO_OR));
#endif
    return i_data.getBit<CPMS_CL2_PFETCNTL_SRAM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_CL2_PFETCNTL_SRAM_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_CL2_PFETCNTL_SRAM_ENABLE]

//>> PREP_[CPMS_FDCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FDCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FDCR]

//>> GET_[CPMS_FDCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FDCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDCR;
#endif
    return fapi2::getScom(i_target, CPMS_FDCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FDCR]

//>> PUT_[CPMS_FDCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FDCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_FDCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FDCR]

//>> PREP_[CPMS_FDCR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FDCR_SCOM2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDCR_SCOM2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FDCR_SCOM2]

//>> GET_[CPMS_FDCR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FDCR_SCOM2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDCR_SCOM2;
#endif
    return fapi2::getScom(i_target, CPMS_FDCR_SCOM2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FDCR_SCOM2]

//>> PUT_[CPMS_FDCR_SCOM2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FDCR_SCOM2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_FDCR_SCOM2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FDCR_SCOM2]

//>> PREP_[CPMS_FDCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_FDCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDCR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_FDCR_WO_CLEAR]

//>> GET_[CPMS_FDCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_FDCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_FDCR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPMS_FDCR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_FDCR_WO_CLEAR]

//>> PUT_[CPMS_FDCR_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_FDCR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return fapi2::putScom(i_target, CPMS_FDCR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_FDCR_WO_CLEAR]


//>> SET_[CPMS_FDCR_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DISABLE]

//>> SET_[CPMS_FDCR_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DISABLE]

//>> SET_[CPMS_FDCR_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_FDCR_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDCR_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DISABLE]

//>> CLEAR_[CPMS_FDCR_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDCR_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_FDCR_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDCR_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDCR_DISABLE]

//>> GET_[CPMS_FDCR_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_DISABLE]

//>> GET_[CPMS_FDCR_DISABLE]
static inline bool GET_CPMS_FDCR_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_FDCR_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDCR_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_DISABLE]

//>> SET_[CPMS_FDCR_FORCE_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_FORCE_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_FORCE_SAMPLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_FORCE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_FORCE_SAMPLE]

//>> SET_[CPMS_FDCR_FORCE_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_FORCE_SAMPLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_FORCE_SAMPLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_FORCE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_FORCE_SAMPLE]

//>> SET_[CPMS_FDCR_FORCE_SAMPLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_FORCE_SAMPLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_FDCR_FORCE_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDCR_FORCE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_FORCE_SAMPLE]

//>> CLEAR_[CPMS_FDCR_FORCE_SAMPLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDCR_FORCE_SAMPLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_FDCR_FORCE_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDCR_FORCE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDCR_FORCE_SAMPLE]

//>> GET_[CPMS_FDCR_FORCE_SAMPLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_FORCE_SAMPLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_FORCE_SAMPLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_FORCE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_FORCE_SAMPLE]

//>> GET_[CPMS_FDCR_FORCE_SAMPLE]
static inline bool GET_CPMS_FDCR_FORCE_SAMPLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_FDCR_FORCE_SAMPLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDCR_FORCE_SAMPLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_FORCE_SAMPLE]

//>> SET_[CPMS_FDCR_STICKY_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_STICKY_CONTROL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_STICKY_CONTROL,
           CPMS_FDCR_STICKY_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_STICKY_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_STICKY_CONTROL]

//>> SET_[CPMS_FDCR_STICKY_CONTROL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_STICKY_CONTROL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_STICKY_CONTROL,
           CPMS_FDCR_STICKY_CONTROL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_STICKY_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_STICKY_CONTROL]

//>> GET_[CPMS_FDCR_STICKY_CONTROL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_STICKY_CONTROL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_STICKY_CONTROL,
           CPMS_FDCR_STICKY_CONTROL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_STICKY_CONTROL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_STICKY_CONTROL]

//>> SET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_CONTROL_UPDATE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_CONTROL_UPDATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_CONTROL_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]

//>> SET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_CONTROL_UPDATE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_CONTROL_UPDATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_CONTROL_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]

//>> SET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_CONTROL_UPDATE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_FDCR_CONTROL_UPDATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDCR_CONTROL_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]

//>> CLEAR_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDCR_CONTROL_UPDATE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_FDCR_CONTROL_UPDATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDCR_CONTROL_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]

//>> GET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_CONTROL_UPDATE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_CONTROL_UPDATE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_CONTROL_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]

//>> GET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]
static inline bool GET_CPMS_FDCR_CONTROL_UPDATE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_FDCR_CONTROL_UPDATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDCR_CONTROL_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_CONTROL_UPDATE_DISABLE]

//>> SET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SUPPRESS_FTC_UPDATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SUPPRESS_FTC_UPDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_SUPPRESS_FTC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]

//>> SET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SUPPRESS_FTC_UPDATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SUPPRESS_FTC_UPDATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_SUPPRESS_FTC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]

//>> SET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SUPPRESS_FTC_UPDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_FDCR_SUPPRESS_FTC_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDCR_SUPPRESS_FTC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]

//>> CLEAR_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDCR_SUPPRESS_FTC_UPDATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_FDCR_SUPPRESS_FTC_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDCR_SUPPRESS_FTC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]

//>> GET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_SUPPRESS_FTC_UPDATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_SUPPRESS_FTC_UPDATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_SUPPRESS_FTC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]

//>> GET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]
static inline bool GET_CPMS_FDCR_SUPPRESS_FTC_UPDATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_FDCR_SUPPRESS_FTC_UPDATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDCR_SUPPRESS_FTC_UPDATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_SUPPRESS_FTC_UPDATE]

//>> SET_[CPMS_FDCR_CAL_ADJUST]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_CAL_ADJUST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_CAL_ADJUST,
           CPMS_FDCR_CAL_ADJUST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_CAL_ADJUST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_CAL_ADJUST]

//>> SET_[CPMS_FDCR_CAL_ADJUST]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_CAL_ADJUST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_CAL_ADJUST,
           CPMS_FDCR_CAL_ADJUST_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_CAL_ADJUST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_CAL_ADJUST]

//>> GET_[CPMS_FDCR_CAL_ADJUST]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_CAL_ADJUST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_CAL_ADJUST,
           CPMS_FDCR_CAL_ADJUST_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_CAL_ADJUST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_CAL_ADJUST]

//>> SET_[CPMS_FDCR_DELAY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DELAY,
           CPMS_FDCR_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DELAY]

//>> SET_[CPMS_FDCR_DELAY]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DELAY,
           CPMS_FDCR_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DELAY]

//>> GET_[CPMS_FDCR_DELAY]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_DELAY,
           CPMS_FDCR_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_DELAY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_DELAY]

//>> SET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_THRESHOLD_UPDATE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_THRESHOLD_UPDATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_THRESHOLD_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]

//>> SET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_THRESHOLD_UPDATE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_THRESHOLD_UPDATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_THRESHOLD_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]

//>> SET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_THRESHOLD_UPDATE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.setBit<CPMS_FDCR_THRESHOLD_UPDATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_FDCR_THRESHOLD_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]

//>> CLEAR_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_FDCR_THRESHOLD_UPDATE_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.clearBit<CPMS_FDCR_THRESHOLD_UPDATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_FDCR_THRESHOLD_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]

//>> GET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_THRESHOLD_UPDATE_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_THRESHOLD_UPDATE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_THRESHOLD_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]

//>> GET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]
static inline bool GET_CPMS_FDCR_THRESHOLD_UPDATE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.getBit<CPMS_FDCR_THRESHOLD_UPDATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_FDCR_THRESHOLD_UPDATE_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_THRESHOLD_UPDATE_DISABLE]

//>> SET_[CPMS_FDCR_TRIP_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_TRIP_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_TRIP_OFFSET,
           CPMS_FDCR_TRIP_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_TRIP_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_TRIP_OFFSET]

//>> SET_[CPMS_FDCR_TRIP_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_TRIP_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_TRIP_OFFSET,
           CPMS_FDCR_TRIP_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_TRIP_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_TRIP_OFFSET]

//>> GET_[CPMS_FDCR_TRIP_OFFSET]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_TRIP_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_TRIP_OFFSET,
           CPMS_FDCR_TRIP_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_TRIP_OFFSET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_TRIP_OFFSET]

//>> SET_[CPMS_FDCR_DATA0_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DATA0_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DATA0_DETECT,
           CPMS_FDCR_DATA0_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_DATA0_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DATA0_DETECT]

//>> SET_[CPMS_FDCR_DATA0_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DATA0_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DATA0_DETECT,
           CPMS_FDCR_DATA0_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_DATA0_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DATA0_DETECT]

//>> GET_[CPMS_FDCR_DATA0_DETECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_DATA0_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_DATA0_DETECT,
           CPMS_FDCR_DATA0_DETECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_DATA0_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_DATA0_DETECT]

//>> SET_[CPMS_FDCR_DATA1_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DATA1_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DATA1_DETECT,
           CPMS_FDCR_DATA1_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_DATA1_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DATA1_DETECT]

//>> SET_[CPMS_FDCR_DATA1_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DATA1_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DATA1_DETECT,
           CPMS_FDCR_DATA1_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_DATA1_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DATA1_DETECT]

//>> GET_[CPMS_FDCR_DATA1_DETECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_DATA1_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_DATA1_DETECT,
           CPMS_FDCR_DATA1_DETECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_DATA1_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_DATA1_DETECT]

//>> SET_[CPMS_FDCR_DATA2_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DATA2_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DATA2_DETECT,
           CPMS_FDCR_DATA2_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_DATA2_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DATA2_DETECT]

//>> SET_[CPMS_FDCR_DATA2_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_DATA2_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_DATA2_DETECT,
           CPMS_FDCR_DATA2_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_DATA2_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_DATA2_DETECT]

//>> GET_[CPMS_FDCR_DATA2_DETECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_DATA2_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_DATA2_DETECT,
           CPMS_FDCR_DATA2_DETECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_DATA2_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_DATA2_DETECT]

//>> SET_[CPMS_FDCR_LARGE_DROOP_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_LARGE_DROOP_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_LARGE_DROOP_DETECT,
           CPMS_FDCR_LARGE_DROOP_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_LARGE_DROOP_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_LARGE_DROOP_DETECT]

//>> SET_[CPMS_FDCR_LARGE_DROOP_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_LARGE_DROOP_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_LARGE_DROOP_DETECT,
           CPMS_FDCR_LARGE_DROOP_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_LARGE_DROOP_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_LARGE_DROOP_DETECT]

//>> GET_[CPMS_FDCR_LARGE_DROOP_DETECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_LARGE_DROOP_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_LARGE_DROOP_DETECT,
           CPMS_FDCR_LARGE_DROOP_DETECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_LARGE_DROOP_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_LARGE_DROOP_DETECT]

//>> SET_[CPMS_FDCR_SMALL_DROOP_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SMALL_DROOP_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SMALL_DROOP_DETECT,
           CPMS_FDCR_SMALL_DROOP_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_SMALL_DROOP_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SMALL_DROOP_DETECT]

//>> SET_[CPMS_FDCR_SMALL_DROOP_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SMALL_DROOP_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SMALL_DROOP_DETECT,
           CPMS_FDCR_SMALL_DROOP_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_SMALL_DROOP_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SMALL_DROOP_DETECT]

//>> GET_[CPMS_FDCR_SMALL_DROOP_DETECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_SMALL_DROOP_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_SMALL_DROOP_DETECT,
           CPMS_FDCR_SMALL_DROOP_DETECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_SMALL_DROOP_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_SMALL_DROOP_DETECT]

//>> SET_[CPMS_FDCR_SLOPEA_START_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEA_START_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEA_START_DETECT,
           CPMS_FDCR_SLOPEA_START_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_SLOPEA_START_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEA_START_DETECT]

//>> SET_[CPMS_FDCR_SLOPEA_START_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEA_START_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEA_START_DETECT,
           CPMS_FDCR_SLOPEA_START_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_SLOPEA_START_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEA_START_DETECT]

//>> GET_[CPMS_FDCR_SLOPEA_START_DETECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_SLOPEA_START_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_SLOPEA_START_DETECT,
           CPMS_FDCR_SLOPEA_START_DETECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_SLOPEA_START_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_SLOPEA_START_DETECT]

//>> SET_[CPMS_FDCR_SLOPEA_END_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEA_END_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEA_END_DETECT,
           CPMS_FDCR_SLOPEA_END_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_SLOPEA_END_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEA_END_DETECT]

//>> SET_[CPMS_FDCR_SLOPEA_END_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEA_END_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEA_END_DETECT,
           CPMS_FDCR_SLOPEA_END_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_SLOPEA_END_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEA_END_DETECT]

//>> GET_[CPMS_FDCR_SLOPEA_END_DETECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_SLOPEA_END_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_SLOPEA_END_DETECT,
           CPMS_FDCR_SLOPEA_END_DETECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_SLOPEA_END_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_SLOPEA_END_DETECT]

//>> SET_[CPMS_FDCR_SLOPEB_START_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEB_START_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEB_START_DETECT,
           CPMS_FDCR_SLOPEB_START_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_SLOPEB_START_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEB_START_DETECT]

//>> SET_[CPMS_FDCR_SLOPEB_START_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEB_START_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEB_START_DETECT,
           CPMS_FDCR_SLOPEB_START_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_SLOPEB_START_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEB_START_DETECT]

//>> GET_[CPMS_FDCR_SLOPEB_START_DETECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_SLOPEB_START_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_SLOPEB_START_DETECT,
           CPMS_FDCR_SLOPEB_START_DETECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_SLOPEB_START_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_SLOPEB_START_DETECT]

//>> SET_[CPMS_FDCR_SLOPEB_END_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEB_END_DETECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEB_END_DETECT,
           CPMS_FDCR_SLOPEB_END_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_SLOPEB_END_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEB_END_DETECT]

//>> SET_[CPMS_FDCR_SLOPEB_END_DETECT]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEB_END_DETECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEB_END_DETECT,
           CPMS_FDCR_SLOPEB_END_DETECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_SLOPEB_END_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEB_END_DETECT]

//>> GET_[CPMS_FDCR_SLOPEB_END_DETECT]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_SLOPEB_END_DETECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_SLOPEB_END_DETECT,
           CPMS_FDCR_SLOPEB_END_DETECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_SLOPEB_END_DETECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_SLOPEB_END_DETECT]

//>> SET_[CPMS_FDCR_SLOPEA_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEA_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEA_CYCLES,
           CPMS_FDCR_SLOPEA_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_SLOPEA_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEA_CYCLES]

//>> SET_[CPMS_FDCR_SLOPEA_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEA_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEA_CYCLES,
           CPMS_FDCR_SLOPEA_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_SLOPEA_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEA_CYCLES]

//>> GET_[CPMS_FDCR_SLOPEA_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_SLOPEA_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_SLOPEA_CYCLES,
           CPMS_FDCR_SLOPEA_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_SLOPEA_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_SLOPEA_CYCLES]

//>> SET_[CPMS_FDCR_SLOPEB_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEB_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEB_CYCLES,
           CPMS_FDCR_SLOPEB_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_FDCR_SLOPEB_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEB_CYCLES]

//>> SET_[CPMS_FDCR_SLOPEB_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_CPMS_FDCR_SLOPEB_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return o_data.insertFromRight<CPMS_FDCR_SLOPEB_CYCLES,
           CPMS_FDCR_SLOPEB_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_FDCR_SLOPEB_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_FDCR_SLOPEB_CYCLES]

//>> GET_[CPMS_FDCR_SLOPEB_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_CPMS_FDCR_SLOPEB_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_FDCR, CPMS_FDCR_SCOM2, CPMS_FDCR_WO_CLEAR));
#endif
    return i_data.extractToRight<CPMS_FDCR_SLOPEB_CYCLES,
           CPMS_FDCR_SLOPEB_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_FDCR_SLOPEB_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_FDCR_SLOPEB_CYCLES]

//>> PREP_[CPMS_PRSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_PRSR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PRSR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_PRSR]

//>> GET_[CPMS_PRSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_PRSR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_PRSR;
#endif
    return fapi2::getScom(i_target, CPMS_PRSR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_PRSR]

//>> PUT_[CPMS_PRSR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_PRSR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_PRSR));
#endif
    return fapi2::putScom(i_target, CPMS_PRSR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_PRSR]


//>> SET_[CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PRSR));
#endif
    return o_data.insertFromRight<CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN,
           CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN]

//>> SET_[CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PRSR));
#endif
    return o_data.insertFromRight<CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN,
           CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN]

//>> GET_[CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_PRSR));
#endif
    return i_data.extractToRight<CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN,
           CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN]

//>> PREP_[EC_PC_FIR_RAM_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_RAM_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RAM_CTRL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_FIR_RAM_CTRL]

//>> GET_[EC_PC_FIR_RAM_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_RAM_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RAM_CTRL;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_RAM_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_FIR_RAM_CTRL]

//>> PUT_[EC_PC_FIR_RAM_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_RAM_CTRL(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_RAM_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_FIR_RAM_CTRL]


//>> SET_[EC_PC_FIR_RAM_CTRL_RAM_VTID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_CTRL_RAM_VTID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_CTRL_RAM_VTID,
           EC_PC_FIR_RAM_CTRL_RAM_VTID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_RAM_VTID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_CTRL_RAM_VTID]

//>> SET_[EC_PC_FIR_RAM_CTRL_RAM_VTID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_CTRL_RAM_VTID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_CTRL_RAM_VTID,
           EC_PC_FIR_RAM_CTRL_RAM_VTID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_RAM_VTID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_CTRL_RAM_VTID]

//>> GET_[EC_PC_FIR_RAM_CTRL_RAM_VTID]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_CTRL_RAM_VTID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_CTRL_RAM_VTID,
           EC_PC_FIR_RAM_CTRL_RAM_VTID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_RAM_VTID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_CTRL_RAM_VTID]

//>> SET_[EC_PC_FIR_RAM_CTRL_PPC_PREDCD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_CTRL_PPC_PREDCD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_CTRL_PPC_PREDCD,
           EC_PC_FIR_RAM_CTRL_PPC_PREDCD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_PPC_PREDCD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_CTRL_PPC_PREDCD]

//>> SET_[EC_PC_FIR_RAM_CTRL_PPC_PREDCD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_CTRL_PPC_PREDCD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_CTRL_PPC_PREDCD,
           EC_PC_FIR_RAM_CTRL_PPC_PREDCD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_PPC_PREDCD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_CTRL_PPC_PREDCD]

//>> GET_[EC_PC_FIR_RAM_CTRL_PPC_PREDCD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_CTRL_PPC_PREDCD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_CTRL_PPC_PREDCD,
           EC_PC_FIR_RAM_CTRL_PPC_PREDCD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_PPC_PREDCD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_CTRL_PPC_PREDCD]

//>> SET_[EC_PC_FIR_RAM_CTRL_SPARE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_CTRL_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_CTRL_SPARE,
           EC_PC_FIR_RAM_CTRL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_CTRL_SPARE]

//>> SET_[EC_PC_FIR_RAM_CTRL_SPARE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_CTRL_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_CTRL_SPARE,
           EC_PC_FIR_RAM_CTRL_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_CTRL_SPARE]

//>> GET_[EC_PC_FIR_RAM_CTRL_SPARE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_CTRL_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_CTRL_SPARE,
           EC_PC_FIR_RAM_CTRL_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_CTRL_SPARE]

//>> SET_[EC_PC_FIR_RAM_CTRL_PPC_INSTR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_CTRL_PPC_INSTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_CTRL_PPC_INSTR,
           EC_PC_FIR_RAM_CTRL_PPC_INSTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_PPC_INSTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_CTRL_PPC_INSTR]

//>> SET_[EC_PC_FIR_RAM_CTRL_PPC_INSTR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_CTRL_PPC_INSTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_CTRL_PPC_INSTR,
           EC_PC_FIR_RAM_CTRL_PPC_INSTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_PPC_INSTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_CTRL_PPC_INSTR]

//>> GET_[EC_PC_FIR_RAM_CTRL_PPC_INSTR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_CTRL_PPC_INSTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_CTRL));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_CTRL_PPC_INSTR,
           EC_PC_FIR_RAM_CTRL_PPC_INSTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RAM_CTRL_PPC_INSTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_CTRL_PPC_INSTR]

//>> PREP_[EC_PC_FIR_RECOV_FWD_PROG_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_RECOV_FWD_PROG_CTRL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RECOV_FWD_PROG_CTRL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_FIR_RECOV_FWD_PROG_CTRL]

//>> GET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_RECOV_FWD_PROG_CTRL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RECOV_FWD_PROG_CTRL;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_RECOV_FWD_PROG_CTRL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL]

//>> PUT_[EC_PC_FIR_RECOV_FWD_PROG_CTRL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_RECOV_FWD_PROG_CTRL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_RECOV_FWD_PROG_CTRL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_FIR_RECOV_FWD_PROG_CTRL]


//>> SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]

//>> SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]

//>> SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return o_data.setBit<EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]

//>> CLEAR_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return o_data.clearBit<EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]

//>> GET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return i_data.extractToRight<EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]

//>> GET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]
static inline bool GET_EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return i_data.getBit<EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG]

//>> SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD,
           EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD]

//>> SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD,
           EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD]

//>> GET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RECOV_FWD_PROG_CTRL));
#endif
    return i_data.extractToRight<EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD,
           EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD]

//>> PREP_[EC_PC_PMU_SPRCOR_HID]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PMU_SPRCOR_HID(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_HID;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_PMU_SPRCOR_HID]

//>> GET_[EC_PC_PMU_SPRCOR_HID]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PMU_SPRCOR_HID(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMU_SPRCOR_HID;
#endif
    return fapi2::getScom(i_target, EC_PC_PMU_SPRCOR_HID, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID]

//>> PUT_[EC_PC_PMU_SPRCOR_HID]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PMU_SPRCOR_HID(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return fapi2::putScom(i_target, EC_PC_PMU_SPRCOR_HID, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_PMU_SPRCOR_HID]


//>> SET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_ONE_PPC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_ONE_PPC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ONE_PPC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]

//>> SET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_ONE_PPC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_ONE_PPC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ONE_PPC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]

//>> SET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_ONE_PPC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_ONE_PPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ONE_PPC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_ONE_PPC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_ONE_PPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ONE_PPC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]

//>> GET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_ONE_PPC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_ONE_PPC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ONE_PPC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]

//>> GET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_ONE_PPC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_ONE_PPC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ONE_PPC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_ONE_PPC]

//>> SET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]

//>> SET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]

//>> SET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]

//>> GET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]

//>> GET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE]

//>> SET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_FLUSH_IC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]

//>> SET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_FLUSH_IC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]

//>> SET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_FLUSH_IC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_FLUSH_IC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]

//>> GET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_FLUSH_IC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]

//>> GET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_FLUSH_IC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_FLUSH_IC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_FLUSH_IC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_FLUSH_IC]

//>> SET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_EN_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]

//>> SET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_EN_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]

//>> SET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_EN_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_EN_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]

//>> GET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_EN_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]

//>> GET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_EN_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_EN_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_EN_ATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_EN_ATTN]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HILE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HILE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HILE]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HILE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HILE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HILE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HILE]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HILE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_HILE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HILE]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_HILE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_HILE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_HILE]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HILE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_HILE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HILE]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HILE]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_HILE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_HILE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HILE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HILE]

//>> SET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]

//>> SET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]

//>> SET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]

//>> GET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]

//>> GET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY]

//>> SET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]

//>> SET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]

//>> SET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]

//>> GET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]

//>> GET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_MEGAMOUTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_MEGAMOUTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_MEGAMOUTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_MEGAMOUTH]

//>> SET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]

//>> SET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]

//>> SET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]

//>> GET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]

//>> GET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET]

//>> SET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_RADIX_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]

//>> SET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_RADIX_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]

//>> SET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_RADIX_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_RADIX_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]

//>> GET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_RADIX_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]

//>> GET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_RADIX_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_RADIX_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_RADIX_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_RADIX_MODE]

//>> SET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]

//>> SET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]

//>> SET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]

//>> GET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]

//>> GET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED]

//>> SET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]

//>> SET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]

//>> SET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]

//>> GET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]

//>> GET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_11]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_12]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_HID_SPARE_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_13]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_HID_SPARE_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_HID_SPARE_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_HID_SPARE_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_HID_SPARE_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_SPARE_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_SPARE_14]

//>> SET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_P10_64K_OPT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_P10_64K_OPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_P10_64K_OPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]

//>> SET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_P10_64K_OPT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_P10_64K_OPT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_P10_64K_OPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]

//>> SET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_P10_64K_OPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_P10_64K_OPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_P10_64K_OPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_P10_64K_OPT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_P10_64K_OPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_P10_64K_OPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]

//>> GET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_P10_64K_OPT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_P10_64K_OPT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_P10_64K_OPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]

//>> GET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_P10_64K_OPT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_P10_64K_OPT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_P10_64K_OPT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_P10_64K_OPT]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.insertFromRight<EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]

//>> SET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.setBit<EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]

//>> CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return o_data.clearBit<EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.extractToRight<EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]

//>> GET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]
static inline bool GET_EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(EC_PC_PMU_SPRCOR_HID));
#endif
    return i_data.getBit<EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID]

//>> PREP_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG]

//>> PUT_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG]


//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]

//>> CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]
static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]

//>> CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]
static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]
static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]

//>> CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]
static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC,
           L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]

//>> CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]
static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]

//>> SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.setBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]

//>> CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return o_data.clearBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]

//>> GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]
static inline bool GET_L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG));
#endif
    return i_data.getBit<L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR]

//>> PREP_[L3_MISC_L3CERRS_MODE_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_MODE_REG1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_MODE_REG1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_MODE_REG1]

//>> GET_[L3_MISC_L3CERRS_MODE_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_MODE_REG1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_MODE_REG1;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_MODE_REG1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG1]

//>> PUT_[L3_MISC_L3CERRS_MODE_REG1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_MODE_REG1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_MODE_REG1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_MODE_REG1]


//>> SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG,
           L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG,
           L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG,
           L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG,
           L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG,
           L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG,
           L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]

//>> SET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.setBit<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]

//>> CLEAR_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return o_data.clearBit<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]

//>> GET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]
static inline bool GET_L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_MODE_REG1));
#endif
    return i_data.getBit<L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG]

//>> PREP_[QME_CDBA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_CDBA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    scomt::last_scom = QME_CDBA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_CDBA]

//>> GET_[QME_CDBA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_CDBA(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    scomt::last_scom = QME_CDBA;
#endif
    return fapi2::getScom(i_target, QME_CDBA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_CDBA]

//>> PUT_[QME_CDBA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_CDBA(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_CDBA));
#endif
    return fapi2::putScom(i_target, QME_CDBA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_CDBA]


//>> SET_[QME_CDBA_MESSAGE_NUMBER]
static inline fapi2::buffer<uint64_t>& SET_QME_CDBA_MESSAGE_NUMBER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_CDBA));
#endif
    return o_data.insertFromRight<QME_CDBA_MESSAGE_NUMBER,
           QME_CDBA_MESSAGE_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CDBA_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CDBA_MESSAGE_NUMBER]

//>> SET_[QME_CDBA_MESSAGE_NUMBER]
static inline fapi2::buffer<uint64_t>& SET_QME_CDBA_MESSAGE_NUMBER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_CDBA));
#endif
    return o_data.insertFromRight<QME_CDBA_MESSAGE_NUMBER,
           QME_CDBA_MESSAGE_NUMBER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CDBA_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CDBA_MESSAGE_NUMBER]

//>> GET_[QME_CDBA_MESSAGE_NUMBER]
static inline fapi2::buffer<uint64_t>& GET_QME_CDBA_MESSAGE_NUMBER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(QME_CDBA));
#endif
    return i_data.extractToRight<QME_CDBA_MESSAGE_NUMBER,
           QME_CDBA_MESSAGE_NUMBER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CDBA_MESSAGE_NUMBER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CDBA_MESSAGE_NUMBER]

//>> PREP_[QME_CSIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_CSIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CSIR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_CSIR]

//>> GET_[QME_CSIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_CSIR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_CSIR;
#endif
    return fapi2::getScom(i_target, QME_CSIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_CSIR]

//>> PUT_[QME_CSIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_CSIR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_CSIR));
#endif
    return fapi2::putScom(i_target, QME_CSIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_CSIR]


//>> SET_[QME_CSIR_PMSR_INSTR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_CSIR_PMSR_INSTR_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CSIR));
#endif
    return o_data.insertFromRight<QME_CSIR_PMSR_INSTR_DATA,
           QME_CSIR_PMSR_INSTR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access QME_CSIR_PMSR_INSTR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CSIR_PMSR_INSTR_DATA]

//>> SET_[QME_CSIR_PMSR_INSTR_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_CSIR_PMSR_INSTR_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CSIR));
#endif
    return o_data.insertFromRight<QME_CSIR_PMSR_INSTR_DATA,
           QME_CSIR_PMSR_INSTR_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access QME_CSIR_PMSR_INSTR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_CSIR_PMSR_INSTR_DATA]

//>> GET_[QME_CSIR_PMSR_INSTR_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_CSIR_PMSR_INSTR_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_CSIR));
#endif
    return i_data.extractToRight<QME_CSIR_PMSR_INSTR_DATA,
           QME_CSIR_PMSR_INSTR_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access QME_CSIR_PMSR_INSTR_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_CSIR_PMSR_INSTR_DATA]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
