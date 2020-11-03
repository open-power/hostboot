/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00017.H $         */
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

#ifndef __PROC_REG00017_H_
#define __PROC_REG00017_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPBR_AD_ALTD_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_ALTD_STATUS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_STATUS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_ALTD_STATUS_REG]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_ALTD_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_STATUS_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_ALTD_STATUS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG]

//>> PUT_[TP_TPBR_AD_ALTD_STATUS_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_ALTD_STATUS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_ALTD_STATUS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_ALTD_STATUS_REG]


//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]

//>> CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]
static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE]

//>> SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE]

//>> GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE]

//>> PREP_[TP_TPBR_PBA_PBAO_PBABAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABAR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBABAR1]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABAR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABAR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR1]

//>> PUT_[TP_TPBR_PBA_PBAO_PBABAR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABAR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABAR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBABAR1]


//>> SET_[TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]
static inline bool GET_TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR1_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR1_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR1_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR1_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR1_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR1_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR1_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR1_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR1_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR1_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR1_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR1_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR1_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR1_VTARGET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_VTARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR1_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR1_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR1_VTARGET]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR1_VTARGET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_VTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR1_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR1_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR1_VTARGET]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR1_VTARGET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR1_VTARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR1_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR1_VTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR1_VTARGET]

//>> PREP_[TP_TPBR_PBA_PBAO_PBABARMSK0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABARMSK0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBABARMSK0]

//>> GET_[TP_TPBR_PBA_PBAO_PBABARMSK0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABARMSK0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABARMSK0]

//>> PUT_[TP_TPBR_PBA_PBAO_PBABARMSK0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABARMSK0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBABARMSK0]


//>> SET_[TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK]

//>> SET_[TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK]

//>> GET_[TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK]

//>> PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBARBUFVAL1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL1]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1]

//>> PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBARBUFVAL1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL1]


//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAXSHBR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHBR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAXSHBR0]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHBR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHBR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHBR0]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAXSHBR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHBR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAXSHBR0]


//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAXSHCS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHCS1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAXSHCS1]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHCS1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAXSHCS1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHCS1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAXSHCS1]


//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE]

//>> PREP_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_CH_MISC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_CH_MISC_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_TX_CH_MISC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG]

//>> PUT_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_TX_CH_MISC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG]


//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
