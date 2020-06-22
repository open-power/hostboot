/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00071.H $         */
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

#ifndef __PROC_REG00071_H_
#define __PROC_REG00071_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT]

//>> PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT]


//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_VALID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_0_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_1_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_2_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_3_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_4_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_5_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_6_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_7_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_8_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_9_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_10_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_11_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_12_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_13_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_14_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE3_NEXT_15_AX_NUM_NEXT_ES3]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT,
           PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT]

//>> PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0]

//>> PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0]


//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_00]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_01]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_02]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_03]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_04]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_05]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_06]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_07]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_08]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_09]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_10]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_11]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_12]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_13]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_14]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_15]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_16]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_17]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_18]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_19]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_20]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_21]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_22]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_23]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_24]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_25]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_26]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_27]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_28]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_29]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_30]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_31]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_32]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_33]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_34]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_35]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_36]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_37]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_38]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_39]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_40]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_41]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_42]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_43]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_44]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_45]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_46]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_47]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_48]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_49]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_50]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_51]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_52]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_53]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_54]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_55]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_56]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_57]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_58]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_59]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_60]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_61]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_62]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_ACTION0_63]

//>> PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW]

//>> PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW]

//>> PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND]

//>> PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND]

//>> PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR]

//>> PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR]


//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_00]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_01]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_02]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_03]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_04]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_05]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_06]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_07]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_08]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_09]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_10]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_11]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_12]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_13]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_14]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_15]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_16]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_17]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_18]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_19]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_20]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_21]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_22]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_23]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_24]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_25]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_26]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_27]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_28]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_29]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_30]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_31]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_32]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_33]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_34]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_35]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_36]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_37]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_38]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_39]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_40]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_41]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_42]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_43]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_44]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_45]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_46]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_47]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_48]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_49]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_50]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_51]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_52]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_53]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_54]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_55]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_56]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_57]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_58]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_59]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_60]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_61]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_62]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]

//>> SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]

//>> CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]

//>> GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]
static inline bool GET_TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_EPS_FIR_LOCAL_MASK_RW, TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_AND,
                           TP_TCN0_N0_EPS_FIR_LOCAL_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN0_N0_EPS_FIR_LOCAL_MASK_63]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
