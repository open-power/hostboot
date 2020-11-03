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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
