/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00001.H $         */
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

#ifndef __PERV_REG00001_H_
#define __PERV_REG00001_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RESET_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RESET_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[RESET_REG]

//>> GET_[RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RESET_REG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RESET_REG;
#endif
    return fapi2::getScom(i_target, RESET_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[RESET_REG]

//>> PUT_[RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RESET_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return fapi2::putScom(i_target, RESET_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[RESET_REG]


//>> SET_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_RESET_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_PCB]

//>> SET_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_PCB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_RESET_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_PCB]

//>> SET_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.setBit<RESET_REG_RESET_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_PCB]

//>> CLEAR_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& CLEAR_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.clearBit<RESET_REG_RESET_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RESET_REG_RESET_PCB]

//>> GET_[RESET_REG_RESET_PCB]
static inline fapi2::buffer<uint64_t>& GET_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.extractToRight<RESET_REG_RESET_PCB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_RESET_PCB]

//>> GET_[RESET_REG_RESET_PCB]
static inline bool GET_RESET_REG_RESET_PCB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.getBit<RESET_REG_RESET_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RESET_REG_RESET_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_RESET_PCB]

//>> SET_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_RESET_ENDPOINTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_ENDPOINTS]

//>> SET_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_ENDPOINTS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_RESET_ENDPOINTS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_ENDPOINTS]

//>> SET_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.setBit<RESET_REG_RESET_ENDPOINTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_RESET_ENDPOINTS]

//>> CLEAR_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& CLEAR_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.clearBit<RESET_REG_RESET_ENDPOINTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RESET_REG_RESET_ENDPOINTS]

//>> GET_[RESET_REG_RESET_ENDPOINTS]
static inline fapi2::buffer<uint64_t>& GET_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.extractToRight<RESET_REG_RESET_ENDPOINTS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_RESET_ENDPOINTS]

//>> GET_[RESET_REG_RESET_ENDPOINTS]
static inline bool GET_RESET_REG_RESET_ENDPOINTS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.getBit<RESET_REG_RESET_ENDPOINTS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RESET_REG_RESET_ENDPOINTS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_RESET_ENDPOINTS]

//>> SET_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_TIMEOUT_RESET_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_TIMEOUT_RESET_EN]

//>> SET_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_TIMEOUT_RESET_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_TIMEOUT_RESET_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_TIMEOUT_RESET_EN]

//>> SET_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.setBit<RESET_REG_TIMEOUT_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_TIMEOUT_RESET_EN]

//>> CLEAR_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.clearBit<RESET_REG_TIMEOUT_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RESET_REG_TIMEOUT_RESET_EN]

//>> GET_[RESET_REG_TIMEOUT_RESET_EN]
static inline fapi2::buffer<uint64_t>& GET_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.extractToRight<RESET_REG_TIMEOUT_RESET_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_TIMEOUT_RESET_EN]

//>> GET_[RESET_REG_TIMEOUT_RESET_EN]
static inline bool GET_RESET_REG_TIMEOUT_RESET_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.getBit<RESET_REG_TIMEOUT_RESET_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RESET_REG_TIMEOUT_RESET_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_TIMEOUT_RESET_EN]

//>> SET_[RESET_REG_QUIESCE_PCB]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_QUIESCE_PCB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_QUIESCE_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access RESET_REG_QUIESCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_QUIESCE_PCB]

//>> SET_[RESET_REG_QUIESCE_PCB]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_QUIESCE_PCB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.insertFromRight<RESET_REG_QUIESCE_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access RESET_REG_QUIESCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_QUIESCE_PCB]

//>> SET_[RESET_REG_QUIESCE_PCB]
static inline fapi2::buffer<uint64_t>& SET_RESET_REG_QUIESCE_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.setBit<RESET_REG_QUIESCE_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access RESET_REG_QUIESCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[RESET_REG_QUIESCE_PCB]

//>> CLEAR_[RESET_REG_QUIESCE_PCB]
static inline fapi2::buffer<uint64_t>& CLEAR_RESET_REG_QUIESCE_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return o_data.clearBit<RESET_REG_QUIESCE_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access RESET_REG_QUIESCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[RESET_REG_QUIESCE_PCB]

//>> GET_[RESET_REG_QUIESCE_PCB]
static inline fapi2::buffer<uint64_t>& GET_RESET_REG_QUIESCE_PCB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.extractToRight<RESET_REG_QUIESCE_PCB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access RESET_REG_QUIESCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_QUIESCE_PCB]

//>> GET_[RESET_REG_QUIESCE_PCB]
static inline bool GET_RESET_REG_QUIESCE_PCB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(RESET_REG));
#endif
    return i_data.getBit<RESET_REG_QUIESCE_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access RESET_REG_QUIESCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[RESET_REG_QUIESCE_PCB]

//>> PREP_[TOD_MISC_RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_MISC_RESET_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_MISC_RESET_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_MISC_RESET_REG]

//>> GET_[TOD_MISC_RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_MISC_RESET_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_MISC_RESET_REG;
#endif
    return fapi2::getScom(i_target, TOD_MISC_RESET_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_MISC_RESET_REG]

//>> PUT_[TOD_MISC_RESET_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_MISC_RESET_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return fapi2::putScom(i_target, TOD_MISC_RESET_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_MISC_RESET_REG]


//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_CREATE_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_STEP_ALIGN_THRESHOLD_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]

//>> GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_04_05]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]
static inline bool GET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]
static inline bool GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_DISABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_0_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_1_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_2_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_PROBE_3_TOGGLE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> CLEAR_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]
static inline bool GET_TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_DISTR_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]
static inline bool GET_TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_CORE_STEP_SYNC_TX_RESET_TRIGGER]

//>> SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_TRACE_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_TRACE_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> CLEAR_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]
static inline bool GET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_REG_0X0B_SPARE_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_17]

//>> SET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_DATA_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_TRACE_DATA_SELECT,
           TOD_MISC_RESET_REG_TRACE_DATA_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_DATA_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]

//>> SET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_TRACE_DATA_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_TRACE_DATA_SELECT,
           TOD_MISC_RESET_REG_TRACE_DATA_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_DATA_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]

//>> GET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_TRACE_DATA_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_TRACE_DATA_SELECT,
           TOD_MISC_RESET_REG_TRACE_DATA_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_TRACE_DATA_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_TRACE_DATA_SELECT]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_0_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> GET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]
static inline bool GET_TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_M_PATH_1_SYNC_CREATE_COUNTER_RESET_ENABLE]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> CLEAR_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]
static inline bool GET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.setBit<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> CLEAR_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.clearBit<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]
static inline bool GET_TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.getBit<TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_ADJUST_RESET]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE,
           TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]

//>> SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE,
           TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]

//>> GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE,
           TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_I_PATH_DELAY_TWOS_COMPL_LOAD_VALUE]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]

//>> SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]
static inline fapi2::buffer<uint64_t>& SET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return o_data.insertFromRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]

//>> GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]
static inline fapi2::buffer<uint64_t>& GET_TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_MISC_RESET_REG));
#endif
    return i_data.extractToRight<TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39,
           TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_MISC_RESET_REG_REG_0X0B_SPARE_33_39]

//>> PREP_[TOD_SEC_PORT_0_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_SEC_PORT_0_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_SEC_PORT_0_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_SEC_PORT_0_CTRL_REG]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_SEC_PORT_0_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_SEC_PORT_0_CTRL_REG;
#endif
    return fapi2::getScom(i_target, TOD_SEC_PORT_0_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG]

//>> PUT_[TOD_SEC_PORT_0_CTRL_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_SEC_PORT_0_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return fapi2::putScom(i_target, TOD_SEC_PORT_0_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_SEC_PORT_0_CTRL_REG]


//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_PORT_0_RX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_03]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT,
           TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_SELECT]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X0_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X1_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X2_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X3_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X4_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X5_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X6_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.setBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.clearBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]
static inline bool GET_TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.getBit<TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_X7_PORT_0_TX_ENABLE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31,
           TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31,
           TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31,
           TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_31]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29,
           TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29,
           TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29,
           TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_REG_0X03_SPARE_28_29]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE,
           TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]

//>> SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return o_data.insertFromRight<TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE,
           TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]

//>> GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TOD_SEC_PORT_0_CTRL_REG));
#endif
    return i_data.extractToRight<TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE,
           TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_SEC_PORT_0_CTRL_REG_SEC_I_PATH_DELAY_VALUE]

//>> PREP_[XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP_MASK_RW]

//>> GET_[XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_RW;
#endif
    return fapi2::getScom(i_target, XSTOP_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP_MASK_RW]

//>> PUT_[XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, XSTOP_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP_MASK_RW]

//>> PREP_[XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP_MASK_WO_CLEAR]

//>> GET_[XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, XSTOP_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP_MASK_WO_CLEAR]

//>> PUT_[XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, XSTOP_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP_MASK_WO_CLEAR]

//>> PREP_[XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[XSTOP_MASK_WO_OR]

//>> GET_[XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = XSTOP_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, XSTOP_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[XSTOP_MASK_WO_OR]

//>> PUT_[XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, XSTOP_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[XSTOP_MASK_WO_OR]


//>> SET_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_01]

//>> SET_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_01]

//>> SET_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_01]

//>> CLEAR_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_01]

//>> GET_[XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_01]

//>> GET_[XSTOP_MASK_01]
static inline bool GET_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_01]

//>> SET_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_02]

//>> SET_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_02]

//>> SET_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_02]

//>> CLEAR_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_02]

//>> GET_[XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_02]

//>> GET_[XSTOP_MASK_02]
static inline bool GET_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_02]

//>> SET_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_03]

//>> SET_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_03]

//>> SET_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_03]

//>> CLEAR_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_03]

//>> GET_[XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_03]

//>> GET_[XSTOP_MASK_03]
static inline bool GET_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_03]

//>> SET_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_04]

//>> SET_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_04]

//>> SET_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_04]

//>> CLEAR_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_04]

//>> GET_[XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_04]

//>> GET_[XSTOP_MASK_04]
static inline bool GET_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_04]

//>> SET_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_05]

//>> SET_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_05]

//>> SET_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_05]

//>> CLEAR_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_05]

//>> GET_[XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_05]

//>> GET_[XSTOP_MASK_05]
static inline bool GET_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_05]

//>> SET_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_06]

//>> SET_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_06]

//>> SET_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_06]

//>> CLEAR_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_06]

//>> GET_[XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_06]

//>> GET_[XSTOP_MASK_06]
static inline bool GET_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_06]

//>> SET_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_07]

//>> SET_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_07]

//>> SET_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_07]

//>> CLEAR_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_07]

//>> GET_[XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_07]

//>> GET_[XSTOP_MASK_07]
static inline bool GET_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_07]

//>> SET_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_08]

//>> SET_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_08]

//>> SET_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_08]

//>> CLEAR_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_08]

//>> GET_[XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_08]

//>> GET_[XSTOP_MASK_08]
static inline bool GET_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_08]

//>> SET_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_09]

//>> SET_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_09]

//>> SET_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_09]

//>> CLEAR_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_09]

//>> GET_[XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_09]

//>> GET_[XSTOP_MASK_09]
static inline bool GET_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_09]

//>> SET_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_10]

//>> SET_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_10]

//>> SET_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_10]

//>> CLEAR_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_10]

//>> GET_[XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_10]

//>> GET_[XSTOP_MASK_10]
static inline bool GET_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_10]

//>> SET_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_11]

//>> SET_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_11]

//>> SET_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_11]

//>> CLEAR_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_11]

//>> GET_[XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_11]

//>> GET_[XSTOP_MASK_11]
static inline bool GET_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_11]

//>> SET_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_12]

//>> SET_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_12]

//>> SET_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_12]

//>> CLEAR_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_12]

//>> GET_[XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_12]

//>> GET_[XSTOP_MASK_12]
static inline bool GET_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_12]

//>> SET_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_13]

//>> SET_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_13]

//>> SET_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_13]

//>> CLEAR_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_13]

//>> GET_[XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_13]

//>> GET_[XSTOP_MASK_13]
static inline bool GET_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_13]

//>> SET_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_14]

//>> SET_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_14]

//>> SET_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_14]

//>> CLEAR_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_14]

//>> GET_[XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_14]

//>> GET_[XSTOP_MASK_14]
static inline bool GET_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_14]

//>> SET_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_15]

//>> SET_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_15]

//>> SET_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_15]

//>> CLEAR_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_15]

//>> GET_[XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_15]

//>> GET_[XSTOP_MASK_15]
static inline bool GET_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_15]

//>> SET_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_16]

//>> SET_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_16]

//>> SET_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_16]

//>> CLEAR_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_16]

//>> GET_[XSTOP_MASK_16]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_16]

//>> GET_[XSTOP_MASK_16]
static inline bool GET_XSTOP_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_16]

//>> SET_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_17]

//>> SET_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_17]

//>> SET_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_17]

//>> CLEAR_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_17]

//>> GET_[XSTOP_MASK_17]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_17]

//>> GET_[XSTOP_MASK_17]
static inline bool GET_XSTOP_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_17]

//>> SET_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_18]

//>> SET_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_18]

//>> SET_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_18]

//>> CLEAR_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_18]

//>> GET_[XSTOP_MASK_18]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_18]

//>> GET_[XSTOP_MASK_18]
static inline bool GET_XSTOP_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_18]

//>> SET_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_19]

//>> SET_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_19]

//>> SET_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_19]

//>> CLEAR_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_19]

//>> GET_[XSTOP_MASK_19]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_19]

//>> GET_[XSTOP_MASK_19]
static inline bool GET_XSTOP_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_19]

//>> SET_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_20]

//>> SET_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_20]

//>> SET_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_20]

//>> CLEAR_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_20]

//>> GET_[XSTOP_MASK_20]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_20]

//>> GET_[XSTOP_MASK_20]
static inline bool GET_XSTOP_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_20]

//>> SET_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_21]

//>> SET_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_21]

//>> SET_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_21]

//>> CLEAR_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_21]

//>> GET_[XSTOP_MASK_21]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_21]

//>> GET_[XSTOP_MASK_21]
static inline bool GET_XSTOP_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_21]

//>> SET_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_22]

//>> SET_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_22]

//>> SET_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_22]

//>> CLEAR_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_22]

//>> GET_[XSTOP_MASK_22]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_22]

//>> GET_[XSTOP_MASK_22]
static inline bool GET_XSTOP_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_22]

//>> SET_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_23]

//>> SET_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_23]

//>> SET_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_23]

//>> CLEAR_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_23]

//>> GET_[XSTOP_MASK_23]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_23]

//>> GET_[XSTOP_MASK_23]
static inline bool GET_XSTOP_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_23]

//>> SET_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_24]

//>> SET_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_24]

//>> SET_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_24]

//>> CLEAR_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_24]

//>> GET_[XSTOP_MASK_24]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_24]

//>> GET_[XSTOP_MASK_24]
static inline bool GET_XSTOP_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_24]

//>> SET_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_25]

//>> SET_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_25]

//>> SET_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_25]

//>> CLEAR_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_25]

//>> GET_[XSTOP_MASK_25]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_25]

//>> GET_[XSTOP_MASK_25]
static inline bool GET_XSTOP_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_25]

//>> SET_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_26]

//>> SET_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_26]

//>> SET_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_26]

//>> CLEAR_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_26]

//>> GET_[XSTOP_MASK_26]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_26]

//>> GET_[XSTOP_MASK_26]
static inline bool GET_XSTOP_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_26]

//>> SET_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_27]

//>> SET_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_27]

//>> SET_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_27]

//>> CLEAR_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_27]

//>> GET_[XSTOP_MASK_27]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_27]

//>> GET_[XSTOP_MASK_27]
static inline bool GET_XSTOP_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_27]

//>> SET_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_28]

//>> SET_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_28]

//>> SET_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_28]

//>> CLEAR_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_28]

//>> GET_[XSTOP_MASK_28]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_28]

//>> GET_[XSTOP_MASK_28]
static inline bool GET_XSTOP_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_28]

//>> SET_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_29]

//>> SET_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_29]

//>> SET_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_29]

//>> CLEAR_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_29]

//>> GET_[XSTOP_MASK_29]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_29]

//>> GET_[XSTOP_MASK_29]
static inline bool GET_XSTOP_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_29]

//>> SET_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_30]

//>> SET_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_30]

//>> SET_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_30]

//>> CLEAR_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_30]

//>> GET_[XSTOP_MASK_30]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_30]

//>> GET_[XSTOP_MASK_30]
static inline bool GET_XSTOP_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_30]

//>> SET_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_31]

//>> SET_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_31]

//>> SET_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_31]

//>> CLEAR_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_31]

//>> GET_[XSTOP_MASK_31]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_31]

//>> GET_[XSTOP_MASK_31]
static inline bool GET_XSTOP_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_31]

//>> SET_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_32]

//>> SET_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_32]

//>> SET_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_32]

//>> CLEAR_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_32]

//>> GET_[XSTOP_MASK_32]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_32]

//>> GET_[XSTOP_MASK_32]
static inline bool GET_XSTOP_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_32]

//>> SET_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_33]

//>> SET_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_33]

//>> SET_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_33]

//>> CLEAR_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_33]

//>> GET_[XSTOP_MASK_33]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_33]

//>> GET_[XSTOP_MASK_33]
static inline bool GET_XSTOP_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_33]

//>> SET_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_34]

//>> SET_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_34]

//>> SET_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_34]

//>> CLEAR_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_34]

//>> GET_[XSTOP_MASK_34]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_34]

//>> GET_[XSTOP_MASK_34]
static inline bool GET_XSTOP_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_34]

//>> SET_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_35]

//>> SET_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_35]

//>> SET_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_35]

//>> CLEAR_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_35]

//>> GET_[XSTOP_MASK_35]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_35]

//>> GET_[XSTOP_MASK_35]
static inline bool GET_XSTOP_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_35]

//>> SET_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_36]

//>> SET_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_36]

//>> SET_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_36]

//>> CLEAR_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_36]

//>> GET_[XSTOP_MASK_36]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_36]

//>> GET_[XSTOP_MASK_36]
static inline bool GET_XSTOP_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_36]

//>> SET_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_37]

//>> SET_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_37]

//>> SET_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_37]

//>> CLEAR_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_37]

//>> GET_[XSTOP_MASK_37]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_37]

//>> GET_[XSTOP_MASK_37]
static inline bool GET_XSTOP_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_37]

//>> SET_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_38]

//>> SET_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_38]

//>> SET_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_38]

//>> CLEAR_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_38]

//>> GET_[XSTOP_MASK_38]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_38]

//>> GET_[XSTOP_MASK_38]
static inline bool GET_XSTOP_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_38]

//>> SET_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_39]

//>> SET_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_39]

//>> SET_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_39]

//>> CLEAR_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_39]

//>> GET_[XSTOP_MASK_39]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_39]

//>> GET_[XSTOP_MASK_39]
static inline bool GET_XSTOP_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_39]

//>> SET_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_40]

//>> SET_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_40]

//>> SET_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_40]

//>> CLEAR_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_40]

//>> GET_[XSTOP_MASK_40]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_40]

//>> GET_[XSTOP_MASK_40]
static inline bool GET_XSTOP_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_40]

//>> SET_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_41]

//>> SET_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_41]

//>> SET_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_41]

//>> CLEAR_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_41]

//>> GET_[XSTOP_MASK_41]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_41]

//>> GET_[XSTOP_MASK_41]
static inline bool GET_XSTOP_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_41]

//>> SET_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_42]

//>> SET_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_42]

//>> SET_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_42]

//>> CLEAR_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_42]

//>> GET_[XSTOP_MASK_42]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_42]

//>> GET_[XSTOP_MASK_42]
static inline bool GET_XSTOP_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_42]

//>> SET_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_43]

//>> SET_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_43]

//>> SET_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_43]

//>> CLEAR_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_43]

//>> GET_[XSTOP_MASK_43]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_43]

//>> GET_[XSTOP_MASK_43]
static inline bool GET_XSTOP_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_43]

//>> SET_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_44]

//>> SET_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_44]

//>> SET_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_44]

//>> CLEAR_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_44]

//>> GET_[XSTOP_MASK_44]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_44]

//>> GET_[XSTOP_MASK_44]
static inline bool GET_XSTOP_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_44]

//>> SET_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_45]

//>> SET_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_45]

//>> SET_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_45]

//>> CLEAR_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_45]

//>> GET_[XSTOP_MASK_45]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_45]

//>> GET_[XSTOP_MASK_45]
static inline bool GET_XSTOP_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_45]

//>> SET_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_46]

//>> SET_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_46]

//>> SET_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_46]

//>> CLEAR_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_46]

//>> GET_[XSTOP_MASK_46]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_46]

//>> GET_[XSTOP_MASK_46]
static inline bool GET_XSTOP_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_46]

//>> SET_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_47]

//>> SET_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_47]

//>> SET_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_47]

//>> CLEAR_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_47]

//>> GET_[XSTOP_MASK_47]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_47]

//>> GET_[XSTOP_MASK_47]
static inline bool GET_XSTOP_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_47]

//>> SET_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_48]

//>> SET_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_48]

//>> SET_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_48]

//>> CLEAR_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_48]

//>> GET_[XSTOP_MASK_48]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_48]

//>> GET_[XSTOP_MASK_48]
static inline bool GET_XSTOP_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_48]

//>> SET_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_49]

//>> SET_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_49]

//>> SET_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_49]

//>> CLEAR_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_49]

//>> GET_[XSTOP_MASK_49]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_49]

//>> GET_[XSTOP_MASK_49]
static inline bool GET_XSTOP_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_49]

//>> SET_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_50]

//>> SET_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_50]

//>> SET_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_50]

//>> CLEAR_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_50]

//>> GET_[XSTOP_MASK_50]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_50]

//>> GET_[XSTOP_MASK_50]
static inline bool GET_XSTOP_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_50]

//>> SET_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_51]

//>> SET_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_51]

//>> SET_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_51]

//>> CLEAR_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_51]

//>> GET_[XSTOP_MASK_51]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_51]

//>> GET_[XSTOP_MASK_51]
static inline bool GET_XSTOP_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_51]

//>> SET_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_52]

//>> SET_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_52]

//>> SET_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_52]

//>> CLEAR_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_52]

//>> GET_[XSTOP_MASK_52]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_52]

//>> GET_[XSTOP_MASK_52]
static inline bool GET_XSTOP_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_52]

//>> SET_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_53]

//>> SET_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<XSTOP_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_53]

//>> SET_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[XSTOP_MASK_53]

//>> CLEAR_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& CLEAR_XSTOP_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[XSTOP_MASK_53]

//>> GET_[XSTOP_MASK_53]
static inline fapi2::buffer<uint64_t>& GET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<XSTOP_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_53]

//>> GET_[XSTOP_MASK_53]
static inline bool GET_XSTOP_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(XSTOP_MASK_RW, XSTOP_MASK_WO_CLEAR, XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<XSTOP_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access XSTOP_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[XSTOP_MASK_53]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
