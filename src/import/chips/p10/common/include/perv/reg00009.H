/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00009.H $         */
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

#ifndef __PERV_REG00009_H_
#define __PERV_REG00009_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[TOD_LOAD_MOD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_LOAD_MOD_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_LOAD_MOD_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_LOAD_MOD_REG]

//>> GET_[TOD_LOAD_MOD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_LOAD_MOD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_LOAD_MOD_REG;
#endif
    return fapi2::getScom(i_target, TOD_LOAD_MOD_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_LOAD_MOD_REG]

//>> PUT_[TOD_LOAD_MOD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_LOAD_MOD_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return fapi2::putScom(i_target, TOD_LOAD_MOD_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_LOAD_MOD_REG]


//>> SET_[TOD_LOAD_MOD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_MOD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return o_data.insertFromRight<TOD_LOAD_MOD_REG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_LOAD_MOD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_MOD_REG_TRIGGER]

//>> SET_[TOD_LOAD_MOD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_MOD_REG_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return o_data.insertFromRight<TOD_LOAD_MOD_REG_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_LOAD_MOD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_MOD_REG_TRIGGER]

//>> SET_[TOD_LOAD_MOD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_MOD_REG_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return o_data.setBit<TOD_LOAD_MOD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_LOAD_MOD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_MOD_REG_TRIGGER]

//>> CLEAR_[TOD_LOAD_MOD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_LOAD_MOD_REG_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return o_data.clearBit<TOD_LOAD_MOD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_LOAD_MOD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_LOAD_MOD_REG_TRIGGER]

//>> GET_[TOD_LOAD_MOD_REG_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_LOAD_MOD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return i_data.extractToRight<TOD_LOAD_MOD_REG_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_LOAD_MOD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_LOAD_MOD_REG_TRIGGER]

//>> GET_[TOD_LOAD_MOD_REG_TRIGGER]
static inline bool GET_TOD_LOAD_MOD_REG_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return i_data.getBit<TOD_LOAD_MOD_REG_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_LOAD_MOD_REG_TRIGGER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_LOAD_MOD_REG_TRIGGER]

//>> SET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_MOD_REG_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return o_data.insertFromRight<TOD_LOAD_MOD_REG_SYNC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_LOAD_MOD_REG_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]

//>> SET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_MOD_REG_SYNC_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return o_data.insertFromRight<TOD_LOAD_MOD_REG_SYNC_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_LOAD_MOD_REG_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]

//>> SET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_LOAD_MOD_REG_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return o_data.setBit<TOD_LOAD_MOD_REG_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_LOAD_MOD_REG_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]

//>> CLEAR_[TOD_LOAD_MOD_REG_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_LOAD_MOD_REG_SYNC_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return o_data.clearBit<TOD_LOAD_MOD_REG_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_LOAD_MOD_REG_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_LOAD_MOD_REG_SYNC_ENABLE]

//>> GET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_LOAD_MOD_REG_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return i_data.extractToRight<TOD_LOAD_MOD_REG_SYNC_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_LOAD_MOD_REG_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]

//>> GET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]
static inline bool GET_TOD_LOAD_MOD_REG_SYNC_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_LOAD_MOD_REG));
#endif
    return i_data.getBit<TOD_LOAD_MOD_REG_SYNC_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_LOAD_MOD_REG_SYNC_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_LOAD_MOD_REG_SYNC_ENABLE]

//>> PREP_[TOD_M_PATH_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_M_PATH_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_M_PATH_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_M_PATH_CTRL_REG]

//>> GET_[TOD_M_PATH_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_M_PATH_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_M_PATH_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_M_PATH_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG]

//>> PUT_[TOD_M_PATH_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_M_PATH_CTRL_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_M_PATH_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_M_PATH_CTRL_REG]


//>> SET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]

//>> SET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]

//>> SET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]

//>> GET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]

//>> GET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]
static inline bool GET_TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID]

//>> SET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]

//>> SET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]

//>> SET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]

//>> GET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]

//>> GET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]
static inline bool GET_TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT,
           TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT]

//>> SET_[TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT,
           TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT]

//>> GET_[TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT,
           TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION,
           TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION,
           TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION,
           TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT,
           TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT,
           TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT,
           TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION,
           TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION,
           TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION,
           TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT,
           TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT,
           TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT,
           TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT]

//>> SET_[TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
           TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR]

//>> SET_[TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
           TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR]

//>> GET_[TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR,
           TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR]

//>> SET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]

//>> SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.setBit<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]

//>> CLEAR_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return o_data.clearBit<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]

//>> GET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]
static inline bool GET_TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_M_PATH_CTRL_REG));
#endif
    return i_data.getBit<TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE]

//>> PREP_[TOD_TIMER_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_TIMER_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TIMER_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_TIMER_REG]

//>> GET_[TOD_TIMER_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_TIMER_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_TIMER_REG;
#endif
    return fapi2::getScom(i_target, TOD_TIMER_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_TIMER_REG]

//>> PUT_[TOD_TIMER_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_TIMER_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return fapi2::putScom(i_target, TOD_TIMER_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_TIMER_REG]


//>> SET_[TOD_TIMER_REG_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_VALUE,
           TOD_TIMER_REG_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TIMER_REG_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_VALUE]

//>> SET_[TOD_TIMER_REG_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_VALUE,
           TOD_TIMER_REG_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TIMER_REG_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_VALUE]

//>> GET_[TOD_TIMER_REG_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_TIMER_REG_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return i_data.extractToRight<TOD_TIMER_REG_VALUE,
           TOD_TIMER_REG_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TIMER_REG_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TIMER_REG_VALUE]

//>> SET_[TOD_TIMER_REG_ENABLE0]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_ENABLE0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_ENABLE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_ENABLE0]

//>> SET_[TOD_TIMER_REG_ENABLE0]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_ENABLE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_ENABLE0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_ENABLE0]

//>> SET_[TOD_TIMER_REG_ENABLE0]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_ENABLE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.setBit<TOD_TIMER_REG_ENABLE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_ENABLE0]

//>> CLEAR_[TOD_TIMER_REG_ENABLE0]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TIMER_REG_ENABLE0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.clearBit<TOD_TIMER_REG_ENABLE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TIMER_REG_ENABLE0]

//>> GET_[TOD_TIMER_REG_ENABLE0]
static inline fapi2::buffer<uint64_t>& GET_TOD_TIMER_REG_ENABLE0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return i_data.extractToRight<TOD_TIMER_REG_ENABLE0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TIMER_REG_ENABLE0]

//>> GET_[TOD_TIMER_REG_ENABLE0]
static inline bool GET_TOD_TIMER_REG_ENABLE0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return i_data.getBit<TOD_TIMER_REG_ENABLE0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TIMER_REG_ENABLE0]

//>> SET_[TOD_TIMER_REG_ENABLE1]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_ENABLE1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_ENABLE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_ENABLE1]

//>> SET_[TOD_TIMER_REG_ENABLE1]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_ENABLE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_ENABLE1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_ENABLE1]

//>> SET_[TOD_TIMER_REG_ENABLE1]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_ENABLE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.setBit<TOD_TIMER_REG_ENABLE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_ENABLE1]

//>> CLEAR_[TOD_TIMER_REG_ENABLE1]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TIMER_REG_ENABLE1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.clearBit<TOD_TIMER_REG_ENABLE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TIMER_REG_ENABLE1]

//>> GET_[TOD_TIMER_REG_ENABLE1]
static inline fapi2::buffer<uint64_t>& GET_TOD_TIMER_REG_ENABLE1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return i_data.extractToRight<TOD_TIMER_REG_ENABLE1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TIMER_REG_ENABLE1]

//>> GET_[TOD_TIMER_REG_ENABLE1]
static inline bool GET_TOD_TIMER_REG_ENABLE1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return i_data.getBit<TOD_TIMER_REG_ENABLE1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TIMER_REG_ENABLE1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TIMER_REG_ENABLE1]

//>> SET_[TOD_TIMER_REG_STATUS0]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_STATUS0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_STATUS0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TIMER_REG_STATUS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_STATUS0]

//>> SET_[TOD_TIMER_REG_STATUS0]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_STATUS0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_STATUS0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TIMER_REG_STATUS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_STATUS0]

//>> SET_[TOD_TIMER_REG_STATUS0]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_STATUS0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.setBit<TOD_TIMER_REG_STATUS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TIMER_REG_STATUS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_STATUS0]

//>> CLEAR_[TOD_TIMER_REG_STATUS0]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TIMER_REG_STATUS0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.clearBit<TOD_TIMER_REG_STATUS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TIMER_REG_STATUS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TIMER_REG_STATUS0]

//>> GET_[TOD_TIMER_REG_STATUS0]
static inline fapi2::buffer<uint64_t>& GET_TOD_TIMER_REG_STATUS0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return i_data.extractToRight<TOD_TIMER_REG_STATUS0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TIMER_REG_STATUS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TIMER_REG_STATUS0]

//>> GET_[TOD_TIMER_REG_STATUS0]
static inline bool GET_TOD_TIMER_REG_STATUS0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return i_data.getBit<TOD_TIMER_REG_STATUS0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TIMER_REG_STATUS0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TIMER_REG_STATUS0]

//>> SET_[TOD_TIMER_REG_STATUS1]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_STATUS1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_STATUS1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_TIMER_REG_STATUS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_STATUS1]

//>> SET_[TOD_TIMER_REG_STATUS1]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_STATUS1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.insertFromRight<TOD_TIMER_REG_STATUS1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_TIMER_REG_STATUS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_STATUS1]

//>> SET_[TOD_TIMER_REG_STATUS1]
static inline fapi2::buffer<uint64_t>& SET_TOD_TIMER_REG_STATUS1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.setBit<TOD_TIMER_REG_STATUS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_TIMER_REG_STATUS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_TIMER_REG_STATUS1]

//>> CLEAR_[TOD_TIMER_REG_STATUS1]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_TIMER_REG_STATUS1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return o_data.clearBit<TOD_TIMER_REG_STATUS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_TIMER_REG_STATUS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_TIMER_REG_STATUS1]

//>> GET_[TOD_TIMER_REG_STATUS1]
static inline fapi2::buffer<uint64_t>& GET_TOD_TIMER_REG_STATUS1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return i_data.extractToRight<TOD_TIMER_REG_STATUS1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_TIMER_REG_STATUS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TIMER_REG_STATUS1]

//>> GET_[TOD_TIMER_REG_STATUS1]
static inline bool GET_TOD_TIMER_REG_STATUS1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_TIMER_REG));
#endif
    return i_data.getBit<TOD_TIMER_REG_STATUS1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_TIMER_REG_STATUS1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_TIMER_REG_STATUS1]

//>> PREP_[TRA0_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TRA0_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TRA0_TR0_TRACE_LO_DATA_REG]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TRA0_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TRA0_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, TRA0_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG]

//>> PUT_[TRA0_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TRA0_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, TRA0_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TRA0_TR0_TRACE_LO_DATA_REG]


//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline bool GET_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline bool GET_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline bool GET_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TRA0_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> SET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> GET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> PREP_[XSTOP1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP1]

//>> GET_[XSTOP1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP1(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP1;
#endif
    return fapi2::getScom(i_target, XSTOP1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP1]

//>> PUT_[XSTOP1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP1(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return fapi2::putScom(i_target, XSTOP1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP1]


//>> SET_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_ENABLE]

//>> SET_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_ENABLE]

//>> SET_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_ENABLE]

//>> CLEAR_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_ENABLE]

//>> GET_[XSTOP1_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_ENABLE]

//>> GET_[XSTOP1_ENABLE]
static inline bool GET_XSTOP1_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_ENABLE]

//>> SET_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_SNOPA]

//>> SET_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_SNOPA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_SNOPA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_SNOPA]

//>> SET_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_SNOPA]

//>> CLEAR_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_WAIT_SNOPA]

//>> GET_[XSTOP1_WAIT_SNOPA]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_WAIT_SNOPA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_SNOPA]

//>> GET_[XSTOP1_WAIT_SNOPA]
static inline bool GET_XSTOP1_WAIT_SNOPA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_WAIT_SNOPA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_WAIT_SNOPA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_SNOPA]

//>> SET_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_TRIGGER_OPCG_GO]

//>> SET_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_TRIGGER_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_TRIGGER_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_TRIGGER_OPCG_GO]

//>> SET_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_TRIGGER_OPCG_GO]

//>> CLEAR_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_TRIGGER_OPCG_GO]

//>> GET_[XSTOP1_TRIGGER_OPCG_GO]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_TRIGGER_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_TRIGGER_OPCG_GO]

//>> GET_[XSTOP1_TRIGGER_OPCG_GO]
static inline bool GET_XSTOP1_TRIGGER_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_TRIGGER_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_TRIGGER_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_TRIGGER_OPCG_GO]

//>> SET_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_ALWAYS]

//>> SET_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_ALWAYS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_ALWAYS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_ALWAYS]

//>> SET_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_ALWAYS]

//>> CLEAR_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_WAIT_ALWAYS]

//>> GET_[XSTOP1_WAIT_ALWAYS]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_WAIT_ALWAYS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_ALWAYS]

//>> GET_[XSTOP1_WAIT_ALWAYS]
static inline bool GET_XSTOP1_WAIT_ALWAYS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_WAIT_ALWAYS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_WAIT_ALWAYS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_ALWAYS]

//>> SET_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_PERV]

//>> SET_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_PERV]

//>> SET_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_PERV]

//>> CLEAR_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_PERV]

//>> GET_[XSTOP1_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_PERV]

//>> GET_[XSTOP1_REGION_PERV]
static inline bool GET_XSTOP1_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_PERV]

//>> SET_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT1]

//>> SET_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT1]

//>> SET_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT1]

//>> CLEAR_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT1]

//>> GET_[XSTOP1_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT1]

//>> GET_[XSTOP1_REGION_UNIT1]
static inline bool GET_XSTOP1_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT1]

//>> SET_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT2]

//>> SET_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT2]

//>> SET_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT2]

//>> CLEAR_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT2]

//>> GET_[XSTOP1_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT2]

//>> GET_[XSTOP1_REGION_UNIT2]
static inline bool GET_XSTOP1_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT2]

//>> SET_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT3]

//>> SET_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT3]

//>> SET_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT3]

//>> CLEAR_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT3]

//>> GET_[XSTOP1_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT3]

//>> GET_[XSTOP1_REGION_UNIT3]
static inline bool GET_XSTOP1_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT3]

//>> SET_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT4]

//>> SET_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT4]

//>> SET_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT4]

//>> CLEAR_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT4]

//>> GET_[XSTOP1_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT4]

//>> GET_[XSTOP1_REGION_UNIT4]
static inline bool GET_XSTOP1_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT4]

//>> SET_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT5]

//>> SET_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT5]

//>> SET_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT5]

//>> CLEAR_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT5]

//>> GET_[XSTOP1_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT5]

//>> GET_[XSTOP1_REGION_UNIT5]
static inline bool GET_XSTOP1_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT5]

//>> SET_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT6]

//>> SET_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT6]

//>> SET_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT6]

//>> CLEAR_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT6]

//>> GET_[XSTOP1_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT6]

//>> GET_[XSTOP1_REGION_UNIT6]
static inline bool GET_XSTOP1_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT6]

//>> SET_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT7]

//>> SET_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT7]

//>> SET_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT7]

//>> CLEAR_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT7]

//>> GET_[XSTOP1_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT7]

//>> GET_[XSTOP1_REGION_UNIT7]
static inline bool GET_XSTOP1_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT7]

//>> SET_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT8]

//>> SET_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT8]

//>> SET_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT8]

//>> CLEAR_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT8]

//>> GET_[XSTOP1_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT8]

//>> GET_[XSTOP1_REGION_UNIT8]
static inline bool GET_XSTOP1_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT8]

//>> SET_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT9]

//>> SET_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT9]

//>> SET_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT9]

//>> CLEAR_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT9]

//>> GET_[XSTOP1_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT9]

//>> GET_[XSTOP1_REGION_UNIT9]
static inline bool GET_XSTOP1_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT9]

//>> SET_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT10]

//>> SET_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT10]

//>> SET_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT10]

//>> CLEAR_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT10]

//>> GET_[XSTOP1_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT10]

//>> GET_[XSTOP1_REGION_UNIT10]
static inline bool GET_XSTOP1_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT10]

//>> SET_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT11]

//>> SET_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT11]

//>> SET_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT11]

//>> CLEAR_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT11]

//>> GET_[XSTOP1_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT11]

//>> GET_[XSTOP1_REGION_UNIT11]
static inline bool GET_XSTOP1_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT11]

//>> SET_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT12]

//>> SET_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT12]

//>> SET_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT12]

//>> CLEAR_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT12]

//>> GET_[XSTOP1_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT12]

//>> GET_[XSTOP1_REGION_UNIT12]
static inline bool GET_XSTOP1_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT12]

//>> SET_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT13]

//>> SET_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT13]

//>> SET_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT13]

//>> CLEAR_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT13]

//>> GET_[XSTOP1_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT13]

//>> GET_[XSTOP1_REGION_UNIT13]
static inline bool GET_XSTOP1_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT13]

//>> SET_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT14]

//>> SET_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT14]

//>> SET_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.setBit<XSTOP1_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_REGION_UNIT14]

//>> CLEAR_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.clearBit<XSTOP1_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP1_REGION_UNIT14]

//>> GET_[XSTOP1_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT14]

//>> GET_[XSTOP1_REGION_UNIT14]
static inline bool GET_XSTOP1_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.getBit<XSTOP1_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP1_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_REGION_UNIT14]

//>> SET_[XSTOP1_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_CYCLES,
           XSTOP1_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP1_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_CYCLES]

//>> SET_[XSTOP1_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& SET_XSTOP1_WAIT_CYCLES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return o_data.insertFromRight<XSTOP1_WAIT_CYCLES,
           XSTOP1_WAIT_CYCLES_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP1_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP1_WAIT_CYCLES]

//>> GET_[XSTOP1_WAIT_CYCLES]
static inline fapi2::buffer<uint64_t>& GET_XSTOP1_WAIT_CYCLES(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP1));
#endif
    return i_data.extractToRight<XSTOP1_WAIT_CYCLES,
           XSTOP1_WAIT_CYCLES_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP1_WAIT_CYCLES chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP1_WAIT_CYCLES]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
