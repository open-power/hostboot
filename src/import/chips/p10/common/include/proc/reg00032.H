/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00032.H $         */
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

#ifndef __PROC_REG00032_H_
#define __PROC_REG00032_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG]

//>> PUT_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG]


//>> SET_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0,
           PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0,
           PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0,
           PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG_EXTFIR_ACTION0]

//>> PREP_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG]

//>> PUT_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG]


//>> SET_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1,
           PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1]

//>> SET_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1,
           PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1]

//>> GET_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1,
           PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG_EXTFIR_ACTION1]

//>> PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT]

//>> PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT]


//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_16_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_17_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_18_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_19_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_20_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_21_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_22_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_23_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_24_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_25_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_26_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_27_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_28_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_29_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_30_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE4_NEXT_31_AX_NUM_NEXT_ES3]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM0_LAST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM0_LAST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM0_LAST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM0_LAST]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM0_LAST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM0_LAST(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM0_LAST;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM0_LAST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM0_LAST]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM0_LAST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM0_LAST(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM0_LAST));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM0_LAST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM0_LAST]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM0_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS,
           PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM0_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS,
           PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM0_LAST));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS,
           PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM0_LAST_HTM0_LAST_ADDRESS]

//>> PREP_[TP_TPBR_AD_ALTD_OPTION_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_ALTD_OPTION_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_OPTION_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_ALTD_OPTION_REG]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_ALTD_OPTION_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_OPTION_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_ALTD_OPTION_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG]

//>> PUT_[TP_TPBR_AD_ALTD_OPTION_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_ALTD_OPTION_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_ALTD_OPTION_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_ALTD_OPTION_REG]


//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]

//>> CLEAR_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]
static inline bool GET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]

//>> CLEAR_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]
static inline bool GET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT,
           TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT,
           TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT,
           TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]

//>> CLEAR_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]
static inline bool GET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]

//>> CLEAR_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]
static inline bool GET_TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT,
           TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT]

//>> SET_[TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT,
           TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT]

//>> GET_[TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_OPTION_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT,
           TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT]

//>> PREP_[TP_TPBR_AD_LPC_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_LPC_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_LPC_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_LPC_DATA_REG]

//>> GET_[TP_TPBR_AD_LPC_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_LPC_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_LPC_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_LPC_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_DATA_REG]

//>> PUT_[TP_TPBR_AD_LPC_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_LPC_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_LPC_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_LPC_DATA_REG]


//>> SET_[TP_TPBR_AD_LPC_DATA_REG_LPC_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_DATA_REG_LPC_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_DATA_REG_LPC_DATA,
           TP_TPBR_AD_LPC_DATA_REG_LPC_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_LPC_DATA_REG_LPC_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_DATA_REG_LPC_DATA]

//>> SET_[TP_TPBR_AD_LPC_DATA_REG_LPC_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_LPC_DATA_REG_LPC_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_LPC_DATA_REG_LPC_DATA,
           TP_TPBR_AD_LPC_DATA_REG_LPC_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_LPC_DATA_REG_LPC_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_LPC_DATA_REG_LPC_DATA]

//>> GET_[TP_TPBR_AD_LPC_DATA_REG_LPC_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_LPC_DATA_REG_LPC_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_LPC_DATA_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_LPC_DATA_REG_LPC_DATA,
           TP_TPBR_AD_LPC_DATA_REG_LPC_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_LPC_DATA_REG_LPC_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_LPC_DATA_REG_LPC_DATA]

//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIR_RW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RW]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIR_RW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> PREP_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCDE_OCIBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_OCIBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCDE_OCIBAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_OCIBAR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_OCIBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]

//>> PUT_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCDE_OCIBAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_OCIBAR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_OCIBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]


//>> SET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_OCIBAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR,
           TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_OCIBAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR,
           TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_OCIBAR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR,
           TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]


//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]

//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
