/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00011.H $         */
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

#ifndef __PROC_REG00011_H_
#define __PROC_REG00011_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPBR_AD_LPC_CMD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_LPC_CMD_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_LPC_CMD_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_LPC_CMD_REG]

//>> GET_[TP_TPBR_AD_LPC_CMD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_LPC_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_LPC_CMD_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_LPC_CMD_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_CMD_REG]

//>> PUT_[TP_TPBR_AD_LPC_CMD_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_LPC_CMD_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_LPC_CMD_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_LPC_CMD_REG]


//>> SET_[TP_TPBR_AD_LPC_CMD_REG_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_CMD_REG_RNW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_CMD_REG_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_RNW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_CMD_REG_RNW]

//>> SET_[TP_TPBR_AD_LPC_CMD_REG_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_CMD_REG_RNW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_CMD_REG_RNW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_RNW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_CMD_REG_RNW]

//>> SET_[TP_TPBR_AD_LPC_CMD_REG_RNW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_CMD_REG_RNW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_LPC_CMD_REG_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_RNW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_CMD_REG_RNW]

//>> CLEAR_[TP_TPBR_AD_LPC_CMD_REG_RNW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_LPC_CMD_REG_RNW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_LPC_CMD_REG_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_RNW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_LPC_CMD_REG_RNW]

//>> GET_[TP_TPBR_AD_LPC_CMD_REG_RNW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_LPC_CMD_REG_RNW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_LPC_CMD_REG_RNW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_RNW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_CMD_REG_RNW]

//>> GET_[TP_TPBR_AD_LPC_CMD_REG_RNW]
static inline bool GET_TP_TPBR_AD_LPC_CMD_REG_RNW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_LPC_CMD_REG_RNW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_RNW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_CMD_REG_RNW]

//>> SET_[TP_TPBR_AD_LPC_CMD_REG_SIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_CMD_REG_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_CMD_REG_SIZE,
           TP_TPBR_AD_LPC_CMD_REG_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_CMD_REG_SIZE]

//>> SET_[TP_TPBR_AD_LPC_CMD_REG_SIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_CMD_REG_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_CMD_REG_SIZE,
           TP_TPBR_AD_LPC_CMD_REG_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_CMD_REG_SIZE]

//>> GET_[TP_TPBR_AD_LPC_CMD_REG_SIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_LPC_CMD_REG_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_LPC_CMD_REG_SIZE,
           TP_TPBR_AD_LPC_CMD_REG_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_CMD_REG_SIZE]

//>> SET_[TP_TPBR_AD_LPC_CMD_REG_ADR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_CMD_REG_ADR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_CMD_REG_ADR,
           TP_TPBR_AD_LPC_CMD_REG_ADR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_ADR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_CMD_REG_ADR]

//>> SET_[TP_TPBR_AD_LPC_CMD_REG_ADR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_CMD_REG_ADR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_CMD_REG_ADR,
           TP_TPBR_AD_LPC_CMD_REG_ADR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_ADR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_CMD_REG_ADR]

//>> GET_[TP_TPBR_AD_LPC_CMD_REG_ADR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_LPC_CMD_REG_ADR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_CMD_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_LPC_CMD_REG_ADR,
           TP_TPBR_AD_LPC_CMD_REG_ADR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_LPC_CMD_REG_ADR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_CMD_REG_ADR]

//>> PREP_[TP_TPBR_AD_SND_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_SND_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_SND_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_SND_MODE_REG]

//>> GET_[TP_TPBR_AD_SND_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_SND_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_SND_MODE_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_SND_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG]

//>> PUT_[TP_TPBR_AD_SND_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_SND_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_SND_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_SND_MODE_REG]


//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG0]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_TRC_GLB_TRIG1]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_GLB_PULSE_MODE]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_SINGLE_OUTSTANDING_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY,
           TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY,
           TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY,
           TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_PROG_REQ_DELAY]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_ERR_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_HTM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TRACE_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_TOD_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_XSCOM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_CLR_ERR_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_ERR_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_HTM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TRACE_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_TOD_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_OVERRIDE_PBINIT_XSCOM_CMD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_SET_PB_STOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_PB_STOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_PB_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_PB_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_PB_STOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_PB_STOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_PB_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_PB_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_PB_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_PB_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_PB_STOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_PB_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_PB_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_PB_STOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_PB_STOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_PB_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_PB_STOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_PB_STOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_PB_STOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_PB_STOP]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_MANUAL_PB_SWITCH_ABCD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER,
           TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER,
           TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER,
           TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TRIGGER]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_RECEIVE_OWN_TOD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_RESET_TOD_STATE]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_AB]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]

//>> SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]

//>> CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]

//>> GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]
static inline bool GET_TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_SND_MODE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_SND_MODE_REG_ENABLE_PB_SWITCH_CD]

//>> PREP_[TP_TPBR_PBA_PBAO_BCUE_PBADR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCUE_PBADR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCUE_PBADR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_BCUE_PBADR]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCUE_PBADR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCUE_PBADR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCUE_PBADR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR]

//>> PUT_[TP_TPBR_PBA_PBAO_BCUE_PBADR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCUE_PBADR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCUE_PBADR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_BCUE_PBADR]


//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_PB_OFFSET]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_25_26]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_EXTADDR]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_PBADR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42,
           TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_PBADR_RESERVED_41_42]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
