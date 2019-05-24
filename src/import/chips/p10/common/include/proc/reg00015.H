/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00015.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __PROC_REG00015_H_
#define __PROC_REG00015_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT;
#endif
    return fapi2::getScom(i_target, PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return fapi2::putScom(i_target, PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MASTER_CHIP_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_TM_MASTER_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_GP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_CHG_RATE_SP_MASTER_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4,
           PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4,
           PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4,
           PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_NP_CMD_RATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_G_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4,
           PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4,
           PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4,
           PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_G_CMD_RATE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_AGGREGATE_NEXT_ES4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_INDIRECT_EN_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.setBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.clearBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.getBit<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_R_GATHER_ENABLE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4,
           PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return o_data.insertFromRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4,
           PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT));
#endif
    return i_data.extractToRight<PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4,
           PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_COM_SCOM_ES4_STATION_HP_MODE1_NEXT_MIN_R_CMD_RATE_NEXT_ES4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_FM0123_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FM0123_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_FM0123_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_FM0123_ERR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_FM0123_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_FM0123_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_FM0123_ERR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_FM0123_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_10_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_10_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_10_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_10_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_10_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_10_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MAILBOX_10_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_10_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM10_MAILBOX_11_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_11_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM10_MAILBOX_11_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM10_MAILBOX_11_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM10_MAILBOX_11_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM10_MAILBOX_11_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM10_MAILBOX_11_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM10_MAILBOX_11_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0,
           PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0,
           PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_ACTION0_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0,
           PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1,
           PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1,
           PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1,
           PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM23_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_TL_LINK_SYN_23_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_TL_LINK_SYN_23_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_TL_LINK_SYN_23_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_TL_LINK_SYN_23_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_TL_LINK_SYN_23_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_TL_LINK_SYN_23_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_00_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_00_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_MAILBOX_00_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_MAILBOX_00_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_MAILBOX_00_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_MAILBOX_00_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_01_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_MAILBOX_01_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_MAILBOX_01_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_MAILBOX_01_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_MAILBOX_01_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_MAILBOX_01_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PMU0_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PMU0_TLPM_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PMU0_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PMU0_TLPM_COUNTER;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PMU0_TLPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PMU0_TLPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PMU0_TLPM_COUNTER));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PMU0_TLPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DOB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB01_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_CROB23_ATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_0_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_1_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_2_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_LINK_DOWN_3_ATTN_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB01_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_DIB23_ERR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB00_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB01_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB10_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB11_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB20_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB21_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB30_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_MB31_SPATTN_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL0_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL1_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL2_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_MASK_REG_RW, PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_AND,
                           PB_PTLSCOM45_PTL_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_PTL_FIR_MASK_REG_PTL3_SPARE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_TRACE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_TRACE_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_TRACE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_TRACE_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_TRACE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_TRACE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_TRACE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TRACE_CFG_0L_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TRACE_CFG_0L_SEL,
           PB_PTLSCOM45_TRACE_CFG_0L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_0L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TRACE_CFG_0L_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TRACE_CFG_0L_SEL,
           PB_PTLSCOM45_TRACE_CFG_0L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_0L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_TRACE_CFG_0L_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_TRACE_CFG_0L_SEL,
           PB_PTLSCOM45_TRACE_CFG_0L_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_0L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TRACE_CFG_0R_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TRACE_CFG_0R_SEL,
           PB_PTLSCOM45_TRACE_CFG_0R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_0R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TRACE_CFG_0R_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TRACE_CFG_0R_SEL,
           PB_PTLSCOM45_TRACE_CFG_0R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_0R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_TRACE_CFG_0R_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_TRACE_CFG_0R_SEL,
           PB_PTLSCOM45_TRACE_CFG_0R_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_0R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TRACE_CFG_1L_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TRACE_CFG_1L_SEL,
           PB_PTLSCOM45_TRACE_CFG_1L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_1L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TRACE_CFG_1L_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TRACE_CFG_1L_SEL,
           PB_PTLSCOM45_TRACE_CFG_1L_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_1L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_TRACE_CFG_1L_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_TRACE_CFG_1L_SEL,
           PB_PTLSCOM45_TRACE_CFG_1L_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_1L_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TRACE_CFG_1R_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TRACE_CFG_1R_SEL,
           PB_PTLSCOM45_TRACE_CFG_1R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_1R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_TRACE_CFG_1R_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_TRACE_CFG_1R_SEL,
           PB_PTLSCOM45_TRACE_CFG_1R_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_1R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_TRACE_CFG_1R_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_TRACE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_TRACE_CFG_1R_SEL,
           PB_PTLSCOM45_TRACE_CFG_1R_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_TRACE_CFG_1R_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_RCMD_RATE_CFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_RCMD_RATE_CFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_RCMD_RATE_CFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_RCMD_RATE_CFG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_RCMD_RATE_CFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_RCMD_RATE_CFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_RCMD_RATE_CFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE,
           PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE,
           PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE,
           PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE,
           PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE,
           PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE,
           PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER,
           PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER,
           PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER,
           PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER,
           PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER,
           PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER,
           PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_RCMD_RATE_ADDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG,
           PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG,
           PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG,
           PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_X_CMD_GAP_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.setBit<PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.clearBit<PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.getBit<PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_DISABLE_TURBO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG,
           PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG,
           PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_RCMD_RATE_CFG));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG,
           PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM45_RCMD_RATE_CFG_Y_CMD_GAP_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_DOB23_DIB23_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_DOB23_DIB23_INT_ERR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_DOB23_DIB23_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_DOB23_DIB23_INT_ERR_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_DOB23_DIB23_INT_ERR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_DOB23_DIB23_INT_ERR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_DOB23_DIB23_INT_ERR_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_DOB23_DIB23_INT_ERR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_MAILBOX_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_MAILBOX_DATA_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_MAILBOX_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_MAILBOX_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_MAILBOX_DATA_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_MAILBOX_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PMU3_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PMU3_CNPM_COUNTER;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PMU3_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PMU3_CNPM_COUNTER;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PMU3_CNPM_COUNTER, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PMU3_CNPM_COUNTER(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PMU3_CNPM_COUNTER));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PMU3_CNPM_COUNTER, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PR0123_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PR0123_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PR0123_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PR0123_ERR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PR0123_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PR0123_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PR0123_ERR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PR0123_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT,
           PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_PTLSCOM67_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_FIR_WOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_FIR_WOF;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_FIR_WOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_FIR_WOF;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_FIR_WOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_FIR_WOF(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_FIR_WOF));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_FIR_WOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_FIR_WOF));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS,
           PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_FIR_WOF));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS,
           PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_FIR_WOF));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS,
           PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_FIR_WOF_FIR_WOF_BITS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_CHSW_CTRL_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_CHSW_CTRL_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_CHSW_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_CHSW_CTRL_REG;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_CHSW_CTRL_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_CHSW_CTRL_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_CHSW_CTRL_REG));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_CHSW_CTRL_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_CHSW_CTRL_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK,
           PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_CHSW_CTRL_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK,
           PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_CHSW_CTRL_REG));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK,
           PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_CHSW_CTRL_REG_CHSW_TTYPE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS,
           PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG));
#endif
    return o_data.insertFromRight<PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS,
           PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG));
#endif
    return i_data.extractToRight<PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS,
           PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_HCA_DECAY_0_ADDRESS_REG_DECAY_0_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS,
           PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access PB_BRIDGE_NHTM_NHTM1_SC_HTM_LAST_HTM_LAST_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_CLOCK_STAT_NSL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CLOCK_STAT_NSL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_CLOCK_STAT_NSL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_CLOCK_STAT_NSL;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_CLOCK_STAT_NSL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_CLOCK_STAT_NSL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_CLOCK_STAT_NSL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_PERV_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT1_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT2_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT3_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT4_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT5_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT6_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT7_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT8_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT9_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT10_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT11_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT12_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT13_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.setBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return o_data.clearBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.extractToRight<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_CLOCK_STAT_NSL));
#endif
    return i_data.getBit<TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_CLOCK_STAT_NSL_UNIT14_NSL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_DBG_CBS_CC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_DBG_CBS_CC;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_DBG_CBS_CC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_DBG_CBS_CC(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_DBG_CBS_CC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_RESET_EP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_OPCG_IP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_VITL_CLKOFF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_TEST_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD,
           TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD,
           TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD,
           TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE,
           TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE,
           TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE,
           TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_IDLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE,
           TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE,
           TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_LAST_OPCG_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.setBit<TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return o_data.clearBit<TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.extractToRight<TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_DBG_CBS_CC));
#endif
    return i_data.getBit<TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_DBG_CBS_CC_TP_TPFSI_CBS_ACK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_OPCG_CAPT3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_OPCG_CAPT3;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_OPCG_CAPT3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_OPCG_CAPT3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_OPCG_CAPT3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_07EVEN,
           TP_TCN0_N0_OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_07EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_07EVEN,
           TP_TCN0_N0_OPCG_CAPT3_07EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_07EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_07EVEN,
           TP_TCN0_N0_OPCG_CAPT3_07EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_07EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_07ODD,
           TP_TCN0_N0_OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_07ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_07ODD,
           TP_TCN0_N0_OPCG_CAPT3_07ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_07ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_07ODD,
           TP_TCN0_N0_OPCG_CAPT3_07ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_07ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_08EVEN,
           TP_TCN0_N0_OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_08EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_08EVEN,
           TP_TCN0_N0_OPCG_CAPT3_08EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_08EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_08EVEN,
           TP_TCN0_N0_OPCG_CAPT3_08EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_08EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_08ODD,
           TP_TCN0_N0_OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_08ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_08ODD,
           TP_TCN0_N0_OPCG_CAPT3_08ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_08ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_08ODD,
           TP_TCN0_N0_OPCG_CAPT3_08ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_08ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_09EVEN,
           TP_TCN0_N0_OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_09EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_09EVEN,
           TP_TCN0_N0_OPCG_CAPT3_09EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_09EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_09EVEN,
           TP_TCN0_N0_OPCG_CAPT3_09EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_09EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_09ODD,
           TP_TCN0_N0_OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_09ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_09ODD,
           TP_TCN0_N0_OPCG_CAPT3_09ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_09ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_09ODD,
           TP_TCN0_N0_OPCG_CAPT3_09ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_09ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_10EVEN,
           TP_TCN0_N0_OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_10EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_10EVEN,
           TP_TCN0_N0_OPCG_CAPT3_10EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_10EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_10EVEN,
           TP_TCN0_N0_OPCG_CAPT3_10EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_10EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_10ODD,
           TP_TCN0_N0_OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_10ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_10ODD,
           TP_TCN0_N0_OPCG_CAPT3_10ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_10ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_10ODD,
           TP_TCN0_N0_OPCG_CAPT3_10ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_10ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_11EVEN,
           TP_TCN0_N0_OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_11EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_11EVEN,
           TP_TCN0_N0_OPCG_CAPT3_11EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_11EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_11EVEN,
           TP_TCN0_N0_OPCG_CAPT3_11EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_11EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_11ODD,
           TP_TCN0_N0_OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_11ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_11ODD,
           TP_TCN0_N0_OPCG_CAPT3_11ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_11ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_11ODD,
           TP_TCN0_N0_OPCG_CAPT3_11ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_11ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_12EVEN,
           TP_TCN0_N0_OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_12EVEN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_12EVEN,
           TP_TCN0_N0_OPCG_CAPT3_12EVEN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_12EVEN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_12EVEN,
           TP_TCN0_N0_OPCG_CAPT3_12EVEN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_12EVEN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_12ODD,
           TP_TCN0_N0_OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_OPCG_CAPT3_12ODD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_OPCG_CAPT3_12ODD,
           TP_TCN0_N0_OPCG_CAPT3_12ODD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_OPCG_CAPT3_12ODD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_OPCG_CAPT3));
#endif
    return i_data.extractToRight<TP_TCN0_N0_OPCG_CAPT3_12ODD,
           TP_TCN0_N0_OPCG_CAPT3_12ODD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_OPCG_CAPT3_12ODD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN0_N0_TRA0_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_TRA0_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN0_N0_TRA0_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN0_N0_TRA0_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TP_TCN0_N0_TRA0_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN0_N0_TRA0_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TP_TCN0_N0_TRA0_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_CONFIG_4_A,
           TP_TCN0_N0_TRA0_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_CONFIG_4_A,
           TP_TCN0_N0_TRA0_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR0_CONFIG_4_A,
           TP_TCN0_N0_TRA0_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_CONFIG_4_B,
           TP_TCN0_N0_TRA0_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN0_N0_TRA0_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN0_N0_TRA0_TR0_CONFIG_4_B,
           TP_TCN0_N0_TRA0_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN0_N0_TRA0_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN0_N0_TRA0_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN0_N0_TRA0_TR0_CONFIG_4_B,
           TP_TCN0_N0_TRA0_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN0_N0_TRA0_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CONF1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CONF1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CONF1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CONF1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CONF1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_LP_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_LP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_LP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CONF1_LP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CONF1_LP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CONF1_LP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CONF1_LP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CONF1_LP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CONF1_LP_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CONF1_LP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CONF1_LP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CONF1_RW, TP_TCN1_N1_CPLT_CONF1_WO_CLEAR, TP_TCN1_N1_CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CONF1_LP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CONF1_LP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL1_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CTRL1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CTRL1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_VITL_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL1_RW, TP_TCN1_N1_CPLT_CTRL1_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK,
           TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE,
           TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE,
           TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE,
           TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_LOCAL_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_XSTOP_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_XSTOP_MASK_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_LOCAL_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_LOCAL_XSTOP_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_LOCAL_XSTOP_MASK_RW, TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_CLEAR,
                           TP_TCN1_N1_LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_LOCAL_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_SCAN32(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_SCAN32;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_SCAN32(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_SCAN32;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_SCAN32, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_SCAN32(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_SCAN32));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_SCAN32, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_SCAN64(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_SCAN64;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_SCAN64(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_SCAN64;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_SCAN64, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_SCAN64(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_SCAN64));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_SCAN64, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA0_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA0_TR1_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA0_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA0_TR1_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA0_TR1_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA0_TR1_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA0_TR1_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_5_C,
           TP_TCN1_N1_TRA0_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_5_C,
           TP_TCN1_N1_TRA0_TR1_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA0_TR1_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA0_TR1_CONFIG_5_C,
           TP_TCN1_N1_TRA0_TR1_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_5_D,
           TP_TCN1_N1_TRA0_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA0_TR1_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA0_TR1_CONFIG_5_D,
           TP_TCN1_N1_TRA0_TR1_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA0_TR1_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA0_TR1_CONFIG_5));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA0_TR1_CONFIG_5_D,
           TP_TCN1_N1_TRA0_TR1_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA0_TR1_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA1_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA1_TR0_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA1_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA1_TR0_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA1_TR0_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA1_TR0_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA1_TR0_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_3_C,
           TP_TCN1_N1_TRA1_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_3_C,
           TP_TCN1_N1_TRA1_TR0_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR0_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR0_CONFIG_3_C,
           TP_TCN1_N1_TRA1_TR0_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_3_D,
           TP_TCN1_N1_TRA1_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR0_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR0_CONFIG_3_D,
           TP_TCN1_N1_TRA1_TR0_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR0_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR0_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR0_CONFIG_3_D,
           TP_TCN1_N1_TRA1_TR0_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR0_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA2_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA2_TR0_CONFIG_4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA2_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA2_TR0_CONFIG_4;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA2_TR0_CONFIG_4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA2_TR0_CONFIG_4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_4));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA2_TR0_CONFIG_4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_4_A,
           TP_TCN1_N1_TRA2_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_4_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_4_A,
           TP_TCN1_N1_TRA2_TR0_CONFIG_4_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA2_TR0_CONFIG_4_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA2_TR0_CONFIG_4_A,
           TP_TCN1_N1_TRA2_TR0_CONFIG_4_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_4_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_4_B,
           TP_TCN1_N1_TRA2_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA2_TR0_CONFIG_4_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_4));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA2_TR0_CONFIG_4_B,
           TP_TCN1_N1_TRA2_TR0_CONFIG_4_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA2_TR0_CONFIG_4_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA2_TR0_CONFIG_4));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA2_TR0_CONFIG_4_B,
           TP_TCN1_N1_TRA2_TR0_CONFIG_4_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA2_TR0_CONFIG_4_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA3_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA3_TR1_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA3_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA3_TR1_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA3_TR1_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA3_TR1_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA3_TR1_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_2_A,
           TP_TCN1_N1_TRA3_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_2_A,
           TP_TCN1_N1_TRA3_TR1_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA3_TR1_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA3_TR1_CONFIG_2_A,
           TP_TCN1_N1_TRA3_TR1_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_2_B,
           TP_TCN1_N1_TRA3_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA3_TR1_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA3_TR1_CONFIG_2_B,
           TP_TCN1_N1_TRA3_TR1_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA3_TR1_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA3_TR1_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA3_TR1_CONFIG_2_B,
           TP_TCN1_N1_TRA3_TR1_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA3_TR1_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA4_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA4_TR1_CONFIG_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA4_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA4_TR1_CONFIG_3;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA4_TR1_CONFIG_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA4_TR1_CONFIG_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_3));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA4_TR1_CONFIG_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_3_C,
           TP_TCN1_N1_TRA4_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_3_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_3_C,
           TP_TCN1_N1_TRA4_TR1_CONFIG_3_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA4_TR1_CONFIG_3_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA4_TR1_CONFIG_3_C,
           TP_TCN1_N1_TRA4_TR1_CONFIG_3_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_3_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_3_D,
           TP_TCN1_N1_TRA4_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA4_TR1_CONFIG_3_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_3));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA4_TR1_CONFIG_3_D,
           TP_TCN1_N1_TRA4_TR1_CONFIG_3_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA4_TR1_CONFIG_3_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA4_TR1_CONFIG_3));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA4_TR1_CONFIG_3_D,
           TP_TCN1_N1_TRA4_TR1_CONFIG_3_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA4_TR1_CONFIG_3_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA5_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR0_CONFIG_5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA5_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA5_TR0_CONFIG_5;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA5_TR0_CONFIG_5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA5_TR0_CONFIG_5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_5));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA5_TR0_CONFIG_5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_5_C,
           TP_TCN1_N1_TRA5_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_5_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_5_C,
           TP_TCN1_N1_TRA5_TR0_CONFIG_5_C_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA5_TR0_CONFIG_5_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA5_TR0_CONFIG_5_C,
           TP_TCN1_N1_TRA5_TR0_CONFIG_5_C_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_5_C chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_5_D,
           TP_TCN1_N1_TRA5_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA5_TR0_CONFIG_5_D(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_5));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA5_TR0_CONFIG_5_D,
           TP_TCN1_N1_TRA5_TR0_CONFIG_5_D_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA5_TR0_CONFIG_5_D(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA5_TR0_CONFIG_5));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA5_TR0_CONFIG_5_D,
           TP_TCN1_N1_TRA5_TR0_CONFIG_5_D_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA5_TR0_CONFIG_5_D chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_TRA6_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_CONFIG_2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_TRA6_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_TRA6_TR0_CONFIG_2;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_TRA6_TR0_CONFIG_2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_TRA6_TR0_CONFIG_2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_2));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_TRA6_TR0_CONFIG_2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_2_A,
           TP_TCN1_N1_TRA6_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_2_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_2_A,
           TP_TCN1_N1_TRA6_TR0_CONFIG_2_A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_CONFIG_2_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_CONFIG_2_A,
           TP_TCN1_N1_TRA6_TR0_CONFIG_2_A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_2_A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_2_B,
           TP_TCN1_N1_TRA6_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_TRA6_TR0_CONFIG_2_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_2));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_TRA6_TR0_CONFIG_2_B,
           TP_TCN1_N1_TRA6_TR0_CONFIG_2_B_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_TRA6_TR0_CONFIG_2_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_TRA6_TR0_CONFIG_2));
#endif
    return i_data.extractToRight<TP_TCN1_N1_TRA6_TR0_CONFIG_2_B,
           TP_TCN1_N1_TRA6_TR0_CONFIG_2_B_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TCN1_N1_TRA6_TR0_CONFIG_2_B chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_COMMAND_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR,
           TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR,
           TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR,
           TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_PIB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE,
           TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE,
           TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE,
           TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_CRESP_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_XSCOM_LOG_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_XSCOM_LOG_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_XSCOM_LOG_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_XSCOM_LOG_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_XSCOM_LOG_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_XSCOM_LOG_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_XSCOM_LOG_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_CMD_IN_PROG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS,
           TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS,
           TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS,
           TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_CMD_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_WRITE_CMD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG,
           TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG,
           TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG,
           TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_ADDR_TAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_THR_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_THR_ID,
           TP_TPBR_AD_XSCOM_LOG_REG_THR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_THR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_THR_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_THR_ID,
           TP_TPBR_AD_XSCOM_LOG_REG_THR_ID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_THR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_LOG_REG_THR_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_LOG_REG_THR_ID,
           TP_TPBR_AD_XSCOM_LOG_REG_THR_ID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_THR_ID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_PIB_COMPONENT_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR,
           TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR,
           TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_XSCOM_LOG_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR,
           TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_XSCOM_LOG_REG_PIB_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCDE_SET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_SET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCDE_SET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_SET;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_SET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCDE_SET(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_SET));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_SET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_SET));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_SET));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_SET));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_SET_RESERVED_0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_SET));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH,
           TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_SET));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH,
           TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_SET));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH,
           TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_BCDE_SET_COPY_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABAR1_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK0_PBABARMSK0_MSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_RD_SLVNUM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_PREFETCH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_BUFFER_STATUS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

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
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL1_MASTERID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXISHBR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHBR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXISHBR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHBR0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHBR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXISHBR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHBR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHBR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHBR0_PBAXISHBR0_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


}
}

#endif
