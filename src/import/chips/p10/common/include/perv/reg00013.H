/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00013.H $         */
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

#ifndef __PERV_REG00013_H_
#define __PERV_REG00013_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[LOCAL_XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_XSTOP_MASK_RW]

//>> GET_[LOCAL_XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_RW;
#endif
    return fapi2::getScom(i_target, LOCAL_XSTOP_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_RW]

//>> PUT_[LOCAL_XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, LOCAL_XSTOP_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_XSTOP_MASK_RW]

//>> PREP_[LOCAL_XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_XSTOP_MASK_WO_CLEAR]

//>> GET_[LOCAL_XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, LOCAL_XSTOP_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_WO_CLEAR]

//>> PUT_[LOCAL_XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, LOCAL_XSTOP_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_XSTOP_MASK_WO_CLEAR]

//>> PREP_[LOCAL_XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_XSTOP_MASK_WO_OR]

//>> GET_[LOCAL_XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, LOCAL_XSTOP_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_WO_OR]

//>> PUT_[LOCAL_XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, LOCAL_XSTOP_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_XSTOP_MASK_WO_OR]


//>> SET_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_01]

//>> SET_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_01]

//>> SET_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_01]

//>> CLEAR_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_01]

//>> GET_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_01]

//>> GET_[LOCAL_XSTOP_MASK_01]
static inline bool GET_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_01]

//>> SET_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_02]

//>> SET_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_02]

//>> SET_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_02]

//>> CLEAR_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_02]

//>> GET_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_02]

//>> GET_[LOCAL_XSTOP_MASK_02]
static inline bool GET_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_02]

//>> SET_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_03]

//>> SET_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_03]

//>> SET_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_03]

//>> CLEAR_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_03]

//>> GET_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_03]

//>> GET_[LOCAL_XSTOP_MASK_03]
static inline bool GET_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_03]

//>> SET_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_04]

//>> SET_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_04]

//>> SET_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_04]

//>> CLEAR_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_04]

//>> GET_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_04]

//>> GET_[LOCAL_XSTOP_MASK_04]
static inline bool GET_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_04]

//>> SET_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_05]

//>> SET_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_05]

//>> SET_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_05]

//>> CLEAR_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_05]

//>> GET_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_05]

//>> GET_[LOCAL_XSTOP_MASK_05]
static inline bool GET_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_05]

//>> SET_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_06]

//>> SET_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_06]

//>> SET_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_06]

//>> CLEAR_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_06]

//>> GET_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_06]

//>> GET_[LOCAL_XSTOP_MASK_06]
static inline bool GET_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_06]

//>> SET_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_07]

//>> SET_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_07]

//>> SET_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_07]

//>> CLEAR_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_07]

//>> GET_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_07]

//>> GET_[LOCAL_XSTOP_MASK_07]
static inline bool GET_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_07]

//>> SET_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_08]

//>> SET_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_08]

//>> SET_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_08]

//>> CLEAR_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_08]

//>> GET_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_08]

//>> GET_[LOCAL_XSTOP_MASK_08]
static inline bool GET_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_08]

//>> SET_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_09]

//>> SET_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_09]

//>> SET_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_09]

//>> CLEAR_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_09]

//>> GET_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_09]

//>> GET_[LOCAL_XSTOP_MASK_09]
static inline bool GET_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_09]

//>> SET_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_10]

//>> SET_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_10]

//>> SET_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_10]

//>> CLEAR_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_10]

//>> GET_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_10]

//>> GET_[LOCAL_XSTOP_MASK_10]
static inline bool GET_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_10]

//>> SET_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_11]

//>> SET_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_11]

//>> SET_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_11]

//>> CLEAR_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_11]

//>> GET_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_11]

//>> GET_[LOCAL_XSTOP_MASK_11]
static inline bool GET_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_11]

//>> SET_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_12]

//>> SET_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_12]

//>> SET_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_12]

//>> CLEAR_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_12]

//>> GET_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_12]

//>> GET_[LOCAL_XSTOP_MASK_12]
static inline bool GET_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_12]

//>> SET_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_13]

//>> SET_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_13]

//>> SET_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_13]

//>> CLEAR_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_13]

//>> GET_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_13]

//>> GET_[LOCAL_XSTOP_MASK_13]
static inline bool GET_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_13]

//>> SET_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_14]

//>> SET_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_14]

//>> SET_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_14]

//>> CLEAR_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_14]

//>> GET_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_14]

//>> GET_[LOCAL_XSTOP_MASK_14]
static inline bool GET_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_14]

//>> SET_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_15]

//>> SET_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_15]

//>> SET_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_15]

//>> CLEAR_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_15]

//>> GET_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_15]

//>> GET_[LOCAL_XSTOP_MASK_15]
static inline bool GET_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_15]

//>> PREP_[REC_ERR_MST14_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_REC_ERR_MST14_REG2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST14_REG2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[REC_ERR_MST14_REG2]

//>> GET_[REC_ERR_MST14_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_REC_ERR_MST14_REG2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = REC_ERR_MST14_REG2;
#endif
    return fapi2::getScom(i_target, REC_ERR_MST14_REG2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[REC_ERR_MST14_REG2]

//>> PUT_[REC_ERR_MST14_REG2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_REC_ERR_MST14_REG2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return fapi2::putScom(i_target, REC_ERR_MST14_REG2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[REC_ERR_MST14_REG2]


//>> SET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_32_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_32_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_32_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_32_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_32_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_32_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_32_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_32_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_32_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_32_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_32_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_32_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_32_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_32_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_32_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_32_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_32_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_32_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_33_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_33_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_33_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_33_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_33_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_33_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_33_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_33_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_33_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_33_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_33_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_33_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_33_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_33_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_33_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_33_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_33_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_33_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_34_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_34_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_34_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_34_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_34_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_34_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_34_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_34_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_34_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_34_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_34_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_34_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_34_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_34_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_34_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_34_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_34_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_34_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_35_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_35_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_35_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_35_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_35_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_35_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_35_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_35_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_35_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_35_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_35_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_35_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_35_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_35_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_35_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_35_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_35_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_35_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_36_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_36_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_36_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_36_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_36_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_36_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_36_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_36_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_36_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_36_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_36_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_36_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_36_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_36_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_36_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_36_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_36_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_36_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_37_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_37_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_37_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_37_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_37_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_37_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_37_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_37_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_37_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_37_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_37_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_37_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_37_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_37_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_37_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_37_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_37_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_37_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_38_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_38_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_38_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_38_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_38_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_38_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_38_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_38_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_38_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_38_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_38_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_38_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_38_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_38_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_38_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_38_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_38_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_38_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_39_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_39_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_39_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_39_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_39_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_39_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_39_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_39_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_39_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_39_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_39_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_39_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_39_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_39_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_39_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_39_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_39_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_39_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_40_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_40_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_40_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_40_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_40_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_40_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_40_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_40_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_40_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_40_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_40_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_40_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_40_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_40_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_40_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_40_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_40_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_40_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_41_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_41_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_41_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_41_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_41_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_41_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_41_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_41_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_41_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_41_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_41_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_41_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_41_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_41_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_41_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_41_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_41_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_41_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_42_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_42_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_42_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_42_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_42_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_42_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_42_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_42_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_42_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_42_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_42_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_42_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_42_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_42_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_42_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_42_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_42_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_42_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_43_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_43_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_43_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_43_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_43_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_43_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_43_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_43_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_43_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_43_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_43_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_43_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_43_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_43_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_43_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_43_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_43_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_43_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_44_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_44_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_44_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_44_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_44_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_44_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_44_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_44_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_44_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_44_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_44_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_44_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_44_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_44_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_44_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_44_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_44_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_44_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_45_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_45_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_45_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_45_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_45_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_45_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_45_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_45_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_45_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_45_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_45_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_45_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_45_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_45_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_45_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_45_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_45_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_45_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_46_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_46_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_46_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_46_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_46_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_46_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_46_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_46_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_46_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_46_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_46_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_46_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_46_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_46_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_46_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_46_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_46_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_46_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.setBit<REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]

//>> CLEAR_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& CLEAR_REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.clearBit<REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]

//>> GET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]
static inline bool GET_REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.getBit<REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT]

//>> SET_[REC_ERR_MST14_REG2_47_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_47_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_47_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_47_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access REC_ERR_MST14_REG2_47_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_47_MST14_ERROR_CODE]

//>> SET_[REC_ERR_MST14_REG2_47_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& SET_REC_ERR_MST14_REG2_47_MST14_ERROR_CODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return o_data.insertFromRight<REC_ERR_MST14_REG2_47_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_47_MST14_ERROR_CODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access REC_ERR_MST14_REG2_47_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[REC_ERR_MST14_REG2_47_MST14_ERROR_CODE]

//>> GET_[REC_ERR_MST14_REG2_47_MST14_ERROR_CODE]
static inline fapi2::buffer<uint64_t>& GET_REC_ERR_MST14_REG2_47_MST14_ERROR_CODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(REC_ERR_MST14_REG2));
#endif
    return i_data.extractToRight<REC_ERR_MST14_REG2_47_MST14_ERROR_CODE,
           REC_ERR_MST14_REG2_47_MST14_ERROR_CODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access REC_ERR_MST14_REG2_47_MST14_ERROR_CODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[REC_ERR_MST14_REG2_47_MST14_ERROR_CODE]

//>> PREP_[TOD_M_PATH_0_STEP_STEER_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_M_PATH_0_STEP_STEER_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_M_PATH_0_STEP_STEER_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_M_PATH_0_STEP_STEER_REG]

//>> GET_[TOD_M_PATH_0_STEP_STEER_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_M_PATH_0_STEP_STEER_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_M_PATH_0_STEP_STEER_REG;
#endif
    return fapi2::getScom(i_target, TOD_M_PATH_0_STEP_STEER_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_M_PATH_0_STEP_STEER_REG]

//>> PUT_[TOD_M_PATH_0_STEP_STEER_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_M_PATH_0_STEP_STEER_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return fapi2::putScom(i_target, TOD_M_PATH_0_STEP_STEER_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_M_PATH_0_STEP_STEER_REG]


//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_0_STEP_STEER_REG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]

//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_0_STEP_STEER_REG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]

//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.setBit<TOD_M_PATH_0_STEP_STEER_REG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]

//>> CLEAR_[TOD_M_PATH_0_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_0_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_0_STEP_STEER_REG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_0_STEP_STEER_REG_MODE]

//>> GET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_0_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_0_STEP_STEER_REG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]

//>> GET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]
static inline bool GET_TOD_M_PATH_0_STEP_STEER_REG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return i_data.getBit<TOD_M_PATH_0_STEP_STEER_REG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_0_STEP_STEER_REG_MODE]

//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_RATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_0_STEP_STEER_REG_RATE,
           TOD_M_PATH_0_STEP_STEER_REG_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_RATE]

//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_RATE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_0_STEP_STEER_REG_RATE,
           TOD_M_PATH_0_STEP_STEER_REG_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_RATE]

//>> GET_[TOD_M_PATH_0_STEP_STEER_REG_RATE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_0_STEP_STEER_REG_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_0_STEP_STEER_REG_RATE,
           TOD_M_PATH_0_STEP_STEER_REG_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_0_STEP_STEER_REG_RATE]

//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.setBit<TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> CLEAR_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> GET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> GET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]
static inline bool GET_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return i_data.getBit<TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG]

//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE,
           TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE]

//>> SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE,
           TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE]

//>> GET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_0_STEP_STEER_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE,
           TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE]

//>> PREP_[TOD_M_PATH_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_M_PATH_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_M_PATH_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_M_PATH_STATUS_REG]

//>> GET_[TOD_M_PATH_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_M_PATH_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_M_PATH_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TOD_M_PATH_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_M_PATH_STATUS_REG]

//>> PUT_[TOD_M_PATH_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_M_PATH_STATUS_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TOD_M_PATH_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_M_PATH_STATUS_REG]


//>> SET_[TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD,
           TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD]

//>> SET_[TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD,
           TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD]

//>> GET_[TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD,
           TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD]

//>> SET_[TOD_M_PATH_STATUS_REG_0_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_STATUS_REG_0_CPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_STATUS_REG_0_CPS,
           TOD_M_PATH_STATUS_REG_0_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_0_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_STATUS_REG_0_CPS]

//>> SET_[TOD_M_PATH_STATUS_REG_0_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_STATUS_REG_0_CPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_STATUS_REG_0_CPS,
           TOD_M_PATH_STATUS_REG_0_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_0_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_STATUS_REG_0_CPS]

//>> GET_[TOD_M_PATH_STATUS_REG_0_CPS]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_STATUS_REG_0_CPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_STATUS_REG_0_CPS,
           TOD_M_PATH_STATUS_REG_0_CPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_0_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_STATUS_REG_0_CPS]

//>> SET_[TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD,
           TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD]

//>> SET_[TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD,
           TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD]

//>> GET_[TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD,
           TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD]

//>> SET_[TOD_M_PATH_STATUS_REG_1_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_STATUS_REG_1_CPS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_STATUS_REG_1_CPS,
           TOD_M_PATH_STATUS_REG_1_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_1_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_STATUS_REG_1_CPS]

//>> SET_[TOD_M_PATH_STATUS_REG_1_CPS]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_STATUS_REG_1_CPS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_STATUS_REG_1_CPS,
           TOD_M_PATH_STATUS_REG_1_CPS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_1_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_STATUS_REG_1_CPS]

//>> GET_[TOD_M_PATH_STATUS_REG_1_CPS]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_STATUS_REG_1_CPS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_STATUS_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_STATUS_REG_1_CPS,
           TOD_M_PATH_STATUS_REG_1_CPS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_STATUS_REG_1_CPS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_STATUS_REG_1_CPS]

//>> PREP_[TOD_PSS_MSS_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_PSS_MSS_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_PSS_MSS_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_PSS_MSS_CTRL_REG]

//>> GET_[TOD_PSS_MSS_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_PSS_MSS_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_PSS_MSS_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_PSS_MSS_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG]

//>> PUT_[TOD_PSS_MSS_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_PSS_MSS_CTRL_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_PSS_MSS_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_PSS_MSS_CTRL_REG]


//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]

//>> GET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE]

//>> SET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]

//>> SET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]

//>> SET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]

//>> GET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]

//>> GET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH]

//>> SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]

//>> SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]

//>> SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]

//>> GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]

//>> GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19]

//>> SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]

//>> SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]

//>> SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]

//>> GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]

//>> GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20]

//>> SET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]

//>> SET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]

//>> SET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.setBit<TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]

//>> CLEAR_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.clearBit<TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]

//>> GET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]

//>> GET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]
static inline bool GET_TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.getBit<TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD]

//>> SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31,
           TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31]

//>> SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31,
           TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31]

//>> GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31]
static inline fapi2::buffer<uint64_t>& GET_TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_PSS_MSS_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31,
           TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31]

//>> PREP_[TOD_RX_TTYPE_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_RX_TTYPE_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_RX_TTYPE_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_RX_TTYPE_CTRL_REG]

//>> GET_[TOD_RX_TTYPE_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_RX_TTYPE_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_RX_TTYPE_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_RX_TTYPE_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_RX_TTYPE_CTRL_REG]

//>> PUT_[TOD_RX_TTYPE_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_RX_TTYPE_CTRL_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_RX_TTYPE_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_RX_TTYPE_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_RX_TTYPE_CTRL_REG]


//>> SET_[TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA]
static inline fapi2::buffer<uint64_t>& SET_TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_RX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA,
           TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA]

//>> SET_[TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA]
static inline fapi2::buffer<uint64_t>& SET_TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_RX_TTYPE_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA,
           TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA]

//>> GET_[TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA]
static inline fapi2::buffer<uint64_t>& GET_TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_RX_TTYPE_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA,
           TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
