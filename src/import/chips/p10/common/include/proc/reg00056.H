/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00056.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __PROC_REG00056_H_
#define __PROC_REG00056_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT]

//>> PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT]


//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_EN_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX0_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX1_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX2_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX3_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX4_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX5_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX6_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_MODE_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_LINK_AX7_ID_NEXT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_NEXT_PB_CFG_SPARE]

//>> PREP_[PB_PTLSCOM10_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM10_PTL_FIR_REG_RW]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_RW]

//>> PUT_[PB_PTLSCOM10_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM10_PTL_FIR_REG_RW]

//>> PREP_[PB_PTLSCOM10_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM10_PTL_FIR_REG_WO_AND]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_WO_AND]

//>> PUT_[PB_PTLSCOM10_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM10_PTL_FIR_REG_WO_AND]

//>> PREP_[PB_PTLSCOM10_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM10_PTL_FIR_REG_WO_OR]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_WO_OR]

//>> PUT_[PB_PTLSCOM10_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_PTL_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM10_PTL_FIR_REG_WO_OR]


//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]

//>> CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]
static inline bool GET_PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_PTL_FIR_REG_RW, PB_PTLSCOM10_PTL_FIR_REG_WO_AND, PB_PTLSCOM10_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM10_PTL_FIR_REG_PTL3_SPARE]

//>> PREP_[PSI_MAC_SCOM_REGS_RX_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PSI_MAC_SCOM_REGS_RX_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSI_MAC_SCOM_REGS_RX_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PSI_MAC_SCOM_REGS_RX_MODE]

//>> GET_[PSI_MAC_SCOM_REGS_RX_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PSI_MAC_SCOM_REGS_RX_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PSI_MAC_SCOM_REGS_RX_MODE;
#endif
    return fapi2::getScom(i_target, PSI_MAC_SCOM_REGS_RX_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_MODE]

//>> PUT_[PSI_MAC_SCOM_REGS_RX_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PSI_MAC_SCOM_REGS_RX_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return fapi2::putScom(i_target, PSI_MAC_SCOM_REGS_RX_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PSI_MAC_SCOM_REGS_RX_MODE]


//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_VREF]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_VREF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_VREF,
           PSI_MAC_SCOM_REGS_RX_MODE_VREF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_VREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_VREF]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_VREF]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_VREF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_VREF,
           PSI_MAC_SCOM_REGS_RX_MODE_VREF_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_VREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_VREF]

//>> GET_[PSI_MAC_SCOM_REGS_RX_MODE_VREF]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_MODE_VREF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_MODE_VREF,
           PSI_MAC_SCOM_REGS_RX_MODE_VREF_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_VREF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_MODE_VREF]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.setBit<PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]

//>> CLEAR_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.clearBit<PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]

//>> GET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]

//>> GET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]
static inline bool GET_PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return i_data.getBit<PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_TEST_MODE]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC,
           PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC,
           PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC]

//>> GET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC,
           PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_MODE_TERM_MODE_ENC]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_PEAK]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_PEAK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_PEAK,
           PSI_MAC_SCOM_REGS_RX_MODE_PEAK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_PEAK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_PEAK]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_PEAK]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_PEAK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_PEAK,
           PSI_MAC_SCOM_REGS_RX_MODE_PEAK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_PEAK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_PEAK]

//>> GET_[PSI_MAC_SCOM_REGS_RX_MODE_PEAK]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_MODE_PEAK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_MODE_PEAK,
           PSI_MAC_SCOM_REGS_RX_MODE_PEAK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_PEAK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_MODE_PEAK]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE,
           PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE]

//>> SET_[PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return o_data.insertFromRight<PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE,
           PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE]

//>> GET_[PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PSI_MAC_SCOM_REGS_RX_MODE));
#endif
    return i_data.extractToRight<PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE,
           PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PSI_MAC_SCOM_REGS_RX_MODE_MODE_SPARE]

//>> PREP_[TP_TPBR_AD_ALTD_ADDR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_ALTD_ADDR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_ADDR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_ALTD_ADDR_REG]

//>> GET_[TP_TPBR_AD_ALTD_ADDR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_ALTD_ADDR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_ADDR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_ALTD_ADDR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_ADDR_REG]

//>> PUT_[TP_TPBR_AD_ALTD_ADDR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_ALTD_ADDR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_ADDR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_ALTD_ADDR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_ALTD_ADDR_REG]


//>> SET_[TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_ADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS,
           TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS]

//>> SET_[TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_ADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS,
           TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS]

//>> GET_[TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_ADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS,
           TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_ADDR_REG_FBC_ALTD_ADDRESS]

//>> SET_[TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_ADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS,
           TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS]

//>> SET_[TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_ADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS,
           TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS]

//>> GET_[TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_ADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS,
           TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_ADDR_REG_ALTD_SM_ADDRESS]

//>> PREP_[TP_TPBR_AD_XSCOM_BASE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_XSCOM_BASE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_XSCOM_BASE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_XSCOM_BASE_REG]

//>> GET_[TP_TPBR_AD_XSCOM_BASE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_XSCOM_BASE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_XSCOM_BASE_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_XSCOM_BASE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_XSCOM_BASE_REG]

//>> PUT_[TP_TPBR_AD_XSCOM_BASE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_XSCOM_BASE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_XSCOM_BASE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_XSCOM_BASE_REG]


//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_BASE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_BASE_REG_BASE,
           TP_TPBR_AD_XSCOM_BASE_REG_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_BASE]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_BASE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_BASE_REG_BASE,
           TP_TPBR_AD_XSCOM_BASE_REG_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_BASE]

//>> GET_[TP_TPBR_AD_XSCOM_BASE_REG_BASE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_BASE_REG_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_BASE_REG_BASE,
           TP_TPBR_AD_XSCOM_BASE_REG_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_XSCOM_BASE_REG_BASE]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_BASE_REG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_BASE_REG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_XSCOM_BASE_REG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> CLEAR_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_XSCOM_BASE_REG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> GET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_BASE_REG_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> GET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline bool GET_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_XSCOM_BASE_REG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.setBit<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> CLEAR_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline bool GET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.getBit<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> CLEAR_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> GET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> GET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline bool GET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.setBit<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> CLEAR_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]
static inline bool GET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.getBit<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_RESET]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> CLEAR_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> GET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> GET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]
static inline bool GET_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_XSCOM_BASE_REG_DISABLE_LOCAL_SHORTCUT]

//>> SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.insertFromRight<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.setBit<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> CLEAR_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return o_data.clearBit<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.extractToRight<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>> GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]
static inline bool GET_P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_BASE_REG));
#endif
    return i_data.getBit<P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_TP_TPBR_AD_XSCOM_BASE_REG_DISABLE]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
