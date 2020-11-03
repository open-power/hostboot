/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00037.H $         */
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

#ifndef __PROC_REG00037_H_
#define __PROC_REG00037_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR]

//>> PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR]


//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_TM_MASTER_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_GP_MASTER_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_CHG_RATE_SP_MASTER_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE0]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_NP_CMD_RATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_AGGREGATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_INDIRECT_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_G_GATHER_ENABLE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE1]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_GP_CMD_RATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_AGGREGATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_INDIRECT_EN_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.setBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]

//>> CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]
static inline bool GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.getBit<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_R_GATHER_ENABLE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE2]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MIN_SP_CMD_RATE_CURR_ES3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]

//>> SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]

//>> GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]
static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3,
           PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_SPARE3]

//>> PREP_[TP_TPBR_AD_TOPOID_XLAT_TBL0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_TOPOID_XLAT_TBL0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_TOPOID_XLAT_TBL0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_TOPOID_XLAT_TBL0]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_TOPOID_XLAT_TBL0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_TOPOID_XLAT_TBL0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_TOPOID_XLAT_TBL0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0]

//>> PUT_[TP_TPBR_AD_TOPOID_XLAT_TBL0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_TOPOID_XLAT_TBL0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_TOPOID_XLAT_TBL0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_TOPOID_XLAT_TBL0]


//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.setBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]

//>> CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.clearBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]
static inline bool GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.getBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.setBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]

//>> CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.clearBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]
static inline bool GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.getBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.setBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]

//>> CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.clearBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]
static inline bool GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.getBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.setBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]

//>> CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.clearBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]
static inline bool GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.getBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.setBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]

//>> CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.clearBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]
static inline bool GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.getBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.setBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]

//>> CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.clearBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]
static inline bool GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.getBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.setBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]

//>> CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.clearBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]
static inline bool GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.getBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.setBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]

//>> CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.clearBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]
static inline bool GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.getBit<TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7_VALID]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_0,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_0,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_0,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_0]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_1,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_1,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_1,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_1]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_2,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_2,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_2,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_2]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_3,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_3,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_3,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_3]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_4,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_4,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_4,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_4]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_5,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_5,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_5,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_5]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_6,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_6,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_6,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_6]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_7,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7]

//>> SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_TOPOID_XLAT_TBL0_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_7,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7]

//>> GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_TOPOID_XLAT_TBL0_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_TOPOID_XLAT_TBL0));
#endif
    return i_data.extractToRight<TP_TPBR_AD_TOPOID_XLAT_TBL0_7,
           TP_TPBR_AD_TOPOID_XLAT_TBL0_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_TOPOID_XLAT_TBL0_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_TOPOID_XLAT_TBL0_7]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
