/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/phb/reg00012.H $          */
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

#ifndef __PHB_REG00012_H_
#define __PHB_REG00012_H_

namespace scomt
{
namespace phb
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL;
#endif
    return fapi2::getScom(i_target, RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return fapi2::putScom(i_target, RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.insertFromRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.setBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return o_data.clearBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.extractToRight<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL));
#endif
    return i_data.getBit<RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
