/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00021.H $         */
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

#ifndef __PROC_REG00021_H_
#define __PROC_REG00021_H_

namespace scomt
{
namespace proc
{


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_IN(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_IN;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_IN(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_IN;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_IN, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_IN(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_IN));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SBE_FIFO_FSB_UPFIFO_DATA_IN, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_WRITE_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_BROADCAST_FLAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS,
           TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS,
           TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS,
           TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION,
           TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION,
           TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION,
           TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE,
           TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE,
           TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI, TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE,
           TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_COMMAND_REGISTER_SCAN_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI, TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI, TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI, TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER,
           TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI, TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER,
           TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI, TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER,
           TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SHIFT_CONTROL_REGISTER_2_SHIFT_CONTROL_REGISTER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RESET(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RESET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RESET(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RESET;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RESET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RESET(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RESET));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_0_RESET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_CMD_WRDAT_WRITE_NOT_READ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIM(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIM(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIM;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIM(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIM));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_B_PIB2OPB_COMP_P_0_CRSIM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MATRB0_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MDTRB0_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_GENERAL_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_WO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_0_MRESP2_ERROR_RESET_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSIEP1_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAESP0_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCRSP1_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MCSIEP0_SCOMFSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_FSI0, TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2,
           TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSTAP1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SCMBR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCMBR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SCMBR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SCMBR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCMBR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SCMBR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SCMBR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SCMBR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SMBR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SMBR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SMBR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SMBR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SMBR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SMBR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SMBR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SMBR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_A_SSI2M(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSI2M;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_A_SSI2M(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_A_SSI2M;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSI2M, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_A_SSI2M(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_A_SSI2M));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_A_SSI2M, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MAESP6_SCOMFSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MDLYR_SCOMFSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MENP1_SCOMFSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_FSI1, TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2,
           TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSTAP7_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SCRSIC0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SCRSIC0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SCRSIC0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SCRSIC0;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SCRSIC0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SCRSIC0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SCRSIC0));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SCRSIC0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SDMA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SDMA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SDMA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SDMA;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SDMA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SDMA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SDMA));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SDMA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SISC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SISC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SISC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SISC;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SISC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SISC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SISC));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SISC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SLAVE_B_SRSIS4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SRSIS4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SLAVE_B_SRSIS4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SLAVE_B_SRSIS4;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SRSIS4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SLAVE_B_SRSIS4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SLAVE_B_SRSIS4));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SLAVE_B_SRSIS4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_BASE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_MEMORY_MAPPING_RESERVED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW,
                           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WAND, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST2_PORT_CONTROL_PORT_CONTROL_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_
(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_
(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_
(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT_));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q,
           TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPVSB_FSI_W_SPIMC_SPI_PIB_SPIMST3_ERROR_INJECT__ERROR_REG_Q chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}


}
}

#endif
