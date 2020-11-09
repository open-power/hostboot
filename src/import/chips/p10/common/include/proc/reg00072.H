/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00072.H $         */
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

#ifndef __PROC_REG00072_H_
#define __PROC_REG00072_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPBR_AD_ALTD_CMD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_ALTD_CMD_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_CMD_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_ALTD_CMD_REG]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_ALTD_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_CMD_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_ALTD_CMD_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG]

//>> PUT_[TP_TPBR_AD_ALTD_CMD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_ALTD_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_ALTD_CMD_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_ALTD_CMD_REG]


//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_START_OP]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_CLEAR_STATUS]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RESET_FSM]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_RNW]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AXTYPE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DATA_ONLY]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_PICK]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCKED]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_LOCK_ID]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_SCOPE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_AUTO_INC]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_DROP_PRIORITY_MAX]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_OVERWRITE_PBINIT]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_PIB_DIRECT]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]

//>> CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]
static inline bool GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_WITH_TM_QUIESCE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TTYPE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE,
           TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE,
           TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE,
           TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TTYPE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE,
           TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_FBC_ALTD_TSIZE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE,
           TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE]

//>> SET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE,
           TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE]

//>> GET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE,
           TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_CMD_REG_ALTD_SM_TSIZE]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIRMASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RW]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIRMASK_RW;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RW]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RW]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR]


//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_APAR_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_SLAVE_INIT_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_WRPAR_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_SETUP_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCUE_OCI_DATERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_SETUP_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_BCDE_OCI_DATERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_INTERNALS_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_OCI_BAD_REG_ADDR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXPUSH_WRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIPUSH_WRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXSND_RSVERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_AXISND_RSVERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK,
           TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK,
           TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK,
           TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]

//>> SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]

//>> SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]

//>> SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]

//>> CLEAR_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]

//>> GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]

//>> GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]
static inline bool GET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_HTM_OVERFLOW_MASK]

//>> SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]

//>> SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]

//>> SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]

//>> CLEAR_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]

//>> GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]

//>> GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]
static inline bool GET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_INVALID_TOPOLOGY_ID_MASK]

//>> SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK,
           P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]

//>> SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK,
           P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]

//>> GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRMASK_RW, TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAO_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK,
           P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_PBA_PBAO_PBAFIRMASK_RESERVED_MASK]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR_OCB_OCI_GPEIVPR_IVPR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_MEM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_LOCAL_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_LOW_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_SRAM_HIGH_PRIORITY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEMACR_WRITE_PROTECT_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_CR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CR2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_CR2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR2_OCB_OCI_ADC_CR2_HWCTRL_INTER_FRAME_DELAY]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_5]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA6_7]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CMD0B_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD0B_CLEAR_STICKY_BITS_0B]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_OUT_COUNT2_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_DELAY2_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS2_IN_COUNT2_2]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SRD2B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD2B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD2B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD2B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD2B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SRD2B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD2B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD2B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD2B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD2B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD2B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD2B_OCB_OCI_O2SRD2B_O2S_RDATA_2B]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SWD0B(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD0B;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD0B(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD0B;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD0B, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SWD0B(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD0B));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD0B, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD0B));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD0B));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD0B_OCB_OCI_O2SWD0B_O2S_WDATA_0B]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1_START]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
