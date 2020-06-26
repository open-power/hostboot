/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/pauc/reg00009.H $         */
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

#ifndef __PAUC_REG00009_H_
#define __PAUC_REG00009_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


//>> PREP_[CPLT_CTRL4_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL4_WO_CLEAR]

//>> GET_[CPLT_CTRL4_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL4_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL4_WO_CLEAR]

//>> PUT_[CPLT_CTRL4_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL4_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL4_WO_CLEAR]

//>> PREP_[CPLT_CTRL4_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL4_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL4_WO_OR]

//>> GET_[CPLT_CTRL4_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL4_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL4_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL4_WO_OR]

//>> PUT_[CPLT_CTRL4_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL4_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL4_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL4_WO_OR]


//>> SET_[CPLT_CTRL4_0_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_0_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_0_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_0_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_0_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_0_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_0_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_0_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_0_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_0_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_0_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_0_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_0_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_0_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_0_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_0_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_0_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_0_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_0_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_0_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_0_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_1_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_1_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_1_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_1_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_1_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_1_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_1_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_1_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_1_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_1_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_1_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_1_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_1_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_1_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_1_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_1_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_1_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_1_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_1_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_1_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_1_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_2_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_2_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_2_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_2_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_2_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_2_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_2_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_2_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_2_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_2_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_2_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_2_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_2_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_2_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_2_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_2_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_2_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_2_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_2_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_2_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_2_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_3_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_3_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_3_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_3_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_3_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_3_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_3_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_3_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_3_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_3_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_3_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_3_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_3_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_3_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_3_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_3_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_3_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_3_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_3_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_3_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_3_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_4_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_4_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_4_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_4_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_4_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_4_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_4_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_4_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_4_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_4_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_4_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_4_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_4_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_4_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_4_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_4_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_4_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_4_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_4_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_4_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_4_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_5_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_5_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_5_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_5_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_5_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_5_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_5_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_5_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_5_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_5_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_5_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_5_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_5_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_5_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_5_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_5_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_5_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_5_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_5_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_5_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_5_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_6_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_6_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_6_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_6_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_6_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_6_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_6_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_6_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_6_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_6_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_6_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_6_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_6_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_6_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_6_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_6_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_6_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_6_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_6_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_6_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_6_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_7_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_7_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_7_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_7_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_7_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_7_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_7_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_7_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_7_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_7_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_7_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_7_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_7_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_7_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_7_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_7_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_7_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_7_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_7_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_7_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_7_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_8_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_8_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_8_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_8_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_8_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_8_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_8_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_8_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_8_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_8_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_8_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_8_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_8_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_8_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_8_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_8_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_8_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_8_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_8_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_8_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_8_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_9_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_9_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_9_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_9_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_9_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_9_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_9_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_9_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_9_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_9_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_9_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_9_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_9_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_9_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_9_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_9_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_9_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_9_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_9_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_9_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_9_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_10_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_10_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_10_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_10_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_10_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_10_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_10_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_10_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_10_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_10_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_10_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_10_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_10_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_10_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_10_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_10_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_10_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_10_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_10_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_10_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_10_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_11_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_11_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_11_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_11_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_11_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_11_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_11_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_11_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_11_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_11_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_11_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_11_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_11_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_11_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_11_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_11_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_11_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_11_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_11_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_11_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_11_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_12_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_12_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_12_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_12_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_12_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_12_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_12_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_12_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_12_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_12_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_12_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_12_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_12_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_12_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_12_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_12_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_12_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_12_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_12_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_12_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_12_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_13_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_13_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_13_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_13_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_13_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_13_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_13_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_13_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_13_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_13_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_13_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_13_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_13_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_13_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_13_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_13_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_13_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_13_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_13_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_13_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_13_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_14_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_14_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_14_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_14_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_14_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL4_14_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_14_FLUSHMODE_INH]

//>> SET_[CPLT_CTRL4_14_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL4_14_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL4_14_FLUSHMODE_INH]

//>> CLEAR_[CPLT_CTRL4_14_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL4_14_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL4_14_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_14_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL4_14_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_14_FLUSHMODE_INH]

//>> GET_[CPLT_CTRL4_14_FLUSHMODE_INH]
static inline bool GET_CPLT_CTRL4_14_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL4_14_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access CPLT_CTRL4_14_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL4_14_FLUSHMODE_INH]

//>> PREP_[EPS_THERM_WSUB_DTS_RESULT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB_DTS_RESULT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_DTS_RESULT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB_DTS_RESULT1]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB_DTS_RESULT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB_DTS_RESULT1;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB_DTS_RESULT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT1]

//>> PUT_[EPS_THERM_WSUB_DTS_RESULT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB_DTS_RESULT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB_DTS_RESULT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB_DTS_RESULT1]


//>> SET_[EPS_THERM_WSUB_DTS_RESULT1_4_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_4_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_4_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT1_4_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT1_4_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_4_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_4_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT1_4_RESULT]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT1_4_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT1_4_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT1_4_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_4_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT1_4_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT1_5_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_5_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_5_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT1_5_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT1_5_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_5_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_5_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT1_5_RESULT]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT1_5_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT1_5_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT1_5_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_5_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT1_5_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT1_6_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_6_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_6_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT1_6_RESULT]

//>> SET_[EPS_THERM_WSUB_DTS_RESULT1_6_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB_DTS_RESULT1_6_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_6_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB_DTS_RESULT1_6_RESULT]

//>> GET_[EPS_THERM_WSUB_DTS_RESULT1_6_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB_DTS_RESULT1_6_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB_DTS_RESULT1));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB_DTS_RESULT1_6_RESULT,
           EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access EPS_THERM_WSUB_DTS_RESULT1_6_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB_DTS_RESULT1_6_RESULT]

//>> PREP_[XSTOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP]

//>> GET_[XSTOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP;
#endif
    return fapi2::getScom(i_target, XSTOP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP]

//>> PUT_[XSTOP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return fapi2::putScom(i_target, XSTOP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP]


//>> SET_[XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_ANY_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_ANY_XSTOP]

//>> SET_[XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_ANY_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_ANY_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_ANY_XSTOP]

//>> SET_[XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_ANY_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_ANY_XSTOP]

//>> CLEAR_[XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_ANY_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_ANY_XSTOP]

//>> GET_[XSTOP_ANY_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_ANY_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_ANY_XSTOP]

//>> GET_[XSTOP_ANY_XSTOP]
static inline bool GET_XSTOP_ANY_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_ANY_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_ANY_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_ANY_XSTOP]

//>> SET_[XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_SYSTEM_XSTOP]

//>> SET_[XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_SYSTEM_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_SYSTEM_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_SYSTEM_XSTOP]

//>> SET_[XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_SYSTEM_XSTOP]

//>> CLEAR_[XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_SYSTEM_XSTOP]

//>> GET_[XSTOP_SYSTEM_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_SYSTEM_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_SYSTEM_XSTOP]

//>> GET_[XSTOP_SYSTEM_XSTOP]
static inline bool GET_XSTOP_SYSTEM_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_SYSTEM_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_SYSTEM_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_SYSTEM_XSTOP]

//>> SET_[XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_ANY_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_ANY_SPATTN]

//>> SET_[XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_ANY_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_ANY_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_ANY_SPATTN]

//>> SET_[XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_ANY_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_ANY_SPATTN]

//>> CLEAR_[XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_ANY_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_ANY_SPATTN]

//>> GET_[XSTOP_ANY_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_ANY_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_ANY_SPATTN]

//>> GET_[XSTOP_ANY_SPATTN]
static inline bool GET_XSTOP_ANY_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_ANY_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_ANY_SPATTN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_ANY_SPATTN]

//>> SET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> SET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_DBG_FIR_XSTOP_ON_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_DBG_FIR_XSTOP_ON_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> SET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> CLEAR_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> GET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_DBG_FIR_XSTOP_ON_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> GET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]
static inline bool GET_XSTOP_DBG_FIR_XSTOP_ON_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_DBG_FIR_XSTOP_ON_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_DBG_FIR_XSTOP_ON_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_DBG_FIR_XSTOP_ON_TRIG]

//>> SET_[XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_PERV]

//>> SET_[XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_PERV]

//>> SET_[XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_PERV]

//>> CLEAR_[XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_PERV]

//>> GET_[XSTOP_PERV]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_PERV]

//>> GET_[XSTOP_PERV]
static inline bool GET_XSTOP_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_PERV]

//>> SET_[XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN05]

//>> SET_[XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN05]

//>> SET_[XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN05]

//>> CLEAR_[XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN05]

//>> GET_[XSTOP_IN05]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN05]

//>> GET_[XSTOP_IN05]
static inline bool GET_XSTOP_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN05]

//>> SET_[XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN06]

//>> SET_[XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN06]

//>> SET_[XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN06]

//>> CLEAR_[XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN06]

//>> GET_[XSTOP_IN06]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN06]

//>> GET_[XSTOP_IN06]
static inline bool GET_XSTOP_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN06]

//>> SET_[XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN07]

//>> SET_[XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN07]

//>> SET_[XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN07]

//>> CLEAR_[XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN07]

//>> GET_[XSTOP_IN07]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN07]

//>> GET_[XSTOP_IN07]
static inline bool GET_XSTOP_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN07]

//>> SET_[XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN08]

//>> SET_[XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN08]

//>> SET_[XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN08]

//>> CLEAR_[XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN08]

//>> GET_[XSTOP_IN08]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN08]

//>> GET_[XSTOP_IN08]
static inline bool GET_XSTOP_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN08]

//>> SET_[XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN09]

//>> SET_[XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN09]

//>> SET_[XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN09]

//>> CLEAR_[XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN09]

//>> GET_[XSTOP_IN09]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN09]

//>> GET_[XSTOP_IN09]
static inline bool GET_XSTOP_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN09]

//>> SET_[XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN10]

//>> SET_[XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN10]

//>> SET_[XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN10]

//>> CLEAR_[XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN10]

//>> GET_[XSTOP_IN10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN10]

//>> GET_[XSTOP_IN10]
static inline bool GET_XSTOP_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN10]

//>> SET_[XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN11]

//>> SET_[XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN11]

//>> SET_[XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN11]

//>> CLEAR_[XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN11]

//>> GET_[XSTOP_IN11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN11]

//>> GET_[XSTOP_IN11]
static inline bool GET_XSTOP_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN11]

//>> SET_[XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN12]

//>> SET_[XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN12]

//>> SET_[XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN12]

//>> CLEAR_[XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN12]

//>> GET_[XSTOP_IN12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN12]

//>> GET_[XSTOP_IN12]
static inline bool GET_XSTOP_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN12]

//>> SET_[XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN13]

//>> SET_[XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN13]

//>> SET_[XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN13]

//>> CLEAR_[XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN13]

//>> GET_[XSTOP_IN13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN13]

//>> GET_[XSTOP_IN13]
static inline bool GET_XSTOP_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN13]

//>> SET_[XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN14]

//>> SET_[XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN14]

//>> SET_[XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN14]

//>> CLEAR_[XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN14]

//>> GET_[XSTOP_IN14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN14]

//>> GET_[XSTOP_IN14]
static inline bool GET_XSTOP_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN14]

//>> SET_[XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN15]

//>> SET_[XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN15]

//>> SET_[XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN15]

//>> CLEAR_[XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN15]

//>> GET_[XSTOP_IN15]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN15]

//>> GET_[XSTOP_IN15]
static inline bool GET_XSTOP_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN15]

//>> SET_[XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN16]

//>> SET_[XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN16]

//>> SET_[XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN16]

//>> CLEAR_[XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN16]

//>> GET_[XSTOP_IN16]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN16]

//>> GET_[XSTOP_IN16]
static inline bool GET_XSTOP_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN16]

//>> SET_[XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN17]

//>> SET_[XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN17]

//>> SET_[XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN17]

//>> CLEAR_[XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN17]

//>> GET_[XSTOP_IN17]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN17]

//>> GET_[XSTOP_IN17]
static inline bool GET_XSTOP_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN17]

//>> SET_[XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN18]

//>> SET_[XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN18]

//>> SET_[XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN18]

//>> CLEAR_[XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN18]

//>> GET_[XSTOP_IN18]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN18]

//>> GET_[XSTOP_IN18]
static inline bool GET_XSTOP_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN18]

//>> SET_[XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN19]

//>> SET_[XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN19]

//>> SET_[XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN19]

//>> CLEAR_[XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN19]

//>> GET_[XSTOP_IN19]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN19]

//>> GET_[XSTOP_IN19]
static inline bool GET_XSTOP_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN19]

//>> SET_[XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN20]

//>> SET_[XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN20]

//>> SET_[XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN20]

//>> CLEAR_[XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN20]

//>> GET_[XSTOP_IN20]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN20]

//>> GET_[XSTOP_IN20]
static inline bool GET_XSTOP_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN20]

//>> SET_[XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN21]

//>> SET_[XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN21]

//>> SET_[XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN21]

//>> CLEAR_[XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN21]

//>> GET_[XSTOP_IN21]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN21]

//>> GET_[XSTOP_IN21]
static inline bool GET_XSTOP_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN21]

//>> SET_[XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN22]

//>> SET_[XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN22]

//>> SET_[XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN22]

//>> CLEAR_[XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN22]

//>> GET_[XSTOP_IN22]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN22]

//>> GET_[XSTOP_IN22]
static inline bool GET_XSTOP_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN22]

//>> SET_[XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN23]

//>> SET_[XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN23]

//>> SET_[XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN23]

//>> CLEAR_[XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN23]

//>> GET_[XSTOP_IN23]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN23]

//>> GET_[XSTOP_IN23]
static inline bool GET_XSTOP_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN23]

//>> SET_[XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN24]

//>> SET_[XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN24]

//>> SET_[XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN24]

//>> CLEAR_[XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN24]

//>> GET_[XSTOP_IN24]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN24]

//>> GET_[XSTOP_IN24]
static inline bool GET_XSTOP_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN24]

//>> SET_[XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN25]

//>> SET_[XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN25]

//>> SET_[XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN25]

//>> CLEAR_[XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN25]

//>> GET_[XSTOP_IN25]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN25]

//>> GET_[XSTOP_IN25]
static inline bool GET_XSTOP_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN25]

//>> SET_[XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN26]

//>> SET_[XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN26]

//>> SET_[XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN26]

//>> CLEAR_[XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN26]

//>> GET_[XSTOP_IN26]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN26]

//>> GET_[XSTOP_IN26]
static inline bool GET_XSTOP_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN26]

//>> SET_[XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN27]

//>> SET_[XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN27]

//>> SET_[XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN27]

//>> CLEAR_[XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN27]

//>> GET_[XSTOP_IN27]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN27]

//>> GET_[XSTOP_IN27]
static inline bool GET_XSTOP_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN27]

//>> SET_[XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN28]

//>> SET_[XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN28]

//>> SET_[XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN28]

//>> CLEAR_[XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN28]

//>> GET_[XSTOP_IN28]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN28]

//>> GET_[XSTOP_IN28]
static inline bool GET_XSTOP_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN28]

//>> SET_[XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN29]

//>> SET_[XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN29]

//>> SET_[XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN29]

//>> CLEAR_[XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN29]

//>> GET_[XSTOP_IN29]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN29]

//>> GET_[XSTOP_IN29]
static inline bool GET_XSTOP_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN29]

//>> SET_[XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN30]

//>> SET_[XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN30]

//>> SET_[XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN30]

//>> CLEAR_[XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN30]

//>> GET_[XSTOP_IN30]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN30]

//>> GET_[XSTOP_IN30]
static inline bool GET_XSTOP_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN30]

//>> SET_[XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN31]

//>> SET_[XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN31]

//>> SET_[XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN31]

//>> CLEAR_[XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN31]

//>> GET_[XSTOP_IN31]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN31]

//>> GET_[XSTOP_IN31]
static inline bool GET_XSTOP_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN31]

//>> SET_[XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN32]

//>> SET_[XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN32]

//>> SET_[XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN32]

//>> CLEAR_[XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN32]

//>> GET_[XSTOP_IN32]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN32]

//>> GET_[XSTOP_IN32]
static inline bool GET_XSTOP_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN32]

//>> SET_[XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN33]

//>> SET_[XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN33]

//>> SET_[XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN33]

//>> CLEAR_[XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN33]

//>> GET_[XSTOP_IN33]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN33]

//>> GET_[XSTOP_IN33]
static inline bool GET_XSTOP_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN33]

//>> SET_[XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN34]

//>> SET_[XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN34]

//>> SET_[XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN34]

//>> CLEAR_[XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN34]

//>> GET_[XSTOP_IN34]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN34]

//>> GET_[XSTOP_IN34]
static inline bool GET_XSTOP_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN34]

//>> SET_[XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN35]

//>> SET_[XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN35]

//>> SET_[XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN35]

//>> CLEAR_[XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN35]

//>> GET_[XSTOP_IN35]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN35]

//>> GET_[XSTOP_IN35]
static inline bool GET_XSTOP_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN35]

//>> SET_[XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN36]

//>> SET_[XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN36]

//>> SET_[XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN36]

//>> CLEAR_[XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN36]

//>> GET_[XSTOP_IN36]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN36]

//>> GET_[XSTOP_IN36]
static inline bool GET_XSTOP_IN36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN36]

//>> SET_[XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN37]

//>> SET_[XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN37]

//>> SET_[XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN37]

//>> CLEAR_[XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN37]

//>> GET_[XSTOP_IN37]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN37]

//>> GET_[XSTOP_IN37]
static inline bool GET_XSTOP_IN37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN37]

//>> SET_[XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN38]

//>> SET_[XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN38]

//>> SET_[XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN38]

//>> CLEAR_[XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN38]

//>> GET_[XSTOP_IN38]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN38]

//>> GET_[XSTOP_IN38]
static inline bool GET_XSTOP_IN38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN38]

//>> SET_[XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN39]

//>> SET_[XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN39]

//>> SET_[XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN39]

//>> CLEAR_[XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN39]

//>> GET_[XSTOP_IN39]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN39]

//>> GET_[XSTOP_IN39]
static inline bool GET_XSTOP_IN39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN39]

//>> SET_[XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN40]

//>> SET_[XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN40]

//>> SET_[XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN40]

//>> CLEAR_[XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN40]

//>> GET_[XSTOP_IN40]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN40]

//>> GET_[XSTOP_IN40]
static inline bool GET_XSTOP_IN40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN40]

//>> SET_[XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN41]

//>> SET_[XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN41]

//>> SET_[XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN41]

//>> CLEAR_[XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN41]

//>> GET_[XSTOP_IN41]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN41]

//>> GET_[XSTOP_IN41]
static inline bool GET_XSTOP_IN41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN41]

//>> SET_[XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN42]

//>> SET_[XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN42]

//>> SET_[XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN42]

//>> CLEAR_[XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN42]

//>> GET_[XSTOP_IN42]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN42]

//>> GET_[XSTOP_IN42]
static inline bool GET_XSTOP_IN42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN42]

//>> SET_[XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN43]

//>> SET_[XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN43]

//>> SET_[XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN43]

//>> CLEAR_[XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN43]

//>> GET_[XSTOP_IN43]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN43]

//>> GET_[XSTOP_IN43]
static inline bool GET_XSTOP_IN43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN43]

//>> SET_[XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN44]

//>> SET_[XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN44]

//>> SET_[XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN44]

//>> CLEAR_[XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN44]

//>> GET_[XSTOP_IN44]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN44]

//>> GET_[XSTOP_IN44]
static inline bool GET_XSTOP_IN44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN44]

//>> SET_[XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN45]

//>> SET_[XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN45]

//>> SET_[XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN45]

//>> CLEAR_[XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN45]

//>> GET_[XSTOP_IN45]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN45]

//>> GET_[XSTOP_IN45]
static inline bool GET_XSTOP_IN45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN45]

//>> SET_[XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN46]

//>> SET_[XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN46]

//>> SET_[XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN46]

//>> CLEAR_[XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN46]

//>> GET_[XSTOP_IN46]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN46]

//>> GET_[XSTOP_IN46]
static inline bool GET_XSTOP_IN46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN46]

//>> SET_[XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN47]

//>> SET_[XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN47]

//>> SET_[XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN47]

//>> CLEAR_[XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN47]

//>> GET_[XSTOP_IN47]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN47]

//>> GET_[XSTOP_IN47]
static inline bool GET_XSTOP_IN47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN47]

//>> SET_[XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN48]

//>> SET_[XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN48]

//>> SET_[XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN48]

//>> CLEAR_[XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN48]

//>> GET_[XSTOP_IN48]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN48]

//>> GET_[XSTOP_IN48]
static inline bool GET_XSTOP_IN48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN48]

//>> SET_[XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN49]

//>> SET_[XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN49]

//>> SET_[XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN49]

//>> CLEAR_[XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN49]

//>> GET_[XSTOP_IN49]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN49]

//>> GET_[XSTOP_IN49]
static inline bool GET_XSTOP_IN49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN49]

//>> SET_[XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN50]

//>> SET_[XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN50]

//>> SET_[XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN50]

//>> CLEAR_[XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN50]

//>> GET_[XSTOP_IN50]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN50]

//>> GET_[XSTOP_IN50]
static inline bool GET_XSTOP_IN50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN50]

//>> SET_[XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN51]

//>> SET_[XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN51]

//>> SET_[XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN51]

//>> CLEAR_[XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN51]

//>> GET_[XSTOP_IN51]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN51]

//>> GET_[XSTOP_IN51]
static inline bool GET_XSTOP_IN51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN51]

//>> SET_[XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN52]

//>> SET_[XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN52]

//>> SET_[XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN52]

//>> CLEAR_[XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN52]

//>> GET_[XSTOP_IN52]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN52]

//>> GET_[XSTOP_IN52]
static inline bool GET_XSTOP_IN52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN52]

//>> SET_[XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN53]

//>> SET_[XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.insertFromRight<XSTOP_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN53]

//>> SET_[XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.setBit<XSTOP_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_IN53]

//>> CLEAR_[XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return o_data.clearBit<XSTOP_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_IN53]

//>> GET_[XSTOP_IN53]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_IN53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.extractToRight<XSTOP_IN53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN53]

//>> GET_[XSTOP_IN53]
static inline bool GET_XSTOP_IN53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP));
#endif
    return i_data.getBit<XSTOP_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access XSTOP_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_IN53]


//>> PREP_[CPLT_CTRL4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL4_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL4_RW]

//>> GET_[CPLT_CTRL4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL4_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL4_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL4_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL4_RW]

//>> PUT_[CPLT_CTRL4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL4_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL4_RW, CPLT_CTRL4_WO_CLEAR, CPLT_CTRL4_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL4_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL4_RW]

//>> PREP_[PB_PSAVE01_MODE_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PSAVE01_MODE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PSAVE01_MODE_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PSAVE01_MODE_CFG]

//>> GET_[PB_PSAVE01_MODE_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PSAVE01_MODE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PSAVE01_MODE_CFG;
#endif
    return fapi2::getScom(i_target, PB_PSAVE01_MODE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PSAVE01_MODE_CFG]

//>> PUT_[PB_PSAVE01_MODE_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PSAVE01_MODE_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return fapi2::putScom(i_target, PB_PSAVE01_MODE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PSAVE01_MODE_CFG]


//>> SET_[PB_PSAVE01_MODE_CFG_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PSAVE01_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return o_data.insertFromRight<PB_PSAVE01_MODE_CFG_MODE,
           PB_PSAVE01_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PSAVE01_MODE_CFG_MODE]

//>> SET_[PB_PSAVE01_MODE_CFG_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_PSAVE01_MODE_CFG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return o_data.insertFromRight<PB_PSAVE01_MODE_CFG_MODE,
           PB_PSAVE01_MODE_CFG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PSAVE01_MODE_CFG_MODE]

//>> GET_[PB_PSAVE01_MODE_CFG_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_PSAVE01_MODE_CFG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return i_data.extractToRight<PB_PSAVE01_MODE_CFG_MODE,
           PB_PSAVE01_MODE_CFG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PSAVE01_MODE_CFG_MODE]

//>> SET_[PB_PSAVE01_MODE_CFG_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_PB_PSAVE01_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return o_data.insertFromRight<PB_PSAVE01_MODE_CFG_WIDTH,
           PB_PSAVE01_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PSAVE01_MODE_CFG_WIDTH]

//>> SET_[PB_PSAVE01_MODE_CFG_WIDTH]
static inline fapi2::buffer<uint64_t>& SET_PB_PSAVE01_MODE_CFG_WIDTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return o_data.insertFromRight<PB_PSAVE01_MODE_CFG_WIDTH,
           PB_PSAVE01_MODE_CFG_WIDTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PSAVE01_MODE_CFG_WIDTH]

//>> GET_[PB_PSAVE01_MODE_CFG_WIDTH]
static inline fapi2::buffer<uint64_t>& GET_PB_PSAVE01_MODE_CFG_WIDTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return i_data.extractToRight<PB_PSAVE01_MODE_CFG_WIDTH,
           PB_PSAVE01_MODE_CFG_WIDTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_WIDTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PSAVE01_MODE_CFG_WIDTH]

//>> SET_[PB_PSAVE01_MODE_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PSAVE01_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return o_data.insertFromRight<PB_PSAVE01_MODE_CFG_SPARE,
           PB_PSAVE01_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PSAVE01_MODE_CFG_SPARE]

//>> SET_[PB_PSAVE01_MODE_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PSAVE01_MODE_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return o_data.insertFromRight<PB_PSAVE01_MODE_CFG_SPARE,
           PB_PSAVE01_MODE_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PSAVE01_MODE_CFG_SPARE]

//>> GET_[PB_PSAVE01_MODE_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PSAVE01_MODE_CFG_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return i_data.extractToRight<PB_PSAVE01_MODE_CFG_SPARE,
           PB_PSAVE01_MODE_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PSAVE01_MODE_CFG_SPARE]

//>> SET_[PB_PSAVE01_MODE_CFG_MIN_RAND_UC]
static inline fapi2::buffer<uint64_t>& SET_PB_PSAVE01_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return o_data.insertFromRight<PB_PSAVE01_MODE_CFG_MIN_RAND_UC,
           PB_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PSAVE01_MODE_CFG_MIN_RAND_UC]

//>> SET_[PB_PSAVE01_MODE_CFG_MIN_RAND_UC]
static inline fapi2::buffer<uint64_t>& SET_PB_PSAVE01_MODE_CFG_MIN_RAND_UC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return o_data.insertFromRight<PB_PSAVE01_MODE_CFG_MIN_RAND_UC,
           PB_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PSAVE01_MODE_CFG_MIN_RAND_UC]

//>> GET_[PB_PSAVE01_MODE_CFG_MIN_RAND_UC]
static inline fapi2::buffer<uint64_t>& GET_PB_PSAVE01_MODE_CFG_MIN_RAND_UC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PSAVE01_MODE_CFG));
#endif
    return i_data.extractToRight<PB_PSAVE01_MODE_CFG_MIN_RAND_UC,
           PB_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_PSAVE01_MODE_CFG_MIN_RAND_UC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PSAVE01_MODE_CFG_MIN_RAND_UC]

//>> PREP_[PB_MISC_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_MISC_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_MISC_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_MISC_CFG]

//>> GET_[PB_MISC_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_MISC_CFG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_MISC_CFG;
#endif
    return fapi2::getScom(i_target, PB_MISC_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_MISC_CFG]

//>> PUT_[PB_MISC_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_MISC_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return fapi2::putScom(i_target, PB_MISC_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_MISC_CFG]


//>> SET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLX0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLX0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> GET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLX0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> GET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]
static inline bool GET_PB_MISC_CFG_SCOM_PTLX0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLX0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX0_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLX1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLX1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> GET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLX1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> GET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]
static inline bool GET_PB_MISC_CFG_SCOM_PTLX1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLX1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX1_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLY0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLY0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> GET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLY0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> GET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]
static inline bool GET_PB_MISC_CFG_SCOM_PTLY0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLY0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY0_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLY1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLY1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> GET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLY1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> GET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]
static inline bool GET_PB_MISC_CFG_SCOM_PTLY1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLY1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY1_ENABLE]

//>> SET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> SET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> SET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> GET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> GET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]
static inline bool GET_PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR]

//>> SET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> SET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> SET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> GET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> GET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]
static inline bool GET_PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR]

//>> SET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> SET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> SET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> GET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> GET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]
static inline bool GET_PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER]

//>> SET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> SET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> SET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> GET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> GET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]
static inline bool GET_PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_0_ENABLE]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]
static inline bool GET_PB_MISC_CFG_TRANSPORT_0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_1_ENABLE]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]
static inline bool GET_PB_MISC_CFG_TRANSPORT_1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_2_ENABLE]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_2_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]
static inline bool GET_PB_MISC_CFG_TRANSPORT_2_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_2_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_3_ENABLE]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_3_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]
static inline bool GET_PB_MISC_CFG_TRANSPORT_3_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_3_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_ENABLE]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]
static inline bool GET_PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> GET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> GET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]
static inline bool GET_PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]
static inline bool GET_PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> GET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> GET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]
static inline bool GET_PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]
static inline bool GET_PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> GET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> GET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]
static inline bool GET_PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]
static inline bool GET_PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> GET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> GET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]
static inline bool GET_PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]
static inline bool GET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]
static inline bool GET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]
static inline bool GET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]
static inline bool GET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]
static inline bool GET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]
static inline bool GET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]
static inline bool GET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]
static inline bool GET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]
static inline bool GET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]
static inline bool GET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]
static inline bool GET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]
static inline bool GET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]
static inline bool GET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]
static inline bool GET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]
static inline bool GET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]
static inline bool GET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3]

//>> SET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> SET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> SET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> GET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> GET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]
static inline bool GET_PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE]

//>> SET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> SET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> SET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> CLEAR_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> GET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> GET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]
static inline bool GET_PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE]

//>> SET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> SET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> SET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> CLEAR_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> GET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> GET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]
static inline bool GET_PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL]

//>> SET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_ENABLE_DEGRADED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> SET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_ENABLE_DEGRADED_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_ENABLE_DEGRADED_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> SET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_ENABLE_DEGRADED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> CLEAR_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_ENABLE_DEGRADED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> GET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_ENABLE_DEGRADED_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> GET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]
static inline bool GET_PB_MISC_CFG_ENABLE_DEGRADED_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_ENABLE_DEGRADED_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_ENABLE_DEGRADED_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_ENABLE_DEGRADED_MODE]

//>> SET_[PB_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_HW517132_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_HW517132_DISABLE]

//>> SET_[PB_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_HW517132_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_HW517132_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_HW517132_DISABLE]

//>> SET_[PB_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.setBit<PB_MISC_CFG_HW517132_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_HW517132_DISABLE]

//>> CLEAR_[PB_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.clearBit<PB_MISC_CFG_HW517132_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_MISC_CFG_HW517132_DISABLE]

//>> GET_[PB_MISC_CFG_HW517132_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_HW517132_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_HW517132_DISABLE]

//>> GET_[PB_MISC_CFG_HW517132_DISABLE]
static inline bool GET_PB_MISC_CFG_HW517132_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.getBit<PB_MISC_CFG_HW517132_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_MISC_CFG_HW517132_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_HW517132_DISABLE]

//>> SET_[PB_MISC_CFG_MISC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_MISC_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_MISC_SPARE,
           PB_MISC_CFG_MISC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_MISC_CFG_MISC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_MISC_SPARE]

//>> SET_[PB_MISC_CFG_MISC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_MISC_CFG_MISC_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return o_data.insertFromRight<PB_MISC_CFG_MISC_SPARE,
           PB_MISC_CFG_MISC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_MISC_CFG_MISC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_MISC_CFG_MISC_SPARE]

//>> GET_[PB_MISC_CFG_MISC_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_MISC_CFG_MISC_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_MISC_CFG));
#endif
    return i_data.extractToRight<PB_MISC_CFG_MISC_SPARE,
           PB_MISC_CFG_MISC_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_MISC_CFG_MISC_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_MISC_CFG_MISC_SPARE]

//>> PREP_[PB_FP01_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_FP01_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_FP01_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_FP01_CFG]

//>> GET_[PB_FP01_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_FP01_CFG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_FP01_CFG;
#endif
    return fapi2::getScom(i_target, PB_FP01_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_FP01_CFG]

//>> PUT_[PB_FP01_CFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_FP01_CFG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return fapi2::putScom(i_target, PB_FP01_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_FP01_CFG]


//>> SET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_DISABLE_GATHERING]

//>> SET_[PB_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_DISABLE_GATHERING]

//>> SET_[PB_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_0_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_DISABLE_GATHERING]

//>> CLEAR_[PB_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_0_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_0_DISABLE_GATHERING]

//>> GET_[PB_FP01_CFG_0_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_DISABLE_GATHERING]

//>> GET_[PB_FP01_CFG_0_DISABLE_GATHERING]
static inline bool GET_PB_FP01_CFG_0_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_0_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_DISABLE_GATHERING]

//>> SET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT,
           PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT,
           PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT,
           PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT,
           PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT,
           PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT,
           PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT,
           PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT,
           PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT,
           PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP01_CFG_01_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_01_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_01_CMD_EXP_TIME,
           PB_FP01_CFG_01_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_01_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_01_CMD_EXP_TIME]

//>> SET_[PB_FP01_CFG_01_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_01_CMD_EXP_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_01_CMD_EXP_TIME,
           PB_FP01_CFG_01_CMD_EXP_TIME_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_01_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_01_CMD_EXP_TIME]

//>> GET_[PB_FP01_CFG_01_CMD_EXP_TIME]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_01_CMD_EXP_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_01_CMD_EXP_TIME,
           PB_FP01_CFG_01_CMD_EXP_TIME_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_01_CMD_EXP_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_01_CMD_EXP_TIME]

//>> SET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP01_CFG_0_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_PRS_SPARE,
           PB_FP01_CFG_0_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_0_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_PRS_SPARE]

//>> SET_[PB_FP01_CFG_0_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_0_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_0_PRS_SPARE,
           PB_FP01_CFG_0_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_0_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_0_PRS_SPARE]

//>> GET_[PB_FP01_CFG_0_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_0_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_0_PRS_SPARE,
           PB_FP01_CFG_0_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_0_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_0_PRS_SPARE]

//>> SET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> CLEAR_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> GET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]
static inline bool GET_PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8]

//>> SET_[PB_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_DISABLE_GATHERING]

//>> SET_[PB_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_DISABLE_GATHERING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_DISABLE_GATHERING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_DISABLE_GATHERING]

//>> SET_[PB_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_1_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_DISABLE_GATHERING]

//>> CLEAR_[PB_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_1_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_1_DISABLE_GATHERING]

//>> GET_[PB_FP01_CFG_1_DISABLE_GATHERING]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_DISABLE_GATHERING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_DISABLE_GATHERING]

//>> GET_[PB_FP01_CFG_1_DISABLE_GATHERING]
static inline bool GET_PB_FP01_CFG_1_DISABLE_GATHERING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_1_DISABLE_GATHERING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_GATHERING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_DISABLE_GATHERING]

//>> SET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> CLEAR_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> GET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]
static inline bool GET_PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION]

//>> SET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> CLEAR_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> GET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]
static inline bool GET_PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION]

//>> SET_[PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT,
           PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT,
           PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT]

//>> GET_[PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT,
           PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT]

//>> SET_[PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT,
           PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT,
           PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT]

//>> GET_[PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT,
           PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT]

//>> SET_[PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT,
           PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT,
           PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT]

//>> GET_[PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT,
           PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT]

//>> SET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> CLEAR_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> GET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]
static inline bool GET_PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP]

//>> SET_[PB_FP01_CFG_1_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_FMR_SPARE,
           PB_FP01_CFG_1_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_FMR_SPARE]

//>> SET_[PB_FP01_CFG_1_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_FMR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_FMR_SPARE,
           PB_FP01_CFG_1_FMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_FMR_SPARE]

//>> GET_[PB_FP01_CFG_1_FMR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_FMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_FMR_SPARE,
           PB_FP01_CFG_1_FMR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_FMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_FMR_SPARE]

//>> SET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> CLEAR_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> GET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]
static inline bool GET_PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR]

//>> SET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.setBit<PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_pauc Invalid dial access PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> CLEAR_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.clearBit<PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_pauc Invalid dial access PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> GET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]
static inline bool GET_PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.getBit<PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_pauc Invalid dial access PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST]

//>> SET_[PB_FP01_CFG_1_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_PRS_SPARE,
           PB_FP01_CFG_1_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_pauc Invalid dial access PB_FP01_CFG_1_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_PRS_SPARE]

//>> SET_[PB_FP01_CFG_1_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_FP01_CFG_1_PRS_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return o_data.insertFromRight<PB_FP01_CFG_1_PRS_SPARE,
           PB_FP01_CFG_1_PRS_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_pauc Invalid dial access PB_FP01_CFG_1_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_FP01_CFG_1_PRS_SPARE]

//>> GET_[PB_FP01_CFG_1_PRS_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_FP01_CFG_1_PRS_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_FP01_CFG));
#endif
    return i_data.extractToRight<PB_FP01_CFG_1_PRS_SPARE,
           PB_FP01_CFG_1_PRS_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_pauc Invalid dial access PB_FP01_CFG_1_PRS_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_FP01_CFG_1_PRS_SPARE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
