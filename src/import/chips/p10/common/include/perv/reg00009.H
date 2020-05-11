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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
