/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00016.H $         */
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

#ifndef __PROC_REG00016_H_
#define __PROC_REG00016_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


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


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_CMD_ARBIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDR_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_DATA_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_RESP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_OVERRUN_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_AUTOINC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_COMMAND_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ADDRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_OP_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_DATA_HANG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_CRESP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PB_UNEXPECT_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_WAIT_PIB_DIRECT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_DIRECT_DONE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_COPY_OF_ALTD_PBINIT_MISSING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_PIB_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_ECC_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_STATUS_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE,
           TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_AD_ALTD_STATUS_REG_FBC_ALTD_CRESP_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
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

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXISHCS1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHCS1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXISHCS1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXISHCS1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHCS1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXISHCS1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXISHCS1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXISHCS1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXISHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHBR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHBR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHBR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHBR0_PUSH_START chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHCS1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHCS1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHCS1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_FULL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_RESERVED_2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_LENGTH chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS1));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS1_PUSH_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_CH_MISC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_CH_MISC_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_TX_CH_MISC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_TX_CH_MISC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_FSM chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE,
           TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_TFRAMESIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_DATA_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_START_TRANS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_MISC_REG_GXDATAAVAIL_Q chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_NOTRUST_BAR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_NOTRUST_BAR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_NOTRUST_BAR0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_NOTRUST_BAR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_NOTRUST_BAR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0,
           TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0,
           TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_NOTRUST_BAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0,
           TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_NOTRUST_BAR0_UNTRUSTED_BAR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_FIR_MASK_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_FIR_MASK_REG_RW;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_FIR_MASK_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_FIR_MASK_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_FIR_MASK_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_ECC_ERR_SUE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_FROM_FSP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_CE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ECC_ERR_UE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_ERROR_STATE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_TTYPE_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INVALID_CRESP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_DATA_TIME_OUT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_PB_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FSP_ACCESS_TRUSTED_SPACE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UNEXPECTED_PB_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT0_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT1_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT2_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT3_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT4_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_INTERRUPT5_ADDRESS_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_0_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_TCBR_TP_PSI_GLB_ERR_1_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_UPSTREAM_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK,
           TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK,
           TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK,
           TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_SPARE_FIR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_MASK_REG_RW, TP_TPBR_PSIHB_FIR_MASK_REG_WO_AND,
                           TP_TPBR_PSIHB_FIR_MASK_REG_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPBR_PSIHB_FIR_MASK_REG_FIR_PARITY_ERROR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_3_MULTICAST3_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK,
           TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK,
           TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK,
           TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLN0_PLL_LOCK_REG_LOCK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_VITAL_SCAN_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_VITAL_SCAN_OUT;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_VITAL_SCAN_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_VITAL_SCAN_OUT));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_VITAL_SCAN_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>&
        i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG(const fapi2::Target<K, M, V>&
        i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_HOSTATTN_INTERRUPT_REG_TYPE4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP,
           TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP,
           TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP,
           TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_MULTICAST_GROUP_3_MULTICAST3_GROUP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CHIPLET_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PCB_EP_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CLK_ASYNC_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_TEST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLL_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_SCAN_IN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_PHASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_ALIGN_OVR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_AL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ACT_DIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TOADMODE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_SYNC_PULSE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_MPW3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_DELAY_LCLKR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_VITAL_THOLD chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FLUSH_SCAN_N chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FENCE_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_DCTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_CPLT_RCTRL2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ADJ_FUNC_CLKSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PM_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_FUNC_LCB_EDIS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_TP_FENCE_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_LVLTRANS_FENCE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_ARRAY_WRITE_ASSIST_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_INTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_HTB_EXTEST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW, TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WAND,
                           TP_TPCHIP_NET_PCBSLPERV_CTRL0_RW_WOR));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_NET_PCBSLPERV_CTRL0_PLLFORCE_OUT_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_VITAL_SCAN_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_VITAL_SCAN_OUT;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_VITAL_SCAN_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_VITAL_SCAN_OUT));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_VITAL_SCAN_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR31_OCB_OCI_GPEXIVDR30_GPR31 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR30_OCB_OCI_GPEXIVDR30_GPR30 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXILR_OCB_OCI_GPEXIDBGINF_LR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISPRG0_SPRG0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR4_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_SRR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGINF_LR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_BYTE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR0_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR30_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
