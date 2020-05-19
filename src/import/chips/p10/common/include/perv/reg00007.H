/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00007.H $         */
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

#ifndef __PERV_REG00007_H_
#define __PERV_REG00007_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[SPATTN_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SPATTN_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SPATTN_MASK_RW]

//>> GET_[SPATTN_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SPATTN_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_RW;
#endif
    return fapi2::getScom(i_target, SPATTN_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SPATTN_MASK_RW]

//>> PUT_[SPATTN_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SPATTN_MASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, SPATTN_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SPATTN_MASK_RW]

//>> PREP_[SPATTN_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SPATTN_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SPATTN_MASK_WO_CLEAR]

//>> GET_[SPATTN_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SPATTN_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, SPATTN_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SPATTN_MASK_WO_CLEAR]

//>> PUT_[SPATTN_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SPATTN_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, SPATTN_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SPATTN_MASK_WO_CLEAR]

//>> PREP_[SPATTN_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SPATTN_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SPATTN_MASK_WO_OR]

//>> GET_[SPATTN_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SPATTN_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SPATTN_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, SPATTN_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SPATTN_MASK_WO_OR]

//>> PUT_[SPATTN_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SPATTN_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, SPATTN_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SPATTN_MASK_WO_OR]


//>> SET_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_01]

//>> SET_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_01]

//>> SET_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_01]

//>> CLEAR_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_01]

//>> GET_[SPATTN_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_01]

//>> GET_[SPATTN_MASK_01]
static inline bool GET_SPATTN_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_01]

//>> SET_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_02]

//>> SET_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_02]

//>> SET_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_02]

//>> CLEAR_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_02]

//>> GET_[SPATTN_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_02]

//>> GET_[SPATTN_MASK_02]
static inline bool GET_SPATTN_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_02]

//>> SET_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_03]

//>> SET_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_03]

//>> SET_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_03]

//>> CLEAR_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_03]

//>> GET_[SPATTN_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_03]

//>> GET_[SPATTN_MASK_03]
static inline bool GET_SPATTN_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_03]

//>> SET_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_04]

//>> SET_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_04]

//>> SET_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_04]

//>> CLEAR_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_04]

//>> GET_[SPATTN_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_04]

//>> GET_[SPATTN_MASK_04]
static inline bool GET_SPATTN_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_04]

//>> SET_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_05]

//>> SET_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_05]

//>> SET_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_05]

//>> CLEAR_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_05]

//>> GET_[SPATTN_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_05]

//>> GET_[SPATTN_MASK_05]
static inline bool GET_SPATTN_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_05]

//>> SET_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_06]

//>> SET_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_06]

//>> SET_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_06]

//>> CLEAR_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_06]

//>> GET_[SPATTN_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_06]

//>> GET_[SPATTN_MASK_06]
static inline bool GET_SPATTN_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_06]

//>> SET_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_07]

//>> SET_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_07]

//>> SET_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_07]

//>> CLEAR_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_07]

//>> GET_[SPATTN_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_07]

//>> GET_[SPATTN_MASK_07]
static inline bool GET_SPATTN_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_07]

//>> SET_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_08]

//>> SET_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_08]

//>> SET_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_08]

//>> CLEAR_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_08]

//>> GET_[SPATTN_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_08]

//>> GET_[SPATTN_MASK_08]
static inline bool GET_SPATTN_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_08]

//>> SET_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_09]

//>> SET_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_09]

//>> SET_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_09]

//>> CLEAR_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_09]

//>> GET_[SPATTN_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_09]

//>> GET_[SPATTN_MASK_09]
static inline bool GET_SPATTN_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_09]

//>> SET_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_10]

//>> SET_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_10]

//>> SET_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_10]

//>> CLEAR_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_10]

//>> GET_[SPATTN_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_10]

//>> GET_[SPATTN_MASK_10]
static inline bool GET_SPATTN_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_10]

//>> SET_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_11]

//>> SET_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_11]

//>> SET_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_11]

//>> CLEAR_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_11]

//>> GET_[SPATTN_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_11]

//>> GET_[SPATTN_MASK_11]
static inline bool GET_SPATTN_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_11]

//>> SET_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_12]

//>> SET_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_12]

//>> SET_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_12]

//>> CLEAR_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_12]

//>> GET_[SPATTN_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_12]

//>> GET_[SPATTN_MASK_12]
static inline bool GET_SPATTN_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_12]

//>> SET_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_13]

//>> SET_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_13]

//>> SET_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_13]

//>> CLEAR_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_13]

//>> GET_[SPATTN_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_13]

//>> GET_[SPATTN_MASK_13]
static inline bool GET_SPATTN_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_13]

//>> SET_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_14]

//>> SET_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_14]

//>> SET_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_14]

//>> CLEAR_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_14]

//>> GET_[SPATTN_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_14]

//>> GET_[SPATTN_MASK_14]
static inline bool GET_SPATTN_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_14]

//>> SET_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_15]

//>> SET_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_15]

//>> SET_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_15]

//>> CLEAR_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_15]

//>> GET_[SPATTN_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_15]

//>> GET_[SPATTN_MASK_15]
static inline bool GET_SPATTN_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_15]

//>> SET_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_16]

//>> SET_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_16]

//>> SET_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_16]

//>> CLEAR_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_16]

//>> GET_[SPATTN_MASK_16]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_16]

//>> GET_[SPATTN_MASK_16]
static inline bool GET_SPATTN_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_16]

//>> SET_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_17]

//>> SET_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_17]

//>> SET_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_17]

//>> CLEAR_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_17]

//>> GET_[SPATTN_MASK_17]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_17]

//>> GET_[SPATTN_MASK_17]
static inline bool GET_SPATTN_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_17]

//>> SET_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_18]

//>> SET_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_18]

//>> SET_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_18]

//>> CLEAR_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_18]

//>> GET_[SPATTN_MASK_18]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_18]

//>> GET_[SPATTN_MASK_18]
static inline bool GET_SPATTN_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_18]

//>> SET_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_19]

//>> SET_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_19]

//>> SET_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_19]

//>> CLEAR_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_19]

//>> GET_[SPATTN_MASK_19]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_19]

//>> GET_[SPATTN_MASK_19]
static inline bool GET_SPATTN_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_19]

//>> SET_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_20]

//>> SET_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_20]

//>> SET_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_20]

//>> CLEAR_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_20]

//>> GET_[SPATTN_MASK_20]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_20]

//>> GET_[SPATTN_MASK_20]
static inline bool GET_SPATTN_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_20]

//>> SET_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_21]

//>> SET_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_21]

//>> SET_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_21]

//>> CLEAR_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_21]

//>> GET_[SPATTN_MASK_21]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_21]

//>> GET_[SPATTN_MASK_21]
static inline bool GET_SPATTN_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_21]

//>> SET_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_22]

//>> SET_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_22]

//>> SET_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_22]

//>> CLEAR_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_22]

//>> GET_[SPATTN_MASK_22]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_22]

//>> GET_[SPATTN_MASK_22]
static inline bool GET_SPATTN_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_22]

//>> SET_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_23]

//>> SET_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_23]

//>> SET_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_23]

//>> CLEAR_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_23]

//>> GET_[SPATTN_MASK_23]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_23]

//>> GET_[SPATTN_MASK_23]
static inline bool GET_SPATTN_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_23]

//>> SET_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_24]

//>> SET_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_24]

//>> SET_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_24]

//>> CLEAR_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_24]

//>> GET_[SPATTN_MASK_24]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_24]

//>> GET_[SPATTN_MASK_24]
static inline bool GET_SPATTN_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_24]

//>> SET_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_25]

//>> SET_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_25]

//>> SET_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_25]

//>> CLEAR_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_25]

//>> GET_[SPATTN_MASK_25]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_25]

//>> GET_[SPATTN_MASK_25]
static inline bool GET_SPATTN_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_25]

//>> SET_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_26]

//>> SET_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_26]

//>> SET_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_26]

//>> CLEAR_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_26]

//>> GET_[SPATTN_MASK_26]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_26]

//>> GET_[SPATTN_MASK_26]
static inline bool GET_SPATTN_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_26]

//>> SET_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_27]

//>> SET_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_27]

//>> SET_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_27]

//>> CLEAR_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_27]

//>> GET_[SPATTN_MASK_27]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_27]

//>> GET_[SPATTN_MASK_27]
static inline bool GET_SPATTN_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_27]

//>> SET_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_28]

//>> SET_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_28]

//>> SET_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_28]

//>> CLEAR_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_28]

//>> GET_[SPATTN_MASK_28]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_28]

//>> GET_[SPATTN_MASK_28]
static inline bool GET_SPATTN_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_28]

//>> SET_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_29]

//>> SET_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_29]

//>> SET_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_29]

//>> CLEAR_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_29]

//>> GET_[SPATTN_MASK_29]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_29]

//>> GET_[SPATTN_MASK_29]
static inline bool GET_SPATTN_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_29]

//>> SET_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_30]

//>> SET_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_30]

//>> SET_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_30]

//>> CLEAR_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_30]

//>> GET_[SPATTN_MASK_30]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_30]

//>> GET_[SPATTN_MASK_30]
static inline bool GET_SPATTN_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_30]

//>> SET_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_31]

//>> SET_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_31]

//>> SET_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_31]

//>> CLEAR_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_31]

//>> GET_[SPATTN_MASK_31]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_31]

//>> GET_[SPATTN_MASK_31]
static inline bool GET_SPATTN_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_31]

//>> SET_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_32]

//>> SET_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_32]

//>> SET_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_32]

//>> CLEAR_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_32]

//>> GET_[SPATTN_MASK_32]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_32]

//>> GET_[SPATTN_MASK_32]
static inline bool GET_SPATTN_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_32]

//>> SET_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_33]

//>> SET_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_33]

//>> SET_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_33]

//>> CLEAR_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_33]

//>> GET_[SPATTN_MASK_33]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_33]

//>> GET_[SPATTN_MASK_33]
static inline bool GET_SPATTN_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_33]

//>> SET_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_34]

//>> SET_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_34]

//>> SET_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_34]

//>> CLEAR_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_34]

//>> GET_[SPATTN_MASK_34]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_34]

//>> GET_[SPATTN_MASK_34]
static inline bool GET_SPATTN_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_34]

//>> SET_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_35]

//>> SET_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.insertFromRight<SPATTN_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_35]

//>> SET_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_SPATTN_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.setBit<SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SPATTN_MASK_35]

//>> CLEAR_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& CLEAR_SPATTN_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return o_data.clearBit<SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SPATTN_MASK_35]

//>> GET_[SPATTN_MASK_35]
static inline fapi2::buffer<uint64_t>& GET_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.extractToRight<SPATTN_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_35]

//>> GET_[SPATTN_MASK_35]
static inline bool GET_SPATTN_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SPATTN_MASK_RW, SPATTN_MASK_WO_CLEAR, SPATTN_MASK_WO_OR));
#endif
    return i_data.getBit<SPATTN_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access SPATTN_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SPATTN_MASK_35]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
