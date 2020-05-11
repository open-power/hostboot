/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00046.H $         */
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

#ifndef __PROC_REG00046_H_
#define __PROC_REG00046_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR]

//>> PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR]


//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ADDR_DIS_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX0_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX1_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX2_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX3_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX4_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX5_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX6_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_MODE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_LINK_AX7_ID_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE,
           PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE2_CURR_PB_CFG_SPARE]

//>> PREP_[PB_COM_SCOM_ES3_STATION_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_MODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_MODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_MODE]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_MODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_MODE;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_MODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE]

//>> PUT_[PB_COM_SCOM_ES3_STATION_MODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_MODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_MODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_MODE]


//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_PBIXXX_INIT]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED,
           PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED,
           PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED,
           PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_ES3_DBG_MAX_HANG_STAGE_REACHED]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HOP_MODE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PUMP_MODE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REPRO_MODE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_HNG_CHK_DISABLE]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_DBG_CLR_MAX_HANG_STAGE]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_REQ_GATHER_ENABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NHTM_EVENT_COMP_EN_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_OPTION_AB_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SW_AB_WAIT_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SP_HW_MARK_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_GP_HW_MARK_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_NP_HW_MARK_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_OVERRIDE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_INTERNAL]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_MCA_RATIO_SEL_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_OVERRIDE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_STEP_SEL_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_SWITCH_CD_GATE_ENABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_PAU_RATIO_INTERNAL]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_SERIES_ID_DISABLE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_TOKEN_ID_RANGE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_TLBI_TOKENS_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3,
           PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_TMGR_MAX_SLBI_TOKENS_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_MODE));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_MODE_PB_CFG_RESET_ERROR_CAPTURE_ES3]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
