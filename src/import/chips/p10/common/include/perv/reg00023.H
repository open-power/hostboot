/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00023.H $         */
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

#ifndef __PERV_REG00023_H_
#define __PERV_REG00023_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[TOD_TX_TTYPE_2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_TX_TTYPE_2_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TX_TTYPE_2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_TX_TTYPE_2_REG]

//>> GET_[TOD_TX_TTYPE_2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_TX_TTYPE_2_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TX_TTYPE_2_REG;
#endif
    return fapi2::getScom(i_target, TOD_TX_TTYPE_2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_TX_TTYPE_2_REG]

//>> PUT_[TOD_TX_TTYPE_2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_TX_TTYPE_2_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_2_REG));
#endif
    return fapi2::putScom(i_target, TOD_TX_TTYPE_2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_TX_TTYPE_2_REG]


//>> SET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_2_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]

//>> SET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_2_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]

//>> SET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_2_REG));
#endif
    return o_data.setBit<TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]

//>> CLEAR_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_2_REG));
#endif
    return o_data.clearBit<TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]

//>> GET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_2_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]

//>> GET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]
static inline bool GET_TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_2_REG));
#endif
    return i_data.getBit<TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER]

//>> PREP_[TOD_TX_TTYPE_4_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_TX_TTYPE_4_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TX_TTYPE_4_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_TX_TTYPE_4_REG]

//>> GET_[TOD_TX_TTYPE_4_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_TX_TTYPE_4_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TX_TTYPE_4_REG;
#endif
    return fapi2::getScom(i_target, TOD_TX_TTYPE_4_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_TX_TTYPE_4_REG]

//>> PUT_[TOD_TX_TTYPE_4_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_TX_TTYPE_4_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_4_REG));
#endif
    return fapi2::putScom(i_target, TOD_TX_TTYPE_4_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_TX_TTYPE_4_REG]


//>> SET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_4_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]

//>> SET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_4_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]

//>> SET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_4_REG));
#endif
    return o_data.setBit<TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]

//>> CLEAR_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_4_REG));
#endif
    return o_data.clearBit<TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]

//>> GET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_4_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]

//>> GET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]
static inline bool GET_TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_4_REG));
#endif
    return i_data.getBit<TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER]

//>> PREP_[TOD_TX_TTYPE_5_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_TX_TTYPE_5_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TX_TTYPE_5_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_TX_TTYPE_5_REG]

//>> GET_[TOD_TX_TTYPE_5_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_TX_TTYPE_5_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TX_TTYPE_5_REG;
#endif
    return fapi2::getScom(i_target, TOD_TX_TTYPE_5_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_TX_TTYPE_5_REG]

//>> PUT_[TOD_TX_TTYPE_5_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_TX_TTYPE_5_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_5_REG));
#endif
    return fapi2::putScom(i_target, TOD_TX_TTYPE_5_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_TX_TTYPE_5_REG]


//>> SET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_5_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]

//>> SET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_5_REG));
#endif
    return o_data.insertFromRight<TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]

//>> SET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_5_REG));
#endif
    return o_data.setBit<TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]

//>> CLEAR_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_5_REG));
#endif
    return o_data.clearBit<TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]

//>> GET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_5_REG));
#endif
    return i_data.extractToRight<TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]

//>> GET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]
static inline bool GET_TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TX_TTYPE_5_REG));
#endif
    return i_data.getBit<TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER]

//>> PREP_[XSTOP4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP4]

//>> GET_[XSTOP4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP4(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP4;
#endif
    return fapi2::getScom(i_target, XSTOP4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP4]

//>> PUT_[XSTOP4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP4(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return fapi2::putScom(i_target, XSTOP4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP4]


//>> SET_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_ENABLE]

//>> SET_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_ENABLE]

//>> SET_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_ENABLE]

//>> CLEAR_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_ENABLE]

//>> GET_[XSTOP4_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_ENABLE]

//>> GET_[XSTOP4_ENABLE]
static inline bool GET_XSTOP4_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_ENABLE]

//>> SET_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_SNOPA]

//>> SET_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_SNOPA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_SNOPA]

//>> SET_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_SNOPA]

//>> CLEAR_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_WAIT_SNOPA]

//>> GET_[XSTOP4_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_WAIT_SNOPA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_SNOPA]

//>> GET_[XSTOP4_WAIT_SNOPA]
static inline bool GET_XSTOP4_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_SNOPA]

//>> SET_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_TRIGGER_OPCG_GO]

//>> SET_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_TRIGGER_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_TRIGGER_OPCG_GO]

//>> SET_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_TRIGGER_OPCG_GO]

//>> CLEAR_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_TRIGGER_OPCG_GO]

//>> GET_[XSTOP4_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_TRIGGER_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_TRIGGER_OPCG_GO]

//>> GET_[XSTOP4_TRIGGER_OPCG_GO]
static inline bool GET_XSTOP4_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_TRIGGER_OPCG_GO]

//>> SET_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_ALWAYS]

//>> SET_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_ALWAYS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_ALWAYS]

//>> SET_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_ALWAYS]

//>> CLEAR_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_WAIT_ALWAYS]

//>> GET_[XSTOP4_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_WAIT_ALWAYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_ALWAYS]

//>> GET_[XSTOP4_WAIT_ALWAYS]
static inline bool GET_XSTOP4_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_ALWAYS]

//>> SET_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_PERV]

//>> SET_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_PERV]

//>> SET_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_PERV]

//>> CLEAR_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_PERV]

//>> GET_[XSTOP4_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_PERV]

//>> GET_[XSTOP4_REGION_PERV]
static inline bool GET_XSTOP4_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_PERV]

//>> SET_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT1]

//>> SET_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT1]

//>> SET_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT1]

//>> CLEAR_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT1]

//>> GET_[XSTOP4_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT1]

//>> GET_[XSTOP4_REGION_UNIT1]
static inline bool GET_XSTOP4_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT1]

//>> SET_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT2]

//>> SET_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT2]

//>> SET_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT2]

//>> CLEAR_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT2]

//>> GET_[XSTOP4_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT2]

//>> GET_[XSTOP4_REGION_UNIT2]
static inline bool GET_XSTOP4_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT2]

//>> SET_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT3]

//>> SET_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT3]

//>> SET_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT3]

//>> CLEAR_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT3]

//>> GET_[XSTOP4_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT3]

//>> GET_[XSTOP4_REGION_UNIT3]
static inline bool GET_XSTOP4_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT3]

//>> SET_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT4]

//>> SET_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT4]

//>> SET_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT4]

//>> CLEAR_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT4]

//>> GET_[XSTOP4_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT4]

//>> GET_[XSTOP4_REGION_UNIT4]
static inline bool GET_XSTOP4_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT4]

//>> SET_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT5]

//>> SET_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT5]

//>> SET_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT5]

//>> CLEAR_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT5]

//>> GET_[XSTOP4_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT5]

//>> GET_[XSTOP4_REGION_UNIT5]
static inline bool GET_XSTOP4_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT5]

//>> SET_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT6]

//>> SET_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT6]

//>> SET_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT6]

//>> CLEAR_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT6]

//>> GET_[XSTOP4_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT6]

//>> GET_[XSTOP4_REGION_UNIT6]
static inline bool GET_XSTOP4_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT6]

//>> SET_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT7]

//>> SET_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT7]

//>> SET_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT7]

//>> CLEAR_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT7]

//>> GET_[XSTOP4_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT7]

//>> GET_[XSTOP4_REGION_UNIT7]
static inline bool GET_XSTOP4_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT7]

//>> SET_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT8]

//>> SET_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT8]

//>> SET_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT8]

//>> CLEAR_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT8]

//>> GET_[XSTOP4_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT8]

//>> GET_[XSTOP4_REGION_UNIT8]
static inline bool GET_XSTOP4_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT8]

//>> SET_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT9]

//>> SET_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT9]

//>> SET_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT9]

//>> CLEAR_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT9]

//>> GET_[XSTOP4_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT9]

//>> GET_[XSTOP4_REGION_UNIT9]
static inline bool GET_XSTOP4_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT9]

//>> SET_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT10]

//>> SET_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT10]

//>> SET_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT10]

//>> CLEAR_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT10]

//>> GET_[XSTOP4_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT10]

//>> GET_[XSTOP4_REGION_UNIT10]
static inline bool GET_XSTOP4_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT10]

//>> SET_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT11]

//>> SET_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT11]

//>> SET_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT11]

//>> CLEAR_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT11]

//>> GET_[XSTOP4_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT11]

//>> GET_[XSTOP4_REGION_UNIT11]
static inline bool GET_XSTOP4_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT11]

//>> SET_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT12]

//>> SET_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT12]

//>> SET_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT12]

//>> CLEAR_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT12]

//>> GET_[XSTOP4_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT12]

//>> GET_[XSTOP4_REGION_UNIT12]
static inline bool GET_XSTOP4_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT12]

//>> SET_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT13]

//>> SET_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT13]

//>> SET_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT13]

//>> CLEAR_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT13]

//>> GET_[XSTOP4_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT13]

//>> GET_[XSTOP4_REGION_UNIT13]
static inline bool GET_XSTOP4_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT13]

//>> SET_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT14]

//>> SET_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT14]

//>> SET_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.setBit<XSTOP4_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_REGION_UNIT14]

//>> CLEAR_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.clearBit<XSTOP4_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP4_REGION_UNIT14]

//>> GET_[XSTOP4_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT14]

//>> GET_[XSTOP4_REGION_UNIT14]
static inline bool GET_XSTOP4_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.getBit<XSTOP4_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP4_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_REGION_UNIT14]

//>> SET_[XSTOP4_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_CYCLES,
           XSTOP4_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP4_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_CYCLES]

//>> SET_[XSTOP4_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP4_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return o_data.insertFromRight<XSTOP4_WAIT_CYCLES,
           XSTOP4_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP4_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP4_WAIT_CYCLES]

//>> GET_[XSTOP4_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_XSTOP4_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP4));
#endif
    return i_data.extractToRight<XSTOP4_WAIT_CYCLES,
           XSTOP4_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP4_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP4_WAIT_CYCLES]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
