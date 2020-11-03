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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
